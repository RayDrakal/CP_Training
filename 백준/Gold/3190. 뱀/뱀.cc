#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct pos {
	int x, y;
};
int dir = 1;
pos np[] = { {0,-1},{1,0},{0,1},{-1,0} };
int mapp[101][101];
int n, k, l, ans;
int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		mapp[a][b] = 2;
	}
	cin >> l;
	queue<pair<int, char>> time;
	for (int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		time.push({ x,c });
	}

	mapp[1][1] = 1;
	deque<pii> dq;
	dq.push_back({ 1,1 });

	while (1) {
		ans++;
		int ny = dq.back().first + np[dir].y;
		int nx = dq.back().second + np[dir].x;
		if (ny <= 0 || ny > n || nx <= 0 || nx > n || mapp[ny][nx] == 1)
			break;
		if (mapp[ny][nx] != 2) {
			mapp[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}
		mapp[ny][nx] = 1;
		dq.push_back({ ny,nx });

		if (ans == time.front().first) {
			char ch = time.front().second;
			if (ch == 'D') dir = (dir + 1) % 4;
			else dir = (dir - 1 + 4) % 4;
			time.pop();
		}
	}
	cout << ans;
}