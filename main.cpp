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




int main(){
  std::cout << "Network\n";
}
