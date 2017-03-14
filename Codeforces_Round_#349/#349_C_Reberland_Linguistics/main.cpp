#include <bits/stdc++.h>
using namespace std;
char s[10010];
bool flag[10010][4];
set<string>ans;
void DFS(int p,int len)
{
	if(flag[p][len] || p-len<5)return ;
	flag[p][len]=true;
	//printf("p=%d len=%d\n",p,len);
	string u1(s+p-len,s+p);
	string u2(s+p-len*2,s+p-len);
	//cout<<u1<<endl<<u2<<endl;
	ans.insert(u1);
	if(u1!=u2)
		DFS(p-len,len);
	DFS(p-len,(len==2?3:2));
}
int main()
{
	gets(s);
	int len=strlen(s);
	DFS(len,2);
	DFS(len,3);
	printf("%d\n",ans.size());
	for(auto c : ans)
		cout<<c<<endl;
	return 0;
}
