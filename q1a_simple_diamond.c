#include <studio.h>

/* Part A) Simple Diamond */
void main(int argc, char *argv[]) { 

	if (argc == 1) { // test if the program has one argument after the name
   	  //to begin with, test if the argument is an integer
   	  if (isNumber(argv[1]) == true){
   	  	int h = atoi(argv[1]); // cast to an integer
   	  	//test if the integer is positive or odd
   	  	if (h > 0 && h % 2 != 0){
   	  		print(h); //do print method
   	  		return 0;
   	  	}else{ //print error msg
   	  		printf("ERROR: Bad argument. Height must be positive odd integer.");
   	  		return -1;
   	  	}
   	  }
   }else{ //print an error msg if the input does not match
      printf("ERROR: Wrong number of arguments. One required.\n");
      return -1;
   }    
} 

bool isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

void print(int n) { 
    int i,j; 
    for(i=1; i<=n; i++) 
    { 
        for(j=1; j<=n-i; j++) 
        { 
            printf(" "); 
        } 
        for(j=n-i+1; j<n+i; j++) 
        { 
            printf("*"); 
        } 
        printf("\n"); 
    } 
     
    for(i=n-1; i>=1; i--) 
    { 
        for(j=1; j<=(n-i); j++) 
        { 
            printf(" "); 
        } 
        for(j=n-i+1; j<n+i; j++) 
        { 
            printf("*"); 
        } 
        printf("\n"); 
    } 
} 
