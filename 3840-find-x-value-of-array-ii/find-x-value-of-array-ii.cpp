class Solution {
private:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int n, k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;

        res.prod = (left.prod * right.prod) % k;

        for (int r = 0; r < k; r++) {
            // Prefixes entirely in the left segment
            res.cnt[r] += left.cnt[r];

            // Prefixes consisting of all left + a prefix of right
            int newRem = (left.prod * r) % k;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            val %= k;

            tree[node] = Node{};
            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(2 * node, l, mid, ql, qr);
        }

        if (ql > mid) {
            return query(2 * node + 1, mid + 1, r, ql, qr);
        }

        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent point update
            update(1, 0, n - 1, index, value);

            // Count prefix products in nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};