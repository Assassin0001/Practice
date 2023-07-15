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
#define read(x) ll x;cin>>x
#define show(x) cout<<x<<endl
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl

int main() {
	//make input output fast
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		string str; cin >> str;
		string rev = str;
		reverse(rev.begin(), rev.end());

		if (str == rev) yes;
		else if (n % 3 == 1) yes;
		else {
			bool flag = false;
			for (int i = 0; i < 26; i++) {

				int l = n, r = -1;

				for (int j = 0; j < n; j++) {
					if (str[j] - 'a' == i && (j % 3 == 0)) {
						l = j;
						break;
					}
				}

				for (int j = n - 1; j >= 0; j--) {
					if (str[j] - 'a' == i && (n - j - 1) % 3 == 0) {
						r = j;
						break;
					}
				}

				if (l <= r) {
					flag = true;
				}
			}
			(flag) ? yes : no;
		}

	}
	return 0;
}
