#pragma once
#include <string>
#include "Logger.h"
#include <cstdlib>
#include <time.h>
#include "Utils.h"
#include "InsertionSorter.h"
#include "BinaryInsertionSorter.h"
#include "MergeSorter.h"
#include "PrintTable.h"
#include "BubbleSorter.h"
#include "SortingTesterModule.h"
#include "InsertionTesterModule.h"

class SortingTester {	
public:

	SortingTester()
	{
		srand((unsigned)time(NULL));
		m_insertionModule = new InsertionTesterModule();
	}

	~SortingTester()
	{
	}

	void Begin()
	{
		RunInputLoop();
	}

private:
	static const int InsertionSortKey = 1;
	static const int BinaryInsertionSortKey = 2;
	static const int MergerSortKey = 3;
	static const int BubbleSortKey = 4;
	SortingTesterModule* m_insertionModule;


	void RunInputLoop()
	{
		int inputKey = 10000;

		auto ResetKey = [&]()
		{
			inputKey = 1000;
		};

		const int returnKey = -1;
		std::string label = "\nEnter Key For the Sort Algorithm";
		std::string prompt = std::string("")
			+ "[" + std::to_string(returnKey) + "]" + "Return\n"
			+ "[" + std::to_string(InsertionSortKey) + "]" + "Insertion sort\n"
			+ "[" + std::to_string(BinaryInsertionSortKey) + "]" + "Binary Insertion sort\n"
			+ "[" + std::to_string(MergerSortKey) + "]" + "Merger sort\n"
			+ "[" + std::to_string(BubbleSortKey) + "]" + "Bubble sort\n";
		
		while (true)
		{
			Logger::LogGreen(label);
			Logger::LogGreen(prompt);
			std::cin >> inputKey;
			switch (inputKey)
			{
				case InsertionSortKey:
					m_insertionModule->RunModule();
					ResetKey();
					break;
				case BinaryInsertionSortKey:

					ResetKey();
					break;
				case MergerSortKey:

					ResetKey();
					break;
				case BubbleSortKey:

					ResetKey();
					break;
				case returnKey:
					return;
				default:
					std::cout << "Unknown key ..." << std::endl;
					break;
			}
		}
	}
};