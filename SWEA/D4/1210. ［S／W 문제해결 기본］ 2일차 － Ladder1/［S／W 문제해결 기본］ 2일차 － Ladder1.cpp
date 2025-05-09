#include<iostream>
#include<queue>

using namespace std;

int mp[101][101];
int btc(int x, int y) {
	while (1) {
		if (!x) return y - 1;
		if (mp[x][y - 1]) {
			while (1) {
				if (!mp[x][y - 1]) break;
				y--;
			}
		}
		else if (mp[x][y + 1]) {
			while (1) {
				if (!mp[x][y + 1]) break;
				y++;
			}
		}
		x--;
	}
}
int main() {
	int tc;
	for (int t = 0; t < 10; t++) {
		cin >> tc;
		int res;
		for (int i = 0; i < 100; i++) {
			for (int j = 1; j < 101; j++) {
				cin >> mp[i][j];
				if (mp[i][j] == 2)
					res = btc(i, j);
			}
		}
		cout << '#' << tc << ' ' << res << '\n';
	}
}