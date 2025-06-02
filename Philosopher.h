#pragma once
#include <array>

#include "Fork.h"

class Fork;

class Philosopher {

	int pos;
	bool isEating;
	bool isThinking;
	bool hasLeftFork;
	bool hasRightFork;
	Fork& leftFork;  // Reference to left fork
	Fork& rightFork; // Reference to right fork

public:

	Philosopher(int  Pos, bool IsEating, Fork leftFork, Fork rightFork);
	~Philosopher() = default;

	int getPos() const { return pos; }
	bool getIsEating() const { return isEating; }
	bool getIsThinking() const { return isThinking; }

	bool getLeftFork() const { return hasLeftFork; }
	bool getRightFork() const { return hasRightFork; }

	void startEating();
	void startThinking();

	void takeLeftFork(Fork leftFork);
	void takeRightFork(Fork rightFork);
	void putLeftFork(Fork leftFork);
	void putRightFork(Fork rightFork);

};
