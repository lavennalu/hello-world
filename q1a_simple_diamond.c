#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Part A) Simple Diamond */
int main(int argc, char *argv[]) { 
  if (argc != 2){ // test if the program has one argument after the name
    printf("ERROR: Wrong number of arguments. One required.\n");
    return 1;
  }

	if (argc == 2) { // test if the program has one argument after the name
   	  if (isdigit(argv[1][0])){ // test if the argument is an integer
   	  	int h = atoi(argv[1]); // parsing an integer
        //printf("%d\n", h);
   	  	//test if the integer is positive or odd
   	  	if ((h > 0 ) && (h % 2 != 0)){
          int i,j;
   	  		for(i=1; i<=h; i++) { 
            for(j=1; j<=h-i; j++) { 
              printf(" "); 
            } 
            for(j=h-i+1; j<h+i; j++) { 
              printf("*"); 
            } 
            printf("\n"); 
          } 
     
          for(i=h-1; i>=1; i--) { 
            for(j=1; j<=(h-i); j++) { 
              printf(" "); 
            } 
            for(j=h-i+1; j<h+i; j++) { 
              printf("*"); 
            } 
            printf("\n"); 
          } 
          return 0;
        }else{
          printf("ERROR: Bad argument. Height must be positive odd integer. * NOT POSITIVE OR ODD");
        }	
   	  }else{ //print error msg
   	  	printf("ERROR: Bad argument. Height must be positive odd integer. * NOT A DIGIT");
   	  		return 1;
   	  }
  }
}

