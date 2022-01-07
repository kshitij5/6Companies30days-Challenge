// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
// using stack
// tc - o(n)
// sc - o(n)
    string printMinNumberForPattern(string S){
        int count = 1;
        stack<int> st;
        string res;
        
        for(char c: S) {
            st.push(count++);
            
            // when we incounter i, which we let as interval point
            // we will push the last count, and pop back everything
            if(c == 'I') {
                while(!st.empty()) {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        // we make sure to push an extra count 
        // and pop back everything we have from the last interval point
        st.push(count);
        while(!st.empty()) {
            res += to_string(st.top());
            st.pop();
        }
        
        return res;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends