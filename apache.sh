#!/bin/bash
sudo apt install apache2
sudo a2enmod ssl
echo "Use your url for the Common Name (CN)"
openssl req $@ -new -x509 -days 365 -nodes -out /etc/apache2/apache.pem -keyout /etc/apache2/apache.pe
echo "-->"
echo "https://debian-administration.org/article/349/Setting_up_an_SSL_server_with_Apache2"
