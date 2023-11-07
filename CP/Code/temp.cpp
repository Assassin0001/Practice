#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define PB push_back
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define f first
#define s second
#define read(x) ll x;cin>>x
#define show(x) cout<<x<<endl
#define vl vector<long long>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void solve() {
	read(n); read(k);
	string a; cin >> a;

	unordered_map<char, int> freq;
	for (auto it : a) {	freq[it]++; }
	int disnct = 0;
	for (auto it : freq) {
		if (it.second == 1) disnct++;
	}
	int len = n - k;
	if (len % 2) {
		if (k % 2)	disnct <= k + 1 ? yes : no;
		else disnct <= k + 1 ? yes : no;
	}
	else {
		if (k % 2) disnct <= k + 1 ? yes : no;
		else disnct <= k ? yes : no;
	}
}

int main() {
	fast_io;
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}