#include<iostream>

using namespace std;
int sq(int n, int r) {
	if (r == 1) return n;
	return n * sq(n, r - 1);
}
int main(int argc, char** argv)
{
	int T;
	for (int test_case = 1; test_case < 11; test_case++) {
		cin >> T;
		int a, b, ans;
		cin >> a >> b;
		ans = sq(a, b);
		cout << '#' << T << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}