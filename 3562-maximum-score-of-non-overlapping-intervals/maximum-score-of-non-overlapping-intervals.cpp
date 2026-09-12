class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        vector<int> p(n);

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();

            p[i] = pos;
        }

        vector<vector<Node>> dp(
            5,
            vector<Node>(n + 1)
        );

        for (int k = 0; k <= 4; k++) {
            dp[k][0] = {0, {}};
        }

        for (int i = 1; i <= n; i++) {
            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {
                Node best = dp[k][i - 1];
                Node take;

                take.score =
                    dp[k - 1][p[idx]].score + a[idx][2];

                take.ids = dp[k - 1][p[idx]].ids;
                take.ids.push_back((int)a[idx][3]);

                sort(take.ids.begin(), take.ids.end());

                if (better(take, best))
                    best = take;

                dp[k][i] = best;
            }
        }

        return dp[4][n].ids;
    }
};