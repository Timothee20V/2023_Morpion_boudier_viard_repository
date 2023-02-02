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

void BoardView_displayAll (void)
{
  // TODO: à compléter
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
