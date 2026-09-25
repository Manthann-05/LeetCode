class Solution {
public:

    set<string> parse(string &expression, int &i) {
        set<string> result;
        set<string> current = {""};

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == ',') {
                // Union
                result.insert(current.begin(), current.end());
                current = {""};
                i++;
            }

            else if (expression[i] == '{') {
                i++; // skip '{'

                set<string> inside = parse(expression, i);

                i++; // skip '}'

                // Concatenation
                set<string> next;

                for (string a : current) {
                    for (string b : inside) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }

            else {
                // Normal character
                char c = expression[i];

                set<string> next;

                for (string s : current) {
                    next.insert(s + c);
                }

                current = next;

                i++;
            }
        }

        // Add final part
        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};