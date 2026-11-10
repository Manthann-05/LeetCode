class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        vector<string> answer(n);

        for(int i = 0; i < n; i++){
            pq.push({score[i], i});
        }

        int count = 1;

        while(!pq.empty()){
            pair<int,int> top = pq.top();
            pq.pop();

            if(count == 1) answer[top.second] = "Gold Medal";
            else if(count == 2) answer[top.second] = "Silver Medal";
            else if(count == 3) answer[top.second] = "Bronze Medal";
            else answer[top.second] = to_string(count);

            count++;
        }

        return answer;
    }
};