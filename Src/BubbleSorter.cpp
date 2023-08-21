#include "BubbleSorter.h"

BubbleSorter::BubbleSorter()
{
}

int BubbleSorter::GetNumberOfSteps()
{
	return m_numberOfSteps;
}

void BubbleSorter::SortIntegers(int* arr, int size)
{
	m_numberOfSteps = 0;
	bool swapped = false;
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size - i - 1; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				int temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
				swapped = true;
				m_numberOfSteps++;
			}
		}
		if (swapped == false)
			break;
	}
}