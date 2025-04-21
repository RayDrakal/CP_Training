#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
string s;
int main() {
	FASTIO;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
	if (s.find("d2") != string::npos) cout << "D2";
	else cout << "unrated";
}