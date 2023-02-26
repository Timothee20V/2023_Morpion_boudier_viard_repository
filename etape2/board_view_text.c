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

char BoardView_displayCoord(Coordinate x, Coordinate y)
{
  //switch pour renvoyer le char correspondant au type de piece
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
  //efface l'ecran
  printf("\033[2J \n"); 

  //Affichage du tableau propre
  printf("-------------\n");
  for(Coordinate i=0; i<3; i++)
  {
    for(Coordinate j=0; j<3; j++)
    {
      printf("| ");
      printf("%c ", BoardView_displayCoord(i, j));
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
  char winner[6];

  //switch pour afficher le gagnant
  switch(result)
  {
    case DRAW:
      strcpy(winner, "PERSONNE");
      break;
    case CROSS_WINS:
      strcpy(winner, "X");
      break;
    case CIRCLE_WINS:
      strcpy(winner, "O");
      break;
  }

  printf("\nGame over: %s a gagne", winner);
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
  //verifie que la valeur est bien un joueur
  assert(thisPlayer != NONE);
  //print le joueur qui doit jouer
  printf("\nPlayer %s doit jouer \n", (thisPlayer == CROSS) ? "X" : "O");
}

void BoardView_sayCannotPutPiece (void)
{
  //print le message d'erreur quand la case n'est pas vide
  printf("Impossible de poser une piece, cette case n'est pas vide\n");
}

void BoardView_sayCannotPutPieceNotThreeChar (void)
{
  //print le message d'erreur quand l'entrée n'a pas 3 caractères
  printf("Pas 3 caracteres\n");
}

void BoardView_sayCannotPutPieceNoComma (void)
{
  //print le message d'erreur quand l'entrée n'a pas de virgule
  printf("Pas de virgule\n");
}

void BoardView_sayCannotPutPieceInvalidPos (void)
{
  //print le message d'erreur quand l'entrée n'a pas de caractère avant et après la virgule
  printf("Pas de caractere avant ou apres la virgule\n");
}

void BoardView_sayCannotPutPieceNoDigit (void)
{
  //print le message d'erreur quand l'entrée n'a pas de caractère numérique
  printf("Pas de caractere numerique\n");
}

void BoardView_sayCannotPutPieceNotBetweenTowAndZero (void)
{
  //print le message d'erreur quand l'entrée a des numéros supérieurs à 2 ou inférieurs à 0
  printf("Pas compris entre 0 et 2\n");
}

#endif // defined CONFIG_TEXTUI
