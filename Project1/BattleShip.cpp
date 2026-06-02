#include "BattleShip.h"
#include <iostream>
using namespace std;

void BattleShip()
{
	srand(time(0));

	GameState* game = new GameState;
	PlaceEnemyShip(game);
	game->PrintRealMap();
	game->PrintMap();
	
	delete game;
	game = nullptr;
}

void Input()
{
	printf("x y 좌표를 입력해 공격하세요: ");

	int x, y;
	cin >> x >> y;
	Attack(y, x);
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
				x = (rand() % 9) + 1;
				y = (rand() % 9) + 1;
			}
			bool wl = rand() % 2; // 0이면 가로, 1이면 세로

			int cnt = 0;
			if (!wl)
			{
				// 배의 크기가 홀수면 x-배의 크기/2 ~ x+배의 크기, 짝수면 x-배의크기/2 ~ x+배의 크기-1
				for (int i = (x - game->getEnemyShip(n) / 2); i <= (x + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
				{
					if (!(game->getRealMap(y, i)))
						cnt++;
				}
				if (cnt == game->getEnemyShip(n))
				{
					for (int i = (x - game->getEnemyShip(n) / 2); i <= (x + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
					{
						game->setRealMap(y, i, game->getEnemyShip(n));
					}
					break;
				}
			}
			else
			{
				// 배의 크기가 홀수면 y-배의 크기/2 ~ y+배의 크기, 짝수면 y-배의크기/2 ~ y+배의 크기-1
				for (int i = (y - game->getEnemyShip(n) / 2); i <= (y + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
				{
					if (!(game->getRealMap(i, x)))
						cnt++;
				}
				if (cnt == game->getEnemyShip(n))
				{
					for (int i = (y - game->getEnemyShip(n) / 2); i <= (y + (game->getEnemyShip(n) % 2 == 1 ? game->getEnemyShip(n) / 2 : game->getEnemyShip(n) / 2 - 1)); i++)
					{
						game->setRealMap(i, x, game->getEnemyShip(n));
					}
					break;
				}
			}
		}
	}
}

void Attack(int y, int x)
{
	
}

//TO DO: 공격, 격침 판정, 게임 종료 출력