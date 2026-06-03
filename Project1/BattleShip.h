#pragma once
#include "GameState.h"

void BattleShip();
void Input(GameState* game);
void PlaceEnemyShip(GameState* game);
void Attack(GameState* game, int y, int x);
void GameEnd(GameState* game);