#include "answer08.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>



List * List_createNode(const char * str)
{
  List * node;
  node->str = str;
  node->ext = NULL;
  return node;
}

void Node_destroy(List * node)
{
  if (node != NULL){
    free(node->str);
    free(node);
  }
}

}

void List_Destroy (List * list){
  if(list != NULL)
    list_destroy_recursive(list->next);
  Node_destroy (list);
}

int List_length (List * list)
{
  int count = 0;
  if (list != NULL)
    count++;
  list = list->next;
  return count;
}
List * List_merge (List *lhs, List * rhs, int(*compar)(const char *, const char *))
{
  List * complete;
  while(rhs != NULL && lhs != NULL)
    {
      if()//compare if right is bigger than left
	{
	  complete = rhs;//hpw do I do it so complete doesnt reset each time
	  rhs = rhs->next;
	}
      else
	{
	  //flip code inside if for lhs
	}
      
    }
  //fill rest of linked list with the leftovers from other side

  return complete;
	

}

List * List_sort (List * list, int (*compar)(const char *, const char*))
{
  List * itr = list;
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
  newH = List_sort (newH, compare);///IDK how to pass compare
  itr = List_sort (list, compare);///IDK how to pass compare

  //merge
  list = List_merge (newH, itr, compare);//IDK how to pass compare

  return list;

}
  
