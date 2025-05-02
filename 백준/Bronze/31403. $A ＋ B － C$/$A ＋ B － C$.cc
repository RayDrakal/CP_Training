#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;


int main() {
	FASTIO;
	string a, b, c;
	cin >> a >> b >> c;
	cout << stoi(a) + stoi(b) - stoi(c) << '\n';
	cout << stoi(a + b) - stoi(c);
}