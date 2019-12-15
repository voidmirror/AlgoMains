//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
// 
//void takeInput(vector <vector <int>> &ary, vector <int> &completed, int &cost, int n)
//{
//	int i, j;
//	
//	cout << "\nEnter the Cost Matrix\n";
//	for (i = 0; i < n; i++)
//	{
//		cout << "\nEnter Elements of Row: " << i + 1 << "\n";
//
//		for (j = 0; j < n; j++)
//			cin >> ary[i][j];
//
//		completed[i] = 0;
//	}
//
//	cout << "\n\nThe cost list is:";
//
//	for (i = 0; i < n; i++)
//	{
//		cout << "\n";
//
//		for (j = 0; j < n; j++)
//			cout << "\t" << ary[i][j];
//	}
//}
//
//int least(int c, vector <vector <int>> &ary, vector <int> &completed, int &cost, int n)
//{
//	int i, nc = 999;
//	int min = 999, kmin;
//
//	for (i = 0; i < n; i++)
//	{
//		if ((ary[c][i] != 0) && (completed[i] == 0))
//		if (ary[c][i] + ary[i][c] < min)
//		{
//			min = ary[i][0] + ary[c][i];
//			kmin = ary[c][i];
//			nc = i;
//		}
//	}
//
//	if (min != 999)
//		cost += kmin;
//
//	return nc;
//}
//
//void mincost(int city, vector <vector <int>> &ary, vector <int> &completed, int &cost, int n)
//{
//	int i, ncity;
//
//	completed[city] = 1;
//
//	cout << city + 1 << "--->";
//	ncity = least(city, ary, completed, cost, n);
//
//	if (ncity == 999)
//	{
//		ncity = 0;
//		cout << ncity + 1;
//		cost += ary[city][ncity];
//
//		return;
//	}
//
//	mincost(ncity, ary,completed, cost, n);
//}
//
//int main()
//{
//	//int ary[10][10]
//	int villages;
//	cin >> villages;
//	//int completed[], n, cost = 0;
//	vector <int> completed(villages);
//	int cost = 0;
//	vector <vector <int>> ary;
//
//	takeInput(ary, completed, cost, villages);
//
//	cout << "\n\nThe Path is:\n";
//	mincost(0, ary, completed, cost, villages); //passing 0 because starting vertex
//
//	cout << "\n\nMinimum cost is " << cost;
//
//	return 0;
//}


// CPP program to implement traveling salesman 
// problem using naive approach. 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
//#define V 4 

// implementation of traveling Salesman Problem 
int travllingSalesmanProblem(vector <vector <int>>& graph, int s, int v)
{
	// store all vertex apart from source vertex 
	vector<int> vertex;
	vector <int> path;
	
	for (int i = 0; i < v; i++)
	if (i != s)
		vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle. 
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost) 
		int current_pathweight = 0;

		// compute current path weight 
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum 
		min_path = min(min_path, current_pathweight);
		
		if (min(min_path, current_pathweight) == current_pathweight) {
			path.push_back(graph[k][s]);
		}
		

	} while (next_permutation(vertex.begin(), vertex.end()));
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
	return min_path;
}

// driver program to test above function 
int main() {
	// matrix representation of graph 

	int v;
	cin >> v;
	vector <vector <int>> graph(v);
	for (int i = 0; i < v; i++) {
		graph[i].resize(v);
	}
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> graph[i][j];
		}
	}

	
	int s = 0;
	cout << travllingSalesmanProblem(graph, s, v) << endl;
	return 0;
}