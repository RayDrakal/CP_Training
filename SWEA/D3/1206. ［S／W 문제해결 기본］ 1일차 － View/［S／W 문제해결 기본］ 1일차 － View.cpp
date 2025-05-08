#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		int arr[1005];
		int ans = 0;
		for (int i = 0; i < N; i++) cin >> arr[i];
		for (int i = 2; i < N - 2; i++) {
			int maxH = max(max(arr[i - 2], arr[i - 1]), max(arr[i + 1], arr[i + 2]));
			if (maxH < arr[i]) {
				ans += arr[i] - maxH;
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}