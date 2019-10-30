#include <iostream>
using namespace std;

int binary(int *mas, int elem, int left, int right) {
	int mid = (int)ceil((left + right) / 2);
	
	if (mas[mid] != elem) {
		cout << mas[mid] << " ";
	}
	if (mas[mid] == elem) {
		cout << mas[mid] << endl;
		return mid;
	}
	else if (mas[mid] > elem) {
		return binary(mas, elem, left, mid);
	}
	else {
		return binary(mas, elem, mid + 1, right);
	}

}

int main() {

	// linear-------------------------------------------------------------------------
	int num, elem;
	cin >> num >> elem;
	int *mas;
	mas = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
		cin >> mas[i];

	cout << "Initial array:" << endl;
	for (int i = 0; i < num - 1; i++) {
		cout << mas[i] << " ";
	}
	cout << mas[num - 1] << endl;

	cout << "Linear search:" << endl;
	int j = 0;
	while (mas[j] != elem) {
		cout << mas[j] << " ";
		j++;
	}
	cout << mas[j] << endl;

	// binary-------------------------------------------------------------------------
	cout << "Binary search:" << endl;
	int binResult;
	binResult = binary(mas, elem, 0, num);
	//cout <<  << endl;
}