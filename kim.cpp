#include<iostream>
using namespace std;

struct Node {
	int x, y;
};

int dist(Node A, Node B) {
	int ans = 0;
	ans += abs(A.x - B.x);
	ans += abs(A.y - B.y);
	return ans;
}


int tsp(Node A[], int curr, int mask, int n) {
	if (mask == (1 << (n + 1)) - 1) {
		return dist(A[curr], A[n + 1]);
	}
	int ans = 9999;
	//cout << "MASK" << mask << endl;
	for (int i = 1; i <= n; i++) {
		//cout << "mask & (1 << i)" << (mask & (1 << i)) << endl;
		if ((mask & (1 << i)) == 0) {
			//cout << "LOOP";
			int sum = tsp(A, i, mask | (1 << i), n) + dist(A[curr], A[i]);
			ans = min(sum, ans);
		}
	}
	return ans;

}

int main() {
	int t;
	t = 10;
	for (int j = 1; j <= t; j++) {
		int n;
		cin >> n;
		Node A[n + 2];

		int sx, sy;
		cin >> sx >> sy;
		Node temp1;
		temp1.x = sx;
		temp1.y = sy;
		A[0] = temp1;

		int ex, ey;
		cin >> ex >> ey;
		Node temp2;
		temp2.x = ex;
		temp2.y = ey;
		A[n + 1] = temp2;

		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			Node temp;
			temp.x = x;
			temp.y = y;
			A[i] = temp;
		}

		cout << "# " << j << " " << tsp(A, 0, 1, n) << endl;










	}




}