#include<iostream>
using namespace std;
int A[200][200];
bool visited[200][200] = {false};
int l = 0, r = 0;


struct Node {
	int x, y, pow;
};

Node queueArray[200];

void push(int x, int y, int pow) {
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
		int n, m, x, y, pow;
		cin >> n >> m >> x >> y >> pow;
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++) {
				A[i][j] = 0;
				visited[i][j] = false;
			}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> A[i][j];
		}

		if (pow == 0 || A[x][y] == 0) {
			cout << 0 << endl;
			continue;
		}

		push(x, y, pow);
		visited[x][y] = true;
		while (!empty()) {
			Node front = top();
			pop();
			int sx = front.x;
			int sy = front.y;
			int sp = front.pow;
			cout << sx << " " << sy << " " << sp << endl;
			if ( sp == 0) {
				continue;
			}
			cout << A[sx][sy] << endl;

			if (A[sx][sy] == 1) {

				if ( (sx + 1) < n && (A[sx + 1][sy] == 3 || A[sx + 1][sy] == 6 || A[sx + 1][sy] == 7 || A[sx + 1][sy] == 1)) {
					if (visited[sx + 1][sy] == false) {
						push(sx + 1, sy, sp - 1);
						visited[sx + 1][sy] = true;
					}
				}

				if (((sy - 1) >= 0) && (A[sx][sy - 1] == 2 || A[sx][sy - 1] == 5 || A[sx][sy - 1] == 6 || A[sx][sy - 1] == 1)) {
					if (visited[sx][sy - 1] == false) {
						push(sx, sy - 1, sp - 1);
						visited[sx][sy - 1] = true;
					}

				}

				if (((sx - 1) >= 0) && (A[sx - 1][sy] == 1 || A[sx - 1][sy] == 3 || A[sx - 1][sy] == 4 || A[sx - 1][sy] == 5 )) {
					if (visited[sx - 1][sy] == false) {
						push(sx - 1, sy, sp - 1);
						visited[sx - 1][sy] = true;
					}
				}

				if ( (sy + 1) < m && (A[sx][sy + 1] == 2 || A[sx][sy + 1] == 4 || A[sx][sy + 1] == 7 || A[sx][sy + 1] == 1)) {
					if (visited[sx][sy + 1] == false) {
						push(sx, sy + 1, sp - 1);
						visited[sx][sy + 1] = true;
					}
				}
			}

			if (A[sx][sy] == 2) {

				if (((sy - 1) >= 0) && (A[sx][sy - 1] == 2 || A[sx][sy - 1] == 5 || A[sx][sy - 1] == 6 || A[sx][sy - 1] == 1)) {
					if (visited[sx][sy - 1] == false) {
						push(sx, sy - 1, sp - 1);
						visited[sx][sy - 1] = true;
					}

				}

				if ( (sy + 1) < m && (A[sx][sy + 1] == 2 || A[sx][sy + 1] == 4 || A[sx][sy + 1] == 7 || A[sx][sy + 1] == 1)) {
					if (visited[sx][sy + 1] == false) {
						push(sx, sy + 1, sp - 1);
						visited[sx][sy + 1] = true;
					}
				}
			}

			if (A[sx][sy] == 3) {
				cout << "HELEO" << " " << A[sx + 1][sy] << endl;
				if ( (sx + 1) < n && (A[sx + 1][sy] == 3 || A[sx + 1][sy] == 6 || A[sx + 1][sy] == 7 || A[sx + 1][sy] == 1)) {
					if (visited[sx + 1][sy] == false) {
						cout << "KSJKS";
						push(sx + 1, sy, sp - 1);
						visited[sx + 1][sy] = true;
					}
				}

				if (((sx - 1) >= 0) && (A[sx - 1][sy] == 1 || A[sx - 1][sy] == 3 || A[sx - 1][sy] == 4 || A[sx - 1][sy] == 5 )) {
					if (visited[sx - 1][sy] == false) {
						push(sx - 1, sy, sp - 1);
						visited[sx - 1][sy] = true;
					}
				}

			}

			if (A[sx][sy] == 4) {

				if ( (sx + 1) < n && (A[sx + 1][sy] == 3 || A[sx + 1][sy] == 6 || A[sx + 1][sy] == 7 || A[sx + 1][sy] == 1)) {
					if (visited[sx + 1][sy] == false) {
						push(sx + 1, sy, sp - 1);
						visited[sx + 1][sy] = true;
					}
				}

				if (((sy - 1) >= 0) && (A[sx][sy - 1] == 2 || A[sx][sy - 1] == 5 || A[sx][sy - 1] == 6 || A[sx][sy - 1] == 1)) {
					if (visited[sx][sy - 1] == false) {
						push(sx, sy - 1, sp - 1);
						visited[sx][sy - 1] = true;
					}

				}

			}

			if (A[sx][sy] == 5) {

				if ( (sx + 1) < n && (A[sx + 1][sy] == 3 || A[sx + 1][sy] == 6 || A[sx + 1][sy] == 7 || A[sx + 1][sy] == 1)) {
					if (visited[sx + 1][sy] == false) {
						push(sx + 1, sy, sp - 1);
						visited[sx + 1][sy] = true;
					}
				}

				if ( (sy + 1) < m && (A[sx][sy + 1] == 2 || A[sx][sy + 1] == 4 || A[sx][sy + 1] == 7 || A[sx][sy + 1] == 1)) {
					if (visited[sx][sy + 1] == false) {
						push(sx, sy + 1, sp - 1);
						visited[sx][sy + 1] = true;
					}
				}
			}

			if (A[sx][sy] == 6) {

				if (((sx - 1) >= 0) && (A[sx - 1][sy] == 1 || A[sx - 1][sy] == 3 || A[sx - 1][sy] == 4 || A[sx - 1][sy] == 5 )) {
					if (visited[sx - 1][sy] == false) {
						push(sx - 1, sy, sp - 1);
						visited[sx - 1][sy] = true;
					}
				}

				if ( (sy + 1) < m && (A[sx][sy + 1] == 2 || A[sx][sy + 1] == 4 || A[sx][sy + 1] == 7 || A[sx][sy + 1] == 1)) {
					if (visited[sx][sy + 1] == false) {
						push(sx, sy + 1, sp - 1);
						visited[sx][sy + 1] = true;
					}
				}
			}

			if (A[sx][sy] == 7) {


				if (((sy - 1) >= 0) && (A[sx][sy - 1] == 2 || A[sx][sy - 1] == 5 || A[sx][sy - 1] == 6 || A[sx][sy - 1] == 1)) {
					if (visited[sx][sy - 1] == false) {
						push(sx, sy - 1, sp - 1);
						visited[sx][sy - 1] = true;
					}

				}

				if (((sx - 1) >= 0) && (A[sx - 1][sy] == 1 || A[sx - 1][sy] == 3 || A[sx - 1][sy] == 4 || A[sx - 1][sy] == 5 )) {
					if (visited[sx - 1][sy] == false) {
						push(sx - 1, sy, sp - 1);
						visited[sx - 1][sy] = true;
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
		cout << cnt << "\n";














	}

}



