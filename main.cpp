#include <iostream>

// Communicate with other programs using sockets and file descriptors.
// File descriptor is integer associated with open file. Everything is file.
// Method "socket()" returns file descriptor for network communication.
// Communicate through file descriptor with "send()" and "recv()" methods.

// Stream Socket | Datagram Socket (SOCK_STREAM,SOCK_DGRAM)
// Datagram Socket is connectionless socket.
// Stream Socket data is always valid and order of items is preserved.

// Stream Socket is used by telnet, web browsers and HTTP.
// Stream Sockets use TCP(Transmission Control Protocol).

// Datagram Sockets are fast but unreliable. To improve reliability other
// protocols are created on top of datagram.
// Datagram Sockets use UDP(User Datagram Protocol).

// Both types of sockets use IP for routing.

// Packets are encapsulated by subsequent protocols.
// For example: TFTP -> UDP -> IP -> Ethernet
// Layers are unpacked by hardware, kernel, software etc.

// In Layered Network Model (ISO/OSI) programmers dont need to know about
// physical data transmission.

// ------------------------------------------------------------------------

// IPv4 is 4 byte address(32 bits):
// - 192.0.2.111.

// IPv6 is 16 byte address(128 bits):
// - 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551

// IPv6 zeros can be ommited:

// 2001:0db8:c9d2:0012:0000:0000:0000:0051
// 2001:db8:c9d2:12::51

// 2001:0db8:ab00:0000:0000:0000:0000:0000
// 2001:db8:ab00::

// IPv6 Loopback address
// 0000:0000:0000:0000:0000:0000:0000:0001
// ::1

// IPv4 Loopback address
// 127.0.0.1

// Compatibility mode:
// IPv4 - 192.0.2.33
// IPv6 - ::ffff:192.0.2.33

// Subnets
// 192.0.2.12
// Network 3 bytes - 192.0.2
// Host 1 byte - 12

// Classes of subnets (A, B, C).
// Network part in 1, 2 or 3 bytes.
// Less bytes for network means higher class and more hosts.

// Network part of IP address is described by netmask
// Netmask - 255.255.255.0
// IP - 192.0.2.12
// Network - IP AND Netmask - 192.0.2.0

// Netmask is 1 bits followed by 0 bits and can have arbitrary number of bits.
// Number of bits after slash:
// IPv4 - 192.0.2.12/30
// IPv6 - 2001:db8::/32
// IPv6 - 2001:db8:5413:4028::9db9/64

// Port is 16 bit number.
// Internet services use different port numbers (IANA)
// Ports under 1024 are special.


int main(){
  std::cout << "Network\n";
}
