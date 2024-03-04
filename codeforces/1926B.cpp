#include <algorithm>
#include <bits/stdc++.h>

void solve();

int main() {
    std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

    // Switch
    bool has_multiple_testcases = 1;
    int num_testcases = 1;
    if (has_multiple_testcases) {
        std::cin >> num_testcases;
    }

    for (int testcase = 1; testcase <= num_testcases; testcase++) {
        solve();
    }

    return 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> ones;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int num_one = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                num_one++;
            }
        }

        if (num_one != 0) {
            ones.push_back(num_one);
            /* std::cout << num_one; */
        }
    }

    std::sort(ones.begin(), ones.end());

    std::string ans = ones[0] == ones[ones.size() - 1] ? "SQUARE" : "TRIANGLE";
    std::cout << ans << "\n";
}
