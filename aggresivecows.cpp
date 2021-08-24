#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long int

void bublesort(ll A[], ll n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
			}
		}
	}
}

int find(ll A[], int mid , ll n) {
	int count = 1;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += A[i] - A[i - 1];
		if (sum >= mid) {
			count++;
			sum = 0;
		}
	}
	//cout << "COUNT" << count << endl;
	return count;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll A[n + 1];
		for (ll i = 0; i < n; i++)
			cin >> A[i];
		sort(A, A + n);
		//bublesort(A, n);

		ll l = 0;
		ll r = A[n - 1] - A[0];
		int pos;

		//cout << l << " " << r << endl;
		while (l <= r) {
			int mid = (l + r ) / 2;
			int possible = find(A, mid, n);
			//cout << "possible" << possible << endl;
			if (k <= possible) {
				l = mid + 1;
				pos = mid;
			}
			else {
				r = mid - 1 ;
			}
		}
		cout << pos << endl;





	}



}