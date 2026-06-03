#include "GameState.h"
#include <iostream>

void GameState::PrintMap()
{
	//system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│       B A T T L E  S H I P       │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│     0  1  2  3  4  5  6  7  8  9 │\n");
	printf("├───┬──────────────────────────────┤\n");
	for (int i = 0; i < 10; i++)
	{
		printf("│ %d │", i);
		for (int j = 0; j < 10; j++)
			printf(" %d ", GameMap[i][j]);
		printf("│\n");
	}
	printf("└───┴──────────────────────────────┘\n");
	printf("남은 공격 횟수: %d회 남은 적 함선 수: %d척\n", Count, EnemyShipCount);
}

void GameState::PrintRealMap()
{
	system("cls");
	printf("┌──────────────────────────────────┐\n");
	printf("│       B A T T L E  S H I P       │\n");
	printf("├──────────────────────────────────┤\n");
	printf("│     0  1  2  3  4  5  6  7  8  9 │\n");
	printf("├───┬──────────────────────────────┤\n");
	for (int i = 0; i < 10; i++)
	{
		printf("│ %d │", i);
		for (int j = 0; j < 10; j++)
			printf(" %d ", RealGameMap[i][j]);
		printf("│\n");
	}
	printf("└───┴──────────────────────────────┘\n");
	printf("남은 공격 횟수: %d회 남은 적 함선 수: %d척\n", Count, EnemyShipCount);
}

bool GameState::VictoryCheck()
{
	if (!EnemyShipCount && Count >= 0)
		return true;
	else
		return false;
}
