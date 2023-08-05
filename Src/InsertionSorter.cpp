#include "InsertionSorter.h"
#include "Logger.h"

//virtual void SetResultDisplayer();
void InsertionSorter::SortIntegers(int* arr, int size)
{
	int current, prev, key = 0;
	m_numberOfSteps = 0;
	for (current = 0; current < size; current++)
	{
		key = arr[current];
		prev = current - 1;
		while (prev >= 0 && arr[prev] > key)
		{
			arr[prev + 1] = arr[prev];
			prev--;
			m_numberOfSteps++;
		}
		arr[prev + 1] = key;
	}
}

int InsertionSorter::GetNumberOfSteps()
{
	return m_numberOfSteps;
}

/*

The auxiliary space complexity of Insertion Sort is O(1)

Characteristics of Insertion Sort
This algorithm is one of the simplest algorithms with a simple implementation
Basically, Insertion sort is efficient for small data values
Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already partially sorted.
Frequently Asked Questions on Insertion Sort
Q1. What are the Boundary Cases of the Insertion Sort algorithm?

Insertion sort takes the maximum time to sort if elements are sorted in reverse order.
And it takes minimum time (Order of n) when elements are already sorted.

Q2. What is the Algorithmic Paradigm of the Insertion Sort algorithm?
The Insertion Sort algorithm follows an incremental approach.

Q3. Is Insertion Sort an in-place sorting algorithm?
Yes, insertion sort is an in-place sorting algorithm.

Q4. Is Insertion Sort a stable algorithm?
*/