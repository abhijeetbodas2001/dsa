#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector<int> c(n);
    long long int difference = 0;

    for (int i = 0; i < n; i++) {
        difference = difference + abs(b[m - 1 - i] - a[n - 1 - i]);
    }
    long long int ans = difference;

    for (int i = 1; i <= n; i++) {
        // i elements are chosen from prefix of b
        /* cout << difference << " :difference | " << i << " :i\n"; */
        difference = difference + abs(a[i - 1] - b[i - 1]) - abs(a[i - 1] - b[(m - 1) - (n - i)]);
        ans = max(ans, difference);
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
