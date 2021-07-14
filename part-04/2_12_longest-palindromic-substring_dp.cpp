// Problem: https://leetcode.com/problems/longest-palindromic-substring/

// O(n^2) time, O(n^2) space DP solution

/*
    Thinking:

    1. Brute force: O(n^3) time
        For 0 <= i <= j <= len - 1, check if substring i to j is palindromic
        This can be done iteratively
    
    2. The same brute force solution can also be written recursively, as below, without
    affecting the time complexity.

    3. Writing the solution recursively gives us a change to memoize
*/

class Solution {
private:
    // -1 for not processed, 0 for false, 1 for true
    vector<vector<int>> ispal;

    // Dont do pass-by-value for `s`, that will give TLE
    bool isPalindrome(string& s, int i, int j) {
        // Tells if substring [i, j] is palindrome
        int len = s.length();
        assert(0 <= i && i <= len);
        assert(0 <= j && j <= len);

        if (i >= j) {
            return true;
        }

        if (ispal[i][j] != -1) {
            return ispal[i][j];
        }

        bool subproblem = isPalindrome(s, i + 1, j - 1);
        bool ret = s[i] == s[j] && subproblem;

        ispal[i][j] = ret ? 1: 0;
        return ret;
    }
public:
    string longestPalindrome(string s) {
        int len = s.length();
        ispal.resize(len);
        for (int i = 0; i < len; i++) {
            ispal[i].resize(len, -1);
        }
        
        // Store the first and last index of the answer string
        int ia = 0, ja = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (isPalindrome(s, i, j)) {
                    if ((ja - ia + 1) < (j - i + 1)) {
                        ia = i;
                        ja = j;
                    }
                }
            }
        }

        string ans = "";
        for (int i = ia; i <= ja; i++) {
            ans = ans + s[i];
        }

        return ans;
    }
};