#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int arr[4001][4];
vector<int> a, b;
ll answer;
int main() {
	FASTIO;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++) cin >> arr[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a.push_back(arr[i][0] + arr[j][1]);
			b.push_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++) {
		int prev = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
		int end = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();

		answer += (end - prev);
	}
	cout << answer;
}