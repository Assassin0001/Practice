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

	int t = 1; //cin >> t;
	while (t--) {
		read(n);
		//find divisors from 1-9
		unordered_set<ll> div;
		for (int i = 1; i < 10; i++) { if (n % i == 0) div.insert(n / i); }
		//Iterate till n
		cout << 1;
		for (int i = 1; i <= n; ++i)
		{
			ll minele = LONG_MAX;
			for (auto it : div) {
				if (i % it == 0) minele = min(minele, (n / it));
			}
			if (minele != LONG_MAX) cout << minele;
			else cout << "-";
		}
	}
	return 0;
}
