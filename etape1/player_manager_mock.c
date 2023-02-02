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

static PieceType currentPlayer = CROSS;

void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
  do{
    Coordinate coordX = scanf("Entrer la coordonnée X : ");
    Coordinate coordY = scanf("Entrer la coordonnée Y : ");
  }while(Board_putPiece(coordX,coordY, currentPlayer) == SQUARE_IS_NOT_EMPTY)
  currentPlayer = (currentPlayer == CROSS) ? CIRCLE : CROSS;
  return 1;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK

