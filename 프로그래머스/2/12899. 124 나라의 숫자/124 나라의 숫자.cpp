#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int r = 0;
    while(n) {
        r = n % 3;
        n /= 3;
        if(!r) {
            answer = "4" + answer;
            --n;
        }
        else answer = to_string(r) + answer;
    }
    return answer;
}