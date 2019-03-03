#include "Game.h"

void main() 
{
	srand(time(0));
	Sparta* sparta;
	size_t nameOfEnemy;
	int sizeEnemy;
	int sizeSpartacus;
	cout << "Enter serial number of enemy: " << endl << "1. Slave" << endl << "2. Barbarian" << endl << "3. Persians" << endl << "4. Dragon" << endl << "5. Demigod" << endl;
	for (int i = 0; i < 1;)
	{
		cout << endl;
		cin >> nameOfEnemy;
		if (nameOfEnemy <= 5 && nameOfEnemy > 0)
		{
			if (nameOfEnemy == 1 || nameOfEnemy == 2 || nameOfEnemy == 3)
			{
				cout << "Enter number of enemies: " << endl;
				cin >> sizeEnemy;
			}
			else 
			{
				sizeEnemy = 1;
			}
			i++;
		}
		else
		{
			cout << endl << "Enter correctly number of enemies" << endl;
		}
	}
	cout << "Enter number of spartacus: " << endl;
	cin >> sizeSpartacus;
		sparta = new Sparta(sizeEnemy, sizeSpartacus);
		sparta->SetNumOfEnemy(nameOfEnemy);
		cout << endl << "SPARTA" << endl;
	Game game(sparta);
	game.AddAndPrintEntities(nameOfEnemy);
	cout << "General!" << endl;
	cout << "On Sparta advancing enemy troops!" << endl <<
		"We must be ready to fight back!" << endl <<
		"The tsar ordered you to attack the enemy's troops!" << endl <<
		"Yes Zeus keeps us!" << endl <<
		"The sons of Hercules today will destroy the enemy!" << endl;
	cout << "___________________" << endl;
	game.Start();
}