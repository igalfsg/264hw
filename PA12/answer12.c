#include "answer12.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

uint128 alphaTou128(const char * str)
{
  uint128 indx = 0;
  uint128 ret = 0;
  while (str[indx] == ' ')
    {
      indx++;
    }

  while ((str[indx] >= '0' && str[indx] <= '9'))
    {
      ret *= 10;
      ret += str[indx] - '0';	
      indx++;
    }
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
  int size = 0;
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
  size = size - 1;
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

typedef struct paramblock {
  uint128 start;
  uint128 stup;
  uint128 number;
  int * prime;

}block;

void *  isprime (void * num_arg)
 {
   block *  numptr = (block *) num_arg;
   block num = * numptr;
   uint128 ind;
   for(ind =  num.start; ind <= num.stup; ind++)
     {
       if (num.number % ind == 0)
	 {
	   * num.prime  = 0;
	 }
     }
   return NULL;
 }

int primalityTestParallel(uint128 value, int n_threads)
{
  int ind;
  int rtv;
  int prime = 1;
  if(value <= 1)
    {
      return 0;
    }
  if(value == 2)
    {
      return 1;
    }
  uint128 top = sqrt(value) + 1;
  block b [n_threads];
  uint128 num = 2;
  uint128 topr;
  uint128 range = top / n_threads;
  for (ind = 0; ind< n_threads; ind++)
    {
      topr = num + range;
      b[ind].start = num;
      b[ind].stup = topr;
      b[ind].number = value;
      b[ind].prime = &prime;
    }
  pthread_t tid[n_threads];
  for (ind = 0; ind < n_threads; ind ++)
    {
      rtv = pthread_create( &tid[ind],NULL ,isprime , (void *)&b[ind]  );
    }
  for(ind = 0; ind < n_threads; ind++)
    {
      rtv = pthread_join (tid[ind],NULL);
    }
  return prime;
}

/* int main(int argc, char * * argv) */
/* { */
/*     const char * str = "340282366920938463463374607431768211455"; */
/*     uint128 w = alphaTou128(str); */
/*     char * w_str = u128ToString(w); */
/*     printf("Biiigggg number: %s\n", w_str); */
/*     if(strcmp(str, w_str) != 0) */
/*        printf("ERROR!, expected %s\n", str); */
/*     free(w_str); */
/*     return EXIT_SUCCESS; */
/* } */


