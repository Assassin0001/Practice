#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a == 0)
		return b;

	if (b == 0)
		return a;

	while (a != b)
	{
		if (a >= b)
			a = a - b;
		else
			b = b - a;
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int min =INT_MAX;
		for (int x = a; x <= b; x++) {
			long long gc = gcd(b, x);
			long long int lc = (a * x) /gcd(a, x);
			long long int temp = lc - gc;
			if (temp < min) min = temp;
		}
		cout << min << endl;
	}
	return 0;
}
