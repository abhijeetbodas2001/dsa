// Problem: https://leetcode.com/problems/decode-ways/

// recursive DP
// O(n) time, O(n) space
// logic for O(n) time : we calculate `numWays(i)` exactly once for every `i`, and `i < n`

// this can be converted to O(1) space by only remembering the `i - 1` and `i - 2` th answers
// in a top down approach

class Solution {
private:
    // memoizes `numWays`
    // -1 stands for "not calculated yet"
    vector<int> dp;

    int numWays(int index, string& s) {
        // given string s, returns the number of ways to decode the substring from
        // [index, s.length() - 1)
        if (index >= s.length()) {
            // ending case
            // there is exactly one way to decode an empty string -- to return an empty string
            return 1;
        }

        if (dp[index] != -1) {
            // we've calculated the value earlier, so reuse it
            return dp[index];
        }

        int ans;
        if (s[index] == '0') {
            // if the substring starts with '0', there's no way to decode it
            ans = 0;
        } else if (index == s.length() - 1) {
            // the substring contains a single character (and it is not '0')
            // only one way to decode it
            ans = 1;
        } else {
            // OK, so the substring contains more than one character, and the first character
            // isn't '0'

            // We can decode it in two ways:
            // 1. Either convert the first character to a letter and then decode the rest of the subtring
            // 2. (If possible, ) decode the first two characters into a letter and then decode rest of
            // the substring

            // This is case `1.`
            ans = numWays(index + 1, s);

            // Now check if `2.` is possible
            // the value of the digits should be <= 26 for `2.` to be possible
            int val = 10 * (s[index] - '0') + (s[index + 1] - '0');
            if (val <= 26) {
                ans = ans + numWays(index + 2, s);
            }
        }

        // memoize!
        dp[index] = ans;

        return ans;        
    }
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        dp.resize(s.length(), -1);
        return numWays(0, s);
    }
};