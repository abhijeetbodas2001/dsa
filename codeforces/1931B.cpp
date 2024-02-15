#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    int prefix_sum[n];
    int a[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total = total + a[i];
    }

    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = a[i] + prefix_sum[i - 1];
    }

    for (int i = 0; i < n; i++) {
        if (prefix_sum[i] < total / n * (i + 1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
