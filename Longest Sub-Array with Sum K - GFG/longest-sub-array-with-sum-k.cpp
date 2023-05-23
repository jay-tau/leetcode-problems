//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int c = 0;
        map<int,vector<int>> m;
        m[0].push_back(0);
        for(int i=0;i<N;i++){
            c+=A[i];
            m[c].push_back(i+1);
        }
        int mc=0;
        
        for(auto i=m.begin();i!=m.end();i++) {
            
            if(m.find((i->first)+k) != m.end()){
                int x= m[i->first+k].back() - m[i->first][0];
                mc=max(mc,x);
            }
        }
        return mc;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends