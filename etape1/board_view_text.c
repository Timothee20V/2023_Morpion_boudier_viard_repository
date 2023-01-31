#include "board_view.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_TEXTUI

void BoardView_init (void)
{
}

void BoardView_free (void)
{
}

char afficherCoord(Coordinate x, Coordinate y)
{
  switch(Board_getSquareContent(x, y)){
        case NONE:
          return ' ';
        case CIRCLE:
          return 'O';
        case CROSS:
          return 'X';
      }
}

void BoardView_displayAll (void)
{
  printf("\033[2J"); 
  printf("-------------\n");
  for(Coordinate i=0; i<3; i++)
  {
    for(Coordinate j=0; j<3; j++)
    {
      printf("| ");
      printf("%c ", afficherCoord(i, j));
    }
    printf("|\n");
    printf("-------------\n");
  }

}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
  printf("Game over: %d ", result);
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  assert(thisPlayer != NONE);
  printf("Player %d has to play", thisPlayer);
}

void BoardView_sayCannotPutPiece (void)
{
  printf("Cannot put piece, this square is not empty");
}

#endif // defined CONFIG_TEXTUI
