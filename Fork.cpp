#include "Fork.h"

#include <iostream>

Fork::Fork(int Pos)
{
	pos = Pos;
	if (pos < 1 || pos > 5)
	{
		pos = -1;
		std::cerr << "Wrong pos value\n";
	}
}

void Fork::occupyFork(Philosopher Philosopher)
{
	if (isOccupied == true)
	{
		std::cerr << "Fork is already Occupied\n";
	}

	switch (pos)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		if (pos != Philosopher.getPos() || pos + 1 != Philosopher.getPos())
		{
			std::cerr << "Philosopher has no access to  this fork\n";
		}
		break;
	case 5:
		if (Philosopher.getPos() != 1 || Philosopher.getPos() != 5)
		{
			std::cerr << "Philosopher has no access to  this fork\n";
		}
		break;
	}

	isOccupied = true;
}

void Fork::releaseFork()
{
	if(isOccupied == false)
	{
		std::cerr << "Fork is already free\n";
	}
	isOccupied = false;}



