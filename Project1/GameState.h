#pragma once
class GameState
{
protected:
	int GameMap[10][10] = { 0, };
	int RealGameMap[10][10] = { 0, };
	int Count = 30;
	int EnemyShipCount = 4;
	int EnemyShip[4] = { 5,4,3,2 };


public:
	void PrintMap();
	void PrintRealMap();
	bool VictoryCheck();

	int getMap(int y, int x) { return GameMap[y][x]; }
	void setMap(int y, int x, int val) { GameMap[y][x] = val; }
	int getRealMap(int y, int x) { return RealGameMap[y][x]; }
	void setRealMap(int y, int x, int val) { RealGameMap[y][x] = val; }

	int getCount() { return Count; }
	void setCountMinusOne() { Count--; }
	int getEnemyShipCount() { return EnemyShipCount; }
	void setEnemyShipCountMinusOne() { EnemyShipCount--; }
	int getEnemyShip(int n) { return EnemyShip[n]; }
};

