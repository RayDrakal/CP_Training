#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
typedef long long ll;
struct pos {
	int x, y, s;
};
int n, m, k;
char wd[1001][1001];
int dist[1001][1001][11];
int dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
int main() {
	FASTIO;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> wd[i][j];
	queue<pos> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		int cx = cur.x, cy = cur.y, cs = cur.s;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (wd[nx][ny] == '1' && cs >= k) continue;
			if (wd[nx][ny] == '1' && cs < k && !dist[nx][ny][cs + 1]) {
				dist[nx][ny][cs + 1] = dist[cx][cy][cs] + 1;
				q.push({ nx,ny,cs + 1 });
			}
			if (wd[nx][ny] == '0' && !dist[nx][ny][cs]) {
				dist[nx][ny][cs] = dist[cx][cy][cs] + 1;
				q.push({ nx,ny,cs });
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= k; i++) {
		if (dist[n - 1][m - 1][i]) ans = min(ans, dist[n - 1][m - 1][i]);
	}
	if (ans == INF) ans = -1;
	cout << ans;
}