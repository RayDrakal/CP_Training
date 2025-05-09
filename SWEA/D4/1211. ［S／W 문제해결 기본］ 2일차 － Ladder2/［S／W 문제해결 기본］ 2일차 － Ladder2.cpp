#include<iostream>

using namespace std;
int mp[101][101];
int dx[] = { 1,0,0 };
int dy[] = { 0,-1,1 };
int main() {
	int test_case, T, ans = 0;
	for (test_case = 1; test_case < 11; test_case++) {
		cin >> T;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++)
				cin >> mp[i][j];
		}
		int minCnt = 10001;
		for (int j = 0; j < 100; j++) {
			if (!mp[0][j]) continue;
			int x = 0, y = j, dir = 0, len = 1;
			while (x < 100) {
				int cnt = 0, key = 0;
				for (int i = 0; i < 3; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx>99 || ny < 0 || ny>99) continue;
					if (mp[nx][ny]) {
						cnt++;
						key += i;
					}
				}
				if (cnt == 2 && key < 3) {
					if (!dir) dir = key;
					else dir = 0;
				}
				if (x == 99) break;
				x += dx[dir]; y += dy[dir];
				len++;
			}
			if (minCnt >= len) {
				minCnt = len;
				ans = j;
			}
		}
		cout << "#" << T << ' ' << ans << '\n';
	}
}