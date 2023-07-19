#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int s,int e)
{
	int i=s-1;
	for(int j=s;j<e;j++)
	{
		if(a[j]<a[e])
		{
			i++;
			swap(a[i],a[j]);
		}
		
	}
	swap(a[i+1],a[e]);
	return i+1;
}
void qsort(int *a,int s,int e)
{
	if(s>=e)
	{
		return;
	}
	int index=partition(a,s,e);
	qsort(a,s,index-1);
	qsort(a,index+1,e);
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
