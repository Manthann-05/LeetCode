class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum > 0){
            if(sum > 9){
                ans += '9';
                sum -= 9;
            }
            else{
                ans += char('0' + sum);
                sum = 0;
            }
        }
        if(ans.size() > num) return "";
        if(ans.size() == num) return ans;
        
        while(ans.size()!=num) ans += '0';
        return ans;
    }
};