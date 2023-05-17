#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unordered_map<ll, ll> ml;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

int main() {
	//make input output fast
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 3) {
			ll a, b, c;
			cin >> a >> b >> c;
			if ((2 * b) == (a + c)) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else {
			vl v(n);
			for (int i = 0; i < n; i++) {
				cin >> v[i];
			}

			vl lSum;
			ll sum = 0;
			for (int i = 1; i < n; i++) {
				sum += v[i] - v[i - 1];
				lSum.PB(sum);
			}

			sum = 0;
			vl rSum;
			for (int i = n - 1; i > 0; i--) {
				sum += v[i] - v[i - 1];
				rSum.PB(sum);
			}

			reverse(rSum.begin(), rSum.end());
			bool ans = false;
			for (int i = 0; i < n - 1; i++) {
				if (rSum[i] == lSum[i]) ans = true;
			}

			if (ans) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}