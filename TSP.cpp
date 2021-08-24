#include<iostream>
using namespace std;
#define SIZE 100

int tsp(int A[SIZE][SIZE], int city, int mask, int n) {
	//cout << "MAD" << mask << endl;
	if (mask == ((1 << n) - 1)) {
		//	cout << "WOKR";
		return A[city][0];
	}
	int ans = 99999;
	//cout << mask << endl;
	for (int i = 0; i < n; i++) {
		//cout << "LOPP<<endl;";
		//cout << "mask & (1 << i)" << (mask & (1 << i)) << endl;
		if ((mask & (1 << i)) == 0) {
			int sum = tsp(A, i, (mask | (1 << i)), n) + A[city][i];
			//cout << sum << "SUM";
			ans = min(ans, sum);
		}
	}
	return ans;




}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int A[SIZE][SIZE];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> A[i][j];
			}
		}
		cout << tsp(A, 0, 1, n) << endl;
	}
}
