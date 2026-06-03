#pragma once
class GameState
{
protected:
	char GameMap[10][10] = {};
	char RealGameMap[10][10] = {};
	int Count = 30;
	int EnemyShipCount = 4;
	int EnemyShip[4] = { 5,4,3,2 };
	int EnemyShipHitCount[6] = { 0, };
	bool SinkPrint = false;
	int LastAttackY;
	int LastAttackX;

public:
	void SetZero();
	void PrintMap();
	void PrintRealMap();
	bool SinkCheck(int y, int x);
	bool VictoryCheck();

	char getMap(int y, int x) { return GameMap[y][x]; }
	void setMap(int y, int x, char val) { GameMap[y][x] = val; }
	char getRealMap(int y, int x) { return RealGameMap[y][x]; }
	void setRealMap(int y, int x, char val) { RealGameMap[y][x] = val; }

	int getCount() { return Count; }
	void setCountMinusOne() { Count--; }
	int getEnemyShipCount() { return EnemyShipCount; }
	void setEnemyShipCountMinusOne() { EnemyShipCount--; }
	int getEnemyShip(int n) { return EnemyShip[n]; }
	int getShipHitCount(int n) { return EnemyShipHitCount[n]; }
	void setShipHitCountPlusOne(int n) { EnemyShipHitCount[n]++; }
	bool getSinkPrint() { return SinkPrint; }
	void reverseSinkPrint() { SinkPrint = !SinkPrint; }
	int getLastAttackY() { return LastAttackY; }
	void setLastAttackY(int y) { LastAttackY = y; }
	int getLastAttackX() { return LastAttackX; }
	void setLastAttackX(int x) { LastAttackX = x; }
};

