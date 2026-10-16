
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r) {
        long long len = r - l + 1;

        // (x + 1)^2 = x^2 + 2*x + 1
        tree[node].sq =
            (tree[node].sq + 2 * tree[node].sum + len) % MOD;

        tree[node].sum = (tree[node].sum + len) % MOD;
        tree[node].lazy++;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long times = tree[node].lazy;

        // Apply the pending increment to both children.
        // For a general increment d:
        // sum' = sum + d*len
        // sq'  = sq + 2*d*sum + d*d*len

        auto updateChild = [&](int child, int left, int right) {
            long long len = right - left + 1;
            long long d = times;
            long long oldSum = tree[child].sum;

            tree[child].sq =
                (tree[child].sq + 2 * d % MOD * oldSum
                 + d * d % MOD * len) % MOD;

            tree[child].sum =
                (oldSum + d * len) % MOD;

            tree[child].lazy += d;
        };

        updateChild(node * 2, l, mid);
        updateChild(node * 2 + 1, mid + 1, r);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            // All subarrays ending at i that gain
            // one new distinct element.
            update(1, 0, n - 1, prev + 1, i);

            // Sum of squared distinct counts for
            // all subarrays ending at i.
            ans = (ans + tree[1].sq) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};
