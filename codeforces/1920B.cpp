#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> prefix_sum(n, a[0]);
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    int ans = INT_MIN;

    int negated_by_B = 0;
    for (int i = n - k; i <= n; i++) {
        // A has removed all elements starting from index i

        if (i == 0) {
            // A has removed every element
            ans = max(ans, 0);
            continue;
        }

        // 1, 4
        // number of elements remaining now = i

        if (x < i) {
            // B makes the last x elements negative
            negated_by_B = prefix_sum[i - 1] - prefix_sum[i - x - 1];
        } else {
            // B makes all the remaining elements negative
            negated_by_B = prefix_sum[i - 1];
        }

        ans = max(ans, prefix_sum[i - 1] - 2 * negated_by_B);
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
