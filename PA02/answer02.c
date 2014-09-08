#include "answer02.h"


size_t my_strlen (const char * str)
{
  int count = 0;
  while (str [count] != "0/")
    {
      count++;
    }
  return count;
}

