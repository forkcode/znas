#ifndef _NET_H_
#define _NET_H_

#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h> 
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void* netget(void* date,int lens);
void* netset(void* date,int lens);

#endif
