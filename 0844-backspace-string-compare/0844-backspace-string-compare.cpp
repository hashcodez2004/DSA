class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {

            // find valid char in s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else break;
            }

            // find valid char in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else break;
            }

            // compare
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } 
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--; 
            j--;
        }
        return true;
    }
};