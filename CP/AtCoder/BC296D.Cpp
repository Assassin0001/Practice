//M<=AB
// find a no x such that a*b >= m where m and n are given. And a,b ->[1,N].
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define INF (long long)2e+18

ll solve(ll n, ll m) {
	ll x, ans = INF;
	for (ll i = 1; i <= n; i++) {
		x = (m + i - 1) / i;
		if (x <= n) ans = min(ans, i * x);
		if (i > x) break;
	}
	if (ans == INF) return -1;
	else return ans;
}

int main() {
	ll n; cin >> n;
	ll m; cin >> m;
	cout << solve(n, m) << endl;
	return 0;
}