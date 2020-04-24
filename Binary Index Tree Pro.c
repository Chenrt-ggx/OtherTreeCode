#include <stdio.h>

int n,a[500100],tr[500100];

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
	int x,y,r,k,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	while (m--)
	{
		scanf("%d",&r);
		if (r==1)
		{
			scanf("%d %d %d",&x,&y,&k);
			add(x,k),add(y+1,-k);
		}
		if (r==2)
		{
			scanf("%d",&x);
			printf("%d\n",a[x]+sum(x));
		}
	}
	return 0;
}