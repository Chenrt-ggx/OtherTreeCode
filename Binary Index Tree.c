#include <stdio.h>

int n,tr[500100];

void add(int x,int k)
{
	while (x<=n)
	{
		tr[x]+=k;
		x+=x&-x;
	}
	return;
}

int sum(int x)
{
	int ans=0;
	while (x)
	{
		ans+=tr[x];
		x-=x&-x;
	}
	return ans;
}

int main()
{
	int x,y,r,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&r),add(i,r);
	while (m--)
	{
		scanf("%d %d %d",&r,&x,&y);
		if (r==1) add(x,y);
		if (r==2) printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}