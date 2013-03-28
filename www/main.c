#include <common.h>

#define max_reqlist_len 6 

requestProto reqlist[max_reqlist_len] = {
{"disk",NULL,1},
{"user",NULL,1},
{"net",NULL,1},
{"sys",NULL,1},
{"database",NULL,1},
{"service",NULL,1}
};

int cgiMain(void){
	cgiHeaderContentType("text/html");

	int i = 0;

	for(i;i<max_reqlist_len;i++){
		if(!strncmp(method,reqlist[i].method)){
			reqlist[i].callback(NULL,0);
			return 0;
		}
	}

	return 0;
}
