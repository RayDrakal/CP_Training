#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
using namespace std;
int arr[500005], ans, cnt;
int tmp[500005], n, k;
bool chk = false;
void merge_f(int *x, int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
	while (i <= q && j <= r) {
		cnt++;
		if (x[i] <= x[j])
			ans = x[i++];
		else ans = x[j++];
		tmp[t++] = ans;
		if (cnt == k) {
			chk = true;
			cout << ans;
			return;
		}
	}
	while (i <= q) {
		cnt++;
		ans = x[i++];
		tmp[t++] = ans;
		if (cnt == k) {
			chk = true;
			cout << ans;
			return;
		}
	}
	while (j <= r) {
		cnt++;
		ans = x[j++];
		tmp[t++] = ans;
		if (cnt == k) {
			chk = true;
			cout << ans;
			return;
		}
	}
	i = p; t = 1;
	while (i <= r) x[i++] = tmp[t++];
}
void merge_sort(int *x, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(x, p, q);
		merge_sort(x, q + 1, r);
		merge_f(x, p, q, r);
	}
	if (chk) return;
}
int main()
{
	FASTIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	merge_sort(arr, 0, n - 1);
	if (cnt < k) cout << -1;
}