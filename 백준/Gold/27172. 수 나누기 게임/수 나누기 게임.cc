#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int N;
vector<int> player;
int scores[1000005], cards[1000005];
int main() {
	FASTIO;
	cin >> N;
	player.resize(N);
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		player[i] = tmp;
		cards[tmp] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = player[i]; j < 1000001; j += player[i]) {
			if (cards[j]) {
				scores[player[i]]++;
				scores[j]--;
			}
		}
	}
	for (auto x : player) cout << scores[x] << ' ';
}