#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;

    int count_0_to_1 = 0, count_1_to_0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == f[i]) {
            continue;
        }

        count_0_to_1 += s[i] == '0';
        count_1_to_0 += s[i] == '1';
    }

    int m = min(count_0_to_1, count_1_to_0), M = max(count_0_to_1, count_1_to_0);

    cout << m + M - m << "\n";
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
