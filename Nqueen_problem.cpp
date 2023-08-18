#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool IsSafe(int mat[][1000],int i,int j,int n)
{
	//for row n column
    for(int k=0;k<n;k++)
	{
		if(mat[i][k]==1||mat[k][j]==1)
		{
			return false;
		}
	}
	while(i>=0&&j<n)
	{
		if(mat[i][j]==1)
		{
			return false;
		}
		i--,j++;
	}
		while(i>=0&&j>=0)
	{
		if(mat[i][j]==1)
		{
			return false;
		}
		i--,j--;
	}
    return true;
}
bool print(int mat[][1000],int i,int n,int &c)
{
	//Base Case
	if(i==n)
	{
			c++;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j]==1)
				{
					cout<<"{"<<i+1<<"-"<<j+1<<"}"<<" ";
				}
			}
		}
		return false;
	}
	for(int j=0;j<n;j++)
	{
		if(IsSafe(mat,i,j,n))
		{
		  mat[i][j]=1;
		  bool d=print(mat,i+1,n,c);
		  if(d==true)
		  {
			  return true;//backtrack
		  }	
          mat[i][j]=0;		  
		}
	}
	return false;
}
int main() {
	int n;
	cin>>n;
	int mat[1000][1000]={0};
	int count=0;
	print(mat,0,n,count);
	cout<<endl;
	cout<<count;
	return 0;
}
