#include <iostream>
#include <time.h>

using namespace std;

void space(int n) { // кол-во отступов
	for (int i = 0; i < n; i++) {
		cout << " ";
	}
}

void delay(int ms) { // функция задержки в мс
	int c = clock() + ms;
	while (clock() < c);
}

void show_vert_arr(int* arr, int size, int max_value) { // (|-strings)
	int n = max_value;
	for (int i = 0; i < max_value; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[j] >= n) {
				cout << "|";
				space(2);
			}
			else space(3);
		}
		n--;
		cout << endl;
	}
}

void sort(int *arr, int size) {

	int max_value = arr[0];
	for (int i = 0; i < size; i++) { //max value
		if (max_value < arr[i])
			max_value = arr[i];
	}

	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{

				show_vert_arr(arr, size, max_value);

				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;

				delay(500);

				system("cls");
			}
		}
	}
	show_vert_arr(arr, size, max_value);
}

#define SIZE 25

int main() {
	srand(time(NULL));

	int arr[SIZE];

	for (int i = 0; i < SIZE; i++) {
		arr[i] = 1 + rand() % 9;
	}

	sort(arr, SIZE);

}