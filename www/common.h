#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cgic.h>
#include <net.h>

#define max_method_len 32
#define max_opt_len 8
#define json_error(fmt,args...) \
	fprintf(cgiOut,"{\"error\":\""fmt"\"}",##args)

struct requestProto{
	char method[max_method_len];
	void (*get)(void* data,int len);
	void (*set)(void* data,int len);
	int condition;
};

#endif
