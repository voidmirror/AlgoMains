#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int kadaneAlgothythm(vector <int>& arr, int &start, int &end, int n) {
	int sum = 0;
	end = -1;
	int maxSum = INT_MIN;
	int tempStart = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			tempStart = i + 1;
		}
		else if (sum > maxSum) {
			maxSum = sum;
			start = tempStart;
			end = i;
		}
	}

	if (end != -1) {
		return maxSum;
	}

	maxSum = arr[0];
	start = 0;
	end = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
			start = end = i;
		}
	}
	return maxSum;
}

int main() {
	int matrX, matrY;
	cin >> matrX >> matrY;

	vector <vector <int>> mat;
	mat.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		mat[i].resize(matrY);
	}
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			cin >> mat[i][j];
		}
	}

	vector <int> tempRow;
	tempRow.resize(matrX);
	int left, right, sum, maxSum = INT_MIN;
	int start, end;

	for (left = 0; left < matrY; left++) {
		for (int i = 0; i < matrX; i++) {
			tempRow[i] = 0;
		}

		for (right = left; right < matrY; ++right) {
			for (int i = 0; i < matrX; ++i) {
				tempRow[i] += mat[i][right];
			}
			sum = kadaneAlgothythm(tempRow, start, end, matrX);
			if (sum > maxSum) {
				maxSum = sum;
			}
		}		
	}

	cout << "Max submatrix: " << maxSum;
}
