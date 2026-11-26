class Solution {
public:
    bool canAliceWin(int n) {
        int start = 10;
        string name = "Alice";
        while(n >= start){
            n -= start;
            start--;
            name = start%2==1 ? "Bob" : "Alice";
        }
        return name == "Alice" ? false : true;
    }
};