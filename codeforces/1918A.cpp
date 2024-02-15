#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << n * (m / 2) << "\n";
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
