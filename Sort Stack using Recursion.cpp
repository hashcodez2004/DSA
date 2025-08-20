#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void mergeStack(int temp, stack<int>& st){
        if(st.empty() || st.top()<=temp){
            st.push(temp);
            return;
        }
        
        int curr = st.top();
        st.pop();
        mergeStack(temp,st);
        st.push(curr);
    }

public:
    void stackSort(stack<int>& st){
        if(st.empty() || st.size()==1) return;
        int temp = st.top();
        st.pop();
        stackSort(st);
        mergeStack(temp,st);
    }
};

void printStack(stack<int>& st){
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int> st;
        while(n--){
            int num;
            cin>>num;
            st.push(num);
        }
        
        Solution obj;
        obj.stackSort(st);
        
        printStack(st);
    }
    return 0;
}

/*
🔎 Time Complexity

At each recursion level (n levels total), we may call insertSorted with cost up to O(n).

So overall complexity = 𝑂(1+2+3+⋯+𝑛)=𝑂(𝑛2)O(1+2+3+⋯+n)=O(n2)

✅ Time Complexity = O(n²)

🔎 Space Complexity

Two sources of space usage:

Recursion depth:

stackSort makes n recursive calls → O(n).

insertSorted may also recurse up to O(n).

But they’re not nested at the same time, so stack depth = O(n).

Auxiliary memory:

We don’t use extra arrays or vectors, only the given stack.

✅ Space Complexity = O(n) (from recursion call stack).
*/