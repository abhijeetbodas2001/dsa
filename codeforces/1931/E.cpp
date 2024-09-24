#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n, m;
    cin >> n >> m;

    int total_digits = 0;
    vector<pair<string, int>> v;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        total_digits = total_digits + num.length();

        int trailing_0s = 0;
        for (int j = num.length() - 1; j >= 0; j--) {
            if (num[j] != '0') {
                break;
            }
            trailing_0s++;
        }
        v.push_back(make_pair(num, trailing_0s));
    }

    sort(v.begin(), v.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    /* cout << v[0].first << " " << v[0].second << endl; */

    int digits_reduced = 0;
    for (int i = 0; i < n; i = i + 2) {
        digits_reduced = digits_reduced + v[i].second;
    }
    /* cout << total_digits - digits_reduced << endl; */

    string ans = total_digits - digits_reduced > m ? "Sasha" : "Anna";
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
