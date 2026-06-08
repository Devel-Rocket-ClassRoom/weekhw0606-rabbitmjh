#include "GameState.h"
#include <iostream>

void GameState::SetZero()
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			SetMap(i, j, '.');
			SetRealMap(i, j, '.');
		}
}

void GameState::PrintMap()
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
			printf(" %c ", (GameMap[i][j] == 'h' ? (RealGameMap[i][j] > '.' ? 'O' : 'X') : GameMap[i][j]));
		printf("│\n");
	}
	printf("├───┴──────────────────────────────┤\n");
	printf("│남은 공격 횟수: %02d회              │\n", GetCount());
	printf("│남은 적 함선 수 : %d척             │\n", GetEnemyShipCount());
	if (GetSinkPrint())
	{
		if (GetRealMap(GetLastAttackY(), GetLastAttackX()) == '5')
			printf("│적 항공모함을 격침했습니다.       │\n");
		else if (GetRealMap(GetLastAttackY(), GetLastAttackX()) == '4')
			printf("│적 전함을 격침했습니다.           │\n");
		else if (GetRealMap(GetLastAttackY(), GetLastAttackX()) == '3')
			printf("│적 순양함을 격침했습니다.         │\n");
		else if (GetRealMap(GetLastAttackY(), GetLastAttackX()) == '2')
			printf("│적 구축함을 격침했습니다.         │\n");
	}
	printf("└──────────────────────────────────┘\n");
	if (GetSinkPrint())
		ReverseSinkPrint();
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
			printf(" %c ", RealGameMap[i][j]);
		printf("│\n");
	}
	printf("├───┴──────────────────────────────┤\n");
	printf("│남은 공격 횟수: %02d회              │\n", GetCount());
	printf("│남은 적 함선 수 : %d척             │\n", GetEnemyShipCount());
	printf("└──────────────────────────────────┘\n");

}

bool GameState::SinkCheck(int y, int x)
{
	if ((GetRealMap(y, x) - '0') == EnemyShipHitCount[GetRealMap(y, x) - '0'])
	{
		SetEnemyShipCountMinusOne();
		ReverseSinkPrint();
		return true;
	}
	else
		return false;
}

bool GameState::VictoryCheck()
{
	if (!GetEnemyShipCount() && GetCount() >= 0)
		return true;
	else
		return false;
}
