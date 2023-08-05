#pragma once
#include "Sorter.h"
class BinaryInsertionSorter :
    public Sorter
{
public:
    void SortIntegers(int* arr, int size) override;
    int GetNumberOfSteps() override;

private :
    int m_numberOfSteps = 0;
    int BinarySearch(int arr[], int item, int start, int end);
};

