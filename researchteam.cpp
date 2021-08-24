#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000
int l = 0, r = 0;
int visited[SIZE][SIZE] = {0};
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, -1, 1};




struct Node {
	int x, y, val;
};
Node Queue[1000];

void push(int x, int y, int val) {
	Queue[r++] = {x, y, val};
}

void pop() {
	l++;
}

Node top() {
	return Queue[l];
}

bool isempty() {
	return l == r;
}

void init() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			visited[i][j] = 0;
	l = 0;
	r = 0;
}

bool isValid(int x, int y, int n, int A[SIZE][SIZE]) {
	if (x >= 0 && x < n && y >= 0 && y < n && A[x][y] != 0 && visited[x][y] == 0)
		return true;
	return false;
}

void bfs(int x, int y, int n, int A[SIZE][SIZE]) {
	push(x, y, 0);
	while (!isempty()) {
		Node temp = top();
		pop();
		int xx = temp.x;
		int yy = temp.y;
		int value = temp.val;
		for (int i = 0; i < 4; i++) {
			if (isValid(xx + X[i], yy + Y[i], n, A)) {

				visited[xx + X[i]][yy + Y[i]] = value + 1;
				push(xx + X[i], yy + Y[i], value + 1);
			}
		}
	}
}





int main() {
	int n, k;
	cin >> n >> k;
	int location[k][2];
	for (int i = 0; i < k; i++) {
		cin >> location[i][0] >> location[i][1];
	}
	int A[SIZE][SIZE];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		init();
	// 		int temp = 0;
	// 		if (A[i][j] == 1) {
	// 			visited[i][j] = true;
	// 			bfs(i, j, n, A);

	// 		}
	// 	}
	// }
	//bfs(0, 0, n, A);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}



}