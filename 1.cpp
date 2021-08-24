/* BFS
#include<bits/stdc++.h>
using namespace std;

int queueArray[1000];
int l = 0, r = 0;

void pop() {
	l++;
}
void push(int x) {
	queueArray[r++] = x;
}
int top() {
	return queueArray[l];
}
bool empty() {
	return l == r;
}

void bfs(int A[200][200], int t) {
	push(1);
	bool visited[1000] = {false};
	visited[1] = true;
	while (!empty()) {
		int temp = top();
		cout << temp << endl;
		pop();
		for (int i = 1; i <= t; i++) {
			if (A[temp][i] == 1) {
				if (visited[i] == false) {
					push(i);
					visited[i] = true;
				}
			}
		}
	}
}
int main() {
	int edges;
	cin >> edges;
	int t;
	cin >> t;
	int A[200][200];
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++)
			A[i][j] = 0;
	}
	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
	bfs(A, t);
}

*/

/* DFS
#include<iostream>
using namespace std;

void dfs(int A[200][200], int x, int t, bool visited[]) {
	cout << x << " ";
	visited[x] = true;
	for (int i = 1; i <= t; i++) {
		if (A[x][i] == 1) {
			if (visited[i] == false)
				dfs(A, i, t, visited);
		}
	}
}


int main() {
	int edges, t; // T is vertices
	cin >> edges >> t;
	int A[200][200] = {0};
	while (edges--) {
		int x, y;
		cin >> x >> y;
		A[x][y] = 1;
	}
	bool visited[200] = {false};
	dfs(A, 1, t, visited);
}
*/

/* UNDIRECTED GRAPH CYCLE
#include<iostream>
using namespace std;


struct Node {
	int data;
	Node *next;
};
Node* A[100005];

void push(int a, int b) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = b;
	temp->next = A[a];
	A[a] = temp;
}
int parent[100005] = { -1};
int start = 0, ended = 0;
bool visited[100005] = {false};
bool dfs(int n, int node, int prev) {

	visited[node] = true;

	Node *temp = A[node];
	while (temp != NULL) {
		int data = temp->data;
		if (visited[data] == false) {
			parent[data] = node;
			if (dfs(n, data, node))
				return true;
		}
		else if (data != prev) {
			start = node;
			ended = data;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void print() {
	int cnt = 2;
	for (int i = start; i != ended; i = parent[i]) {
		//cout << i << " ";
		cnt++;
	}
	cout << cnt << endl;
	cout << ended << " ";
	for (int i = start; i != ended; i = parent[i]) {
		cout << i << " ";
	}
	cout << ended << endl;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		push(a, b);
		push(b, a);
	}
	// for (int i = 1; i <= n; i++) {
	// 	Node *temp = A[i];
	// 	cout << i << "--->";
	// 	while (temp) {
	// 		cout << temp->data << " ";
	// 		temp = temp->next;
	// 	}
	// 	cout << endl;

	// }
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			if (dfs(n, i, -1)) {
				print();
				ok = true;
				break;
			}
		}
	}
	if (!ok)
		cout << "IMPOSSIBLE" << endl;


}
*/

/* DirectedGraph Cycle
#include<iostream>
using namespace std;
#define SIZE 100005
bool visited[SIZE] = {false};
bool inloop[SIZE] = {false};
int parent[SIZE] = { -1};
int start, ended;

struct Node {
	int data; Node *next;
};

Node *A[SIZE];

void push(int a, int b) {
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->data = b;
	temp->next = A[a];
	A[a] = temp;
}

void print() {
	int cnt = 2;
	for (int i = start; i != ended; i = parent[i]) {
		//cout << i << " ";
		cnt++;
	}
	cout << cnt << endl;
	//cout << ended << " ";
	int index = 0;
	int cycle[SIZE];
	for (int i = start; i != ended; i = parent[i]) {
		//cout << i << " ";
		cycle[index++] = i;
	}
	cycle[index++] = ended;
	for (int i = index - 1; i >= 0; i--)
		cout << cycle[i] << " ";
	cout << ended << endl;
	//vect.push_back(ended);

}

bool dfs(int node , int n) {
	visited[node] = true;
	inloop[node] = true;
	Node *temp = A[node];
	while (temp) {
		int data = temp->data;
		if (visited[data] == false) {
			parent[data] = node;
			if (dfs(data, n))
				return true;
		}
		else if (inloop[data]) {
			start = node;
			ended = data;
			return true;
		}
		temp = temp->next;
	}
	inloop[node] = false;
	return 0;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		push(a, b);
	}
	// for (int i = 1; i <= n; i++) {
	// 	Node *temp = A[i];
	// 	cout << i << "--->";
	// 	while (temp) {
	// 		cout << temp->data << " ";
	// 		temp = temp->next;
	// 	}
	// 	cout << endl;
	// }

	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			if (dfs(i, n)) {
				print();
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;


}
*/
/* https://www.spoj.com/problems/TOPOSORT/
#include<iostream>
using namespace std;
#define SIZE 100005
bool visited[SIZE] = {false};
bool inloop[SIZE] = {false};
int ans[SIZE];
int index = 0;

struct Node {
	int data;
	Node *next;
};
Node* A[SIZE];

void push(int a, int b) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = b;
	temp->next = A[a];
	A[a] = temp;
}

void print() {
	for (int i = index - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}

bool dfs(int node) {
	visited[node] = true;
	inloop[node] = true;
	Node *temp = A[node];
	while (temp) {
		int data = temp->data;
		if (visited[data] == false) {
			if (dfs(data))
				return true;
		}
		else if (inloop[data])
			return true;

		temp = temp->next;
	}
	inloop[node] = false;
	ans[index++] = node;
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		push(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			if (dfs(i))
			{
				cout << "Sandro fails.";
				return 0;
			}
		}
	}
	print();
}
*/

#include<iostream>
using namespace std;



int main() {


}
