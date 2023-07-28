#include<iostream>
using namespace std;
void printify(string s,string &m,int i,int n)
{
	if(i==n)
	{
		return;
	}
	if(s[i+1]!='\0'&&s[i]==s[i+1])
	{
		m=m+s[i]+"*";
		printify(s,m,i+1,n);
	}
	else
	{
		m=m+s[i];
		printify(s,m,i+1,n);
	}
}
int main() {
	string s;
	cin>>s;
    int n=s.size();
	string m="";
	printify(s,m,0,n);
	cout<<m;
	return 0;
}
