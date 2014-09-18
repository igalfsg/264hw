#include "answer03.h"
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  int destlen;
  if (*dest == NULL || (((strlen(*dest)) + (strlen(src)) + 1 ) > *n))
    {
      if(*dest != NULL)
	destlen = strlen(*dest);
      else
	destlen = 0;
      *n = 1 + 2 * (destlen + (strlen(src)));
      char * buffer = malloc (*n * sizeof (char));
      *buffer = '\0';
      if (*dest != NULL)
	{
	  strcpy(buffer, *dest);
	}      
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
  const char * first; 
  int tempind = 0;
  while (str[ind] != '\0')
    {//count delimeters
      if ((strchr(delims,str[ind])) != NULL)
	{
	numdelim++; //add another delimeter to the count
	}
      ind++;
    }//end counting of delimeters
  char ** dest = malloc((numdelim + 1) * sizeof(char*));
  first = str;
  for(ind = 0; ind <= numdelim; ind ++){
     
    while ((strchr(delims,str[tempind])) == NULL)
	{
	  letters++;
	  tempind++;
	}
    dest[ind] = malloc((letters + 1) * sizeof(char));
    memcpy(dest[ind],first,(sizeof(char)*letters));
    dest[ind][letters] = '\0';
    tempind++;
    first += 1 + (sizeof(char)*letters);
    letters = 0;
  }
return dest;
}

char * implode (char ** strArr, int len, const char * glue)
{
  //char * together = "a";
  int sizze = len;//equal it to len cause there is at least len * char
  char * together = NULL; //malloc(sizze * sizeof(char));
  //together = '\0';
  int ind;
  int * prueba = &sizze;
  for (ind = 0; ind < len; ind++)
    {
      together = strcat_ex(&together, prueba, strArr[ind]);
      if ((ind + 1) != len)
	{
	  together = strcat_ex(&together, prueba, glue);
	}
    }
  return together;
}

int stringcmp (const void *first, const void *second)
{
  const char **fir = (const char **)first;
  const char **las = (const char **)second;
  return strcmp(*fir, *las);
}//inspired from internet browsing

void sortStringArray(char ** arrString, int len)
{
  qsort(arrString, len, sizeof(char *), stringcmp);
}
int charcomp (const void * first, const void * second ) {
  return strcmp((char*)first, (char*)second);
}
void sortStringCharacters(char * str)
{
  int ind = 0;
  while (str[ind] != '\0')
    {
      ind++;
    }
  qsort(str, ind, sizeof(char),charcomp);
}
void destroyStringArray (char ** strArr, int len)
{
  if (strArr != NULL && len != 0)
    {
      int ind;
      for(ind = 0; ind < len; ind ++){
	free(strArr[ind]);
      }
      free(strArr);
    }
}
