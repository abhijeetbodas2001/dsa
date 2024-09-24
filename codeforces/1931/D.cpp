#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int x, y, n;
    cin >> n >> x >> y;

    int a[n];

    unordered_map<pair<int, int>, int> mod;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        /* cout << mody[0].size() << endl; */

        pair<int, int> p = make_pair(a[i] % x, a[i] % y);
        if (mod.find(p) == mod.end()) {
            mod[p] = 0;
            cout << p << end;
            return;
        }
        mod[p]++;
    }

    /* cout << endl; */

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int other_mod_x = a[i] % x == 0 ? 0 : x - a[i] % x;
        int other_mod_y = a[i] % y == 0 ? 0 : a[i] % y;

        ans = ans + mod[other_mod_x][other_mod_y];
    }
    cout << ans / 2 << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

    int num_testcases = 1;
    if (has_multiple_testcases) {
        cin >> num_testcases;
    }

    for (int testcase = 1; testcase <= num_testcases; testcase++) {
        solve();
    }

    return 0;
}
