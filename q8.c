#include <stdio.h>
#include <stdlib.h>

int main(){

int* board[8];

for( int row=0; row<8; row++ )
board[row] = malloc(8*sizeof(int));
// Play some chess!

for( int row=0; row<8; row++ )
free( chess_board );
}