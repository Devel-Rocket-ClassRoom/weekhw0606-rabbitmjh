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

	char GetMap(int y, int x) { return GameMap[y][x]; }
	void SetMap(int y, int x, char val) { GameMap[y][x] = val; }
	char GetRealMap(int y, int x) { return RealGameMap[y][x]; }
	void SetRealMap(int y, int x, char val) { RealGameMap[y][x] = val; }

	int GetCount() { return Count; }
	void SetCountMinusOne() { Count--; }
	int GetEnemyShipCount() { return EnemyShipCount; }
	void SetEnemyShipCountMinusOne() { EnemyShipCount--; }
	int GetEnemyShip(int n) { return EnemyShip[n]; }
	int GetShipHitCount(int n) { return EnemyShipHitCount[n]; }
	void SetShipHitCountPlusOne(int n) { EnemyShipHitCount[n]++; }
	bool GetSinkPrint() { return SinkPrint; }
	void ReverseSinkPrint() { SinkPrint = !SinkPrint; }
	int GetLastAttackY() { return LastAttackY; }
	void SetLastAttackY(int y) { LastAttackY = y; }
	int GetLastAttackX() { return LastAttackX; }
	void SetLastAttackX(int x) { LastAttackX = x; }
};

