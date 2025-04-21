#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using namespace std;
int n;
int ac[27], bc[27];
string a, aa, b, bb;
int main() {
    FASTIO;
    cin >> n;
    cin >> a >> b;
    aa = a, bb = b;
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO";
        return 0;
    }
    aa.erase(remove(aa.begin(), aa.end(), 'a'), aa.end());
    aa.erase(remove(aa.begin(), aa.end(), 'e'), aa.end());
    aa.erase(remove(aa.begin(), aa.end(), 'i'), aa.end());
    aa.erase(remove(aa.begin(), aa.end(), 'o'), aa.end());
    aa.erase(remove(aa.begin(), aa.end(), 'u'), aa.end());
    bb.erase(remove(bb.begin(), bb.end(), 'a'), bb.end());
    bb.erase(remove(bb.begin(), bb.end(), 'e'), bb.end());
    bb.erase(remove(bb.begin(), bb.end(), 'i'), bb.end());
    bb.erase(remove(bb.begin(), bb.end(), 'o'), bb.end());
    bb.erase(remove(bb.begin(), bb.end(), 'u'), bb.end());
    if (aa != bb) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        ac[a[i] - 97]++;
        bc[b[i] - 97]++;
    }
    for (int i = 0; i < 27; i++) {
        if (ac[i] != bc[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}