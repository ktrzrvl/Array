#include <iostream>

using namespace std;

class Array {
	int n;
	int *array;

public:
	Array(int n); 

	void PrintArray();
	void RandomArray(int a, int b);
	void KeyboardArray();

	int SumArray();
	int MinArray();
	int MaxArray();
	double AverageArray();

	void SortArray();
	void SelectionSortArray();

	int IndexOf(int value);
	int BinIndexOf(int value);

	void ReverseArray();
};

Array::Array(int n) {
	this->n = n;
	array = new int[n];
	for (int i = 0; i < n; i++)
		array[i] = 0;
}

void Array::PrintArray() {
	for (int i = 0; i < n; i++) {
		cout << array[i] << "  ";
	}
	cout << endl;
	}

void Array::RandomArray(int a, int b) {
	for (int i = 0; i < n; i++) {
		array[i] = a + rand() % (b - a + 1);
	}
}

void Array::KeyboardArray() {
	cout << "enter values of array: ";
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
}

int Array::SumArray() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum;
}

int Array::MinArray() {
	int min = array[0];
	for (int i = 1; i < n; i++) {
		if (min > array[i])
			min = array[i];
	}
	return min;
}

int Array::MaxArray() {
	int max = array[0];
	for (int i = 1; i < n; i++) {
		if (max < array[i])
			max = array[i];
	}
	return max;
}

void Array::SortArray() {
	bool isSorted = false;
	while (isSorted == false) {
		isSorted = true;
		for (int i = 0; i < n - 1; i++) {
			if (array[i] > array[i + 1]) {
				int tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				isSorted = false;
			}
		}
	}
}

int Array::IndexOf(int value) {
	for (int i = 0; i < n; i++) {
		if (array[i] == value) {
			cout << "Iterations: " << (i + 1) << endl;
			return i;
		}
	}

	return -1;
}

int Array::BinIndexOf(int value) {
	int left = 0;
	int right = n;
	int k = 0;

	while (left < right) {
		int mid = (left + right) / 2;
		if (value <= array[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
		k++;
	}

	cout << "Iterations: " << k << endl;
	if (array[right] == value)
		return right;
	return -1;
}

double Array::AverageArray() {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + array[i];
	}
	return sum / n;
}

void Array::ReverseArray() {
	for (int i = 0; i < n / 2; i++) {
		int b = array[i];
		array[i] = array[n - i - 1];
		array[n - i - 1] = b;
	}
}

void Array::SelectionSortArray() {
	for (int i = 0; i < n; i++) {
		int imin = i;
		for (int j = i+1; j < n; j++) {
			if (array[imin] > array[j]) {
				imin = j;
			}
		}
		int tmp = array[imin];
		array[imin] = array[i];
		array[i] = tmp;
	}
}

int main() {
	int n = 10;
	Array array(n);
	array.KeyboardArray();
	array.PrintArray();
	
}