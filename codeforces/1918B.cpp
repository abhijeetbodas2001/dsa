#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    int map[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        map[a[i] - 1] = b[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << "\n";
    for (int i = 0; i < n - 1; i++) {
        cout << map[a[i] - 1] << " ";
    }
    cout << map[a[n - 1] - 1] << "\n";
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
