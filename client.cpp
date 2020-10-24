#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Start client program with command line argument "127.0.0.1"

void * get_in_addr(sockaddr * sa);

int main(int argc,char * argv []){

  const char * PORT = "3490"; const int MAX_DATA_SIZE = 100;
  int sockfd; int numbytes; char buf[MAX_DATA_SIZE];
  addrinfo hints; addrinfo * servinfo; addrinfo * p;
  int rv; char s[INET6_ADDRSTRLEN];

  if(argc != 2){
    fprintf(stderr, "usage: client hostname\n");
    exit(1);
  }

  memset(&hints,0,sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if((rv = getaddrinfo(argv[1],PORT,&hints,&servinfo)) != 0){
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  for(p = servinfo; p != NULL; p = p->ai_next){

    if((sockfd = socket(p->ai_family,p->ai_socktype,p->ai_protocol)) == -1){
      perror("client: socket");
      continue;
    }

    if(connect(sockfd,p->ai_addr,p->ai_addrlen) == -1){
      close(sockfd);
      perror("client: connect");
      continue;
    }

    break;
  }

  if(p == NULL){
    fprintf(stderr, "client: failed to connect\n");
    return 2;
  }

  // Convert binary to text
  inet_ntop(p->ai_family,get_in_addr((sockaddr *)p->ai_addr),s,sizeof s);

  printf("client: connecting to %s\n",s);
  freeaddrinfo(servinfo);

  if((numbytes = recv(sockfd,buf,MAX_DATA_SIZE-1,0)) == -1){
    perror("recv");
    exit(1);
  }

  buf[numbytes] = '\0';
  printf("client: received '%s'\n",buf);

  close(sockfd);
}

void * get_in_addr(sockaddr * sa){

  if(sa->sa_family == AF_INET){
    return &(((sockaddr_in *)sa)->sin_addr);
  }else{
    return &(((sockaddr_in6 *)sa)->sin6_addr);
  }

}
