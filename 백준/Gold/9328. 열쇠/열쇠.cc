#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;
struct Coords { int r, c; };
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int T, h, w, cnt, chk[101][101];
char buil[101][101];
map<char, int> keys;
vector<Coords> entry;
void pushEntries() {
	for (int col = 0; col < w; col++) {
		if (buil[0][col] != '*')
			entry.push_back({ 0,col });
	}
	for (int row = 1; row < h; row++) {
		if (buil[row][w - 1] != '*')
			entry.push_back({ row,w - 1 });
	}
	for (int col = w - 2; col >= 0; col--) {
		if (buil[h - 1][col] != '*')
			entry.push_back({ h - 1,col });
	}
	for (int row = 1; row < h - 1; row++) {
		if (buil[row][0] != '*')
			entry.push_back({ row,0 });
	}
}
int bfs() {
	int nu = 0;
	memset(chk, 0, sizeof(chk));
	queue<Coords> q;
	for (auto e : entry) {
		if ('A' <= buil[e.r][e.c] && buil[e.r][e.c] <= 'Z') {
			if (keys[buil[e.r][e.c] - 'A' + 'a']) buil[e.r][e.c] = '.';
			else continue;
		}
		if ('a' <= buil[e.r][e.c] && buil[e.r][e.c] <= 'z') {
			keys[buil[e.r][e.c]] = 1;
		}
		q.push({ e.r,e.c });
		chk[e.r][e.c] = 1;
		if (buil[e.r][e.c] == '$') buil[e.r][e.c] = '.', cnt++;
	}

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (0 > nr || nr >= h || 0 > nc || nc >= w) continue;
			if (buil[nr][nc] == '*' || chk[nr][nc]) continue;
			if ('A' <= buil[nr][nc] && buil[nr][nc] <= 'Z') {
				char key = buil[nr][nc] - 'A' + 'a';
				if (!keys[key]) continue;
				nu = 1;
			}

			if (buil[nr][nc] == '$') cnt++;
			if ('a' <= buil[nr][nc] && buil[nr][nc] <= 'z') {
				keys[buil[nr][nc]] = 1;
				nu = 1;
			}

			buil[nr][nc] = '.';
			chk[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
	return nu;
}
int main() {
	FASTIO;
	cin >> T;
	while (T--) {
		keys.clear();
		entry.clear();
		cnt = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> buil[i][j];
			}
		}

		string keyp;
		cin >> keyp;

		for (auto k : keyp) keys[k] = 1;

		pushEntries();
		while (bfs());
		cout << cnt << '\n';
	}
}