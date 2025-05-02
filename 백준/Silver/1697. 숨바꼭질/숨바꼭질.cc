#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int chk[100001];
queue<pair<int, int>> q;
int n, k;
int mv[] = { -1,1 };
void bfs() {
	q.push({ n,0 });
	chk[n] = 1;
	while (!q.empty()) {
		int v = q.front().first, t = q.front().second;
		q.pop();
		if (v == k) {
			cout << t;
			break;
		}
		for (int i = 0; i < 3; i++) {
			int nxt = v + (i < 2 ? mv[i] : v);
			if (nxt < 0 || nxt>100000) continue;
			if (!chk[nxt]) {
				chk[nxt] = 1;
				q.push({ nxt,t + 1 });
			}
		}
	}
}
int main() {
	FASTIO;
	cin >> n >> k;
	bfs();
}