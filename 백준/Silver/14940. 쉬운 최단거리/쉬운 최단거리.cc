#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int n, m;
struct pos { int x, y; };
int wd[1001][1001], ans[1001][1001];
void bfs(pos dest) {
	queue<pos> q;
	vector<vector<bool>> vis(n, vector<bool>(m));
	q.push(dest);
	ans[dest.x][dest.y] = 0;
	vis[dest.x][dest.y] = true;
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (wd[nx][ny] == 0) continue;
			if (vis[nx][ny]) continue;

			q.push({ nx,ny });
			ans[nx][ny] = ans[cur.x][cur.y] + 1;
			vis[nx][ny] = true;
		}
	}
}
int main() {
	pos dest;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> wd[i][j];
			if (wd[i][j] == 2) dest.x = i, dest.y = j;
		}
	}
	bfs(dest);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 0 && wd[i][j] == 1) cout << -1 << ' ';
			else cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}