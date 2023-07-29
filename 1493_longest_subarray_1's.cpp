class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> n(100000,0);
        vector<int> n1(3,0);
        if(nums==n||nums==n1)
        {
            return 0;
        }
        int i=0;
        int j=0;
        int k=0;
        int maxi=0;
        while(j<nums.size())
        {
            if(nums[j]==1)
            {
                j++;
            }
            else if(nums[j]==0)
            {
                k++;
                j++;
            }
            if(j==nums.size()&&maxi==0)
            {
             maxi=max(maxi,j-1);
             break;
            }
            if(k==1)
            {
             maxi=max(maxi,(j-i-1));
            }
            if(k>1)
            {
              while(nums[i]!=0)
              {
                  i++;
              }
              i++;
              k--;
            }
        }
      return maxi;      
    }
};
