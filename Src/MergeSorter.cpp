#include "MergeSorter.h"

void MergeSorter::SortIntegers(int* arr, int size)
{
	MergeSort(arr, 0, size - 1);
}

void MergeSorter::MergeSort(int array[], int begin, int end)
{
	m_numberOfSteps = 0;
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	MergeSort(array, begin, mid);
	MergeSort(array, mid + 1, end);
	Merge(array, begin, mid, end);
}

void MergeSorter::Merge(int arr[], int start, int mid, int last)
{
	int subLengthLeft = mid - start + 1;
	int subLengthRight = last - mid;
	auto* leftArray = new int[subLengthLeft];
	auto* rightArray = new int[subLengthRight];
	// copy into new arrays
	for (auto i = 0; i < subLengthLeft; i++)
		leftArray[i] = arr[start + i];

	for (auto i = 0; i < subLengthLeft; i++)
		rightArray[i] = arr[mid + 1 + i];
	// merging back to one
	auto leftArrIndex = 0;
	auto rightArrIndex = 0;
	auto mergedIndex = start;
	while (leftArrIndex < subLengthLeft
		&& rightArrIndex < subLengthRight)
	{
		if (leftArray[leftArrIndex] <= rightArray[rightArrIndex])
		{
			arr[mergedIndex] = leftArray[leftArrIndex];
			leftArrIndex++;
		}
		else
		{
			arr[mergedIndex] = rightArray[rightArrIndex];
			rightArrIndex++;
		}
		mergedIndex++;
		m_numberOfSteps++;
	}

	while (leftArrIndex < subLengthLeft)
	{
		arr[mergedIndex] = leftArray[leftArrIndex];
		leftArrIndex++;
		mergedIndex++;
		m_numberOfSteps++;
	}

	while (rightArrIndex < subLengthRight)
	{
		arr[mergedIndex] = rightArray[rightArrIndex];
		rightArrIndex++;
		mergedIndex++;
		m_numberOfSteps++;
	}
}

int MergeSorter::GetNumberOfSteps()
{
	return m_numberOfSteps;
}