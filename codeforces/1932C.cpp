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
    long long int n, m;
    std::cin >> n >> m;
    long long int a[n];
    long long int product = 1;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        product = product * a[i];
    }
    std::string s;
    std::cin >> s;

    long long int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        std::cout << product % m << " ";
        if (s[i] == 'L') {
            product = product / a[left];
            left++;
        } else {
            product = product / a[right];
            right--;
        }
    }
    std::cout << "\n";
}
