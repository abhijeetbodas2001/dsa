#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;

    char c1 = 'a';
    char c2 = 'a';
    char c3 = 'a';
    n = n - 3;

    c3 = c3 + min(25, n);
    n = n - min(25, n);
    c2 = c2 + min(25, n);
    n = n - min(25, n);
    c1 = c1 + min(25, n);
    n = n - min(25, n);

    cout << c1 << c2 << c3 << endl;
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
