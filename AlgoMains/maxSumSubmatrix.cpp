#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int kadaneAlgothythm(int* arr, int n) {
	int sum = 0;
	int negative = 0;
	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			negative++;
		}
	}

	if (!negative) {
		return maxSum;
	}

	maxSum = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
		}
	}
	return maxSum;
}

int main() {

}