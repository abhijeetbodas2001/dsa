// Problem: https://leetcode.com/problems/longest-palindromic-substring/discuss/2928/Very-simple-clean-java-solution

// O(n^2) time, O(1) space solution
// see official solution for explaination

class Solution {
private:
    pair<int, int> palIndices(string& s, int left, int right) {
        // Returns the indices of the longest palindromic substring centered
        // at `left`, `right`
        int L = left, R = right;
        while (0 <= L && R <= s.length() && s[L] == s[R]) {
            L--;
            R++;
        }

        return {R, L};
    }
public:
    string longestPalindrome(string s) {
        int len = s.length();

        // right and left indcies of answer
        int ra = 0, la = 0;

        for (int i = 0; i < len; i++) {
            // even length palindrome
            pair<int, int> even = palIndices(s, i, i + 1);
            int R = even.first;
            int L = even.second;
            if (R - L + 1 > ra - la + 1) {
                ra = R;
                la = L;
            }

            // odd length palindrome
            pair<int, int> odd = palIndices(s, i, i);
            int R = odd.first;
            int L = odd.second;
            if (R - L + 1 > ra - la + 1) {
                ra = R;
                la = L;
            }
        }

        string ans = "";
        for (int i = la; i <= ra; i++) {
            ans = ans + s[i];
        }
        return ans;
    }
};