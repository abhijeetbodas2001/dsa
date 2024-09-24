#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int x, n;
    cin >> x >> n;

    int ans = 1;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i != 0) {
            continue;
        }

        if (x / i >= n) {
            ans = max(ans, i);
        }

        if (i >= n) {
            ans = max(ans, x / i);
        }
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
