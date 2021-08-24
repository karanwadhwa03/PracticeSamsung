#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	A[0] = A[n + 1] = 1;
	int dp[n + 2][n + 2] = {0};
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i < n + 2 - len; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				if (i == 1 && j == n) {
					dp[i][j] = max(dp[i][j],  A[k] + dp[i][k - 1] + dp[k + 1][j]);
				}
				else
					dp[i][j] = max(dp[i][j], A[i - 1] * A[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
			}
		}
	}
	cout << dp[1][n] << endl;


}
