#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char * buff=NULL;
int size,cnt;
void word_cnt(char * s)
{
	cnt=0;
	char * p=NULL;
	for((p=strtok(s," "));p!=NULL;(p=strtok(NULL," ")))
	{
		cnt++;
	}
	printf("The No of Words:%d\n",cnt);
}
void fileread(char * filename)
{
	FILE * fp=NULL;
	fp=fopen(filename,"r");
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);
	buff=calloc(1,size+1);
	fread(buff,size,1,fp);
	word_cnt(buff);
	fclose(fp);
}
int main(int argc,char * argv[])
{
	if(argc!=2)
	{
		printf("Invalid_Input\n");
		return 0;
	}
	fileread(argv[1]);
	return 0;
}
