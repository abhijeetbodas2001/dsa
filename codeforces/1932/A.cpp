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
    std::string s;
    std::cin >> s;

    int score = s[0] == '@';
    for (int i = 1; i < n; i++) {
        if (s[i] == '@') {
            score++;
        }

        if (s[i] == '*' && s[i - 1] == '*') {
            break;
        }
    }

    std::cout << score << "\n";
}
