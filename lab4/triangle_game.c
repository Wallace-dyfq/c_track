#include <stdio.h>
#include "triangle_routines.h"


#define NMOVES 36

#define SIZE 15

int moves[NMOVES][3] =
{
  {0, 1, 3},
  {0, 2, 5},
  {1, 3, 6},
  {1, 4, 8},
  {2, 4, 7},
  {2, 5, 9},
  {3, 1, 0},
  {3, 4, 5},
  {3, 6, 10},
  {3, 7, 12},
  {4, 7, 11},
  {4, 8, 13},
  {5, 2, 0},
  {5, 4, 3},
  {5, 8, 12},
  {5, 9, 14},
  {6, 3, 1},
  {6, 7, 8},
  {7, 4, 2},
  {7, 8, 9},
  {8, 4, 1},
  {8, 7, 6},
  {9, 5, 2},
  {9, 8, 7},
  {10, 6, 3},
  {10, 11, 12},
  {11, 7, 4},
  {11, 12, 13},
  {12, 7, 3},
  {12, 8, 5},
  {12, 11, 10},
  {12, 13, 14},
  {13, 8, 4},
  {13, 12, 11},
  {14, 9, 5},
  {14, 13, 12}
};


/* Return the number of pegs on the board. */
int npegs(int board[]);

/* Return 1 if the move is valid on this board, otherwise return 0. */
int valid_move(int board[], int move[]);

/* Make this move on this board. */
void make_move(int board[], int move[]);

/* Unmake this move on this board. */
void unmake_move(int board[], int move[]);

/* 
 * Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board passed
 * in. Once a solution is found, print the boards making up the solution in
 * reverse order. 
 */
int solve(int board[]);

int main(void)
{
    int board[15];
    triangle_input(board);

    /* printf("Here is the board you entered:\n"); */
    /* triangle_print(board); */
    int result;
    result = solve(board);
    if (!result)
      printf("\nFail to find successful move~~\n");
    else
      printf("\n======== Sucess!!! ========\n");
    return 0;
}


/* Return the number of pegs on the board. */
int npegs(int board[]) {
  int count = 0;
  int i;
  for (i = 0; i < SIZE; ++i)
    if (board[i] == 1)
      count++;
  return count;
}

/* Return 1 if the move is valid on this board, otherwise return 0. */
int valid_move(int board[], int move[]) {
  int i = move[0];
  int j = move[1];
  int k = move[2];
  int valid = 0; /* 0 invalid, 1 valid */
  if (board[i] == 1 &&
      board[j] == 1 &&
      board[k] == 0)
    valid = 1;
  else
    valid = 0;
  return valid;


}

/* Make this move on this board. */
void make_move(int board[], int move[]) {
  int i = move[0];
  int j = move[1];
  int k = move[2];
  board[i] = !board[i];
  board[j] = !board[j];
  board[k] = !board[k];
  

}

/* Unmake this move on this board. */
void unmake_move(int board[], int move[]) {
  int i = move[0];
  int j = move[1];
  int k = move[2];
  board[i] = !board[i];
  board[j] = !board[j];
  board[k] = !board[k];
 }

/* 
 * Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board passed
 * in. Once a solution is found, print the boards making up the solution in
 * reverse order. 
 */
int solve(int board[]) {
  if (npegs(board) == 1)
  {
    printf("\nYou did it!!!\n");
    triangle_print(board);
    return 1;
  }
  else
  {
   
    int i;
    int valid = 0;
    int success = 0;
    for(i = 0; i < NMOVES; ++i)
    {
      int  move[3];
      int j;
      for ( j = 0; j < 3; ++j)
        move[j] = moves[i][j];
       
      valid = valid_move(board, move);
      if (valid) {
        make_move(board, move);
        success = solve(board);
        if (success == 1)
        {
          unmake_move(board, move);
          triangle_print(board);
          return 1;
        }
        else
        {
          unmake_move(board, move);
          
        }
        
      }
    }
    
    return 0;
  }
}
