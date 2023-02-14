/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include <assert.h>
#include <stdio.h>

#if defined CONFIG_PLAYER_MANAGER_MOCK

PieceType currentPlayer = CROSS;

int conteur = 0;
const struct {
  Coordinate x;
  Coordinate y;} test[9] = {
    { 1, 1},
    { 0, 0},
    { 0, 1},
    { 2, 1},
    { 2, 0},
    { 1, 0},
    { 0, 2},
    { 1, 2},
    { 2, 2},
};

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  Coordinate coordX;
  Coordinate coordY;
  do{
    coordX = test[conteur].x;
    coordY = test[conteur].y;
  }while(Board_putPiece(coordX,coordY, currentPlayer) == SQUARE_IS_NOT_EMPTY);
  currentPlayer = (currentPlayer == CROSS) ? CIRCLE : CROSS;
  conteur++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK

