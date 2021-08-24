#include<iostream>
using namespace std;
#define SIZE 1000005
int color[SIZE] = {0};

struct Node {
	int data;
	Node *next;
};

Node *A[SIZE];

void push(int a, int b) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = b;
	temp->next = A[a];
	A[a] = temp;
}

bool dfs(int node, int col) {
	if (color[node] != 0 && color[node] != col ) {
		return false;
	}
	color[node] = col;
	Node *temp = A[node];
	while (temp) {
		int data = temp->data;
		if (color[data] == 0) {
			if (col == 1) {
				if (!dfs(data, 2))
					return false;
			}
			else {
				if (!dfs(data, 1))
					return false;
			}
		}
		else if (color[data] == col)
			return false;


		temp = temp->next;
	}

	return true;


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

	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			if (!dfs(i, 1)) {
				cout << "IMPOSSIBLE";
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << color[i] << " ";


}