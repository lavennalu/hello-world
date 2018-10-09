#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
	FILE* fp;
	fp=fopen("argv[1]","r");
	if(fp==NULL)
	{
		printf("file not found");
		return 0;
	}
	char p[1000];
	//Added to get the starting locations of <a,</a > href=" and title="
	char start[10]="<a";
	char end[10]="</a >";
	char s[10]="href=\"";
	char a[10]="title=\"";
	char *p1;
	//printf("\n%s",strstr(p1,s)+6);
	while((p1=fgets(p,1000,fp))){
		char *sloc=strstr(p,s);
		char *aloc=strstr(p,a);
		char *startloc=strstr(p,start);
		char *endloc=strstr(p,end);
	//If the string does not contain <a or </a >
		if(!startloc || !endloc){
			continue;
		}
		int pos0=startloc-p1;
		int pos3=endloc-p1;
		int pos1=sloc-p1;
		int pos2=aloc-p1;
		p[strlen(p)-1]='\0';
		// title tag should come after href tag and </a > should come after <a and difference between <a and href tag =3
		if((strstr(p,s)) && (strstr(p,a))&& (pos2>pos1) && (pos3>pos0) &&(pos1-pos0)==3 ){
			char *ptr=strstr(p,"title=");
			ptr+=7;
			while(*ptr!='\"'){
				printf("%c",*ptr);
				ptr++;
			}
		}
		printf("\n");
	}
}