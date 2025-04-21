#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999999999
using namespace std;
typedef long long ll;
int n;
string str, res;
int main() {
	FASTIO;
	cin >> n >> str;
	for (int i = 0; i < str.size(); i += n) {
		res += str[i];
	}
	cout << res;
}