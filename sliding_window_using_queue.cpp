class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        deque <int> q;
        vector<int> ans;
        for(i=0;i<k;i++)
        {
           while(!q.empty()&&nums[i]>=nums[q.back()])
           {
               q.pop_back();
           }
           q.push_back(i);
        }
        // for remaining elements
        for(;i<nums.size();i++)
        {
            //print the element
            ans.push_back(nums[q.front()]);
            //remove element which do not lie in that slab
            while(!q.empty()&&q.front()<=(i-k))
            {
                q.pop_front();
            }
            //elements which are in slab but are smaller
            while(!q.empty()&&nums[i]>=nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
         ans.push_back(nums[q.front()]);
         return ans;
    }
};
