#include <common.h>

#define sysfs_net "/sys/class/net/"
#define 

struct interface{
	char ifname[8];
	char duplex[8];
	char ip[32];
	char mask[32];
	char mac[24];
	int  mtu;
	int  speed;  //speed MB

	struct interface * next;
};

struct statistics{
	char ifname[8];
	unsigned long long rx_bytes
        unsigned long long tx_bytes
        unsigned long long rx_packets
        unsigned long long tx_packets
        unsigned long long rx_dropped
        unsigned long long tx_dropped	
};

int interface(){
	char buffer[4096] = {0};

	DIR *lpDir;
	struct dirent *ent;
	int i = 0;

	struct interface lpIFH = NULL;
	struct interface lpIFL = NULL;

	lpDir = opendir(sysfs_net);
	while((ent=readdir(lpDir))!=NULL){
		if(ent->d_type & DT_DIR){
			if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)
				continue;

			struct interface lpIFC = (struct interface)malloc(sizeof(struct interface));
			memset(lpIFC,0,sizeof(struct interface));
			memcpy(lpIFC->ifname,ent->d_name,strlen(ent->d_name));

			if(!lpIFH){
				lpIFH = lpIFL = lpIFC;
			}else{
				lpIFL->next = lpIFC;
				lpIFL = lpIFC;
			}
		}
	}

	closedir(lpDir);

	return 0;
}

void router(){
}

void* netget(void* data,int unused){
}

void* netset(void* data,int unused){
}
