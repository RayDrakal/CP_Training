#include <string>
#include <vector>

using namespace std;
int dp[15];
int fuc(int x) {
    if(x <= 1) return dp[x] = 1;
    int& ret = dp[x];
    if(ret != 0) return ret;
    for(int i = 1; i <= x; i++) 
        ret += fuc(x - i) * fuc(i - 1);
    return ret;
}
int solution(int n) {
    int answer = 0;
    answer = fuc(n);
    return answer;
}