class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> dict;

        for(string word : words)
            dict[word]++;

        auto comparer = [](const pair<int, string>& a,
                           const pair<int, string>& b) {

            if(a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        };

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(comparer)
        > pq(comparer);

        for(auto& [word, frequency] : dict){

            pair<int, string> newPair =
                {frequency, word};

            if(pq.size() < k)
                pq.push(newPair);
            else{
                pq.push(newPair);
                pq.pop();
            }
        }

        vector<string> result(k);

        for(int i = k - 1; i >= 0; i--){
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};