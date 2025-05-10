#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	for (int i = 1; i < 11; i++) {
		int size, ans = 0;
		vector<string> v;
		cin >> size;
		for (int j = 0; j < 8; j++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		if (size == 1)
			cout << '#' << i << ' ' << 64 << '\n';
		else {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k <= 8 - size; k++) {
					bool chk = true;
					for (int l = 0; l < size / 2; l++) {
						if (v[j][k + l] != v[j][k + size - l - 1])
							chk = false;
					}
					if (chk) ans++;
				}
			}
			for (int j = 0; j <= 8 - size; j++) {
				for (int k = 0; k < 8; k++) {
					bool chk = true;
					for (int l = 0; l < size / 2; l++) {
						if (v[j + l][k] != v[j + size - l - 1][k])
							chk = false;
					}
					if (chk) ans++;
				}
			}
		}
		cout << '#' << i << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}