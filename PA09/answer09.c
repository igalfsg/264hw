#include "answer09.h"

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * t;
  t = malloc (sizeof(BusinessNode));
  t -> name = name;
  t -> stars = stars;
  t -> address = address;
  return t;
}

BusinessNode * tree_instert (BusinessNode * node, BusinessNode * root)
{
  if (root == NULL)
    return (node);
  if (strcmp(node->name ,root->name) <= 0)//go left
    {
      root->left = (tree_instert(root->left, node));
      return root;
    }
  else//go right
    {
      root->right = (tree_instert(root->right, node));
      return root;
    }

}

/* void explode (char * buffer, char * name, char * stars, char * address) */
/* { */
/*   int letters = 0; */
/*   int tempind = 0; */
/*   char * first = buffer; */
/*   while ((strchr('\t',buffer[tempind])) == NULL) */
/*     { */
/*       letters++; */
/*       tempind++; */
/*     } */
/*   name = malloc((letters + 1) * sizeof(char)); */
/*   memcpy(name,first,(sizeof(char)*letters)); */
/*   name[letters] = '\0'; */
/*   first +=  (sizeof(char)*(1 + letters)); */
/*   letters = 0; */

/* } */


char * * explode(const char * str, const char * delims)
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
  char * address;
  char * buffer;
  char ** secondbuffer;
  buffer = malloc( 2000 * sizeof(char));
  FILE * x = fopen(filename, "r");
  while (fgets(buffer, 2000, x) != NULL);
  {
    secondbuffer = explode (buffer, "\t");
    stars = secondbuffer[0];//change this to strdup
    name = secondbuffer[1];
    address = secondbuffer[2];
    BusinessNode * node = create_node(stars, name, address);
    root = tree_instert(node, root); 
  }
  free(buffer);
  return root;

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

void print_node(BusinessNode * node)
{
  printf("%s\n", node->name);
  printf("stars:\n");
  printf("%s\n",node->stars);
  printf("address:\n");
  printf("%s\n",node->address);
  return;
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
}

