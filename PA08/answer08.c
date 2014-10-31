#include "answer08.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>



List * List_createNode(const char * str)
{
  List * node = malloc(sizeof(List));
  node->str = strdup(str);
  node->next = NULL;
  return node;
}

void Node_destroy(List * node)
{
  if (node != NULL){
    free(node->str);
    free(node);
  }
}


void List_destroy (List * list){
  if(list != NULL)
    List_destroy(list->next);
  Node_destroy (list);
}

int List_length (List * list)
{
  int count = 0;
  while (list != NULL){
    count++;
    list = list->next;
  }
  return count;
}
List * List_merge (List *lhs, List * rhs, int(*compar)(const char *, const char *))
{
  //List * head;
  List * complete;
  //List *  tmp;
  //int first = 0; 

  if (rhs == NULL)
    return lhs;
  else if (lhs == NULL)
    return rhs;


if(compar(rhs->str, lhs->str) < 0)//compare if right is smaller than left
  {
    complete = rhs;
    complete->next = List_merge (lhs, rhs->next, compar);
  }
 else
   {
     complete = lhs;
     complete->next = List_merge (rhs, lhs->next, compar);
   }
 return complete;
  /* while(rhs != NULL && lhs != NULL) */
  /*   { */
  /*     if(compar(rhs->str, lhs->str) < 0)//compare if right is smaller than left */
  /* 	{ */
  /* 	  tmp = rhs->next;  */
  /* 	  rhs->next = NULL; */
  /* 	  if(first == 0) */
  /* 	    { */
  /* 	      complete = rhs;//hpw do I do it so complete doesnt reset each time */
  /* 	       head = complete; */
  /* 	      first = 1; */
  /* 	    } */
  /* 	  complete->next = rhs; */
  /* 	  rhs = tmp; */
  /* 	} */
  /*     else */
  /* 	{ */
  /* 	  tmp = lhs->next;  */
  /* 	  lhs->next = NULL; */
  /* 	  if(first == 0) */
  /* 	    { */
  /* 	      complete = lhs;//hpw do I do it so complete doesnt reset each time */
  /* 	      head = complete; */
  /* 	      first = 1; */
  /* 	    } */
  /* 	  complete->next = lhs; */
  /* 	  lhs = tmp; */
  /* 	  //flip code inside if for lhs */
  /* 	} */
      
  /*   } */

  /* if (rhs == NULL) */
  /*   { */
  /*     complete->next = lhs; */
  /*   } */
  /* else */
  /*   complete->next = rhs; */

  /* //fill rest of linked list with the leftovers from other side */

  /* return head; */
	

}

List * List_sort (List * list, int (*compar)(const char *, const char*))
{
  List * itr = list;
  if (list != NULL){
  List * newH = list->next;
  int i;
  int len = List_length (list);
  if (len <= 1)
    return list;
  //devide the list
  for(i=1; i < (len / 2); ++i)
    {
      itr = itr->next;
      newH = newH->next;
    }
  itr->next = NULL;

  //sort
  newH = List_sort (newH, compar);///IDK how to pass compare
  itr = List_sort (list, compar);///IDK how to pass compare

  //merge
  list = List_merge (newH, itr, compar);//IDK how to pass compare
  }
  return list;

}
  
