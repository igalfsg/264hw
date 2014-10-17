#include "answer06.h"
#include <stdio.h>
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

int checknorth1 (int x, int y, char ** maze)
{
  if(maze[--y][x] != 'X')
    return 1;
  else
    return 0;
}

int checksouth1 (int x, int y, char ** maze)
{
  if(maze[++y][x] != 'X')
    return 1;
  else
    return 0;
}
int checkeast1 (int x, int y, char ** maze)
{
  if(maze[y][++x] != 'X')
    return 1;
  else
    return 0;
}

int checkwest1 (int x, int y, char ** maze)
{
  if(maze[y][--x] != 'X')
    return 1;
  else
    return 0;
}

void explore (int x, int y, int * previous, char ** maze, int countsteps, int h, int w)
{
  int options = 0;


  if (checknorth(x,y, maze) == 1 && y != 0)
    {
      if (*previous == NORTH)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y - 1, previous, maze,countsteps, h, w); 
	}
      else
	{
	  if (*previous != 7)
	    printdirection(*previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  *previous = NORTH;
	  explore(x, y - 1, previous, maze,1, h, w);
	  if (checknorth1(x,y, maze) == 1 && y != 0)
	    options++;
	  if (checksouth1(x,y, maze) == 1 && y < h - 1)
	    options++;
	  if (checkeast1(x,y, maze) == 1 && x < w - 1)
	    options++;
	  if (checkwest1(x,y, maze) == 1 && x != 0)
	    options++;
	  if (*previous == 7 && options > 1)
	    *previous = 8;
	  if (*previous != 7)
	    printf("S %d\n", countsteps);

	}
    }

  if (checksouth(x,y, maze) == 1 && y < h - 1)
    {
      if (*previous == SOUTH)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, previous, maze,countsteps, h, w);
	}
      else
	{

	  if (*previous != 7)
	    printdirection(*previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  *previous = SOUTH;
	  explore(x, y + 1, previous, maze,1, h ,w);
	  if (checknorth1(x,y, maze) == 1 && y != 0)
	    options++;
	  if (checksouth1(x,y, maze) == 1 && y < h - 1)
	    options++;
	  if (checkeast1(x,y, maze) == 1 && x < w - 1)
	    options++;
	  if (checkwest1(x,y, maze) == 1 && x != 0)
	    options++;
	  if (*previous == 7 && options > 1)
	    *previous = 8;
	  if (*previous != 7)
	    printf("N %d\n", countsteps);

	}
    }
  if (checkeast(x,y, maze) == 1 && x < w - 1)
    {
      if (*previous == EAST)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x + 1, y , previous, maze,countsteps, h, w);
	}
      else
	{
	  if (*previous != 7)
	    printdirection(*previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  *previous = EAST;
	  explore(x + 1, y, previous, maze,1, h ,w);
	  if (checknorth1(x,y, maze) == 1 && y != 0)
	    options++;
	  if (checksouth1(x,y, maze) == 1 && y < h - 1)
	    options++;
	  if (checkeast1(x,y, maze) == 1 && x < w - 1)
	    options++;
	  if (checkwest1(x,y, maze) == 1 && x != 0)
	    options++;
	  if (*previous == 7 && options > 1)
	    *previous = 8;
	  if (*previous != 7)
	    printf("W %d\n", countsteps);
	}
    }
  if (checkwest(x,y, maze) == 1 && x != 0)
    {
      if (*previous == WEST)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x - 1, y , previous, maze,countsteps, h, w);
	}
      else
	{
	  if (*previous != 7)
	    printdirection(*previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  *previous = WEST;
	  explore(x - 1, y, previous, maze,1, h ,w);
	  if (checknorth1(x,y, maze) == 1 && y != 0)
	    options++;
	  if (checksouth1(x,y, maze) == 1 && y < h - 1)
	    options++;
	  if (checkeast1(x,y, maze) == 1 && x < w - 1)
	    options++;
	  if (checkwest1(x,y, maze) == 1 && x != 0)
	    options++;
	  if (*previous == 7 && options > 1)
	    *previous = 8;
	  if (*previous != 7)
	    printf("W %d\n", countsteps);
	}
    }
 
  if(options == 0 && maze[y][x] == ' ')
    {
      printdirection(*previous,countsteps );
      (*previous) *= -1;
      printdirection(*previous,countsteps );
      * previous = 7;
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

}
