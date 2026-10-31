class Solution {
public:
    int lengthOfLastWord(string s) {
        auto last = s.end();
        while (last != s.begin() && *(last - 1) == ' ')
            last--;

        int cnt = 0;
        while (last != s.begin() && *(last - 1) != ' ') {
            last--;
            cnt++;
        }
        return cnt;
    }
};