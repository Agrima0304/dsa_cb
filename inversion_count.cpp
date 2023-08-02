int merge(vector<int>& nums,int s,int e)
    {
        int temp[100000];
        int mid=(s+e)/2;
        int i=s,j=mid+1,k=0;
        int cnt=0;
        while(i<=mid&&j<=e)
        {
          if(nums[i]<=nums[j])
          {
              temp[k++]=nums[i++];
          }
          else if(nums[i]>nums[j])
          {
              cnt=cnt+(mid-i+1);
              temp[k++]=nums[j++];
          }
        }
        while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
         while(j<=e)
        {
            temp[k++]=nums[j++];
        }
        for(int i=0;i<k;i++)
        {
            nums[s+i]=temp[i];
        }
        return cnt;
    } 
    int mergesort(vector<int>& nums,int s,int e)
    {
        if(s>=e)
        {
            return 0;
        }
        int mid=(s+e)/2;
        int x=mergesort(nums,s,mid);
        int y=mergesort(nums,mid+1,e);
        int z=merge(nums,s,e);
        return x+y+z;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int l=0;
        set<int> v;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                l++;
            }
        }
        int gl=mergesort(nums,0,nums.size()-1);
        return l==gl;
    }
