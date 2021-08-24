#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int A[n + 2];
	A[0] = A[n + 1] = 1;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	int dp[100][100] = {0};
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i < n + 2 - len; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				dp[i][j] = max(dp[i][j], A[i - 1] * A[j + 1]  + dp[i][k - 1] + dp[k + 1][j]);
			}


		}



	}

	cout << dp[1][n] << endl;


}