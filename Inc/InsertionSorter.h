#include "Sorter.h"

#pragma once
class InsertionSorter : public Sorter
{
public:
	InsertionSorter(){}
	void SortIntegers(int* arr, int size) override;
	int GetNumberOfSteps() override;
private:
	int m_numberOfSteps = 0;
};

