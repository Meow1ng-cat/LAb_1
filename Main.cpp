#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include "Fork.h"
#include "Philosopher.h"

using namespace std;

int main()
{
	const std::array<Fork, 5>& forks = {
		Fork(1), Fork(2), Fork(3), Fork(4), Fork(5)
	};

	std::array<Philosopher, 5> philosophers = {
		Philosopher(1, true, forks[0], forks[4]),
		Philosopher(2, false, forks[1], forks[0]),
    	Philosopher(3, true, forks[2], forks[1]),
		Philosopher(4, false, forks[3], forks[2]),
    	Philosopher(5, false, forks[4], forks[3])
    };

	while(true)
	{
		int counter = 1;
		std::cout << counter;
		std::cout << "\n";

		for (Philosopher i : philosophers)
		{
			std::cout << i.getPos();
			std::cout << i.getIsEating();
			std::cout << i.getIsThinking();
			std::cout << "\n";
		}

		std::cout << "=================================================================================================";
		std::cout << "\n";

		for (Philosopher i : philosophers)
		{
			if(i.getIsEating() == true)
			{
				for(Philosopher j : philosophers)
				{
					if(i.getPos() +1 == j.getPos() || (i.getPos() == 5 && j.getPos() == 1))
					{
						switch (i.getPos())
						{
						case 1:
							i.putLeftFork(forks[0]);
							i.putRightFork(forks[4]);
							j.takeLeftFork(forks[1]);
							j.takeRightFork(forks[0]);
							break;
						case 2:
							i.putLeftFork(forks[1]);
							i.putRightFork(forks[0]);
							j.takeLeftFork(forks[2]);
							j.takeRightFork(forks[1]);
							break;
						case 3:
							i.putLeftFork(forks[2]);
							i.putRightFork(forks[1]);
							j.takeLeftFork(forks[3]);
							j.takeRightFork(forks[2]);
							break;
						case 4:
							i.putLeftFork(forks[3]);
							i.putRightFork(forks[2]);
							j.takeLeftFork(forks[4]);
							j.takeRightFork(forks[3]);
							break;
						case 5:
							i.putLeftFork(forks[4]);
							i.putRightFork(forks[3]);
							j.takeLeftFork(forks[0]);
							j.takeRightFork(forks[4]);
							break;
						}
					}
				}
			}
		}

		counter = +1;
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}
