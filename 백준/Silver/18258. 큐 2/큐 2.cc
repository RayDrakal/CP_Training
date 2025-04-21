#include <bits/stdc++.h>
#define ioscall ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;
typedef long long ll;
queue<int> q;
int main() {
	ioscall;
	int n;
	cin >> n;
	while (n--) {
		string ord;
		int x;
		cin >> ord;
		if (ord == "push") {
			cin >> x;
			q.push(x);
		}
		else if (ord == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (ord == "size") {
			cout << q.size() << '\n';
		}
		else if (ord == "empty") {
			cout << (int)q.empty() << '\n';
		}
		else if (ord == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (ord == "back") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}