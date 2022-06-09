#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void solve() {
    int a = 3, b = 5;
    swap(&a, &b);
    printf("%d %d", a, b);
}
int main() {
	solve();
	return 0;
}