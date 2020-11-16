#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<int> arr(10);		
	int count = 0;

	int n;
	cout << "Enter numbers: ";
	cin >> n;

	for (int i = 2; i <= n; ++i)
	{
		if (count == arr.getSize())
		{
			arr.resize(count * 2);
		}
		arr[count++] = i;

	}

	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;

	system("pause");

}