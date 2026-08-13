class Solution {
public:

    struct Node {
        char leftChar, rightChar;

        int leftLen;   // longest same-character prefix
        int rightLen;  // longest same-character suffix
        int best;      // longest repeating substring
        int len;       // total length of this segment

        Node() {
            leftChar = rightChar = '#';
            leftLen = rightLen = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c;
            leftLen = rightLen = best = len = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // --------------------
        // Prefix
        // --------------------

        res.leftLen = a.leftLen;

        // Entire left segment has one character
        // and it matches the first character of right
        if (a.leftLen == a.len &&
            a.leftChar == b.leftChar) {

            res.leftLen = a.len + b.leftLen;
        }

        // --------------------
        // Suffix
        // --------------------

        res.rightLen = b.rightLen;

        // Entire right segment has one character
        // and it matches the last character of left
        if (b.rightLen == b.len &&
            a.rightChar == b.rightChar) {

            res.rightLen = b.len + a.rightLen;
        }

        // --------------------
        // Best
        // --------------------

        res.best = max(a.best, b.best);

        // Join suffix of left + prefix of right
        if (a.rightChar == b.leftChar) {

            res.best = max(
                res.best,
                a.rightLen + b.leftLen
            );
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(string &s, int node, int l, int r,
                int idx, char c) {

        if (l == r) {
            s[l] = c;
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(
                s,
                node * 2,
                l,
                mid,
                idx,
                c
            );
        }
        else {
            update(
                s,
                node * 2 + 1,
                mid + 1,
                r,
                idx,
                c
            );
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                s,
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};