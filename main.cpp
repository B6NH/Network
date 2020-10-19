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

// ------------------------------------------------------------------------

// Different Byte Orders:
// Big End First (Network Byte Order)
// Little End First

// Computer uses Host Byte Order (BE or LE)
// Send data as NBO. After receiving value
// convert it to HBO.

// Host to Network:
// Short - htons()
// Long - htonl()

// Network to Host:
// Short - ntohs()
// Long - ntohl()

// ------------------------------------------------------------------------

// Socket descriptor is integer.
// Create struct addrinfo and call function gedaddrinfo().
// It returns pointer to new linked list of addrinfo structures.

// ai_family:
// IPv4 - AF_INET
// IPv6 - AF_INET6
// Unspecified - AF_UNSPEC

// Struct sockaddr can store data for different sockets:
// sa_family (AF_XXX)
// sa_data[14] (protocol address)

// Struct sockaddr_in - IPv4.
// Struct sockaddr_in6 - IPv6.
// Struct sockaddr_storage - IPv4 and IPv6.

// Convert IP addres from numbers and dots to sockaddr_in/sockaddr_in6 with
// function inet_pton() (presentation to network).
// Convert sockaddr_in/sockaddr_in6 to IP string with function inet_ntop().

// Network Address Translation (NAT) is process of changing internal IP address
// to its external representation. For example external address can be
// 192.0.2.33 and internal 10.0.0.5. Addresses 10.X.X.X are reserved to be
// used for disconnected networks or networks behind firewall.
// Addresses 192.168.X.X and 172.Y.X.X are also used for this purpose.
// Range: X(0-255), Y(16-31).

// IPv6 private networks start with fdXX:.

// ------------------------------------------------------------------------

// Adapt to use IPv6.

// Call getaddrinfo() to get sockaddr data. Change AF_INET to AF_INET6,
// PF_INET to PF_INET6 and INADDR_ANY assignments to in6addr. Value
// IN6ADDR_AN_INIT can be used as initializer for in6_addr structure.
// Change sockaddr_in to sockaddr_in6 and in_addr to in6_addr.
// Use inet_pton(), inet_ntop(), getaddrinfo() and getnameinfo() functions.

// ------------------------------------------------------------------------

// Function getaddrinfo() takes 3 parameters and returns pointer to linked
// list of results (addrinfo structures). Parameters are:
// node - host name or IP address
// service - port number("80") or service name("http")
// hints - addrinfo structure
// res - result

// Configure addrinfo hints (ai_family, ai_socktype, ai_flags) and call function
// getaddrinfo(). It returns 0 if operation was successful. At the end free
// list of structures with function freeaddrinfo().

// ------------------------------------------------------------------------

// Function socket(domain, type, protocol) returns socket descriptor or -1.
// Pass parameters from getaddrinfo():
// - res->ai_family
// - res->ai_socktype
// - res->ai_protocol

// Function bind(sockfd, my_addr, addrlen):
// - file descriptor from socket() function
// - pointer to sockaddr structure
// - length of address

// Function connect(sockfd, serv_addr, addrlen)
// - file descriptor
// - structure with destination port and address
// - length of address structures

// Function listen(sockfd, backlog)
// - file descriptor
// - number of allowed connections

// Connections wait in queue until function accept() is called.

// Order of functions:
// getaddrinfo() -> socket() -> bind() -> listen()

// Function accept(sockfd, addr, addrlen)
// - listening socket descriptor
// - pointer to sockaddr_storage
// - sizeof struct sockaddr_storage

// ------------------------------------------------------------------------

// Function send(sockfd, msg, len, flags) returns number of bytes sent.
// - socket descriptor
// - pointer to data
// - length of data
// - 0

// Function recv(sockfd, buf, len, flags) returns number of bytes read.
// - socket descriptor
// - data buffer
// - maximum length of buffer
// - 0

// Functions sendto and recvfrom are used for connectionless datagram sockets.
// Use function close() with socket descriptor to close connection.
// Function shutdown() can control how sockets are closed.

// Function getpeername() returns information about other side of stream socket.
// Function gethostname() returns name of current computer that can be later
// used by gethostbyname() to get IP address.


int main(){
  std::cout << "Network\n";
}
