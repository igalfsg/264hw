#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
   // We want some variables to store which "switches" were set
   int showHelp = FALSE;
   int ch;
   FILE * fptr;
   int estanda = FALSE;
   int index2 = 1;
   int ind = 1; // we always skip 0, which is the program path
   for( ; ind < argc; ++ind) {
      if(strcmp(argv[ind], "--help") == 0) 
         showHelp = TRUE;
      if (argc < 2)
	estanda = TRUE;
      if (strcmp(argv[ind], "-") == 0)
	estanda = TRUE;
   }
   if (showHelp){
     printf("Usage: cat-lite [--help] [FILE]...\n");
     printf("With no FILE, or when FILE is -, read standard input.\n\nExamples:\n  cat-lite README   Print the file README to standard output.\n  cat-lite f - g    Print f's contents, then standard input, \n                    then g's contents.\n  cat-lite          Copy standard input to standard output.\n");
     return EXIT_SUCCESS;
   }
   for( ; index2 < argc; ++index2) {
     if (strcmp(argv[index2], "-") == 0)
       {
	 fptr = stdin;
       }
     else
       fptr = fopen(argv[index2], "r");
     if(fptr == NULL){
       printf("cat cannot open %s\n", argv[index2]);
       return EXIT_FAILURE;
     }
     do
       {
	 ch = fgetc(fptr);
	 if(ch != EOF)
	   fprintf(stdout, "%c",ch);
       }while(ch != EOF);
     fclose(fptr);
   }
if (argc == 1)
       {
	 fptr = stdin;
	 do
       {
	 ch = fgetc(fptr);
	 if(ch != EOF)
	   fprintf(stdout, "%c",ch);
       }while(ch != EOF);
       }
   return EXIT_SUCCESS;
}
