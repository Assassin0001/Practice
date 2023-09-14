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
#define PII pair<int, int>

//Practice Comparators
//Sorted ascending by first element and ascending by second element
class Comp {
public:
	bool operator()(PII below, PII above)
	{
		if (below.first > above.first) {
			return true;
		}
		else if (below.first == above.first
		         && below.second > above.second) {
			return true;
		}

		return false;
	}
};

int main() {
	//make input output fast
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		read(n);
		string s; cin >> s;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') { idx = i; break; }
		}

		string ans;
		if (idx == -1 || idx > n - 3) ans = s;
		else {
			for (int i = 0; i < n; i++) {
				if (i == idx) ans.push_back('1');
				else ans.push_back('0');
			}
		}
		cout << ans << endl;
	}
	return 0;
}
