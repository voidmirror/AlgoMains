#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge{
	int peak1;
	int peak2;
	int weight;
};


int main() {
	int numEdges;
	cin >> numEdges;
	//edge* mas = (edge*)malloc(sizeof(edge)*numEdges);
	vector <edge> mas(numEdges);
	
	for (int i = 0; i < numEdges; i++) {
		cin >> mas[i].peak1;
		cin >> mas[i].peak2;
		cin >> mas[i].weight;
	}
	
	for (int i = 0; i < numEdges; i++) {
		cout << mas[i].peak1 << " ";
		cout << mas[i].peak2 << " ";
		cout << mas[i].weight << " ";
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < numEdges; i++) {
		for (int j = i; j < numEdges; j++) {
			if (mas[i].weight > mas[j].weight) {
				edge _temp = mas[i];
				mas[i] = mas[j];
				mas[j] = _temp;
			}
		}
	}
	
	for (int i = 0; i < numEdges; i++) {
		cout << mas[i].peak1 << " ";
		cout << mas[i].peak2 << " ";
		cout << mas[i].weight << " ";
		cout << endl;
	}
	cout << endl;
	
	int* done = (int*)malloc(sizeof(int)*(numEdges+1));
	for (int i = 0; i < numEdges + 1; i++) {
		done[i] = 0;
	}
	
	
	/*for (int i = 0; i < numEdges + 1; i++) {
		for (int j = 0; j < numEdges; j++) {
			int minWeight = 0;
			for (int k = 0; k < numEdges; k++) {
				if ((mas[k].weight > minWeight) && (done[mas[i].peak1 - 1])) {
					
				}
			}
		}
	}*/

	int checkPeaks = 1;
	for (int i = 0; i < numEdges; i++) {
		checkPeaks *= done[i];
	}

	while (!checkPeaks) {


		// check----------------------------------------------------------------------
		for (int i = 0; i < numEdges; i++) {
			checkPeaks *= done[i];
		}
	}
}
    

//int main() {
//	vector < vector<int> > g; // граф
//	int n; // число вершин
//	int s; // стартовая вершина (вершины везде нумеруются с нуля)
//
//	for (int i = 0; i < n; i++) {
//
//	}
//
//	queue<int> q;
//	q.push(s);
//	vector<bool> used(n);
//	vector<int> d(n), p(n);
//	used[s] = true;
//	p[s] = -1;
//	while (!q.empty()) {
//		int v = q.front();
//		q.pop();
//		for (size_t i = 0; i<g[v].size(); ++i) {
//			int to = g[v][i];
//			if (!used[to]) {
//				used[to] = true;
//				q.push(to);
//				d[to] = d[v] + 1;
//				p[to] = v;
//			}
//
//			if (!used[to])
//				cout << "No path!";
//			else {
//				vector<int> path;
//				for (int v = to; v != -1; v = p[v])
//					path.push_back(v);
//				reverse(path.begin(), path.end());
//				cout << "Path: ";
//				for (size_t i = 0; i<path.size(); ++i)
//					cout << path[i] + 1 << " ";
//			}
//		}
//	}
//
//	
//}