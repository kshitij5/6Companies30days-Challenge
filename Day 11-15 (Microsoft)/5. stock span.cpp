// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    // using brute force
    // tc - o(n2)
    // sc - o(n)
    // vector <int> calculateSpan(int price[], int n)
    // {
    //     vector<int> res;
    //     for(int i=0; i<n; i++) {
    //         int curr_ele = price[i];
    //         int j = i;
    //         while(price[j] <= curr_ele && j>=0) j--;
            
    //         int curr_span = i - j;
    //         res.push_back(curr_span);
    //     }
        
    //     return res;
    // }
    
    
    // using stack - pop - ans - push method
    // tc - o(n)
    // sc - o(n)
    vector <int> calculateSpan(int price[], int n) {
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            // pop
            while(!st.empty() && price[st.top()] <= price[i]) 
                st.pop();
            
            // ans
            if(st.empty())
                res[i] = i + 1;
            else    res[i] = i - st.top();
            
            // push
            st.push(i);
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends