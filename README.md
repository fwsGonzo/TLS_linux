> $ openssl speed sha
```
The 'numbers' are in 1000s of bytes per second processed.
type             16 bytes     64 bytes    256 bytes   1024 bytes   8192 bytes
sha1            169325.03k   515286.25k  1175890.01k  1731965.95k  2008976.04k
sha256          273751.41k   654760.75k  1297437.27k  1719499.43k  1899651.07k
sha512           56248.84k   224978.45k   394397.87k   587907.07k   689070.08k
```

> tls-speed
```
Starting TLS performance test using:
	Public key algorithm: rsa
	Public key size: 2048 bits
	Cipher: aes-128-cbc
	MAC: sha256
	PFS: ecdhe
	PFS ec curve: secp256r1
	PRF: sha256
	Object size: 104857600 bytes
	TLS record size: 16384
	TLS records per object: 6400
	Transactions: 10

Data processed:
	2560 bytes of public key stuff
	1049600000 bytes encrypted
	2048000 total MAC bytes
Duration:
	1.458 seconds
Approximate bytes that would be sent:
	1051648000 (bytes encrypted + MACs)
	1051684096 (bytes encrypted + MACs + TLS overhead estimate)
Approximate transfer rate (based on (bytes encrypted + MACs)/duration):
	721248168.578 bytes/sec
	5769985348.625 bits/sec
	5769985.349 kilobits/sec
	5769.985 megabits/sec
	5.770 gigabits/sec
Approximate transfer timing:
	6.858 transactions/second
	0.146 seconds/transfer
```
