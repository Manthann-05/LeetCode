
class Solution {
public:
    void possibleAns(string digits, vector<pair<int,string>>& pairs,vector<string>& ans, int idx, string curr) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[idx] - '0';
        string letters = pairs[digit - 2].second;

        for (char ch : letters) {
            curr.push_back(ch);
            possibleAns(digits, pairs, ans, idx + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<pair<int,string>> pairs = {
            {2, "abc"}, {3, "def"}, {4, "ghi"},
            {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
            {8, "tuv"}, {9, "wxyz"}
        };

        vector<string> ans;
        possibleAns(digits, pairs, ans, 0, "");
        return ans;
    }
};
