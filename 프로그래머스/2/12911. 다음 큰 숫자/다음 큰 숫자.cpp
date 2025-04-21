#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    if((n & (-n)) == n) answer = n * 2;
    else if(((n + 1) & (-(n + 1))) == n + 1) answer = n + ((n + 1) / 2);
    else {
        bitset<32> bs(n);
        string s = bs.to_string();
        next_permutation(s.begin(), s.end());
        for(int i = s.length() - 1; i >= 0; i--) {
            int e = 1;
            for(int j = 0; j < s.length() - i - 1; j++) e *= 2;
            if(s[i] == '1') answer += e;
        }
    }
    return answer;
}