#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;

vector<int> dp (50001, 0x7f7f7f7f);
int main()
{
	int x;
	cin >> x;
	rep(i, 1, x) {
		if ((int)sqrt(i) * (int)sqrt(i) == i) dp[i] = 1;
	}
	rep(i, 1, x) {
		rep(j, 1, (int)sqrt(i)) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - (j * j)]);
		}
	}
	cout << dp[x];
}