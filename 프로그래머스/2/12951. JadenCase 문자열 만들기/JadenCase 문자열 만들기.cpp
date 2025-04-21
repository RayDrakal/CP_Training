#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool chk = true;
    if(s[0] >= 'a' && s[0] <= 'z') {
        answer += (s[0] - 32);
    }
    else answer += s[0];
    chk = !chk;
    for(int i=1;i<s.size();i++) {
        if(chk) {
            if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
            chk = false;
        }
        else
            if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        if(s[i] == ' ')
            chk = true;
        answer += s[i];
    }
    return answer;
}