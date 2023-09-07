    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans(n,0);
       ans[0]=1;
       stack<int> s;
       s.push(0);
       for(int i=1;i<n;i++)
       {
           int curr_price=price[i];
           while(!s.empty()&&curr_price>=price[s.top()])
           {
               s.pop();
           }
           if(!s.empty())
           {
               int high=s.top();
               ans[i]=i-high;
           }
           else
           {
               ans[i]=i+1;
           }
           s.push(i);
       }
       return ans;
    }
