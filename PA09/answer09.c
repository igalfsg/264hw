#include "answer09.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * t;
  t = malloc (sizeof(BusinessNode));
  t -> name = name;
  t -> stars = stars;
  t -> address = address;
  t -> right = NULL;
  t -> left = NULL;
  return t;
}

BusinessNode * tree_insert (BusinessNode * node, BusinessNode * root)
{
  if (root == NULL)
    return node;
  if (node == NULL)
    return root;
  if (strcmp(node->name ,root->name) <= 0)//go left
    {
      root->left = (tree_insert(node, root->left));
      return root;
    }
  else//go right
    {
      root->right = (tree_insert( node, root->right));
      return root;
    }

}



char * * explode(const char * str, const char * delims, int * len)
{
  int ind = 0; 
  int numdelim = 0;
  int letters = 0;
  const char * first; 
  int tempind = 0;
  while (str[ind] != '\0')
    {//count delimeters
      if ((strchr(delims,str[ind])) != NULL)
	{
	numdelim++; //add another delimeter to the count
	}
      ind++;
    }//end counting of delimeters
  char ** dest = malloc((numdelim + 1) * sizeof(char*));
  first = str;
  *len = numdelim + 1;
  for(ind = 0; ind <= numdelim; ind ++){
     
    while ((strchr(delims,str[tempind])) == NULL)
	{
	  letters++;
	  tempind++;
	}
    dest[ind] = malloc((letters + 1) * sizeof(char));
    memcpy(dest[ind],first,(sizeof(char)*letters));
    dest[ind][letters] = '\0';
    tempind++;
    first +=  (sizeof(char)*(1 + letters));
    letters = 0;
  }
return dest;
}



BusinessNode * load_tree_from_file (char * filename)
{
  BusinessNode * root = NULL;
  char * name;
  char * stars;
  int leng;
  char * address;
  char * buffer;
  char ** secondbuffer;
  FILE * x = fopen(filename, "r");
  if (x == NULL)
    return NULL;
  buffer = malloc( 2000 * sizeof(char));
  while (fgets(buffer, 2000, x) != NULL);
  {
    secondbuffer = explode (buffer, "\t", &leng);
    stars = strdup(secondbuffer[0]);
    name = strdup(secondbuffer[1]);
    address =strdup(secondbuffer[2]);
    free(secondbuffer[0]);
    free(secondbuffer[1]);
    free(secondbuffer[2]);
    free(secondbuffer);
    BusinessNode * node = create_node(stars, name, address);
    root = tree_insert(node, root); 
  }
  free(buffer);
  return root;

}

void print_node(BusinessNode * node)
{
  printf("%s\n", node->name);
  printf("stars:\n");
  printf("%s\n",node->stars);
  printf("address:\n");
  printf("%s\n",node->address);
  return;
}
BusinessNode * tree_search_name(char * name, BusinessNode * root)
{

  if (root == NULL)
    return NULL;
  if (strcmp(name ,root->name) == 0)
    return root;
  if (strcmp(name ,root->name) < 0)//go left
    {
      root = (tree_search_name(name, root->left ));
      return root;
    }
  else//go right
    {
      root = (tree_search_name(name, root->right));
      return root;
    }
}
void destroy_tree(BusinessNode * root)
{
  if (root == NULL){
    return;
  }
  destroy_tree(root->left);
  destroy_tree(root->right);
  free(root->name);
  free(root->stars);
  free(root->address);
  free(root);
  return;
}

