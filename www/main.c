#include <common.h>

#define max_reqlist_len 7

static 
struct requestProto reqlist[max_reqlist_len] = {
{"help",NULL,NULL,1},
{"disk",NULL,NULL,1},
{"user",NULL,NULL,1},
{"network",netget,netset,1},
{"system",NULL,NULL,1},
{"database",NULL,NULL,1},
{"service",NULL,NULL,1}
};

void (*callback)(void* data,int len);

int cgiMain(void){
	cgiHeaderContentType("text/html");

	int i = 0;
	char method[32] = {0};
	char opt[32] = {0};

	cgiFormStringNoNewlines("method",method,max_method_len);
	cgiFormStringNoNewlines("opt",opt,max_opt_len);

	for(i;i<max_reqlist_len;i++){
		if(!strncmp(method,reqlist[i].method,max_method_len)){
			if(!strncmp(opt,"get",max_opt_len)){
				callback = reqlist[i].get;
			}
			if(!strncmp(opt,"set",max_opt_len)){
				callback = reqlist[i].set;
			}
			if(callback == NULL){
				json_error("call back is null");
			}else{
				callback(NULL,1);
			}
			return 0;
		}
	}

	json_error("unknow method");

	return 0;
}
