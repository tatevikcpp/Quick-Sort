#include <iostream>

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Part(int *arr, int low, int high)
{
	int k = arr[high];    
	int i = (low - 1);  

	for (int j = low; j <= high - 1; ++j)
	{
		
		if (arr[j] <= k)
		{
			i++;  
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void QuickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		
		int m = Part(arr, low, high);

		QuickSort(arr, low, m - 1);
		QuickSort(arr, m + 1, high);
	}
}


void PrintArr(int *arr, int size)
{
	
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}


int main()
{
	int arr[] = { 10, 21, 11, 9, 7, 57 };
	int n = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, 0, n - 1);
	PrintArr(arr, n);

	system("pause");
}