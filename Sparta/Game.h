#pragma once
#include "Sparta.h"

class Game
{
	Sparta* SpartaGame;
	int day = 1;
public:
	Game(Sparta* con);
	void AddAndPrintEntities(size_t SerialNumberOfEnemy);
	void PrintDay();
	void Start();
};