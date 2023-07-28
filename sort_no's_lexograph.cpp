class Solution {
public:
    void util(int i,int n,vector<int>& s)
    {
        if(i>n)
        {
            return;
        }
        s.push_back(i);
        for(int j=0;j<=9;j++)
        {
            util(i*10+j,n,s);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> s;
        for(int i=1;i<=9;i++)
        {
            util(i,n,s);
        }
       
        return s;
    }
};
