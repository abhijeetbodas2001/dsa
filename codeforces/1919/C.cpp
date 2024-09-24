#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(1, INT_MAX);
    vector<int> b(1, INT_MAX);

    int x = 0;
    int a_back, b_back;

    int penalty = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a_back = a.back();
        b_back = b.back();
        if ((x > a_back && x > b_back) || (x <= a_back && x <= b_back)) {
            if (a_back > b_back) {
                b.push_back(x);
            } else {
                a.push_back(x);
            }

            if (x > a_back) {
                penalty++;
            }

            continue;
        }

        if (x <= a_back) {
            a.push_back(x);
            continue;
        }

        assert(x <= b_back);
        b.push_back(x);
    }

    cout << penalty << "\n";
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
