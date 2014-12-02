#include "answer11.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Create a new, properly intialized HuffNode
 */
HuffNode * HuffNode_create(int value)
{
  HuffNode * n;
  n = malloc(sizeof(HuffNode));
  n->value = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/**
 * Destroy a tree, including all sub-children. Must handle NULL values safely.
 */
void HuffNode_destroy(HuffNode * tree)
{
  if(tree == NULL)
    {
      return;
    }
  HuffNode_destroy(tree->left);
  HuffNode_destroy(tree->right);
  free(tree);
  return;
}

// ----------------------------------------------------------------------- Stack

/**
 * We need a "Stack" to build the tree structure that is used to decode
 * a Huffman encoding. Stacks are very simple to implement with linked lists.
 * We must implement the following functions (given below). Each of these 
 * functions should only be a few lines of code.
 *
 * (1) Stack_create();              // Allocate a brand new stack.
 * (2) Stack_destroy(stack);        // Clean up memory for the stack.
 * (3) Stack_isEmpty(stack);    // TRUE iff (if and only if) the stack is empty.
 * (4) Stack_pushFront(stack, tree); // Push a tree onto the stack.
 * (6) Stack_popFront(stack);  // Remove a tree from the stack and return it.
 *
 * Altogether, these six functions should be around 40 lines of code.
 */

/**
 * Returns a pointer to a new empty stack struct
 */
Stack * Stack_create()
{
  Stack * n;
  n = malloc(sizeof(Stack));
  n->head = NULL;
  return n;
}

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you must free the entire contained linked-list.
 * Also, you must safely do nothing if stack == NULL. 
 */

void List_destroy (StackNode * list){
  if(list != NULL)
    List_destroy(list->next);
  HuffNode_destroy(list->tree);
  free(list);
  return;
}

void Stack_destroy(Stack * stack)
{
  if (stack == NULL)
    {
      return;
    }
  List_destroy(stack->head);
  return;
}

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */
int Stack_isEmpty(Stack * stack)
{
  if (stack == NULL)
    return 1;
  if (stack->head == NULL)
    {
    return 1;
    }
  return 0;
}

/**
 * Pop the front (top) 'value' from the stack.
 *
 * More precisely, this function must do three things:
 * (1) Save the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 * (3) Return the value saved in (1).
 */
HuffNode * Stack_popFront(Stack * stack)
{
  HuffNode * n;
  StackNode * s = stack->head;
  n = s->tree;
  StackNode * p = s->next;
  stack->head = p;
  free (s);
  return n;
}

/**
 * Push a 'value' onto the front (top) of the stack.
 *
 * More precisely, this function must do two things:
 * (1) Create a new StackNode with 'tree' for its tree.
 * (2) Push that new StackNode onto the front of the stack's list.
 */
void Stack_pushFront(Stack * stack, HuffNode * tree)
{
  StackNode * n;
  n = malloc(sizeof(StackNode));
  n->tree = tree;
  n->next = stack->head;
  stack->head = n;
  return;
}

// -------------------------------------------------------- Pop Pop combine Push

/**
 * This function helps simplify building a Huffman Coding Tree from the header
 * information. It takes a stack as input. As a precondition, you can assume 
 * that the stack has at least two nodes. This function pops the front (top) 
 * two nodes, combines them into a single node, and pushes the new node back 
 * onto the stack. See Huffman_Coding.pdf to understand conceptually how this
 * should be done.
 */
void Stack_popPopCombinePush(Stack * stack)
{
  HuffNode * n1 = Stack_popFront(stack);
  HuffNode * n2 = Stack_popFront(stack);
  int num = n1->value + n2->value;
  HuffNode * root = HuffNode_create(num);
  root->left = n1;
  root->right = n2;
  Stack_pushFront(stack, root);
  return;
}

// ---------------------------------------------------- Reading HuffTree headers

/**
 * Read a Huffman Coding Tree (in text format) from 'fp'.
 */
HuffNode * HuffTree_readTextHeader(FILE * fp)
{ 
  int ch = fgetc(fp);
  Stack * s = Stack_create();
  while (ch != '\n')
    {
      if (ch= '1')
	{
	  ch = fgetc(fp);
	  HuffNode * huff = HuffNode_create(ch);
	  Stack_pushFront(s, huff);
	}
      else if (ch == '0')
	{
	  Stack_popPopCombinePush(s);
	}
      ch = fgetc(fp);
    }
  HuffNode * tree = Stack_popFront(s);
  return tree;
}

/**
 * Read a Huffman Coding Tree (in binary format) from 'fp'.
 * You will need to (conceptually) read a file a bit at a time. See the README
 * for hints on how to do this.
 */
HuffNode * HuffTree_readBinaryHeader(FILE * fp){
  HuffNode * node = HuffNode_create('1');
  return node;
}
