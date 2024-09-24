#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int prefix = 1, suffix = 1, common = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            break;
        }
        prefix++;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1]) {
            break;
        }
        suffix++;
    }

    if (prefix == n || suffix == n) {
        cout << 0 << "\n";
        return;
    }

    common = min(n / 2, min(prefix, suffix) * (a[0] == a[n - 1]));

    /* cout << prefix << suffix << common << endl; */

    int ans = min(n - prefix, n - suffix);
    if (common > 0) {
        ans = min(ans, n - prefix - suffix);
    }
    cout << ans << "\n";
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
