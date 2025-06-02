#include "Philosopher.h"

#include <iostream>

Philosopher::Philosopher(int const Pos, bool const IsEating, Fork LeftFork, Fork RightFork)
	: pos(Pos),
	isEating(IsEating),
	isThinking(!IsEating),
	leftFork(LeftFork), rightFork(RightFork)
{

	if (pos < 1 || pos > 5)
	{
		pos = -1;
		std::cerr << "Wrong pos value\n";
	}

	if(isEating == true)
	{
		hasLeftFork = true;
		hasRightFork = true;
		isThinking = false;

		if (pos != 1) {
			if (pos == leftFork.getPos())
			{
				leftFork.occupyFork(*this);
			}
			else if(pos == rightFork.getPos() || pos == rightFork.getPos() - 1)
			{
				rightFork.occupyFork(*this);
			}
		}
		else if (pos == 1)
		{
			if (pos == leftFork.getPos())
			{
				leftFork.occupyFork(*this);
			}
			else if (rightFork.getPos() == 5)
			{
				rightFork.occupyFork(*this);
			}
		}
	}
	else
	{
		hasLeftFork = false;
		hasRightFork = false;
		isThinking = true;
	}
}

void Philosopher::startEating()
{
	if (hasLeftFork == true && hasRightFork == true)
	{
		isEating = true;
	}
}

void Philosopher::startThinking()
{
	if (hasLeftFork == false && hasRightFork == false)
	{
		isThinking = true;
	}
}

void Philosopher::takeLeftFork(Fork leftFork)
{
	if(leftFork.getPos() == pos)
	{
		if(!leftFork.getIsOccupied())
		{
			leftFork.occupyFork(*this);
			hasLeftFork = true;
		}
		else
		{
			std::cerr << "Fork is already occupied\n";
		}
	}
	else
	{
		std::cerr << " This fork is not left\n";
	}
}

void Philosopher::takeRightFork(Fork rightFork)
{
	if(pos != 1)
	{
		if(rightFork.getPos() == pos-1)
		{
			if(!rightFork.getIsOccupied())
			{
				rightFork.occupyFork(*this);
				hasRightFork = true;
			}
			else
			{
				std::cerr << "Fork is already occupied\n";
			}
		}
		else
		{
			std::cerr << " This fork is not right\n";
		}
	}
	else if (pos == 1)
	{
		if(rightFork.getPos() == 5)
		{
			if(!rightFork.getIsOccupied())
			{
				rightFork.occupyFork(*this);
				hasRightFork = true;
			}
			else
			{
				std::cerr << "Fork is already occupied\n";
			}
		}
		else
		{
			std::cerr << " This fork is not right\n";
		}
	}
}

void Philosopher::putLeftFork(Fork leftFork)
{
	if (leftFork.getPos() == pos)
	{
		if (leftFork.getIsOccupied())
		{
			leftFork.releaseFork();
			hasLeftFork = false;
		}
		else
		{
			std::cerr << "Fork is not occupied\n";
		}
	}
	else
	{
		std::cerr << " This fork is not left\n";
	}
}

void Philosopher::putRightFork(Fork rightFork)
{
	if (pos != 1)
	{
		if (rightFork.getPos() == pos - 1)
		{
			if (rightFork.getIsOccupied())
			{
				rightFork.releaseFork();
				hasRightFork = false;
			}
			else
			{
				std::cerr << "Fork is not occupied\n";
			}
		}
		else
		{
			std::cerr << " This fork is not right\n";
		}
	}
	else if (pos == 1)
	{
		if (rightFork.getPos() == 5)
		{
			if (rightFork.getIsOccupied())
			{
				rightFork.releaseFork();
				hasRightFork = false;
			}
			else
			{
				std::cerr << "Fork is not occupied\n";
			}
		}
		else
		{
			std::cerr << " This fork is not right\n";
		}
	}
}




