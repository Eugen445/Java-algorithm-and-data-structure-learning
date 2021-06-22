## PostSelectSort

```
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

template<class T>
class selectSort {
public:

	void sort(T& arr) {

		int len = arr.size();
		for (int i = len - 1; i >= 0; --i) {
			
			int maxIndex = i;
			for (int j = 0; j < i; ++j) {

				if (arr[j] > arr[maxIndex])
					maxIndex = j;
			}
			swap(arr, i, maxIndex);
		}
	}

	void sort(T arr[], int len) {

		for (int i = len - 1; i >= 0; --i) {

			int maxIndex = i;
			for (int j = 0; j < i; ++j) {

				if (arr[j] > arr[maxIndex])
					maxIndex = j;
			}
			swap_in(arr, i, maxIndex);
		}
	}

	bool isSorted(T& arr) {

		int n = arr.size();
		for (int i = 1; i < n; ++i) {
			
			if (arr[i - 1] > arr[i])
				return false;
		}

		return true;
	}

	bool isSorted(T arr[], int len) {

		for (int i = 1; i < len; ++i) {

			if (arr[i - 1] > arr[i])
				return false;
		}

		return true;
	}

private:

	void swap(T& arr, int i, int j) {

		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	void swap_in(T arr[], int i, int j) {

		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
};


int main()
{
	constexpr int n = 1000;
	srand(time(NULL));

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % n;
	
	selectSort<vector<int>>().sort(arr);
	if (!selectSort<vector<int>>().isSorted(arr))
		cout << "selectSort failed" << endl;
	else
		cout << "selectSort success" << endl;

	for (int e : arr)
		cout << e << " ";
	cout << endl;

// - - - - - - - - - - - - - - - - - //

	int arr2[n] = { 0 };
	for (int i = 0; i < n; ++i)
		arr2[i] = rand() % n;

	selectSort<int>().sort(arr2, n);
	if (!selectSort<int>().isSorted(arr2, n))
		cout << "selectSort failed" << endl;
	else
		cout << "selectSort success" << endl;

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
```

