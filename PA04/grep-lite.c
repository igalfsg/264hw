#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv)
{
   // We want some variables to store which "switches" were set
   int showHelp = FALSE;
   int inver = FALSE;
   int quiet = FALSE;
   int num = FALSE;
   int line = 1;
   char buffer[2001];
   int badSwitch = FALSE;
   int r = 1;

   // Loop through the arguments, looking for our switches...
   int ind = 1; // we always skip 0, which is the program path
   for( ; ind < argc; ++ind) {
      if(strcmp(argv[ind], "--help") == 0) 
         showHelp = TRUE;
      if(strcmp(argv[ind][0], "-") == 0 && ind == (argc - 1))
          badSwitch = TRUE;
      if(strcmp(argv[ind], "-n") == 0 || strcmp (argv[ind],"--line-number"))
	num = TRUE;
      if(strcmp(argv[ind], "-q") == 0 || strcmp (argv[ind],"--quiet"))
	quiet = TRUE;
      if(strcmp(argv[ind], "-i") == 0 || strcmp (argv[ind],"--invert-match"))
	inver = TRUE;
     
   }
   // If --help is passed, you usually show help and do nothing else
   if(showHelp) {
      printf("Usage: ./icecream OPTIONS...\n"
             "   -i, --serve-icecream  Not as exciting as it sounds\n"
	     "\n");
      return EXIT_SUCCESS;
   }
   // Usually you want to bail if the switches aren't perfect...
   // because this helps developers make more reliable software.
   if(badSwitch) {
      fprintf(stderr, "Aborting...\n");
      return 2;
   }
   while(fgets(buffer,2001,stdin) != NULL){
     if(!inver && strstr(buffer,argc[argv-1]) != NULL)
       {
	 r = 1;
	 if(!quiet){
	   if(num)
	     fprintf(stdout,"%d ",line);
	   fprintf(stdout,"%s",buffer);
	 }
       }
     if(inver && strstr(buffer,argc[argv-1]) == NULL)
       {
	 r = 1;
	 if(!quiet){
	   if(num)
	     fprintf(stdout,"%d ",line);
	   fprintf(stdout,"%s",buffer);
	 }
       }
     line++;
   }
	   


   return r;
}


