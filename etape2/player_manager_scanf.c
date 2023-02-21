/**
 * @file player_manager_scanf.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if defined CONFIG_PLAYER_MANAGER_SCANF

PieceType currentPlayer;

int conteur = 0;


int Is_valid(char *str) {
  int i, x, y, size;
  char *str_x, *str_y, *virgule;

  printf("---\n");
  printf("Move : %s\n", str);

  size = strlen(str);
  if (size != 3) {  // La chaine doit contenir exactement 3 caractères (X,Y)
    BoardView_sayCannotPutPieceNotThreeChar();
    return false;
  }

  virgule = strchr(str, ',');  // Recherche de la virgule dans la chaîne
  if (virgule == NULL) {  // Si pas de virgule trouvée
    BoardView_sayCannotPutPieceNoComma();
    return false;
  }

  str_x = str;
  str_y = virgule + 1;

  if (str_x == virgule || str_y - virgule != 1) {  // Vérification qu'il y a un caractère avant et après la virgule
    BoardView_sayCannotPutPieceInvalidPos();
    return false;
  }

  for (i = 0; i < size; i++) {
    if (i != virgule - str && !isdigit(str[i])) {  // Vérification que seuls les caractères numériques sont utilisés
      BoardView_sayCannotPutPieceNoDigit();
      return false;
    }
  }
  x = str_x[0] - '0'; // conversion de char à int
  y = str_y[0] - '0'; // conversion de char à int

  if (x < 0 || x > 2 || y < 0 || y > 2) {  // Vérification que les numéros (de ligne ou de colonne) sont compris entre 0 et 2 inclus
    BoardView_sayCannotPutPieceNotBetweenTowAndZero();
    return false;
  }
  return true;
}

void PlayerManager_init (void)
{
  currentPlayer = CROSS;
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  
  Coordinate coordX;
  Coordinate coordY;
  char coord[4];
  do{
    printf("Player %s, quel deplacement ? (x,y) : ", (currentPlayer == CROSS) ? "X" : "O");
    scanf("%s", coord);
    coordX = coord[0] - '0'; // conversion de la chaîne en entier
    coordY = coord[2] - '0'; // conversion de la chaîne en entier
  }while(!Is_valid(coord) || Board_putPiece(coordX,coordY, currentPlayer) == SQUARE_IS_NOT_EMPTY);
  currentPlayer = (currentPlayer == CROSS) ? CIRCLE : CROSS;
  conteur++;
}



#endif // defined CONFIG_PLAYER_MANAGER_SCANF
