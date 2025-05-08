#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		int ans = 0, ans_score;
		vector<int> scores(101);
		int num;
		cin >> num;
		for (int i = 0; i < 1000; i++) {
			cin >> num;
			scores[num]++;
		}
		for (int i = 0; i < 101; i++) {
			if (ans <= scores[i]) {
				ans = scores[i];
				ans_score = i;
			}
		}
		cout << '#' << test_case << ' ' << ans_score << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}