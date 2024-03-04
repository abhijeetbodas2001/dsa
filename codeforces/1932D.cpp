#include <bits/stdc++.h>
#include <string>
#include <vector>

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
    char hukum_char;
    std::cin >> hukum_char;

    int hukum;
    if (hukum_char == 'C')
        hukum = 0;
    if (hukum_char == 'D')
        hukum = 1;
    if (hukum_char == 'H')
        hukum = 2;
    if (hukum_char == 'S')
        hukum = 3;

    int cards[n][2];
    std::vector<int> counts(4, 0);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        cards[i][0] = s[0] - '0';
        /* std::cout << cards[i][0] << "\n"; */

        int house;
        if (s[1] == 'C')
            house = 0;
        if (s[1] == 'D')
            house = 1;
        if (s[1] == 'H')
            house = 2;
        if (s[1] == 'S')
            house = 3;

        counts[house]++;
    }

    int odds = 0;
    for (int i = 0; i < 4; i++) {
        if (counts[i] % 2 == 1 && i != hukum) {
            odds++;
        }
    }

    if (hukum < odds) {
        std::cout << "IMPOSSIBLE";
    }
}
