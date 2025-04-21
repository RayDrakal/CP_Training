#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n;
string ccc, ans;
vector<string> cd = { "aespa","baekjoon","cau","debug","edge",
"firefox","golang","haegang","iu","java","kotlin","lol","mips",
"null","os","python","query","roka","solvedac","tod","unix",
"virus","whale","xcode","yahoo","zebra" };
vector<int> cl(26);
int main() {
	FASTIO;
	for (int i = 0; i < 26; i++) cl[i] = cd[i].length();
	cin >> ccc;
	for (int i = 0; i < ccc.length();) {
		int x = ccc[i] - 97;
		int y = cl[x];
		int k = i;
		int m = ccc.length() - i;
		if (y > m) {
			cout << "ERROR!";
			return 0;
		}
		for (int j = 0; j < y; j++) {				
			if (ccc[k] != cd[x][j]) {
				cout << "ERROR!";
				return 0;
			}
			k++;
		}
		ans.push_back(ccc[i]);
		i += cl[x];
	}
	cout << "It's HG!\n";
	cout << ans;
}