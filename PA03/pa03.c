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
	printf(" answerr %s \n",name); 
	return 0;
}
