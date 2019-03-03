#include "Game.h"

Game::Game(Sparta * con) : SpartaGame(con) {}

void Game::AddAndPrintEntities(size_t SerialNumberOfEnemy) 
{
	SpartaGame->SetNumOfEnemy(SerialNumberOfEnemy);
	SpartaGame->AddEnemies(SpartaGame->GetSizeOfEnemies());
	SpartaGame->AddSpartacus(SpartaGame->GetSizeOfSpartacus());
	SpartaGame->PrintEnities();
}

void Game::PrintDay() 
{
	cout << endl << "Day " << day << endl;
}

void Game::Start() 
{
	do 
	{
		PrintDay();
		SpartaGame->AttackSpartacus();
		SpartaGame->AttackEnemies();
		day++;
	} while (SpartaGame->GetGame());
}