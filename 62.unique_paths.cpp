class Solution {
public:
int cnt=0;
    
    bool check(int a[100][100],int i,int j,int m,int n)
    {
        if(i==(m-1)&&j==(n-1))
        {
            cnt++;
            return false;
        }
        a[i][j]=1;
        if(j+1<n)
        {
            if(check(a,i,j+1,m,n))
            {
                return true;
            }
        }
        if(i+1<m)
        {
            if(check(a,i+1,j,m,n))
            {
              return true;
            }
        }
        a[i][j]=0;
        return false;
    }
    int uniquePaths(int m, int n) {
         int a[100][100]={0};
         a[0][0]=1;
        bool ans=check(a,0,0,m,n);
        return cnt;
    }
};
