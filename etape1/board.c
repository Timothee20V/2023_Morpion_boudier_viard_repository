#include "board.h"
#include <assert.h>


// Déclaration de la variable boardSquares un tableau vide de trois pointeurs de PieceType
static PieceType (*boardSquares)[3];
/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */


static bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
{
  int numberSquaresEmpty = 0;
  bool end = false;
  bool win = false;
  *gameResult = DRAW;
  
  // Test des lignes
  for(int i=0; i<3; i++)
  {
    if(boardSquares[i][0] != NONE && boardSquares[i][0] == boardSquares[i][1] && boardSquares[i][1] == boardSquares[i][2])
    {
      end = true;
      win = true;
    }
  }

  // Test des colonnes
  for(int i=0; i<3; i++)
  {
    if(boardSquares[0][i] != NONE && boardSquares[0][i] == boardSquares[1][i] && boardSquares[1][i] == boardSquares[2][i])
    {
      end = true;
      win = true;
    }
  }

  // Test de la 1er diagonnale
  if(boardSquares[0][0] != NONE && boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2])
  {
      end = true;
      win = true;
  }

  // Test de la 2eme diagonale
  if(boardSquares[0][2] != NONE && boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0])
  {
      end = true;
      win = true;
  }

  // Test tableau rempli
  for(int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (boardSquares[i][j] == NONE)
      {
        numberSquaresEmpty += 1;
      }
    }
  }
  if (numberSquaresEmpty == 0)
  {
    end = true;
  }

  if(end && win)
  { 
    if(boardSquares[lastChangeY][lastChangeX] == CROSS)
    {
      *gameResult = CROSS_WINS;
    }
    if(boardSquares[lastChangeY][lastChangeX] == CIRCLE)
    {
      *gameResult = CIRCLE_WINS;
    }
  }
  
  return end;

}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
  boardSquares = calloc(3, sizeof *boardSquares);
  for(int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      boardSquares[i][j] = NONE;
    }
  }

}
  
void Board_free ()  
{
 //efface en memoire le tableau boardSquares
  free(boardSquares);
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{ 
  if (boardSquares[x][y] != NONE)
  {
    return SQUARE_IS_NOT_EMPTY;
  }
  else
  {
    boardSquares[x][y] = kindOfPiece;
    squareChangeCallback(x, y, kindOfPiece);

    GameResult gameResult;
    if (isGameFinished(boardSquares, x, y, gameResult))
    {
      endOfGameCallback(gameResult);
    }
    return PIECE_IN_PLACE;
  }
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
  //verifie que les coordonnées sont dans le tableau
  assert(x >= 0 && x <= 2);
  assert(y >= 0 && y <= 2);
  //retourne la valeur de la case du tableau
  return boardSquares[y][x];
}
