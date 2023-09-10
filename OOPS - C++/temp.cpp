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
		map<string, int> mpp;
        mpp.insert({"tourist",3858});
        mpp.insert({"ksun48" ,3679});
        mpp.insert({"Benq" ,3658});
        mpp.insert({"apiad" ,3638});
        mpp.insert({"Um_nik" ,3648});
        mpp.insert({"Stonefeang", 3630});
        mpp.insert({"ecnerwala", 3613});
        mpp.insert({"mnbvmar" ,3555});
        mpp.insert({"newbiedmy" ,3516});
        mpp.insert({"semiexp" ,3481});
			
		string temp; cin >> temp;
		cout << mpp[temp];
	}
	return 0;
}
