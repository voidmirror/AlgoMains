#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Cell {
	int x, y;
	int money;
};

int main() {
	int matrX, matrY;
	cin >> matrX >> matrY;
	matrX++;	// for creating additional 0-cross
	matrY++;	// for creating additional 0-cross

	vector <vector <string>> data;
	data.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		data[i].resize(matrY);
	}
	int startX, startY;
	for (int i = 1; i < matrX; i++) {
		for (int j = 1; j < matrY; j++) {
			cin >> data[i][j];
			if (data[i][j][0] == 'S') {
				startX = i; startY = j;
				//cout << startX << " " << startY << endl;
			}
		}
	}

	//j = atoi(&s[0]);

	

	// create matrix------------------------------------------------------------------

	// Field matrix
	vector <vector <int>> field;
	field.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		field[i].resize(matrY);
	}

	/*for (int i = 0; i < matrX; i++) {
		field[0][i] = 0;
	}
	for (int i = 0; i < matrY; i++) {
		field[i][0] = 0;
	}*/
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			field[i][j] = 0;
		}
	}
	
	for (int i = startX; i < matrX; i++) {
		for (int j = startY; j < matrY; j++) {
			//cin >> field[i][j];
			if (data[i][j][0] == 'S') {
				field[i][j] = 0;
			}
			else {
				field[i][j] = atoi(&data[i][j][0]);
			}
		}
	}
	
	/*for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}*/

	// coins matrix-------------------------------------------------------------------

	cout << endl;
	// coins matrix
	vector <vector <int>> coins;
	coins.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		coins[i].resize(matrY);
	}
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			coins[i][j] = 0;
		}
	}
	/*for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			cout << coins[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 1; i < matrX; i++) {
		for (int j = 1; j < matrY; j++) {
			coins[i][j] = max(coins[i - 1][j], coins[i][j - 1]) + field[i][j];
		}
	}
	/*cout << endl;
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			cout << coins[i][j] << " ";
		}
		cout << endl;
	}*/

	vector <vector <int>> path;
	int string = matrX - 1;
	int colomn = matrY - 1;
	int cells = -1;		// numbers of cells in path
	while (string != startX || colomn != startY) {
		path.push_back(vector <int>());
		cells++;
		path[cells].push_back(string);
		path[cells].push_back(colomn);
		//cout << string << " " << colomn << endl;
		if (coins[string][colomn - 1] > coins[string - 1][colomn]) {
			if (colomn != startY) {
				colomn--;
			}
			else {
				string--;
			}			
		}
		else {
			if (string != startX) {
				string--;
			}
			else {
				colomn--;
			}			
		}
	}
	path.push_back(vector <int>());
	cells++;
	path[cells].push_back(string);
	path[cells].push_back(colomn);

	/*cout << endl;
	for (int i = 0; i < cells + 1; i++) {
		for (int j = 0; j < 2; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	reverse(path.begin(), path.end());
	for (int i = 0; i < cells + 1; i++) {
		for (int j = 0; j < 2; j++) {
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	cout << "Path:" << endl;
	for (int i = 0; i < cells + 1; i++) {
		cout << "(" << path[i][0] - 1 << "," << path[i][1] - 1 << ")" << " ";
	}
	cout << endl;
	cout << "Coins: " << coins[matrX - 1][matrY - 1];


	/*
	// Vector of current Robot's path
	vector <Cell> way;

	// reflexion of Explored field's cells
	vector <vector <int>> fieldPhantom;
	field.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		field[i].resize(matrY);
	}
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			fieldPhantom[i][j] = 1;			// if (fieldPhantom[i][j])
		}
	}

	// right-down --------------------------------------------------------------------

	int downChange = 0, rightChange = 0, xCounter = 0,  yCounter = 0;
	for (xCounter; xCounter < matrX - downChange; xCounter++) {
		for (yCounter; yCounter < matrY; yCounter++) {


			//rightChange++;
		}

		//downChange++;
	}
	*/
}