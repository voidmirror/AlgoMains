#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int n;
vector < vector<int> > g;
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v) {
	cl[v] = 1;
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0) {
			p[to] = v;
			if (dfs(to))  return true;
		}
		else if (cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

int main() {
	//... ������ ����� ...
	int v, e, a, b, check = 1;
	cin >> v >> e;
	g.resize(v);

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		sort(g[a].begin(), g[a].end());
	}

	p.assign(v, -1);
	cl.assign(v, 0);
	cycle_st = -1;

	int k = 0;

	while (!check) {
		for (; k < v; ++k)
		if (dfs(k))
			break;

		if (cycle_st == -1)
			//puts("Acyclic");
			cout << "No cycles";
		else {
			//puts("Cyclic");
			cout << "Cycle:" << endl;
			vector<int> cycle;
			cycle.push_back(cycle_st);
			for (int v = cycle_end; v != cycle_st; v = p[v])
				cycle.push_back(v);
			cycle.push_back(cycle_st);
			reverse(cycle.begin(), cycle.end());
			if (cycle[cycle.size() - 2] < cycle[0]) {
				cout << cycle[cycle.size() - 2] << " ";
				for (int i = 0; i < cycle.size() - 2; ++i)
					cout << cycle[i] << " ";
			}
			else
			for (int i = 0; i < cycle.size() - 1; ++i)
				cout << cycle[i] << " ";
		}
	}
}

//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
////int n;
//vector < vector<int> > g;
//vector<char> cl;
//vector<int> p;
//int cycle_st, cycle_end;
//
//bool dfs(int v) {
//	cl[v] = 1;
//	for (size_t i = 0; i<g[v].size(); ++i) {
//		int to = g[v][i];
//		if (cl[to] == 0) {
//			p[to] = v;
//			if (dfs(to))  return true;
//		}
//		else if (cl[to] == 1) {
//			cycle_end = v;
//			cycle_st = to;
//			return true;
//		}
//	}
//	cl[v] = 2;
//	return false;
//}
//
//int main() {
//	//... ������ ����� ...
//	int v, e, a, b;
//	cin >> v >> e;
//	g.resize(v);
//
//	for (int i = 0; i < e; i++) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		sort(g[a].begin(), g[a].end());
//	}
//
//	p.assign(v, -1);
//	cl.assign(v, 0);
//	cycle_st = -1;
//
//	for (int i = 0; i<v; ++i)
//	if (dfs(i))
//		break;
//
//	if (cycle_st == -1)
//		//puts("Acyclic");
//		cout << "No cycles";
//	else {
//		//puts("Cyclic");
//		cout << "Cycle:" << endl;
//		vector<int> cycle;
//		cycle.push_back(cycle_st);
//		for (int v = cycle_end; v != cycle_st; v = p[v])
//			cycle.push_back(v);
//		cycle.push_back(cycle_st);
//		reverse(cycle.begin(), cycle.end());
//		if (cycle[cycle.size() - 2] < cycle[0]) {
//			cout << cycle[cycle.size() - 2] << " ";
//			for (int i = 0; i<cycle.size() - 2; ++i)
//				cout << cycle[i] << " ";
//		}
//		else
//		for (int i = 0; i<cycle.size() - 1; ++i)
//			cout << cycle[i] << " ";
//	}
//}