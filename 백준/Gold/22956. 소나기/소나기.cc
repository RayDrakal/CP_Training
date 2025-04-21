#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
int land[1001][1001], wtime[1001][1001];
pii parent[1001][1001];
int n, m, q;
pii find(int x, int y) {
	if (parent[x][y].first < 0 && parent[x][y].second < 0) return { x,y };
	return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}
void merge(int x1, int y1, int x2, int y2) {
	pii xy1 = find(x1, y1), xy2 = find(x2, y2);
	int a1 = x1, a2 = y1;
	if (land[xy1.first][xy1.second] <= land[a1][a2]) {
		a1 = xy1.first, a2 = xy1.second;
	}
	int b1 = xy2.first, b2 = xy2.second;
	if (make_pair(a1, a2) == make_pair(b1, b2)) return;
	if (land[a1][a2] > land[b1][b2]) {
		swap(a1, b1);
		swap(a2, b2);
	}
	else if (land[a1][a2] == land[b1][b2]) {
		if (wtime[a1][a2] > wtime[b1][b2]) {
			swap(a1, b1);
			swap(a2, b2);
		}
	}
	parent[a1][a2].first = -1;
	parent[a1][a2].second = -1;
	parent[b1][b2].first = a1;
	parent[b1][b2].second = a2;
	return;
}
int main() {
	FASTIO;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> land[i][j];
			parent[i][j].first = -1;
			parent[i][j].second = -1;
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y, dh;
		cin >> x >> y >> dh;
		land[x][y] -= dh;
		wtime[x][y] = i;
		if (wtime[x - 1][y] > 0) {
			merge(x, y, x - 1, y);
		}
		if (wtime[x + 1][y] > 0) {
			merge(x, y, x + 1, y);
		}
		if (wtime[x][y - 1] > 0) {
			merge(x, y, x, y - 1);
		}
		if (wtime[x][y + 1] > 0) {
			merge(x, y, x, y + 1);
		}
		pii ret = find(x, y);
		cout << ret.first << ' ' << ret.second << '\n';
	}
}