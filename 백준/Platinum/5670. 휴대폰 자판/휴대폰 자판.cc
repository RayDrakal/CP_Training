#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int tc, ans;
struct Trie {
	Trie* ch[26];
	int cnt;
	bool end;
	Trie() {
		for (int i = 0; i < 26; i++) ch[i] = NULL;
		cnt = 0;
		end = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			end = true;
			return;
		}
		int now = *s - 'a';
		if (!ch[now]) {
			ch[now] = new Trie;
			cnt++;
		}
		ch[now]->insert(s + 1);
	}
	void find(const char* s, int k, bool root) {
		if (!*s) {
			ans += k;
			return;
		}
		int now = *s - 'a';
		if (root) ch[now]->find(s + 1, k, false);
		else {
			if (cnt == 1 && !end)ch[now]->find(s + 1, k, false);
			else ch[now]->find(s + 1, k + 1, false);
		}
	}
};
int main() {
	FASTIO;
	while (cin >> tc) {
		ans = 0;
		Trie* root = new Trie;
		vector<string> v;
		for (int i = 0; i < tc; i++) {
			string s; cin >> s;
			v.push_back(s);
			root->insert(s.c_str());
		}
		for (string s : v) {
			root->find(s.c_str(), 1, true);
		}
		cout.precision(2);
		cout << fixed;
		cout << (double)ans / v.size() << '\n';
		delete root;
	}
}