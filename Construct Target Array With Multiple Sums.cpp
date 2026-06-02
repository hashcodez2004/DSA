class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum=0;
        for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum+=target[i];
        }

        long long maxEle, remSum, element;
        while(pq.top()!=1){
            maxEle=pq.top();
            pq.pop();
            remSum=sum-maxEle;

            //edge cases
            if(remSum<=0 || remSum>=maxEle) return false;

            //changes done for removing TLE
            element=maxEle%remSum;
            if(element==0){
                if(remSum!=1) return false;
                else return true;
            }

            // element=maxEle-remSum;
            sum=remSum+element;
            pq.push(element);
        }

        return true;
    }
};