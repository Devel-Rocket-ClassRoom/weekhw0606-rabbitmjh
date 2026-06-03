#include "BattleShip.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void BattleShip()
{
	srand(time(0));

	GameState* game = new GameState;
	game->SetZero();
	PlaceEnemyShip(game);
	while (game->getCount()&&game->getEnemyShipCount())
	{
		//game->PrintRealMap();
		game->PrintMap();
		Input(game);
	}
	GameEnd(game);
	
	delete game;
	game = nullptr;
}

void Input(GameState* game)
{
	printf("x y 좌표를 입력해 공격하세요: ");

	int x, y;
	cin >> x >> y;
	while (x < 0 || y < 0 || x>9 || y>9 || game->getMap(y, x) == 'h')
	{
		if (x < 0 || y < 0 || x>9 || y>9)
		{
			printf("범위를 벗어났습니다. 0~9를 입력하세요: ");
			cin >> x >> y;
		}
		else
		{
			printf("이미 공격한 좌표입니다. 다른 곳을 공격해주세요: ");
			cin >> x >> y;
		}
	}

	Attack(game, y, x);
	game->setLastAttackX(x);
	game->setLastAttackY(y);
}

void PlaceEnemyShip(GameState* game)
{
	for (int n = 0; n < 4; n++)
	{
		while (1)
		{
			int x, y;
			if (n == 0 || n == 1)
			{
				x = (rand() % 6) + 2;
				y = (rand() % 6) + 2;
			}
			else
			{
				x = (rand() % 8) + 1;
				y = (rand() % 8) + 1;
			}
			bool wl = rand() % 2; // 0이면 가로, 1이면 세로

			int cnt = 0;
			if (!wl) // 가로
			{
				// 배의 크기가 홀수면 x-배의 크기/2 ~ x+배의 크기, 짝수면 x-배의크기/2 ~ x+배의 크기-1
				for (int i = (x - game->getEnemyShip(n) / 2); i <= (x + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
				{
					if ((game->getRealMap(y, i)) == '.')
						cnt++;
				}
				if (cnt == game->getEnemyShip(n))
				{
					for (int i = (x - game->getEnemyShip(n) / 2); i <= (x + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
					{
						game->setRealMap(y, i, game->getEnemyShip(n) + '0');
					}
					break;
				}
			}
			else // 세로
			{
				// 배의 크기가 홀수면 y-배의 크기/2 ~ y+배의 크기, 짝수면 y-배의크기/2 ~ y+배의 크기-1
				for (int i = (y - game->getEnemyShip(n) / 2); i <= (y + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
				{
					if ((game->getRealMap(i, x)) == '.')
						cnt++;
				}
				if (cnt == game->getEnemyShip(n))
				{
					for (int i = (y - game->getEnemyShip(n) / 2); i <= (y + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
					{
						game->setRealMap(i, x, game->getEnemyShip(n) + '0');
					}
					break;
				}
			}
		}
	}
}

void Attack(GameState* game, int y, int x)
{
	game->setCountMinusOne();
	game->setMap(y, x, 'h');
	if (game->getRealMap(y, x) != '.')
	{
		game->setShipHitCountPlusOne(game->getRealMap(y, x) - '0');
		game->SinkCheck(y, x);
	}
}

void GameEnd(GameState* game)
{
	system("cls");
	if (game->VictoryCheck())
	{
		game->PrintMap();
		printf("┌──────────────────────────────────┐\n");
		printf("│       P L A Y E R    W I N       │\n");
		printf("└──────────────────────────────────┘\n");
	}
	else
	{
		game->PrintRealMap();
		printf("┌──────────────────────────────────┐\n");
		printf("│       P L A Y E R  L O S E       │\n");
		printf("└──────────────────────────────────┘\n");
	}
}

//TO DO: 공격, 격침 판정, 게임 종료 출력