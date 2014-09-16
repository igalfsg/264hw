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
  int index = 0; 
  int numdelim = 0;
  while (str[index] != '\0')
    {//count delimeters
      if ((strchr(delims,str[index])) != NULL)
	{
	numdelim++; //add another delimeter to the count
	}
      index++;
    }//end counting of delimeters

return str;
}

