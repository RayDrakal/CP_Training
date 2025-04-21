#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	double tot = 0, grd = 0;
	for (int i = 0; i < 20; i++) {
		string at, grade;
		double agrd;
		cin >> at >> agrd >> grade;
		if (grade == "P") continue;
		tot += agrd;
		if (grade == "A+")
			grd += (4.5 * agrd);
		else if (grade == "A0")
			grd += (4.0 * agrd);
		else if (grade == "B+")
			grd += (3.5 * agrd);
		else if (grade == "B0")
			grd += (3.0 * agrd);
		else if (grade == "C+")
			grd += (2.5 * agrd);
		else if (grade == "C0")
			grd += (2.0 * agrd);
		else if (grade == "D+")
			grd += (1.5 * agrd);
		else if (grade == "D0")
			grd += (1.0 * agrd);
	}
	double ans = grd / tot;
	cout << fixed;
	cout.precision(6);
	cout << ans;
}