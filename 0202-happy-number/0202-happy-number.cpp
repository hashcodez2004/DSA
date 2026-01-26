class Solution {
private:
    int sumOfSquares(int n){
        int sum=0;
        while(n){
            int x=n%10;
            sum+=x*x;
            n=n/10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        // unordered_set<int> st;
        // while(st.find(n)==st.end()){
        //     st.insert(n);
        //     n=sumOfSquares(n);
        //     if(n==1) return true;
        // }
        // return false;


        //NO EXTRA SPACE REQUIRED => SLOW AND FAST POINTER
        int slow=n;
        int fast=n;
        slow=sumOfSquares(slow);
        fast=sumOfSquares(sumOfSquares(fast));
        while(slow!=fast){
            slow=sumOfSquares(slow);                        // 1 step
            fast=sumOfSquares(sumOfSquares(fast));          // 2 step
        }
        if(slow==1) return true;
        return false;
    }
};