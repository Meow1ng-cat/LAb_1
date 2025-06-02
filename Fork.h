#pragma once
#include "Philosopher.h"

class Philosopher;

class Fork
{
	int pos;
	bool isOccupied;

public:
	Fork(int Pos);
	~Fork() = default;

	int getPos() const { return pos; }
	bool getIsOccupied() const { return isOccupied; }

	void occupyFork(Philosopher Philosopher);
	void releaseFork();
};

