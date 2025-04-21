#include <bits/stdc++.h>
#define ioscall ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
vector<pii> nods[5001], edge;
int dist1[5001], dist2[5001];
int n, e, sum, st, ed;
void rt(int dist[], int s, int n) {
	memset(dist, 1000000, 4 * (n + 1));
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[s],s });
	while (!pq.empty()) {
		int now = pq.top().second, nd = pq.top().first;
		pq.pop();
		if (dist[now] ^ nd) continue;
		for (int i = 0; i < nods[now].size(); i++) {
			int next = nods[now][i].first, nxtd = nd + nods[now][i].second;
			if (dist[next] > nxtd) {
				dist[next] = nxtd;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	ioscall;
	bool chk1 = true, chk2 = true;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		sum += c;
		nods[a].push_back({ b,c });
		nods[b].push_back({ a,c });
		edge.push_back({ a,b });
	}
	cin >> st >> ed;
	rt(dist1, st, n);
	rt(dist2, ed, n);
	int mn = INF;
	for (auto x : edge) {
		mn = min(mn, dist1[x.first] + dist2[x.second]);
		mn = min(mn, dist2[x.first] + dist1[x.second]);
	}
	cout << sum - mn << '\n';
}