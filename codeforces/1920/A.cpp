#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    int upper_bound = INT_MAX;
    int lower_bound = INT_MIN;
    unordered_set<int> not_equal;
    int a, x;
    for (int i = 0; i < n; i++) {
        cin >> a >> x;
        if (a == 1) {
            lower_bound = max(x, lower_bound);
            continue;
        }

        if (a == 2) {
            upper_bound = min(upper_bound, x);
            continue;
        }

        if (a == 3) {
            not_equal.insert(x);
            continue;
        }
    }

    if (upper_bound < lower_bound) {
        cout << 0 << "\n";
        return;
    }

    int ans = upper_bound - lower_bound + 1;
    // cout << "LB " << lower_bound << " UB " << upper_bound << "\n";
    for (int const &ne : not_equal) {
        if (ne <= upper_bound && ne >= lower_bound) {
            ans--;
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
