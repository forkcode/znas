#include <common.h>

typedef struct {
	char *iface;
	char addr[16];
	char dstaddr[16];
	char broadaddr[16];
	char netmask[16];
	char hwaddr[32];
	int  mtu;
	int  metric;
}ifinfo;

int ifcfg_info(){
	struct ifconf ifc;
	int sock = socket(AF_INET,SOCK_DGRAM,0);

	if((ioctl(sock, SIOCGIFCONF, &ifc)) == -1){
		json_error("%s %d %s",__FILE__,__LINE__,__FUNCTION__);
		goto error;
	}

	struct ifreq * lpifr = ifc.ifc_req;
	struct sockaddr_in * lpaddr = NULL;
	char * lpstr = NULL;

	json_error("ifclen:%d",ifc.ifc_len);

	if(!ifc.ifc_len){
		goto error;
	}

	while(lpifr){
		lpaddr = (struct sockaddr_in*)(&lpifr->ifr_addr);
		lpstr = inet_ntoa(lpaddr->sin_addr);
		fprintf(cgiOut,"src ip:%s",lpstr);

		lpaddr = (struct sockaddr_in*)(&lpifr->ifr_dstaddr);
		lpstr = inet_ntoa(lpaddr->sin_addr);
		fprintf(cgiOut,"dst ip:%s",lpstr);

		lpaddr = (struct sockaddr_in*)(&lpifr->ifr_broadaddr);
                lpstr = inet_ntoa(lpaddr->sin_addr);
		fprintf(cgiOut,"brd ip:%s",lpstr);

		lpaddr = (struct sockaddr_in*)(&lpifr->ifr_netmask);
                lpstr = inet_ntoa(lpaddr->sin_addr);
		fprintf(cgiOut,"msk ip:%s",lpstr);

		lpifr += sizeof(struct ifreq);
	}


error:
	close(sock);
	return 0;
}

void* netget(void* data,int unused){
	if(ifcfg_info() != 0){
		json_error("%s %d %s",__FILE__,__LINE__,__FUNCTION__);
	}else{
		json_error("success");
	}
}

void* netset(void* data,int unused){
	
}
