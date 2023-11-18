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
	read(n);
	vl months(n);
	for (int i = 0; i < n; i++) {
		cin >> months[i];
	}

	ll repDigitSum = 0;
	for (int i = 0; i < n; i++) {
		int onePlace = months[i] % 10;
		int maxRange = (11 * months[i]);
		if ((i + 1) <= 9) {
			if (months[i] >= maxRange) repDigitSum += 2;
			else if (months[i] >= i) repDigitSum += 1;
		}
		else if (i + 1 <= 99) {
			int tenPlace = months[i] / 10;
			if (tenPlace != onePlace) continue;
			else {
				if (months[i] >= maxRange) repDigitSum += 2;
				else if (months[i] >= i) repDigitSum += 1;
			}
		}
		else {
			if (months[i] == 100) repDigitSum += 1;
		}
	}
	cout << repDigitSum << endl;
}

int main() {
	fast_io;
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}