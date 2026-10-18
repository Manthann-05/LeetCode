
class Solution {
public:
    bool isValid(string& s) {
        int n = s.size();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }

    void totalPartitions(string& s, vector<vector<string>>& ans, vector<string>& curr, int idx) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (isValid(sub)) {
                curr.push_back(sub);
                totalPartitions(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        totalPartitions(s, ans, curr, 0);
        return ans;
    }
};
