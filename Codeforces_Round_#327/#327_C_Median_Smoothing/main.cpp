#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
#define rep(i, l, r) for(int i=l; i<=r; i++)
#define down(i, l, r) for(int i=l; i>=r; i--)
#define clr(x, c) memset(x, c, sizeof(x))
#define travel(x) for(edge *p=fir[x]; p; p=p->n)
#define maxn 500009
#define inf 0x7fffffff
#define ll long long
#define ull unsigned long long
#define l(x) Left[x]
#define r(x) Right[x]
using namespace std;
int read()
{
	int x=0, f=1; char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+ch-'0', ch=getchar();
	return x*f;
}
int n, k[maxn], c[maxn];
int main()
{
	n=read(); rep(i, 1, n) k[i]=read();
	int now=0, mx=1; rep(i, 1, n)
	{
		now-=2; if (now<=0) now=1;
		while (i+now<=n && i-now>=1 && k[i+now-1]+k[i+now]==1 && k[i+now]==k[i-now]) now++;
		mx=max(mx, now);
		c[i]=k[i+now-1];
	}
	printf("%d\n", mx-1);
	rep(i, 1, n) printf("%d%c", c[i], i==n?'\n':' ');
	return 0;
}
