#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    int curr = 0;
    unordered_set<char> chars;
    int parts = 0;
    string ans = "";
    for (int i = 0; i < m; i++) {
        chars.insert(s[i]);

        if (chars.size() == k) {
            parts++;
            chars = {};
            ans = ans + s[i];
            /* cout << chars.size() << "\n"; */
            /* cout << i << "\n"; */
        }
    }

    if (parts >= n) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    char x;

    /* cout << parts << "\n"; */
    // any char not in chars, n times
    for (int i = 0; i < k; i++) {
        if (chars.find(char('a' + i)) == chars.end()) {
            x = char('a' + i);
        }
    }

    for (int i = ans.size(); i < n; i++) {
        ans = ans + x;
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
