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
  int count = 
