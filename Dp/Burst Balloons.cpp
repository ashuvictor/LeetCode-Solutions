

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

class Solution {
public:
    int t[501][501];
    int solve(vector<int>& arr , int i , int j){
        if(i>=j)
        return 0;
        if(t[i][j]!=-1)
          return t[i][j];
        int mn=INT_MIN;
        for (int k=i;k<=j-1;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
             mn=max(temp,mn);
        }
       return t[i][j]=mn;
    }
    int maxCoins(vector<int>& nums) {
         int N=nums.size();
         memset(t,-1,sizeof(t));
         vector<int>arr(N+2);
         int n=arr.size();
         arr[0]=1;
         arr[n-1]=1;
        for(int i = 1;i<=nums.size();i++){
            arr[i]=nums[i-1];   
        }
        return solve(arr,1,n-1);
        
    }
};



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(n<1)
            return 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=0;len<=n;len++){
            for(int i=0;i<=nums.size()-len;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    int leftValue=1;
                    int rightValue=1;
                    if(i!=0)
                        leftValue=nums[i-1];
                    if(j!=n-1)
                        rightValue=nums[j+1];
                    int before=0;
                    int after=0;
                    if(i!=k)
                        before=dp[i][k-1];
                    if(j!=k)
                        after=dp[k+1][j];
                    dp[i][j]=max(dp[i][j],leftValue*nums[k]*rightValue+before+after);
                        
                    
                }
            }
        }
    return dp[0][n-1];}
};