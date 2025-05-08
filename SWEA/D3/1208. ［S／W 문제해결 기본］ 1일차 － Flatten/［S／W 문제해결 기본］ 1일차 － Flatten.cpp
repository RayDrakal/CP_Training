#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case){
		int lim;
		vector<int> box;
		cin >> lim;
		for (int i = 0; i < 100; i++) {
			int k;
			cin >> k;
			box.push_back(k);
		}

		sort(box.begin(), box.end());
		for (int i = 0; i < lim; i++) {
			box.back()--;
			box.front()++;
			sort(box.begin(), box.end());

			if (box.back() - box.front() <= 1) break;
		}
		cout << '#' << test_case << ' ' << box.back() - box.front() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}