#include "answer06.h"
#include <stdio.h>
#include <stdlib.h>
#define NORTH -1
#define SOUTH 1
#define EAST 2
#define WEST -2

void printdirection(int previous, int countsteps)
{
  if (previous == NORTH)
    printf("N %d\n",countsteps);
  else if (previous == SOUTH)
    printf("S %d\n",countsteps);
  else if (previous == EAST)
    printf("E %d\n",countsteps);
  else 
    printf("W %d\n",countsteps);
}


int checknorth (int x, int y, char ** maze)
{
  if(maze[--y][x] == ' ')
    return 1;
  else
    return 0;
}

int checksouth (int x, int y, char ** maze)
{
  if(maze[++y][x] == ' ')
    return 1;
  else
    return 0;
}

int checkeast (int x, int y, char ** maze)
{
  if(maze[y][++x] == ' ')
    return 1;
  else
    return 0;
}

int checkwest (int x, int y, char ** maze)
{
  if(maze[y][--x] == ' ')
    return 1;
  else
    return 0;
}



void explore (int x, int y, int * previous, char ** maze, int countsteps, int h, int w)
{
  int options = 0;
  int prev =  0;
  int inter = 0;
  int previn;
  int countint;

  if (y != 0 && checknorth(x,y, maze) == 1  )
    {
      if (*previous == NORTH)
	{
	  if((x != 0 && checkwest(x,y, maze) == 1) || (x < w - 1 && checkeast(x,y, maze) == 1 ))
	    {
	      countint = countsteps;
	      inter = 1;
	      previn = *previous;
	    }
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y - 1, previous, maze,countsteps, h, w); 
	  if (inter)
	    printdirection(previn, countint);
	}
      else
	{
	  if (*previous != 7){
	    printdirection(*previous, countsteps);
	    prev = *previous;
	  }
	  maze[y][x] = '.';
	  options++;
	  *previous = NORTH;
	  explore(x, y - 1, previous, maze,1, h, w);
	}
    }

  if (y < h - 1 && checksouth(x,y, maze) == 1)
    {
      if (*previous == SOUTH)
	{
	  if((x != 0 && checkwest(x,y, maze) == 1) || (x < w - 1 && checkeast(x,y, maze) == 1 ))
	    {
	      countint = countsteps;
	      inter = 1;
	      previn = *previous;
	    }
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, previous, maze,countsteps, h, w);
	  if (inter)
	    printdirection(previn, countint);
	}
      else
	{

	  if (*previous != 7){
	    printdirection(*previous, countsteps);
	  prev = *previous;
	  }
	  maze[y][x] = '.';
	  options++;
	  *previous = SOUTH;
	  explore(x, y + 1, previous, maze,1, h ,w);
	}
    }
  if (x < w - 1 && checkeast(x,y, maze) == 1 )
    {
      if (*previous == EAST)
	{
	   if( (y < h - 1 && checksouth(x,y, maze) == 1)   ||(y != 0 && checknorth(x,y, maze) == 1  )  )
	    {
	      countint = countsteps;
	      inter = 1;
	      previn = *previous;
	    }
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x + 1, y , previous, maze,countsteps, h, w);
	  if (inter)
	    printdirection(previn, countint);
	}
      else
	{
	  if (*previous != 7){
	    printdirection(*previous, countsteps);
	  prev = *previous;
	  }
	  maze[y][x] = '.';
	  options++;
	  *previous = EAST;
	  explore(x + 1, y, previous, maze,1, h ,w);
	}
    }
  if (x != 0 && checkwest(x,y, maze) == 1)
    {
      if (*previous == WEST)
	{
	  if( (y < h - 1 && checksouth(x,y, maze) == 1)   ||(y != 0 && checknorth(x,y, maze) == 1  )  )
	    {
	      countint = countsteps;
	      inter = 1;
	      previn = *previous;
	    }
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x - 1, y , previous, maze,countsteps, h, w);
	  if (inter)
	    printdirection(previn, countint);
	}
      else
	{
	  if (*previous != 7){
	    printdirection(*previous, countsteps);
	    prev = *previous;
	  }
	  maze[y][x] = '.';
	  options++;
	  *previous = WEST;
	  explore(x - 1, y, previous, maze,1, h ,w);
	}
    }
  if (prev != 7 && prev != 0)
    printdirection((-1*prev), countsteps);
  if(options == 0 && maze[y][x] == ' ')
    {
      maze[y][x] = '.';
      printdirection(*previous,countsteps );
      (*previous) *= -1;
      printdirection(*previous,countsteps );
      * previous = 7;
    }
  if (inter){
    printdirection((-1*previn), countint);
      }

}

void print_directions(char** maze, int w, int h)
{
  int i = 0;
  int out = 0;
  int x;
  int y = 1;
  int p = 1;
  int * prev;
  prev = &p;
  while (i < w && out == 0)
    {
    if (maze[0][i] == ' ')
      {
	x = i;
	maze[0][i] = '.';
	out = 1;
	printf("S 1\n");
      }
    i++;
    }// enter the maze
  explore (x, y, prev, maze, 0, h, w);
  //free(prev);
}
