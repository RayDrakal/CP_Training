#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string ans;
        int N;
        cin >> N;
        if(N % 3 == 0) {
            for(int i = 0; i < N/3; i++) ans += "BBA";
        }
        else if(N%3 == 1) ans = "impossible";
        else {
        	ans += "BA";
            for(int i = 0; i < N/3; i++) ans += "BBA";
        }
        cout << ans << '\n';
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}