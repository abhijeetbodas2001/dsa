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
    std::string s;
    std::cin >> s;
    int As = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            As++;
        }
    }

    char ans;
    ans = As > s.length() - As ? 'A' : 'B';
    std::cout << ans << "\n";
}
