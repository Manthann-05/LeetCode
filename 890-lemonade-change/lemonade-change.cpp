class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0, ten = 0;
        for(int i = 0; i < n; i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(five==0) return false;
                else five--;
                ten++;
            }
            else{
                if(ten==0){
                    if(five < 3) return false;
                    else five -= 3;
                }
                else{
                    ten--;
                    if(five==0) return false;
                    else five--;
                }
            }
        }
        return true;
    }
};