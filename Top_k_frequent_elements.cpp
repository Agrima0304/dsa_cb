class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int n=nums.back()+1;
       int p[20000]={0};
       for(int i=0;i<nums.size();i++)
       {
           p[nums[i]+10000]++;
       }
       vector<int> ans;
       ans.reserve(k);
       vector<pair<int,int>> a;
       for(int i=0;i<n+10000;i++)
       {
           if(p[i]>0)
           {
               a.push_back(make_pair(p[i],i));
           }
       }
       sort(a.rbegin(),a.rend());
       for(int i=0;i<k;i++)
       {
           ans.push_back(a[i].second-10000);
       }
      return ans;
    }
};
