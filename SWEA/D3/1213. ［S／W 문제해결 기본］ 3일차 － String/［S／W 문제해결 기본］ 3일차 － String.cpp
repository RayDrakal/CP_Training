#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case < 11; test_case++) {
		int n, size;
		cin >> n;
		string tg, str;
		cin >> tg >> str;
		size = tg.size();
		n = 0;
		for (int i = 0; i < str.size(); i++) {
			if (tg == str.substr(i, size)) {
				n++;
				i += size;
			}
		}
		cout << '#' << test_case << ' ' << n << '\n';
	}
	return 0;
}