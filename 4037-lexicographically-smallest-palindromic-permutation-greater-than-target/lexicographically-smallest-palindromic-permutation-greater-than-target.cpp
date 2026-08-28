class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        // A palindrome can have at most one odd frequency
        int odd = 0;
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int halfLen = n / 2;
        string left;

        // Checks whether the current prefix can be completed
        // into a palindrome > target.
        auto possible = [&]() -> bool {
            string temp = left;

            // Make the largest possible remaining left half
            for (int c = 25; c >= 0; c--) {
                temp += string(half[c], char('a' + c));
            }

            string pal = temp;

            if (mid != -1)
                pal += char('a' + mid);

            for (int i = (int)temp.size() - 1; i >= 0; i--)
                pal += temp[i];

            return pal > target;
        };

        // Build left half greedily
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Try this character
                half[c]--;
                left += char('a' + c);

                if (possible()) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        // Construct final palindrome
        string ans = left;

        if (mid != -1)
            ans += char('a' + mid);

        for (int i = (int)left.size() - 1; i >= 0; i--)
            ans += left[i];

        return ans > target ? ans : "";
    }
};