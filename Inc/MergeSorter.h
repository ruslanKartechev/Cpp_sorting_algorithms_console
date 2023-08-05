#pragma once
#include "Sorter.h"
class MergeSorter : public Sorter
{
public:
    MergeSorter() {}
    void SortIntegers(int* arr, int size) override;
    int GetNumberOfSteps() override;

private:
    int m_numberOfSteps = 0;
    void MergeSort(int array[], int begin, int end);
    void Merge(int arr[], int start, int mid, int last);
};

