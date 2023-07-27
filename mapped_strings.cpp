#include<iostream>
using namespace std;
void printify(string s,char out[],int i,int j)
{
	if(s[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int id=s[i]-'0';
	char c='A'+id-1;
	out[j]=c;
	printify(s,out,i+1,j+1);
	if(s[i+1]!='\0')
	{
		int sd=s[i+1]-'\0';
		int fm=id*10+sd;
		if(fm<=26)
		{
			char ch='A'+fm-1;
			out[j]=ch;
			printify(s,out,i+2,j+1);
		}
	}
}
int main() {
	string s;
	cin>>s;\
	char out[100];
	printify(s,out,0,0);
	return 0;
}
