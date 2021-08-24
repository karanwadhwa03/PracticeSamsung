#include<iostream>
using namespace std;
int ans = 0;

void maxCoins(int A[][5], int row, int col, int cost, bool bomb, int effect) {
	if (row < 0) {
		ans = max(ans, cost);
		return ;
	}
	for (int i = -1; i <= 1; i++) {
		if (((col + i) < 0) || ((col + i) >= 5))
			continue;
		if (A[row][col] == 1) {
			cout << row << " " << col << endl;
			if (bomb) {
				maxCoins(A, row - 1, col + i, cost + 1, bomb, effect - 1);
			}
			else {
				maxCoins(A, row - 1, col + i, cost + 1, bomb, effect);
			}
		}
		else if (A[row][col] == 0) {
			if (bomb) {
				maxCoins(A, row - 1, col + i, cost, bomb, effect - 1);
			}
			else {
				maxCoins(A, row - 1, col + i, cost, bomb, effect);
			}
		}
		else {
			if (bomb && effect >= 0) {
				maxCoins(A, row - 1, col + i, cost, bomb, effect - 1);
			}
			else {
				maxCoins(A, row - 1 - 1, col + i, cost, true, 4);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {

		int n;
		cin >> n;
		int A[n][5];
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++)
				cin >> A[i][j];
		}

		maxCoins(A, n - 1, 2, 0, false, 0);

		cout << "#" << _ << " " << ans << endl;
	}



}