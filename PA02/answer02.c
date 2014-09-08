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

