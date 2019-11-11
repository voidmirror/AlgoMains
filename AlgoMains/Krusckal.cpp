#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int x, y;
	edge(){}
	edge(int a, int b) {
		x = a;
		y = b;
	}
};

int main() {
	int n, m;			// m - edges of source graph, n - apex num
	cin >> n >> m;

	vector <edge> graph(m);
	vector <edge> tree;
	vector <int> apex(n);


	for (int i = 0; i < n; i++) {
		apex[i] = rand() % 5 + 1;			// range from 1 to 5	(variatively)
		apex[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << apex[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < m; i++) {
		int a, b;

		//cin >> a >> b;

		a = rand() % n;
		b = rand() % n;
		cout << "ab: " << a << " " << b << endl;

		graph[i].x = a;
		graph[i].y = b;
	}

	for (int i = 0; i < m; i++) {
		int a = graph[i].x;
		int b = graph[i].y;
		if (apex[a] != apex[b]) {
			tree.push_back(graph[i]);
			int old_apex = apex[b], new_apex = apex[a];
			for (int j = 0; j < n; j++) {
				if (apex[j] == old_apex) {
					apex[j] = new_apex;
				}
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		cout << tree[i].x << " " << tree[i].y;
		if (i != n - 2) {
			cout << endl;
		}
	}
}