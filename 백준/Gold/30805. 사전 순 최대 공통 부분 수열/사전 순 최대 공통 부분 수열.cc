#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
vector<int> answer;
vector<pii> a, b;
bool cmp(pii a, pii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
int main() {
	FASTIO;
	cin >> n;
	a.resize(n);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		a[i] = { x,i };
	}
	cin >> m;
	b.resize(m);
	for (int i = 0, x; i < m; i++) {
		cin >> x;
		b[i] = { x,i };
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	int i_a = 0, i_b = 0, lim_a = 0, lim_b = 0;
	while (i_a < n && i_b < m) {
		if (a[i_a].first == b[i_b].first) {
			if (lim_a > a[i_a].second) i_a++;
			else if (lim_b > b[i_b].second) i_b++;
			else {
				lim_a = a[i_a].second;
				lim_b = b[i_b].second;
				answer.push_back(a[i_a].first);
				i_a++;
				i_b++;
			}
		}
		else if (a[i_a].first > b[i_b].first) i_a++;
		else i_b++;
	}
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';
}