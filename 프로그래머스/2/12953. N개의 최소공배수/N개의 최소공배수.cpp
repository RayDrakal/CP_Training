#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++) {
        int x = gcd(arr[i], arr[i+1]);
        answer = (arr[i] * arr[i + 1]) / x;
        arr[i + 1] = answer;
    }
    return answer;
}