#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"


void ppartition (int * numbers, int length)
{
  int indx;
  printf("= ");
  for (indx = 0; indx < length - 1; indx ++)
    printf("%d + ", numbers[indx]);
  printf("%d\n", numbers[length - 1]);
  return;
}
 int isprime (int num)
 {
   int ind;
   int count = 0;
   for(ind =  2; ind < num; ind++)
     {
       if (num % ind == 0)
	 {
	   count++;
	 }
     }
   return count;
 }
void partition (int * suming, int ind, int left, int fun)
{
  if (fun == 1 || fun == 6)
    {
      int val;
      int in;
      if (left == 0){
	ppartition(suming, ind);
	return;
      }
      for(val = 1; val <= left; val++)
	{
	  if(fun == 6)
	    {
	      if (ind == 0)
		in  = 1;
	      else if(suming[ind - 1] % 2 != val % 2){
		  in = 1;
	      }
	      else
	        in = 0;
	    }
	  if (fun == 1 || (fun == 6 && in == 1))
	    {
	      suming[ind] = val;
	      partition (suming, ind + 1, left - val, fun);
	    }
	}
    }
  else if (fun == 2)
    {
      int val;
      if (left == 0){
	ppartition(suming, ind);
	return;
      }
	  if (ind == 0)
	    val = 0;
	  else
	    val = suming[ind - 1];
	  val++;
      for(; val <= left; val++)
	{
	  suming[ind] = val;
	  partition (suming, ind + 1, left - val, fun);
	}//insipred from the book
    }
     else if (fun == 3)
    {
      int val;
      int top;
      if (left == 0){
	ppartition(suming, ind);
	return;
      }
      if (ind == 0)
	top = left + 1;
      else
	top = suming[ind - 1];
      for(val = 1; val < top; val++)
	{
	  suming[ind] = val;
	  partition (suming, ind + 1, left - val, fun);
	}//insipred from the book
    } 
  else if (fun == 4 || fun == 5)
    {
      int val;
      if (left == 0){
	ppartition(suming, ind);
	return;
      }//insipred from the book
	  if (fun == 4)
	    val = 1;//odd number
	  else
	    val = 2;
      for(; val <= left; val += 2)
	{
	  suming[ind] = val;
	  partition (suming, ind + 1, left - val, fun);
	}//insipred from the book
    }
  else if (fun == 7)
    {
      int val;
      int prime;
      if (left == 0){
	ppartition(suming, ind);
	return;
      }//insipred from the book
      for(val = 2; val <= left; val ++)
	{
	  prime = isprime(val);
	  if (prime == 0)
	    {
	      suming[ind] = val;
	      partition(suming, ind + 1, left -val, fun);
	    }
	}
    }
}



void partitionAll(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 1);
  free (numbers);
  return;
}//insipred from the book

void partitionIncreasing(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 2);
  free (numbers);
  return;
}//insipred from the book

void partitionDecreasing(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 3);
  free (numbers);
  return;
}//insipred from the book

void partitionOdd(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 4);
  free (numbers);
  return;
}//insipred from the book

void partitionEven(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 5);
  free (numbers);
  return;
}//insipred from the book

void partitionOddAndEven(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 6);
  free (numbers);
  return;
}//insipred from the book

void partitionPrime(int value)
{
  int * numbers;
  numbers = malloc(sizeof(int)*value);
  partition (numbers, 0, value, 7);
  free (numbers);
  return;
}


