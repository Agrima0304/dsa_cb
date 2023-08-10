#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(string s,int i,set<string>& ans)
{
	if(i==s.size())
	{
		ans.insert(s);
		return;
	}
	for(int j=i;j<s.size();j++)
	{
		swap(s[j],s[i]);
		solve(s,i+1,ans);
		swap(s[j],s[i]);//backtrack
	}
}
int main() {
	string s;
	cin>>s;
	set<string> ans;
	solve(s,0,ans);
   //	sort(ans.begin(),ans.end());
	bool check=false;
	for(auto x:ans)
	{
		cout<<x<<endl;
	}
	
	return 0;
}
