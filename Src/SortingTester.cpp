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

class SortingTester {	
public:

	SortingTester()
	{
		srand((unsigned)time(NULL));
		sorterType = 1;
	}

	~SortingTester()
	{
	}

	void Begin()
	{
		sorterType = 4;
		RunByKey();
	}

	void RunAll()
	{
		RunInsertSort();
		RunBinaryInsertSort();
		RunMergingSort();
	}

	void RunByKey()
	{
		switch (sorterType)
		{
		case -1 :
			RunInsertSort();
			RunBinaryInsertSort();
			RunMergingSort();
			break;
		case 1:
			RunInsertSort();
			break;
		case 2:
			RunBinaryInsertSort();
			break;
		case 3:
			RunMergingSort();
			break;
		case 4:
			RunBubbleSort();
			break;
		default:
			Logger::Log("Wrong sorter type");
			break;
		}
	}

private:
	const std::size_t m_numbersSize = 50;
	int mMinRandom = 1;
	int mMaxRandom = 100;
	int sorterType = 1;

	int* MakeRandomIntArr(int length)
	{
		int* arr = new int[length];
		for (int i = 0; i < length; i++)
			arr[i] = Utils::GetRandRange(mMinRandom, mMaxRandom);
		return arr;
	}

	int GetRandomInt()
	{
		return rand();
	}


	void SortAndPrint(Sorter* sorter, int* arr, int size)
	{
		PrintTable* table = new PrintTable();
		table->AddColon(L"Index", 10);
		table->AddColon(L"Unsorted", 12);
		table->AddColon(L"Sorted", 12);

		for (int i = 0; i < size; i++)
		{
			table->AddLineToColon(L"i: " + std::to_wstring(i), 0);
			table->AddLineToColon(std::to_wstring(arr[i]), 1);
		}
		sorter->SortIntegers(arr, m_numbersSize);
		for (int i = 0; i < size; i++)
			table->AddLineToColon(std::to_wstring(arr[i]), 2);
		Logger::LogGreen("Number of steps: " + std::to_string(sorter->GetNumberOfSteps()));
		table->Print();
		delete table;
	}


	void RunInsertSort()
	{
		Logger::Log("\n");
		Logger::LogCyan("Starting Insertion Sort");
		auto* sorter = new InsertionSorter();
		auto size = m_numbersSize;
		int* arr = MakeRandomIntArr(size);
		SortAndPrint(sorter, arr, size);
		delete sorter;
		delete[] arr;
	}

	void RunBinaryInsertSort()
	{
		Logger::Log("\n");
		Logger::LogCyan("Starting Binary Insertion Sort");
		auto* sorter = new BinaryInsertionSorter();
		auto size = m_numbersSize;
		int* arr = MakeRandomIntArr(size);
		SortAndPrint(sorter, arr, size);
		delete sorter;
		delete[] arr;
	}

	void RunMergingSort()
	{
		Logger::Log("\n\n");
		Logger::LogCyan("Starting Merging Sort");
		auto* sorter = new MergeSorter();
		auto size = m_numbersSize;
		int* arr = MakeRandomIntArr(size);
		SortAndPrint(sorter, arr, size);
		delete sorter;
		delete[] arr;
	}

	void RunBubbleSort()
	{
		Logger::Log("\n\n");
		Logger::LogCyan("Starting Bubble Sort");
		auto* sorter = new BubbleSorter();
		auto size = m_numbersSize;
		int* arr = MakeRandomIntArr(size);
		SortAndPrint(sorter, arr, size);
		delete sorter;
		delete[] arr;
	}

};