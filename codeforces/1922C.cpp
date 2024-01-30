#include <bits/stdc++.h>
using namespace std;

bool has_multiple_testcases = 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]++;
    }

    vector<int> closest_index(n);
    closest_index[0] = 1;
    closest_index[n - 1] = n - 2;
    for (int i = 1; i < n - 1; i++) {
        if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1])) {
            closest_index[i] = i + 1;
        } else {
            closest_index[i] = i - 1;
        }
    }

    int cache[n][2]; // second index is 0 if backwards, 1 if forward
    for (int i = 0; i < n; i++) {
        cache[i][0] = -1;
        cache[i][1] = -1;
    }

    // VERY CRAPPY DUPLICATION OF CODE, FIX THIS

    int direction_index;
    direction_index = 0;
    for (int from = 0; from < n; from++) {
        // find cost for travelling from `from` to (n-1)*direction_index
        int direction = direction_index > 0 ? direction_index : -1;
        int curr_pos = from;
        int ans = 0;

        // LOOP IS NOT REALLY REQUIRED, IT ITERATES ONLY ONCE BECOS THERE IS ONLY ONE CACHE MISS
        while (curr_pos != direction_index * (n - 1)) {
            if (cache[curr_pos][direction_index] != -1) {
                ans = ans + cache[curr_pos][direction_index];
                break;
            }

            if (direction * (a[closest_index[curr_pos]] - a[curr_pos]) > 0) {
                // closest is in direction of motion
                ans = ans + 1;
            } else {
                ans = ans + abs(a[curr_pos] - a[curr_pos + direction]);
            }

            curr_pos = curr_pos + direction;
        }

        cache[from][direction_index] = ans;
    }

    direction_index = 1;
    for (int from = n - 1; from >= 0; from--) {
        // find cost for travelling from `from` to (n-1)*direction_index
        int direction = direction_index > 0 ? direction_index : -1;
        int curr_pos = from;
        int ans = 0;
        while (curr_pos != direction_index * (n - 1)) {
            if (cache[curr_pos][direction_index] != -1) {
                ans = ans + cache[curr_pos][direction_index];
                break;
            }

            if (direction * (a[closest_index[curr_pos]] - a[curr_pos]) > 0) {
                // closest is in direction of motion
                ans = ans + 1;
            } else {
                ans = ans + abs(a[curr_pos] - a[curr_pos + direction]);
            }

            curr_pos = curr_pos + direction;
        }

        cache[from][direction_index] = ans;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        int direction_index = to >= from ? 1 : 0;
        cout << cache[from][direction_index] - cache[to][direction_index] << "\n";
    }
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
