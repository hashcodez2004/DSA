class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};


/*
Time Complexity: O(N * M * 26 * M)   M is taken because in case of string the amortized TC of unordered_set is O(M)......WC is O(M*size of set)
- N = number of words in wordList
- M = length of each word
- 26 = letter substitutions
- Inner M for average-case hashing/comparison cost

Explanation:
- For each word in queue (at most N), we try M positions with 26 letters, and each set lookup costs O(M) in average case (due to string comparison).

Space Complexity: O(N + M)
- O(N) for unordered_set of words
- O(N * M) max queue size in worst case (all transformations are valid)
*/