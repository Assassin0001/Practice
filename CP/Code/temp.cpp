#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, y; cin >> n >> y;
		int arr[n];
		int sumor = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sumor = sumor | arr[i];
		}
		int ans = sumor ^ y;
		if ((ans | sumor) == y)
			cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}
