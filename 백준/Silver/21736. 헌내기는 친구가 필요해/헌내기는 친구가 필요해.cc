#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m, cnt;
char camp[601][601];
int chk[601][601];
pii i_pos;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
void bfs() {
	queue<pii> q;
	q.push(i_pos);
	chk[i_pos.first][i_pos.second] = 1;

	while (!q.empty()) {
		pii cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			pii nxt = { cur.first + dy[i], cur.second + dx[i] };

			if (nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= m) continue;
			if (camp[nxt.first][nxt.second] == 'X') continue;
			if (chk[nxt.first][nxt.second]) continue;
			if (camp[nxt.first][nxt.second] == 'P') cnt++;

			q.push(nxt);
			chk[nxt.first][nxt.second] = 1;
		}
	}
}
int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> camp[i][j];

			if (camp[i][j] == 'I') i_pos = { i,j };
		}
	}
	bfs();

	if (!cnt) cout << "TT";
	else cout << cnt;
}