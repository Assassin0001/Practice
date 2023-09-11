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

void helper(vector<vector<int>>& matrix, vector<int> &ans) {
	int m = matrix.size(), n = matrix[0].size();
	if (m <= 0 || n <= 0)
		return;
	int rows = 0, rowsend = m - 1;
	int cols = 0, colsend = n - 1;

	while (rows <= rowsend && cols <= colsend)
	{
		// right
		for (int i = cols; i <= colsend; i++)
			ans.push_back(matrix[rows][i]);
		rows++;

		//  down
		for (int i = rows; i <= rowsend; i++)
			ans.push_back(matrix[i][colsend]);
		colsend--;

		if (rows > rowsend)
			break;
		//  left
		for (int i = colsend; i >= cols; i--)
			ans.push_back(matrix[rowsend][i]);
		rowsend--;

		if (cols > colsend)
			break;
		//  up
		for (int i = rowsend; i >= rows; i--)
			ans.push_back(matrix[i][cols]);
		cols++;
	}
	reverse(ans.begin(), ans.end());
	return;
}

int main() {
	//make input output fast
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1; //cin >> t;
	while (t--) {
		read(n); read(m);
		//Reading Input
		vector<vector<int>> matrix;
		for (int row = 0; row < n; row++) {
			vector<int> temp;
			for (int col = 0; col < m; col++) {
				read(x);
				temp.push_back(x);
			}
			matrix.push_back(temp);
		}

		vector<int> ans;
		helper(matrix, ans);
		for (auto it : ans) cout << it << " ";
	}
	return 0;
}
