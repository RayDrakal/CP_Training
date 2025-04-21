#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> stk;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') stk.push(1);
        else {
            if(stk.empty()) {
                answer = false;
                break;
            }
            stk.pop();
        }
    }
    if(!stk.empty()) answer = false;
    return answer;
}