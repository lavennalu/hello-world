/* FILE: A3_solutions.c is where you will code your answers for Assignment 3.
 * 
 * Each of the functions below can be considered a start for you. They have 
 * the correct specification and are set up correctly with the header file to
 * be run by the tester programs.  
 *
 * You should leave all of the code as is, especially making sure not to change
 * any return types, function name, or argument lists, as this will break
 * the automated testing. 
 *
 * Your code should only go within the sections surrounded by
 * comments like "REPLACE EVERTHING FROM HERE... TO HERE.
 *
 * The assignment document and the header A3_solutions.h should help
 * to find out how to complete and test the functions. Good luck!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A3_provided_functions.h"

unsigned char*
bmp_open( char* bmp_filename,        unsigned int *width, 
          unsigned int *height,      unsigned int *bits_per_pixel, 
          unsigned int *padding,     unsigned int *data_size, 
          unsigned int *data_offset                                  )
{
  unsigned char *img_data=NULL;
  // REPLACE EVERYTHING FROM HERE
 
  //open a binary bmp file
  FILE *bmpfile;
  //open bmp file
  bmpfile = fopen(bmp_filename,"rb");
  if (bmpfile == NULL){
    return NULL;
    printf( "File not found.\n");
  }

  //read info and read filesize by a var of 4 bytes
  fseek(bmpfile, 0, SEEK_END);
  long filesize = ftell(bmpfile);
  //create header and its memory
  //allocate enough memory for the bmp image data
  unsigned char *header = malloc(filesize);
  fread(header, filesize, 1, bmpfile);

  //assign each value to the ptrs
  int *height_pointer = (int *)&header[22];
  *height = *height_pointer;
  unsigned int *width_pointer = (unsigned int*)(header + 18);
  *width = *width_pointer;
  unsigned int *data_offset_potiner = (unsigned int*)(header + 10);
  *data_offset = *data_offset_potiner;
  unsigned int *bits_per_pixel_pointer = （unsigned int*)(header + 28);
  *bits_per_pixel = *bits_per_pixel_pointer;
   //write datasize
  *data_size = filesize;

  //calculate padding
  int result1 = (*width) * (*bits_per_pixel / 8);
  int result2 = result1 % 4;
  int result3 = (4 - result2) % 4;

  *padding = result3;
  unsigned char* voidPtr = (unsigned char *)malloc(*data_size);
  rewind(bmpfile);
  fread(voidPtr, *data_size, 1, bmpfile);
  *img_data = *voidPtr;

  // TO HERE!  
  return img_data;  
}

void 
bmp_close( unsigned char **img_data )
{
  // REPLACE EVERYTHING FROM HERE
  if( *img_data != NULL ){
    free(*img_data);
    *img_data = NULL;
  }
  // TO HERE!  
}

unsigned char***  
bmp_scale( unsigned char*** pixel_array, unsigned char* header_data, unsigned int header_size,
           unsigned int* width, unsigned int* height, unsigned int num_colors,
           float scale )
{
  unsigned char*** new_pixel_array = NULL; 
  // REPLACE EVERYTHING FROM HERE
  
  
  // TO HERE! 
  return new_pixel_array;
}         

int 
bmp_collage( char* background_image_filename,     char* foreground_image_filename, 
             char* output_collage_image_filename, int row_offset,                  
             int col_offset,                      float scale )
{

  printf( "UNIMPLEMENTED FUNCTION: bmp_collage has not yet been coded. Please complete before submitting!\n");
  // TO HERE! 
  return 0;
}              

