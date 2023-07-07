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

void helper(int start, vector<int>& nums, vector<int>& temp, int& ans) {
	int n = nums.size();
	if (start == n) {
		int maxi = INT_MIN;
		for (int i = 0; i < 2; i++) {
			maxi = max(maxi, temp[i]);
		}
		ans = min(ans, maxi);
		return;
	}

	for (int i = 0; i < 2; i++) {
		temp[i] += nums[start];
		helper(start + 1, nums, temp, ans);
		temp[i] -= nums[start];
	}
}

int main() {
	//make input output fast
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> nums(n);
		ll sum = 0;
		for (int i = 0; i < n; i++) { cin >> nums[i]; sum += nums[i]; }
		vector<int> temp(2, 0);
		int ans = INT_MAX;
		helper(0, nums, temp, ans);
		int diff = sum - ans;
		cout << abs((ans * ans) - (diff * diff)) << endl;
	}
	return 0;
}
