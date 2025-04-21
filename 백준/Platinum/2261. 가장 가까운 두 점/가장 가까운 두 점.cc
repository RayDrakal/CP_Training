#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
using namespace std;
const int MAX = 2000000000;
int n;
vector<pair<int, int>> arr;
int dist(int low, int high) {
	int lowx = arr[low].first, lowy = arr[low].second;
	int highx = arr[high].first, highy = arr[high].second;
	int disx = highx - lowx, disy = highy - lowy;
	return disx * disx + disy * disy;
}
int binsearch(int low, int high) {
	if (low == high) return MAX;
	if (low + 1 >= high) return dist(low, high);
	int dismin = dist(low, high);
	int tempdis = 0, mid = (low + high) / 2;
	if ((tempdis = binsearch(low, mid)) < dismin) {
		dismin = tempdis;
	}
	if ((tempdis = binsearch(mid + 1, high)) < dismin) {
		dismin = tempdis;
	}
	vector<pair<int, int>> inner;
	int linex = arr[mid].first;
	for (int i = mid; i >= low; i--) {
		int x = arr[i].first, dis = linex - x;
		if (dismin <= dis * dis) break;
		inner.push_back({ arr[i].second,arr[i].first });
	}
	for (int i = mid + 1; i <= high; i++) {
		int x = arr[i].first, dis = linex - x;
		if (dismin <= dis * dis) break;
		inner.push_back({ arr[i].second, arr[i].first });
	}
	int len = inner.size();
	if (len == 0) return dismin;
	sort(inner.begin(), inner.end());
	for (int i = 0; i < len; i++) {
		int ix = inner[i].second, iy = inner[i].first;
		for (int j = i + 1; j < len; j++) {
			int jx = inner[j].second, jy = inner[j].first;
			int distx = jx - ix, disty = jy - iy;
			if (dismin <= disty * disty) break;
			if (dismin <= distx * distx) break;
			int dis = distx * distx + disty * disty;
			if (dis < dismin) dismin = dis;
		}
	}
	return dismin;
}
int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	cout << binsearch(0, n - 1);
}