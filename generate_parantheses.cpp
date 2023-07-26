#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
vector<string> j;
static bool compare(string a,string b)
{
	return "(">")";
}
void printify(int n, int open, int close, string m) {
    if (m.size() == 2 * n) {
        j.push_back(m);
        return;
    }

    if (open < n) {
        printify(n, open + 1, close, m + "(");
    }
    if (close < open) {
        printify(n, open, close + 1, m + ")");
    }
}

int main() {
    int n;
    cin >> n;
    string s ="";
    printify(n, 0, 0, s);
	reverse(j.begin(),j.end());
	for(auto x:j)
	{
		cout<<x<<endl;
	}
    return 0;
}
