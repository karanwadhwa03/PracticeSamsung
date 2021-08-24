#include<bits/stdc++.h>
using namespace std;
#define SIZE 10000
int l = 0, r = 0;
int visited[SIZE][SIZE] = {false};

struct Node {
	int x, y, pow;
};

Node queueArray[SIZE];

void push(int x, int y, int pow) {
	//cout << x << " " << y << " " << pow << endl;
	Node temp;
	temp.x = x;
	temp.y = y;
	temp.pow = pow;
	queueArray[r++] = temp;
}

void pop() {
	l++;
}

Node top() {
	return queueArray[l];
}

bool empty() {
	return l == r;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, sx, sy, pow;
		cin >> n >> m >> sx >> sy >> pow;
		int A[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> A[i][j];
		}
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++) {
				visited[i][j] = 0;
			}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << A[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		if (A[sx][sy] == 0) {
			cout << 0 << endl;
			continue;
		}

		push(sx, sy, pow);
		visited[sx][sy] = true;
		while (!empty()) {
			Node temp = top();
			pop();
			int x = temp.x;
			int y = temp.y;
			int p = temp.pow;
			if (p == 1)
				continue;
			//cout << "A[x][y]" << A[x][y] << endl;

			if (A[x][y] == 1) {
				if ( (x + 1) < n && (A[x + 1][y] == 1 || A[x + 1][y] == 2 || A[x + 1][y] == 4 || A[x + 1][y] == 7 ) ) {
					if (visited[x + 1][y] == false) {
						push(x + 1, y, p - 1);
						visited[x + 1][y] = true;
					}

				}

				if ( (x - 1) >= 0 && (A[x - 1][y] == 1 || A[x - 1][y] == 2 || A[x - 1][y] == 5 || A[x - 1][y] == 6 ) ) {
					if (visited[x - 1][y] == false) {
						push(x - 1, y, p - 1);
						visited[x - 1][y] = true;
					}

				}

				if ((y + 1) < m && (A[x][y + 1] == 1 || A[x][y + 1] == 6 || A[x][y + 1] == 7 || A[x][y + 1] == 3)) {
					if (visited[x][y + 1] == false) {
						push(x, y + 1, p - 1);
						visited[x][y + 1] = true;
					}
				}

				if ((y - 1) >= 0 && (A[x][y - 1] == 1 || A[x][y - 1] == 5 || A[x][y - 1] == 4 || A[x][y - 1] == 3)) {
					if (visited[x][y - 1] == false) {
						push(x, y - 1, p - 1);
						visited[x][y - 1] = true;
					}
				}
			}


			if (A[x][y] == 2) {
				if ( (x + 1) < n && (A[x + 1][y] == 1 || A[x + 1][y] == 2 || A[x + 1][y] == 4 || A[x + 1][y] == 7 ) ) {
					if (visited[x + 1][y] == false) {
						push(x + 1, y, p - 1);
						visited[x + 1][y] = true;
					}

				}

				if ( (x - 1) >= 0 && (A[x - 1][y] == 1 || A[x - 1][y] == 2 || A[x - 1][y] == 5 || A[x - 1][y] == 6 ) ) {
					if (visited[x - 1][y] == false) {
						push(x - 1, y, p - 1);
						visited[x - 1][y] = true;
					}

				}

			}

			if (A[x][y] == 3) {
				if ((y + 1) < m && (A[x][y + 1] == 1 || A[x][y + 1] == 6 || A[x][y + 1] == 7 || A[x][y + 1] == 3)) {
					if (visited[x][y + 1] == false) {
						push(x, y + 1, p - 1);
						visited[x][y + 1] = true;
					}
				}

				if ((y - 1) >= 0 && (A[x][y - 1] == 1 || A[x][y - 1] == 5 || A[x][y - 1] == 4 || A[x][y - 1] == 3)) {
					if (visited[x][y - 1] == false) {
						push(x, y - 1, p - 1);
						visited[x][y - 1] = true;
					}
				}



			}

			if (A[x][y] == 4) {
				if ( (x - 1) >= 0 && (A[x - 1][y] == 1 || A[x - 1][y] == 2 || A[x - 1][y] == 5 || A[x - 1][y] == 6 ) ) {
					if (visited[x - 1][y] == false) {
						push(x - 1, y, p - 1);
						visited[x - 1][y] = true;
					}

				}

				if ((y + 1) < m && (A[x][y + 1] == 1 || A[x][y + 1] == 6 || A[x][y + 1] == 7 || A[x][y + 1] == 3)) {
					if (visited[x][y + 1] == false) {
						push(x, y + 1, p - 1);
						visited[x][y + 1] = true;
					}
				}

			}

			if (A[x][y] == 5) {
				if ((y + 1) < m && (A[x][y + 1] == 1 || A[x][y + 1] == 6 || A[x][y + 1] == 7 || A[x][y + 1] == 3)) {
					if (visited[x][y + 1] == false) {
						push(x, y + 1, p - 1);
						visited[x][y + 1] = true;
					}
				}

				if ( (x + 1) < n && (A[x + 1][y] == 1 || A[x + 1][y] == 2 || A[x + 1][y] == 4 || A[x + 1][y] == 7 ) ) {
					if (visited[x + 1][y] == false) {
						push(x + 1, y, p - 1);
						visited[x + 1][y] = true;
					}

				}
			}

			if (A[x][y] == 6) {
				if ( (x + 1) < n && (A[x + 1][y] == 1 || A[x + 1][y] == 2 || A[x + 1][y] == 4 || A[x + 1][y] == 7 ) ) {
					if (visited[x + 1][y] == false) {
						push(x + 1, y, p - 1);
						visited[x + 1][y] = true;
					}

				}
				if ((y - 1) >= 0 && (A[x][y - 1] == 1 || A[x][y - 1] == 5 || A[x][y - 1] == 4 || A[x][y - 1] == 3)) {
					if (visited[x][y - 1] == false) {
						push(x, y - 1, p - 1);
						visited[x][y - 1] = true;
					}
				}
			}

			if (A[x][y] == 7) {
				if ((y - 1) >= 0 && (A[x][y - 1] == 1 || A[x][y - 1] == 5 || A[x][y - 1] == 4 || A[x][y - 1] == 3)) {
					if (visited[x][y - 1] == false) {
						push(x, y - 1, p - 1);
						visited[x][y - 1] = true;
					}
				}

				if ( (x - 1) >= 0 && (A[x - 1][y] == 1 || A[x - 1][y] == 2 || A[x - 1][y] == 5 || A[x - 1][y] == 6 ) ) {
					if (visited[x - 1][y] == false) {
						push(x - 1, y, p - 1);
						visited[x - 1][y] = true;
					}

				}


			}



		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j])
					cnt++;
			}
		}

		cout << cnt << endl;



	}
}