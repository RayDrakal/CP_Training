#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
const int nmax = 40001, imax = 16;
int N;
vector<pair<int, int>> adj[nmax];
bool visited[nmax];
int length[nmax][imax], parent[nmax][imax], depth[nmax];
void dfs(int start, int n) {
	visited[start] = true;
	depth[start] = n;
	for (int i = 0; i < adj[start].size(); i++) {
		int nxt = adj[start][i].first, weight = adj[start][i].second;
		if (visited[nxt]) continue;
		parent[nxt][0] = start;
		length[nxt][0] = weight;
		dfs(nxt, n + 1);
	}
}
void connect() {
	for (int p = 1; p < imax; p++) {
		for (int cur = 1; cur <= N; cur++) {
			int prevp = parent[cur][p - 1];
			parent[cur][p] = parent[prevp][p - 1];
			if (parent[prevp][p - 1] == 0) continue;
			int prevl = length[cur][p - 1];
			length[cur][p] = prevl + length[prevp][p - 1];
		}
	}
}
int LCA(int xnode, int ynode) {
	if (depth[xnode] > depth[ynode]) {
		int tmp = xnode;
		xnode = ynode;
		ynode = tmp;
	}
	int lensum = 0;
	for (int i = imax - 1; i >= 0; i--) {
		int jump = 1 << i;
		if (depth[ynode] - depth[xnode] >= jump) {
			lensum += length[ynode][i];
			ynode = parent[ynode][i];
		}
	}
	if (xnode == ynode) return lensum;
	for (int i = imax - 1; i >= 0; i--) {
		if (parent[xnode][i] == parent[ynode][i]) continue;
		lensum += length[xnode][i];
		xnode = parent[xnode][i];
		lensum += length[ynode][i];
		ynode = parent[ynode][i];
	}
	lensum += length[xnode][0] + length[ynode][0];
	return lensum;
}
int main() {
	FASTIO;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({ e,w });
		adj[e].push_back({ s,w });
	}
	dfs(1, 0);
	connect();
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << LCA(x, y) << '\n';
	}
}