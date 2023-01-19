#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int cnt = 0;
		bool ans = true;
		for (int i = 0; i < n - 1; i++) {
			if (arr[0] != arr[n - 1]) {
				if (arr[i] != arr[i + 1]) cnt += 2;
			}
			else {
				if (arr[i] != arr[i + 1]) {
					cnt = cnt + 1;
					ans = false;
				}
			}
		}
		if (arr[0] != arr[n - 1]) cout << cnt  << endl;
		else {
			if (ans) cout << 0 << endl;
			else cout << cnt + 1 << endl;
		}
	}
	return 0;
}
