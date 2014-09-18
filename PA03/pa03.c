#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "answer03.h"


int main(int argc, char * * argv)
{
	int try = 20;
	int * tes = &try;
	char * name = malloc(20 * sizeof(char));
	char * nam2 = malloc(8 * sizeof(char));
	//char * answer1 = malloc(20 * sizeof(char));
	strcpy(name, "hello");
	strcpy(nam2, "test");
	name = strcat_ex(&name, tes, nam2);
	const char * naming = "please work im beggin";
	printf(" answerr %s \n",name);
	const char * spaces =  " ";
	char ** testing = explode(naming, spaces, tes);
	for (try = 0; try <4; try++)
	  {
	    printf("test %s \n",testing[try]);
	  }
	name = implode(testing, 4, " ");
	printf("testing in %s\n",name);
	sortStringArray(testing, 4);
	for (try = 0; try <4; try++)
          {
            printf(" %s",testing[try]);
          }
	printf("\n");
	printf ("before" );
	sortStringCharacters(name);
	free(nam2);
	free(name);
	destroyStringArray (testing, 4);
	return 0;

}
