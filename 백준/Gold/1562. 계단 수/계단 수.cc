#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int n;
const int mod = 1000000000;
ll ans, dp[101][10][1024];
int main()
{
  FASTIO;
  cin >> n;
  for(int i=1;i<10;i++) dp[1][i][1 << i]=1;
  for(int i=2;i<=n;i++) {
    for(int j=0;j<10;j++) {
      for(int k=1;k<1024;k++) {
        if (j==0) {
          dp[i][0][k | 1 << 0] += dp[i-1][1][k] % mod;
        }
        else if (j==9) {
          dp[i][9][k | 1 << 9] += dp[i-1][8][k] % mod;
        }
        else {
          dp[i][j][k | 1 << j] += dp[i-1][j-1][k] % mod;
          dp[i][j][k | 1 << j] += dp[i-1][j+1][k] % mod;
        }
      }
    }
  }
  for(int i=0;i<10;i++) {
    ans = (ans + dp[n][i][1023]) % mod;
  }
  cout << ans;
}