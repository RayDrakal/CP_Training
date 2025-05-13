#include <iostream>

using namespace std;

int x1, x2, y1, y2;
int n;

bool check(int x, int y, int r, int p) {
	return ((p - 1) ? ((x - x2) * (x - x2) + (y - y2) * (y - y2) < (r*r)) : ((x - x1) * (x - x1) + (y - y1) * (y - y1) < (r * r)));
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			ans += check(x, y, r, 1) ^ check(x, y, r, 2);
		}
		cout << ans << '\n';
	}
}