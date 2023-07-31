class Solution {
public: 
    void solve(vector<int>& candidates, int target,int i,int n,vector<vector<int>>& ans, vector<int>& y)
    {
      if(i==n)
      {
          if(target==0)
          {
           ans.push_back(y);
          }
           return;
      }
      if(candidates[i]<=target)
      {
          y.push_back(candidates[i]);
          solve(candidates,target-candidates[i],i,n,ans,y);
          y.pop_back();
      }
      solve(candidates,target,i+1,n,ans,y);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> y;
        solve(candidates,target,0,n,ans,y);
        return ans;
    }
};
