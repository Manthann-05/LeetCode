class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int level = 0, maxLevel = 0;
        for(char a: s){
            if(a=='(') level++;
            if(a==')') level--;
            maxLevel = max(maxLevel, level);
        }
        return maxLevel;
    }
};