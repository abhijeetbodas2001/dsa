#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    long long int n;
    cin >> n;

    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 3) {
        cout << 0 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    a.push_back(-1);

    long long int ans = 0;
    long long int streak = 1;
    for (int i = 1; i <= n; i++) {
        /* cout << streak << " :streak\n"; */
        if (a[i] == a[i - 1]) {
            streak++;
        } else {
            if (streak >= 2) {
                // select 2 from streak, 1 from elsewhere
                if (streak < i) {
                    ans = ans + (i - streak) * (streak * (streak - 1) / 2);
                }
                if (streak >= 3) {
                    // select 3 from streak
                    ans = ans + streak * (streak - 1) * (streak - 2) / 6;
                }
            }
            streak = 1;
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
