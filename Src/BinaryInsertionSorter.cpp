#include "BinaryInsertionSorter.h"

void BinaryInsertionSorter::SortIntegers(int* arr, int size)
{
	m_numberOfSteps = 0;
	int targetIndex = 0;
	int j = 0;
	int k = 0;
	int current = 0;
	for (auto ind = 1; ind < size; ind++)
	{
		j = ind - 1;
		current = arr[ind];
		targetIndex = BinarySearch(arr, current, 0, j);
		while (j >= targetIndex)
		{
			arr[j + 1] = arr[j];
			j--;
			m_numberOfSteps++;
		}
		arr[targetIndex] = current;
	}
}

int BinaryInsertionSorter::BinarySearch(int arr[], int item, int start, int end)
{
	m_numberOfSteps++;
	if (end <= start)
		return (item > arr[start]) ? (start + 1) : start;

	int mid = (start + end) / 2;

	if (item == arr[mid])
		return mid + 1;

	if (item > arr[mid])
		return BinarySearch(arr, item, mid + 1, end);
	return BinarySearch(arr, item, start, mid - 1);
}

int BinaryInsertionSorter::GetNumberOfSteps()
{
	return m_numberOfSteps;
}
