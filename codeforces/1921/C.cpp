#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    long long int n, f, a, b;
    cin >> n >> f >> a >> b;

    vector<long long int> m(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }

    for (int i = 1; i <= n; i++) {
        f = f - min((m[i] - m[i - 1]) * a, b);
        /* cout<<"f "<<f<<"\n"; */
        if (f <= 0) {
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
