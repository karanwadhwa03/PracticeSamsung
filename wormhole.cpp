#include<iostream>
using namespace std;
int ans = 99999;

int dist(int sx, int sy, int ex, int ey) {
	int ans = 0;
	ans += abs(sx - ex);
	ans += abs(sy - ey);
	return ans;
}


int wormhole(int A[][5], int n, int mask, int sx, int sy, int ex, int ey, int dis) {
	ans = min(ans, dist(sx, sy, ex, ey) + dis);
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0 ) {
			wormhole(A, n, (mask | (1 << i)), A[i][2], A[i][3], ex, ey, A[i][4] + dis + dist(sx, sy, A[i][0], A[i][1]));
			wormhole(A, n, (mask | (1 << i)), A[i][0], A[i][1], ex, ey, A[i][4] + dis + dist(sx, sy, A[i][2], A[i][3]));
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
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int A[n][5];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> A[i][j];
			}
		}
		wormhole(A, n, 0, sx, sy, ex, ey, 0);
		cout << ans << endl;



	}
}