// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <os>
#include <net/inet4>
#include <memdisk>
#include <timers>
#include <https>
static http::Server* server = nullptr;
extern http::Response_ptr handle_request(const http::Request&);

void Service::start()
{
  extern void create_network_device(int N, const char* route, const char* ip);
  create_network_device(0, "10.0.0.0/24", "10.0.0.1");

  // Get and configure IP stack
  auto& inet = net::Super_stack::get<net::IP4>(0);
  inet.network_config({10,0,0,42}, {255,255,255,0}, {10,0,0,1});

  // Print some useful netstats every 30 secs
  Timers::periodic(5s, 30s,
  [&inet] (uint32_t) {
    printf("<Service> TCP STATUS:\n%s\n", inet.tcp().status().c_str());
  });

  fs::memdisk().init_fs(
  [] (auto err, auto&) {
    assert(!err);
  });
  auto& filesys = fs::memdisk().fs();
  // load CA certificate
  auto ca_cert = filesys.stat("/test.der");
  // load CA private key
  auto ca_key  = filesys.stat("/test.key");
  // load server private key
  auto srv_key = filesys.stat("/server.key");

  server = new http::Secure_server(
        "blabla", ca_key, ca_cert, srv_key, inet.tcp());

  server->on_request(
    [] (auto request, auto response_writer) {
      response_writer->set_response(handle_request(*request));
      response_writer->write();
    });

  // listen on default HTTPS port
  server->listen(443);
  printf("*** TLS service started ***\n");
}
