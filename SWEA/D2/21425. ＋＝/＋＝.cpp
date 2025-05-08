#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int x, y, N;
        int cnt = 0;
        cin >> x >> y >> N;
        while(x <= N) {
            if(x > y) {
                int tmp = y;
                y = x;
                x = tmp;
            }
            x += y;
            cnt++;
        }
        cout << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}