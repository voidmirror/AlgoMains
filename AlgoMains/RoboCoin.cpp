#include <iostream>
#include <vector>

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

	// create matrix------------------------------------------------------------------

	// Field matrix
	vector <vector <int>> field;
	field.resize(matrX);
	for (int i = 0; i < matrX; i++) {
		field[i].resize(matrY);
	}

	for (int i = 0; i < matrX; i++) {
		field[0][i] = 0;
	}
	for (int i = 0; i < matrY; i++) {
		field[i][0] = 0;
	}
	
	for (int i = 1; i < matrX; i++) {
		for (int j = 1; j < matrY; j++) {
			cin >> field[i][j];
		}
	}
	
	for (int i = 0; i < matrX; i++) {
		for (int j = 0; j < matrY; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}



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