#include "answer12.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>




uint128 alphaTou128  (const char * str)
{
  uint128 multiplier = 1;
  uint128 indx = 0;
  uint128 ret = 0;
  while (str[indx] == ' ')
    {
      indx++;
    }

  while ((str[indx] >= '0' && str[indx] <= '9') || str[indx] == ' ')
    {
      if(str[indx] != ' ')
	{
	  ret *= 10;
	  ret += str[indx];
	  ret -= 48;
	}
      indx++;
    }
  if (ret == 0 && str[indx] != '\0')
    return 0;
  ret = ret * multiplier;
  return ret;
}

/**
 * Return a newly allocated C-string which represents the passed value.
 * The caller is responsible for freeing the allocated string.
 *
 * If you have already implemented alphaTou128(...) (see hint), then you should
 * be able to figure out how to implement u128ToString(...).
 */
char * u128ToString(uint128 value)
{
  uint128 size = 0;
  if(value == 0)
    size = 1;
  uint128 val2 = value;
  while(value != 0)
    {
      size++;
      value = value / 10;
    }
  char * numb = malloc(sizeof(char) * (size + 1));
  numb[size] = '\0';
  size = size -1;
  for (; size >= 0; size--)
  {
    numb[size] = val2 % 10 + '0';
    val2 = val2 / 10;
  }
  
  return numb;
}

/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY.
 *
 * Good luck!
 */
void *  isprime (uint128 num)
 {
   uint128 ind;
   uint128 count = 0;
   for(ind =  2; ind < num; ind++)
     {
       if (num % ind == 0)
	 {
	   count++;
	 }
     }
   return count;
 }

typedef struct paramblock {
  uint128 start;
  uint128 stup;
  uint128 number;
  int prime;

}block;
int primalityTestParallel(uint128 value, int n_threads)
{
  int ind;
  int rtv;
  int prime = 0;
  for (ind = 0; ind< n_threads; ind++)
    {
      block b;
    }
  pthread_t tid[n_threads];
  for (ind = 0; ind < n_threads; ind ++)
    {
      //rtv = pthread_create( &tid[ind],NULL , , (void *)  );
      
    }
  return 1;
}

int main(int argc, char * * argv)
{
    const char * str = "340282366920938463463374607431768211455";
    uint128 w = 0//alphaTou128(str);
    char * w_str = u128ToString(w);
    printf("Biiigggg number: %s\n", w_str);
    if(strcmp(str, w_str) != 0)
       printf("ERROR!, expected %s\n", str);
    free(w_str);
    return EXIT_SUCCESS;
}


