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

// ------------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include <cstring>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h> // close(), gethostbyname()

using std::cout; using std::endl; using std::string;

void one();
void two();

int main(){
  one();
  two();
}



void one(){

  cout << "One\n";

  // Display host name
  char hostname[20];
  gethostname(hostname,sizeof(hostname));
  cout << "Host name: " << hostname << endl;

  // Byte order conversion
  const short current = 15;
  const short netshort = htons(current);
  assert(ntohs(netshort)==current);

  // IP to binary conversion
  sockaddr_in sa; sockaddr_in6 sa6;
  const char ip4address[] = "10.12.110.57";
  const char ip6address[] = "2001:db8:63b3:1::3490";
  inet_pton(AF_INET, ip4address, &(sa.sin_addr));
  inet_pton(AF_INET6, ip6address, &(sa6.sin6_addr));

  // Binary to string conversion
  char ip4[INET_ADDRSTRLEN]; char ip6[INET6_ADDRSTRLEN];
  inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
  inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);
  assert(0==strcmp(ip4,ip4address)); assert(0==strcmp(ip6,ip6address));

  // Use getaddrinfo(address|ip, service|port, hints, result)
  int status; addrinfo hints; addrinfo * servinfo;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // ip is NULL

  // Results are addrinfo structures with pointers to sockaddr_in/sockaddr_in6.
  if((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0){
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(1);
  }

  int sockfd = socket(servinfo->ai_family,
                      servinfo->ai_socktype,
                      servinfo->ai_protocol);

  int rr = bind(sockfd,servinfo->ai_addr, servinfo->ai_addrlen);
  assert(0==rr);

  listen(sockfd,10);

  close(sockfd);

  sockaddr_storage their_addr;
  socklen_t addr_size = sizeof their_addr;

  // Call accept(descriptor, storage, sizeof sockaddr_storage).
  // Return new file descriptor.
  //int new_fd = accept(sockfd,(sockaddr *)&their_addr,&addr_size);

  // Free linked list of results through servinfo pointer
  freeaddrinfo(servinfo);

  cout << "End One\n";
}

void two(){

  cout << "Two\n";

  int status; addrinfo hints; addrinfo * res; addrinfo * p;

  memset(&hints,0,sizeof hints);
  hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM;
  // Skip "hints.ai_flags = AI_PASSIVE" for specific address

  if((status = getaddrinfo("example.com","3490",&hints,&res)) != 0){
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return;
  }

  char ipstr[INET6_ADDRSTRLEN];

  cout << "IP addresses for example.com:\n";

  for(p=res; p!=NULL; p=p->ai_next){
    void * addr; char ipver[5];

    if(p->ai_family == AF_INET){
      sockaddr_in * ipv4 = (sockaddr_in *)p->ai_addr;
      addr = &(ipv4->sin_addr);
      strcpy(ipver,"IPv4");
    }else{
      sockaddr_in6 * ipv6 = (sockaddr_in6 *)p->ai_addr;
      addr = &(ipv6->sin6_addr);
      strcpy(ipver,"IPv6");
    }

    // Convert binary IP to string
    inet_ntop(p->ai_family,addr,ipstr, sizeof ipstr);
    cout << ipver << ": " << ipstr << endl;

  }

  // Return socket descriptor
  int s;
  s = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

  sockaddr_in peer; unsigned int peer_len = sizeof(peer);
  getpeername(s,(sockaddr *)&peer,&peer_len);

  cout << "Peer IP address is: " << inet_ntoa(peer.sin_addr) << endl;
  cout << "Peer's port is: " << peer.sin_port << endl;

  // connect(s,(sockaddr *)res->ai_addr,res->ai_addrlen);

  //close(s);

  // const char * msg { "Test message" };
  // int len = strlen(msg);
  //
  // int bytes = send(s,msg,len,0);

  freeaddrinfo(res);

  cout << "End Two\n";
}
