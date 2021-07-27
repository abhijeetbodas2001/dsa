// Problem: https://leetcode.com/problems/word-break/

// recursive DP solution
// O(n) space, some weird time
// can also write this as iterative

class Solution {
private:
    // set of the words in the `wordDict`, as is
    unordered_set<string> dict;

    // If we have calculated whether or not substring from [i, s.length() - 1) can be formed
    // using `dict`, dp[i] stores 0 or 1 (bool), otherwise it stores -1
    vector<int> dp;

    bool canForm(int index, string& s) {
        if (index >= s.length()) {
            return true;
        }

        // avoid processing the string if possible
        if (dp[index] != -1) {
            // implicit type conversion. 0 -> false, 1 -> true
            return dp[index];
        }

        string pref = "";
        for (int i = index; i < s.length(); i++) {
            pref = pref + s[i];

            if (dict.find(pref) != dict.end()) {
                int to_process = i + 1;
                bool can_form_suff = canForm(to_process, s);

                if (can_form_suff) {
                    // store the result (memoization)
                    dp[index] = 1;

                    return true;
                }
            }
        }

        // no match was found
        dp[index] = 0;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(), -1);
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }

        return canForm(0, s);
    }
};