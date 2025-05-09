#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
	FASTIO;
	int N, A, B;
	cin >> N >> A >> B;
	if (N > (A / 2) + B) cout << ((A / 2) + B);
	else cout << N;
}