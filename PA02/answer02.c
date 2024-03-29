#include "answer02.h"


size_t my_strlen (const char * str)
{
  int count = 0;
  while (str [count] != '\0')
    {
      count++;
    }
  return count;
}

int my_countchar (const char * str, char ch)
{
  int count = 0;
  int index = 0;
  while (str [index] != '\0')
    {
      if (str[index] == ch)
	{ 
	  count++;
	}
      index ++;
    }
  return count;
}

char * my_strchr (const char * str, int ch)
{
  // if ch is 
  char * point = NULL;
  int index = 0;
  while (str[index] != '\0')
    {
      if (str[index] == ch)
	{ 
	  point = (char *)&str[index];
	  return point;
	}
      index ++;
    }
  if (ch == '\0')
    {
     point = (char *)&str[index];
     return point;
    } 
  return point;
}

char * my_strrchr (const char * str, int ch)
{
  // if ch is 
  char * point = NULL;
  int index = 0;
  while (str[index] != '\0')
    {
      if (str[index] == ch)
	{ 
	  point = (char *)&str[index];
	}
      index ++;
    }
  if (ch == '\0')
    {
     point = (char *)&str[index];
     return point;
    } 
  return point;
}
/*
char * my_strstr(const char * haystack, const char * needle)
{
  char * point = NULL;
  int index = 0;
  int secondi = 0;
  int tempindex = 0;

*/




char * my_strstr(const char * haystack, const char * needle)
{
  char * point = NULL;
  int index = 0;
  int secondi = 0;
  int tempindex = 0;
  if (*needle == '\0')
    {
      point = (char *)&haystack[index];
      return point;
    }
  while (haystack[index] != '\0')
    {
      if (haystack[index] == needle[secondi])
        {
	  tempindex = index;
	  while (needle[secondi] != '\0' && needle[secondi] == haystack[tempindex])
	    {
	      secondi++;
	      tempindex++;
	    }   
	  if (needle[secondi] == '\0')
	    {
	      point = (char *)&haystack[index];
	      return point;
	    }
	  secondi = 0;
        }
      index ++;
    }
      return point;

}
char * my_strcpy(char * dest, const char * src)
{
  int index = 0;
  while (src[index] != '\0')
    {
      dest[index] = src[index];
      index ++;
    }
  dest[index] = '\0';
  return dest;
}

char * my_strcat(char * dest, const char * src)
{
  int secin = 0;
  int index = 0;
  while (dest[index] != '\0')
    {
      index++;//go to the finish of the string
    }
  while(src[secin] != '\0')
    {
      dest[index] = src[secin];//copy the next string
      index++;
      secin++;
    }
  dest[index] = '\0';
  return dest;
}

int my_isspace (int ch)
{
  if (ch < 14 && ch > 8)
    {
      return 1;
    }
  else if ( ch == 32)
    {
      return 1;
    }
  else 
    {
      return 0;
    }
}


int my_atoi (const char * str)
{
  int multiplier = 1;
  int index = 0;
  int ret = 0;
  while (my_isspace(str[index]) == 1)
    {
      index++;
    }
  if (str[index] == '-')
    {
      multiplier = -1;
      index++;
    }
  while (str[index] >= '0' && str[index] <= '9')
    {
      ret *= 10;
      ret += str[index];
      ret -= 48;
      index++;
    }
  ret = ret * multiplier;
  return ret;
}
