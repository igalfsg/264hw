
#include "answer07.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>



#define FALSE 0
#define TRUE 1
#define ECE264_NUMBER 0x21343632


Image * Image_load(const char * filename)
{
  FILE * fp = NULL;
  size_t read;
  Image * tmp_im = NULL, * im = NULL;
  size_t n_bytes = 0;
  int err = FALSE;
  ImageHeader header;

  if(!err) { // Open filename
    fp = fopen(filename, "rb");
    if(!fp) {
      fprintf(stderr, "Failed to open file '%s'\n", filename);
      err = TRUE;
    }
  }

    if(!err) { // Read the header
	read = fread(&header, sizeof(ImageHeader), 1, fp);
	if(read != 1) {
	    fprintf(stderr, "Failed to read header from '%s'\n", filename);
	    err = TRUE;
	}
    }
    if(!err) { // We're only interested in a subset of valid bmp files
      if (header.magic_number != ECE264_NUMBER) {
	    fprintf(stderr, "Invalid header in '%s', invalid magic number\n", filename);
	    err = TRUE;
      }

    // Make sure we are getting 24 bits per pixel
    if (header.width == 0 ){
	    fprintf(stderr, "Invalid header in '%s', width = 0\n", filename);
	    err = TRUE;

    }

   if (header.height == 0 ){
	    fprintf(stderr, "Invalid header in '%s', height = 0\n", filename);
	    err = TRUE;

    }

    // Make sure there is no compression
   if (header.comment_len == 0 )
      {
	    fprintf(stderr, "Invalid header in '%s', comment-len = 0\n", filename);
	    err = TRUE;
      }
	
    }

   if(!err) { // Allocate Image struct
	tmp_im = malloc(sizeof(Image));			
	if(tmp_im == NULL) {
	    fprintf(stderr, "Failed to allocate im structure\n");
	    err = TRUE;
	} 
    }


   if(!err) { // Init the Image struct
   tmp_im->width = header.width;
   tmp_im->height = header.height;
   tmp_im->comment = NULL;
   tmp_im->data = NULL;
   tmp_im->comment = malloc(sizeof(char)*header.comment_len);
   if(tmp_im->comment == NULL){
     fprintf(stderr, "Failed to allocate im structure\n");
     err = TRUE;
   }
   tmp_im->data = malloc(sizeof(uint8_t)*header.width * header.height);
   if(tmp_im->data  == NULL)
     {
       fprintf(stderr, "Failed to allocate im structure\n");
       err = TRUE;
     }
   }
   if(!err) { 
     n_bytes = fread(tmp_im->comment,sizeof(char),header.comment_len,fp);
     if(n_bytes != header.comment_len){
       fprintf(stderr, "failed to read entire comment\n");
       err = TRUE;
     }
     else if(tmp_im->comment[header.comment_len-1] != '\0'){
       fprintf(stderr, "failed to read entire comment\n");
       err = TRUE;
     }
   
   }

   if(!err) { 
     n_bytes = fread(tmp_im->data,sizeof(uint8_t),header.width * header.height,fp);
     if(n_bytes != header.width * header.height){
       fprintf(stderr, "failed to read entire picutre\n");
       err = TRUE;
     }
     uint8_t byte;
     read = fread(&byte,sizeof(uint8_t),1,fp);
     if(read != 0){
       fprintf(stderr, "didnt reach end of file\n");
       err = TRUE;
     }
   }

    if(!err) { // We're winners... 
	im = tmp_im;  // bmp will be returned
	tmp_im = NULL; // and not cleaned up
    }

    if(tmp_im != NULL) {
	free(tmp_im->comment); // Remember, you can always free(NULL)
	free(tmp_im->data);
	free(tmp_im);
    }
    if(fp) {
	fclose(fp);
    }

    return im;
}

int Image_save(const char * filename, Image * image)
{
    int err = FALSE; 
    FILE * fp = NULL;    
    size_t written = 0;
    

    fp = fopen(filename, "wb");
    if(fp == NULL) {
	fprintf(stderr, "Failed to open '%s' for writing\n", filename);
	return FALSE; // No file ==> out of here.
    }
  ImageHeader header;
  header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  header.width = image->width;
  header.height = image->height;
  header.comment_len = strlen(image->comment) + 1;

 if(!err) {  // Write the header
   written = fwrite(&header, sizeof(ImageHeader), 1, fp);
   if(written != 1) {
     fprintf(stderr, "error could not write the full heder");
     err = TRUE;	
   }
 }
 if(!err){
   written = fwrite(image->comment, sizeof(char) * header.comment_len, 1, fp);
   if(written != 1) {
     fprintf(stderr, "error could not write the full comment");
     err = TRUE;	
   }
 }

 if(!err){
   written = fwrite(image->data, sizeof(uint8_t) * header.width * header.height, 1, fp);
   if(written != 1) {
     fprintf(stderr, "error could not write the full comment");
     err = TRUE;	
   }
 }

 if(fp)
   fclose(fp);
 return !err;


}

void Image_free(Image * image)
{
  if(image != NULL) {
    free(image->comment); // Remember, you can always free(NULL)
    free(image->data);
    free(image);
  }
}


void linearNormalization(int width, int height, uint8_t * intensity){
  int min = 255;
  int max= 0;
  int len = width * height;
  int i = 0;
  while (i < len)
    {
      if (intensity[i] > max){
	max = intensity[i];
      }
      if(intensity[i] < min)
	min = intensity[i];
      i++;
    }
  i = 0;
  if (min != max){
    while (i < len)
      {
	intensity[i] =( (intensity[i] - min) * 255.0) / (max - min);
	i++;
      }
  }
}
  
