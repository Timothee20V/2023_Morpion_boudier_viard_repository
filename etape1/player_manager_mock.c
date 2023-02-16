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

// CROSS
static const struct {
  Coordinate x;
  Coordinate y;
} test_CROSS[9] = {
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

// CIRCLE
static const struct {
  Coordinate x;
  Coordinate y;
} test_CIRCLE[9] = {
  { 1, 1},
  { 0, 0},
  { 0, 1},
  { 2, 0},
  { 1, 2},
  { 1, 0},
  { 2, 1},
  { 0, 2},
  { 2, 2},
};

// DRAW
static const struct {
  Coordinate x;
  Coordinate y;
} test_DRAW[9] = {
  { 0, 0},
  { 1, 0},
  { 2, 0},
  { 0, 1},
  { 1, 1},
  { 2, 2},
  { 1, 2},
  { 0, 2},
  { 2, 1},
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
    coordX = test_DRAW[conteur].x;
    coordY = test_DRAW[conteur].y;
  }while(Board_putPiece(coordX,coordY, currentPlayer) == SQUARE_IS_NOT_EMPTY);
  currentPlayer = (currentPlayer == CROSS) ? CIRCLE : CROSS;
  conteur++;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK

