#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	if (max(b, c) > 0) {
		int flag1 = b - max(c, 0);
		int flag2 = c - max(b , 0);
		if (flag1 == 0 || flag1 == 1 || flag2 == 0 || flag2 == 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		if (a == 0 || d == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
