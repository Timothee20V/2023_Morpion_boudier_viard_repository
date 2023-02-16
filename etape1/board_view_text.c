#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

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
  printf("\033[2J \n"); 
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
  //Declaration du tableau de char pour le switch
  char winner[10];

  //switch pour afficher le gagnant
  switch(result)
  {
    case DRAW:
      strcpy(winner, "NOBODY");
      printf("Null game");
      break;
    case CROSS_WINS:
      strcpy(winner, "CROSS");
      printf("Cross wins");
      break;
    case CIRCLE_WINS:
      strcpy(winner, "CIRCLE");
      printf("Circle wins");
      break;
  }

  printf("Game over: %s", winner);
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  //verifie que la valeur est bien un joueur
  assert(thisPlayer != NONE);
  //print le joueur qui doit jouer
  printf("Player %d has to play", thisPlayer);
}

void BoardView_sayCannotPutPiece (void)
{
  //print le message d'erreur quand la case n'est pas vide
  printf("Cannot put piece, this square is not empty");
}

#endif // defined CONFIG_TEXTUI
