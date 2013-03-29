#include <common.h>

int ifcfg_info(){
	
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
