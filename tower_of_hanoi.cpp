#include<bits/stdc++.h>
using namespace std;

void printify(int n,string src,string dest,string help,int &count)
{
    if(n==0)
    {
        return;
    }
    if(n>0)
    {
        count++;
        printify(n-1,src,help,dest,count);
        cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;
        printify(n-1,help,dest,src,count);
    }
}
int main()
{
    int n;
    cin>>n;
    int count=0;
    printify(n,"T1","T2","T3",count);
    cout<<count;
    return 0;
}
