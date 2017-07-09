// Policy.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include <conio.h>
#include "HelloWorld.h"
#include "MultiContainer.h"
#include "BasicStopWatch.h"
#include "TimerBase.h"

constexpr unsigned int allocationSize = 100 * 100;
constexpr unsigned int maxIter = 2*10000 * 100000;

unsigned int virtualPerformance()
{

	TimerBase timer;

	MultiContainer<double> bigTable;

	auto size = bigTable.Size();
	auto ptr = bigTable.Ptr();

	bigTable.Allocate(allocationSize);

	double* p = bigTable.Ptr();
	double value = 3.14159;
	while (p != bigTable.Last() + 1)
	{
		*p = value;
		value += 0.25;
		p++;
	}

	
	double total = 0.0;
	double valueToCompare = 3.14;

	timer.Start();

	for (unsigned int counter = 0; counter < maxIter; ++counter)
	{
		

		unsigned index = counter % bigTable.Size();
		valueToCompare += (valueToCompare*0.142);

		if (bigTable.Size() == 0 || *bigTable.First() > valueToCompare || *bigTable.Last() < valueToCompare)
		{
			double val = *bigTable.Last();
			continue;
		}

		total += *(bigTable.Ptr() + index);
			
	}
	unsigned int elapsedTime = timer.GetMs();
	std::cout << elapsedTime << std::endl;
	std::cout << total << std::endl;

	return elapsedTime;
}

unsigned int callbackPerformance()
{
	TimerBase timer;

	//MultiCallbackContainer<double> bigTable;
#ifdef TOTO
	auto size = bigTable.Size();
	auto ptr = bigTable.Ptr();

	bigTable.Allocate(allocationSize);

	double* p = bigTable.Ptr();
	double value = 3.14159;
	while (p != bigTable.Last() + 1)
	{
		*p = value;
		value += 0.25;
		p++;
	}

	
	double total = 0.0;
	double valueToCompare = 3.14;

	timer.Start();

	for (unsigned int counter = 0; counter < maxIter; ++counter)
	{
		

		unsigned index = counter % bigTable.Size();
		valueToCompare += (valueToCompare*0.142);

		if (bigTable.Size() == 0 || *bigTable.First() > valueToCompare || *bigTable.Last() < valueToCompare)
		{
			double val = *bigTable.Last();
			continue;
		}

		total += *(bigTable.Ptr() + index);
			
	}
	unsigned int elapsedTime = timer.GetMs();
	std::cout << elapsedTime << std::endl;
	std::cout << total << std::endl;

	return elapsedTime;
#endif

	return 0;
}
unsigned int realPerformance()
{

	TimerBase timer;

	MultiContainerReal<double> bigTable;

	auto size = bigTable.Size();
	auto ptr = bigTable.Ptr();

	bigTable.Allocate(allocationSize);

	double* p = bigTable.Ptr();
	double value = 3.14159;
	while (p != bigTable.Last() + 1)
	{
		*p = value;
		value += 0.25;
		p++;
	}

	
	double total = 0.0;
	double valueToCompare = 3.14;

	timer.Start();

	for (unsigned int counter = 0; counter < maxIter; ++counter)
	{
		

		unsigned index = counter % bigTable.Size();
		valueToCompare += (valueToCompare*0.142);

		if (bigTable.Size() == 0 || *bigTable.First() > valueToCompare || *bigTable.Last() < valueToCompare)
		{
			double val = *bigTable.Last();
			continue;
		}

		total += *(bigTable.Ptr() + index);
			
	}

	unsigned int elapsedTime = timer.GetMs();
	std::cout << elapsedTime << std::endl;
	std::cout << total << std::endl;

	return elapsedTime;
}

int main()
{
	//TimerBase timer;

	//timer.Start();

	///* Example 1 */
	//typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyEnglish> HelloWorldEnglish;

	//HelloWorldEnglish hello_world;
	//hello_world.run(); // prints "Hello, World!"

	//				   /* Example 2
	//				   * Does the same, but uses another language policy */
	//typedef HelloWorld<OutputPolicyWriteToCout, LanguagePolicyGerman> HelloWorldGerman;

	//HelloWorldGerman hello_world2;
	//hello_world2.run(); // prints "Hallo Welt!"

	//auto duration = timer.GetMs();
	//std::cout << timer.GetMs() << std::endl;

	auto  virtualTime = virtualPerformance();

	auto  realTime = realPerformance();

	auto callbackTime = callbackPerformance();

	std::cout << "Perf gain = " << double(virtualTime)/realTime << std::endl;

	//_getch();
	return 0;
}
