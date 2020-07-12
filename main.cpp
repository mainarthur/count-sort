#include <iostream>
#include <unordered_map>

using namespace std;

int *enterArray(int n);
void printArray(int *arr, int n);
void sortArray(int *arr, int n);

int main()
{
	int n;
	cin >> n;

	int *arr = enterArray(n);
	sortArray(arr, n);

	printArray(arr, n);
	return 0;
}

void sortArray(int *arr, int n)
{
	if (n == 1)
		return;

	int min = arr[0];
	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];

		if (arr[i] < min)
			min = arr[i];
	}

	int *map = new int[max + 1];

	for (int i = 0; i < n; i++)
	{
		map[arr[i]]++;
	}

	for (int i = min, j = 0; i <= max; i++)
	{
		while (map[i] != 0)
		{
			arr[j] = i;
			map[i]--;
			j++;
		}
	}
}

int *enterArray(int n)
{
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return arr;
}

void printArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}