#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define PB push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define f first
#define s second
#define read(x) ll x;cin>>x
#define show(x) cout<<x<<endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	read(N); read(M);
	vector<int> days(M);
	for (int i = 0; i < M; i++) {
		cin >> days[i];
	}
	sort(days.begin(), days.end());
	int j = 0;
	for (int i = 1; i <= N; i++) {
		if (i > days[j]) {j++;}
		cout << days[j] - i << endl;
	}
}

int main() {
	fast_io;
	int t; //cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}