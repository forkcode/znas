#include <stdio.h>
#include <cgic.h>

int cgiMain(void){
	cgiHeaderContentType("text/html");

	fprintf(cgiOut,"<html>Hello World</html>");

	return 0;
}
