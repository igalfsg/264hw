#include "answer03.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  if (*dest == '\0' || (((strlen(*dest)) + (strlen(src)) + 1 ) > *n))
    {
      *n = 1 + 2 * ((strlen(*dest)) + (strlen(src)));
      char * buffer = malloc (*n * sizeof (char));
      strcpy(buffer, *dest);
      free (*dest);
      *dest = buffer;
      strcat (*dest, src);
      return *dest;
      
    }
  else 
    {
     strcat (*dest, src);
      return *dest;
    }
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  int ind = 0; 
  int numdelim = 0;
  int letters = 0;
  char * first; 
  int destindex = 0;
  while (str[ind] != '\0')
    {//count delimeters
      if ((strchr(delims,str[ind])) != NULL)
	{
	numdelim++; //add another delimeter to the count
	}
      ind++;
    }//end counting of delimeters
  ind = 0;
  char ** dest = malloc((numdelim + 1) * sizeof(char*));
  while (str[ind] != '\0')
    {
      letters = 0;
      first = (char *)str; 
      first += ind;
      while ((strchr(delims,str[ind])) == NULL)
	{
	  letters++;
	  ind++;
	}
      memcpy(dest[destindex],first, letters);
    }
return dest;
}

