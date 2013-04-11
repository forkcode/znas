#include <common.h>

char * fileout(char * filepath){
	static char buffer[4096] = {0};

	FILE* fp = fopen(filepath,"rb");
	if(!fp) return NULL;

	int bytes =  fread(buffer,4096,1,fp);

	fclose(fp);

	return buffer;
}
