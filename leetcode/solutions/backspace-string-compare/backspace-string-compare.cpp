// Problem: https://leetcode.com/problems/backspace-string-compare/

// O(n) time, O(1) space, super-buggy
// DOES NOT WORK

class Solution {
private:
    void processBackspaceGroup(string &s, int &index) {
        // Turns index into the index of the next character which would exist
        // in the processed string.
        if (index < 0) {
            return;
        }

        int backs = 0;
        while (index >= 0 && s[index] == '#') {
            backs++;
            index--;
        }

        while (backs > 0) {
            backs--;
            index--;
        }

        return;
    }
public:
    bool backspaceCompare(string s, string t) {
        int s_index = s.length() - 1;
        int t_index = t.length() - 1;
        while (true) {
            if (s_index < 0 && t_index < 0) {
                return true;
            }

            if (s_index < 0 || t_index < 0) {
                return false;
            }

            if (s[s_index] != '#' && t[t_index] != '#') {
                if (s[s_index] != t[t_index]) {
                    return false;
                }
                s_index--;
                t_index--;
            } else {
                processBackspaceGroup(s, s_index);
                processBackspaceGroup(t, t_index);
            }
        }

        // Never reaches here.
        return false;
    }
};