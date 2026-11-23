class ProductOfNumbers {
public:
    vector<int> ans; 
    ProductOfNumbers() {

    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int n = ans.size();
        int p = 1, i = 0;
        while(k > 0){
            p *= ans[n-i-1];
            i++;
            k--;
        }
        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */