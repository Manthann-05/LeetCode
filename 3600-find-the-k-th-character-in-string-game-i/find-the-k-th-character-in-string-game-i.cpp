class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (word.size() < k) {
            int n = word.size();

            for (int i = 0; i < n; i++) {
                word += (word[i] - 'a' + 1) % 26 + 'a';
            }
        }

        return word[k - 1];
    }
};