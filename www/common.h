#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cgic.h>

#define max_method_len 32

struct requestProto{
	char method[max_method_len];
	void (*callback)(void* data,int len);
	int condition;
};

#endif
