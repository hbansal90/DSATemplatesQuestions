/*Question: 
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
int dp[102][10002];
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // using 0/1 knapsack problem
        // as we have only one array, we will choose wt array
        // sum is maxWeight
        // Two choices - take notTake
        // Code varation -> 
        memset(dp, 0, sizeof(dp));
        int n = arr.size();
        // base conditions
        for(int i = 0; i<102; i++)
            dp[i][0] = 1;
        for(int j = 1; j<10002; j++)
            dp[0][j] = 0;
        // choice conditions
        // max(0,1) -> OR
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= sum; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
                else
                dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends