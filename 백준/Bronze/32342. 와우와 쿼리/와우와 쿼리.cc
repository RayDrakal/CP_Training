#include <bits/stdc++.h>
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
using namespace std;
int n;
string s;
int main() {
    FASTIO;
    cin >> n;
    while(n--) {
        int cnt = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'W') {
                if(s[i+1] == 'O' && s[i+2] == 'W') {
                    cnt++;
                    i++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}