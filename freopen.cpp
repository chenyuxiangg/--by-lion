#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
	if(freopen("file.txt","w",stdout) == NULL)
		fprintf(stderr,"freopen error\n");
	printf("this is test statement\n");
	fclose(stdout);
	return 0;
}
