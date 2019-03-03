#include "Sparta.h"
#include "TypeUnits.h"
#include "TypeEnemy.h"

Sparta::Sparta(int sizeEnemy, int sizeSpartacus) : m_SizeForEnemy(sizeEnemy), m_SizeForSpartacus(sizeSpartacus)
{
	m_enemies = new Enemy*[sizeEnemy];
	m_spartacus = new Units*[sizeSpartacus];
}

void Sparta::SetNumOfEnemy(size_t num) 
{
	m_num_of_enemy = num;
}

const bool Sparta::GetGame() 
{
	return Game;
}

const int Sparta::GetNumOfEnemy() 
{
	return m_num_of_enemy;
}

const int Sparta::GetSizeOfEnemies() 
{
	return m_SizeForEnemy;
}

const int Sparta::GetSizeOfSpartacus() 
{
	return m_SizeForSpartacus;
}

void Sparta::AddEnemies(int sizeEnemy) 
{
	for (int i = 0; i < sizeEnemy;)
	{
		CreateEnemies(GetNumOfEnemy());
		i++;
	}
}

void Sparta::AddSpartacus(int sizeSpartacus) 
{
	size_t num;
	for (int i = 0; i < sizeSpartacus;)
	{
		num = rand() % 2 + 1;
		CreateSpartacus(num);
		i++;
	}
}

void Sparta::CreateEnemies(size_t enemy)
{
	Enemy* enemys = nullptr;
	switch (enemy)
	{
	case 1:
		enemys = new Slave;
		break;
	case 2:
		enemys = new Barbarian;
		break;
	case 3:
		enemys = new Persians;
		break;
	case 4:
		enemys = new Dragon;
		break;
	case 5:
		enemys = new Demigod;
		break;
	}
	if (m_CountOfEnemy < m_SizeForEnemy) 
	{
		m_enemies[m_CountOfEnemy] = enemys;
		m_CountOfEnemy++;
	}
}

void Sparta::CreateSpartacus(size_t spartacus) 
{
	Units* spart = nullptr;
	switch (spartacus)
	{
	case 1:
		spart = new Hoplite;
		break;
	case 2:
		spart = new Hypaspists;
		break;
	case 3:
		spart = new Agriana;
		break;
	case 4:
		spart = new Peltasts;
		break;
	case 5:
		spart = new Libertini;
		break;
	}
	if (m_CountOfSpartacus < m_SizeForSpartacus) 
	{
		m_spartacus[m_CountOfSpartacus] = spart;
		m_CountOfSpartacus++;
	}
}

void Sparta::DeleteEnemies(size_t index)
{
	if (index < m_SizeForEnemy)
	{
		delete m_enemies[index];
		for (int i = index; i < m_SizeForEnemy - 1; i++)
		{
			m_enemies[i] = m_enemies[i + 1];
		}
		m_SizeForEnemy--;
	}
}
void Sparta::DeleteSpartacus(size_t index)
{
	if (index < m_SizeForSpartacus)
	{
		delete m_spartacus[index];
		for (int i = index; i < m_SizeForSpartacus - 1; i++)
		{
			m_spartacus[i] = m_spartacus[i + 1];
		}
		m_SizeForSpartacus--;
	}
}

void Sparta::AttackSpartacus() 
{
	for (int i = 0; i < m_SizeForSpartacus && Game == true; i++)
	{
		int Luck = rand() % 100 - 50;
		m_spartacus[i]->SetLuck(Luck);
		int attack = m_spartacus[i]->GetDamage() + m_spartacus[i]->GetLuck();
		int UnitForAttack = rand() % m_SizeForEnemy;
		m_enemies[UnitForAttack]->GetDamageAfterAttack(attack);
		PrintAttackSpartacus(i);
		DeleteEnemiesForConsole(UnitForAttack);
		PrintWinners();
	}
}

void Sparta::AttackEnemies() 
{
	for (int i = 0; i < m_SizeForEnemy && Game == true; i++)
	{
		int Luck = rand() % 20 - 30;
		m_enemies[i]->SetLuck(Luck);
		int attack = m_enemies[i]->GetDamage() + m_enemies[i]->GetLuck();
		int UnitForAttack = rand() % m_SizeForSpartacus;
		PrintAttackEnemies();
		if (m_enemies[i]->GetName() != "Dragon" || m_enemies[i]->GetName() != "Demigod")
		{
			m_spartacus[UnitForAttack]->GetDamageAfterAttack(attack);
			DeleteSpartacusForConsole(UnitForAttack);
			attack = 0;
			PrintWinners();
		}
		else
		{
			int DamageAfterAttack = attack;
			while (attack > 0 && Game == true)
			{
				if (m_spartacus[UnitForAttack]->GetHealth() > attack)
				{
					DamageAfterAttack = attack - m_spartacus[UnitForAttack]->GetHealth();
					m_spartacus[UnitForAttack]->GetDamageAfterAttack(attack);
					DeleteSpartacusForConsole(UnitForAttack);
					attack = DamageAfterAttack;
					UnitForAttack = m_SizeForSpartacus - 1;
				}
				else
				{
					m_spartacus[UnitForAttack]->GetDamageAfterAttack(attack);
					DeleteSpartacusForConsole(UnitForAttack);
					attack = 0;
				}
				PrintWinners();
			}
		}
	}
}


void Sparta::PrintAttackEnemies() 
{
	cout << m_enemies[0]->GetName() << " attacks!" << endl;
}

void Sparta::PrintAttackSpartacus(int index) 
{
	cout << m_spartacus[index]->GetName() << " attacks!" << endl;
}

void Sparta::DeleteEnemiesForConsole(int index)
{
	if (m_enemies[index]->GetHealth() <= 0)
	{
		DeleteEnemies(index);
		cout << "General! " << "Enemy died on the battlefield!" << endl;
	}
}

void Sparta::DeleteSpartacusForConsole(int index)
{
	if (m_spartacus[index]->GetHealth() <= 0)
	{
		DeleteSpartacus(index);
		cout << "General! " << "Our troops of were defeated on the battlefield!" << endl;
	}
}

void Sparta::PrintWinners() 
{
	if (m_SizeForEnemy == 0 && m_SizeForSpartacus != 0)
	{
		cout << "Spartacus win!" << endl;
		Game = false;
	}
	if (m_SizeForEnemy != 0 && m_SizeForSpartacus == 0)
	{
		cout << m_enemies[0]->GetName() << " wins!" << endl;
		Game = false;
	}
	if (m_SizeForEnemy == 0 && m_SizeForSpartacus == 0)
	{
		cout << "Snake? Snake! Snaaaake!" << endl;
		Game = false;
	}
}

void Sparta::PrintEnities()
{
	cout << endl << "___________________";
	cout << endl << "Enemies: " << endl;
	for (int i = 0; i < m_SizeForEnemy; i++)
	{
		m_enemies[i]->Show();
	}
	cout << endl << "Count of Enemies: " << m_CountOfEnemy << endl << "___________________";
	cout << endl << "Spartacus: " << endl;
	for (int i = 0; i < m_SizeForSpartacus; i++)
	{
		m_spartacus[i]->Show();
	}
	cout << endl << "Count of Spartacus: " << m_CountOfSpartacus << endl << "___________________" << endl;
}