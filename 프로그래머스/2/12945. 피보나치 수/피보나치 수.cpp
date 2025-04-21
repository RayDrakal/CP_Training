#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int x1 = 0, x2 = 1;
    for(int i=2; i<=n; i++) {
        answer = x1%1234567 + x2%1234567;
        x1 = x2;
        x2 = answer;
    }
    
    return answer % 1234567;
}