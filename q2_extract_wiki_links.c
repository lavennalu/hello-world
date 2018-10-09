#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){

	//open the file
	FILE* fp;
	fp = fopen(argv[1], "r");

	//if nothing is entered in the command line, return 1
	if(fp == NULL){
		printf("Cannot open file.\n");
		return 1;
	}

	// set chars

	char p[1000]; //create a temporary char 
	//create to set the starting locations of <a,</a > href=" and title="
	char start[10]="<a";
	char end[10]="</a >";
	char s[10]="href=\"";
	char a[10]="title=\"";
	char *p1; //a temporary pointer to use the fgets function

	//printf("\n%s",strstr(p1,s)+6);
	while((p1=fgets(p,1000,fp))){ 
		char *sloc=strstr(p,s); //pointer to the location where href=\" is
		char *aloc=strstr(p,a); //pointer to the location where title=\" is
		char *startloc=strstr(p,start); //pointer to the location where <a is
		char *endloc=strstr(p,end); //pointer to the location where </a > is
	
		if(!startloc || !endloc){ //test if the string contains <a or </a >
			continue;
		}

		int pos0=startloc-p1;
		int pos3=endloc-p1;
		int pos1=sloc-p1;
		int pos2=aloc-p1;
		p[strlen(p)-1]='\0';

		// title tag should come after href tag and </a > should come after <a and difference between <a and href tag =3
		if((strstr(p,s)) && (strstr(p,a))&& (pos2>pos1) && (pos3>pos0) &&(pos1-pos0)==3 ){
			char *pointer=strstr(p,"title=");
			pointer+=7;
			while(*pointer!='\"'){
				printf("%c",*ptr);
				pointer++;
			}
		}
		printf("\n");
		fclose(argv[1]);
		return 0;
	}
}
