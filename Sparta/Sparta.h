#pragma once
#include "Enemy.h"
#include "Units.h"

class Sparta
{
protected:
	int m_num_of_enemy = 1;
	int m_SizeForEnemy;
	int m_SizeForSpartacus;
	int m_CountOfEnemy = 0;
	int m_CountOfSpartacus = 0;
	bool Game = true;
	Enemy** m_enemies;
	Units** m_spartacus;
public:
	Sparta(int sizeEnemy, int sizeSpartacus);
	void SetNumOfEnemy(size_t num);
	const bool GetGame();
	const int GetNumOfEnemy();
	const int GetSizeOfEnemies();
	const int GetSizeOfSpartacus();
	void CreateEnemies(size_t enemy);
	void CreateSpartacus(size_t spartacus);
	void DeleteEnemies(size_t index);
	void DeleteSpartacus(size_t index);
	void AttackSpartacus();
	void AttackEnemies();
	void AddEnemies(int sizeEnemy);
	void AddSpartacus(int sizeSpartacus);
	void PrintAttackEnemies();
	void PrintAttackSpartacus(int index);
	void DeleteEnemiesForConsole(int index);
	void DeleteSpartacusForConsole(int index);
	void PrintWinners();
	void PrintEnities();
};