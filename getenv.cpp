#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	char* ptr = NULL;
	if((ptr = getenv("path")) != NULL)
		printf("%s\n",ptr);
	return 0;
}
