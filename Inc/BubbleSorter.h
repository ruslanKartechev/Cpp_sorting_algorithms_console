#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	void SortIntegers(int* arr, int size) override;
	int GetNumberOfSteps() override;
private:
	int m_numberOfSteps = 0;
};

