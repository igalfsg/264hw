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

char * my_strcpy(char * dest, const char * src)
{
  int index = 0;
  while (str[index] != '\0')
    {
      dest[index] = str[index];
      index ++;
    }
  dest[index] = '\0';
  return dest;
}

