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

void explore (int x, int y, int previous, char ** maze, int countsteps, int h, int w)
{
  int options = 0;

  if (checknorth(x,y, maze) && y != 0)
    {
      if (previous == NORTH)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y - 1, NORTH, maze,countsteps, h, w); 
	}
      else
	{
	  printdirection(previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  explore(x, y - 1, NORTH, maze,0, h, w);
	  printf("S %d\n", countsteps);
	}
    }

  if (checksouth(x,y, maze) && y < h)
    {
      if (previous == SOUTH)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, SOUTH, maze,countsteps, h, w);
	}
      else
	{
	  printdirection(previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, SOUTH, maze,0, h ,w);
	  printf("N %d\n", countsteps);
	}
    }
  if (checkeast(x,y, maze) && x < w)
    {
      if (previous == EAST)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, EAST, maze,countsteps, h, w);
	}
      else
	{
	  printdirection(previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, EAST, maze,0, h ,w);
	  printf("W %d\n", countsteps);
	}
    }
  if (checkwest(x,y, maze) && x != 0)
    {
      if (previous == WEST)
	{
	  countsteps++;
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, WEST, maze,countsteps, h, w);
	}
      else
	{
	  printdirection(previous, countsteps);
	  maze[y][x] = '.';
	  options++;
	  explore(x, y + 1, WEST, maze,0, h ,w);
	  printf("E %d\n", countsteps);
	}
    }
  if(options == 0)
    {
      printdirection(previous,countsteps);
      previous *= -1;
      printdirection(previous,countsteps);
    }
}

void print_directions(char** maze, int w, int h)
{
  int i = 0;
  int out = 0;
  int x;
  int y = 1;
  while (i < w || out == 1)
    {
    if (maze[0][i] == ' ')
      {
	x = i;
	maze[0][i] = '.';
	out = 1;
      }
    }// enter the maze
  explore (x, y, 7, maze, 0, h, w);

}
