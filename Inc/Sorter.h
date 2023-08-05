#pragma once
class Sorter
{
public:
	//virtual void SetResultDisplayer();
	virtual void SortIntegers(int* arr, int size) = 0;
	virtual int GetNumberOfSteps() = 0;
};

