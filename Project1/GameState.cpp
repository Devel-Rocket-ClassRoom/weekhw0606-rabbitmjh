#include "GameState.h"
#include <iostream>

void GameState::PrintMap()
{
	system("cls");
	printf("┌──────────────────────────────┐\n");
	for (int i = 0; i < 10; i++)
	{
		printf("│");
		for (int j = 0; j < 10; j++)
			printf(" %d ", RealGameMap[i][j]);
		printf("│\n");
	}
	printf("└──────────────────────────────┘\n");
	printf("남은 공격 횟수: %d\t남은 적 함선 수: %d\n", Count, EnemyShipCount);
}

bool GameState::VictoryCheck()
{
	if (!EnemyShipCount && Count >= 0)
		return true;
	else
		return false;
}
