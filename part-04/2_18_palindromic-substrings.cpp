// Problem: https://leetcode.com/problems/palindromic-substrings/

// O(n^2) time, O(1) extra space

// This problem is very similar to https://leetcode.com/problems/longest-palindromic-substring/
// This solution uses the "expand around the center" method

class Solution {
private:
    void findPals(string& s, int& ans, int i, int j) {
        // finds the number of palindromes centered at `i` and `j`
        // and increments ans with that value
        int len = s.length();
        assert(i <= j);
        assert(0 <= i && 0 <= j && i < len && j < len);

        while (0 <= i && 0 <= j && i < len && j < len) {
            if (s[i] != s[j]) {
                // the substring is no longer palindromic, so end the loop
                break;
            }

            ans++;

            // shift the pointers outwards
            i--;
            j++;
        }
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            // odd length palindromes centered at `i`
            findPals(s, ans, i, i);

            if (i < len - 1) {
                // even lengthed palindromes centered at `i` and `i + 1`
                findPals(s, ans, i, i + 1);
            }
        }

        return ans;
    }
};