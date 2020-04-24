#include <stdio.h>

typedef long long int lld;
lld ls(lld a) {return a<<1;}
lld rs(lld a) {return a<<1|1;}
lld arr[100100],tr[400100],tag[400100];

void build(lld p,lld l,lld r)
{
	if (l==r) {tr[p]=arr[l]; return;}
	lld mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	tr[p]=tr[ls(p)]+tr[rs(p)];
	return;
}

void f(lld p,lld l,lld r,lld k)
{
	tag[p]+=k;
	tr[p]+=k*(r-l+1);
	return;
}

void spread(lld p,lld l,lld r)
{
	if (tag[p])
	{
		lld mid=(l+r)>>1;
		f(ls(p),l,mid,tag[p]);
		f(rs(p),mid+1,r,tag[p]);
		tag[p]=0;
	}
	return;
}

void add(lld p,lld l,lld r,lld x,lld y,lld k)
{
	if (x<=l && r<=y)
	{tr[p]+=k*(r-l+1),tag[p]+=k; return;}
	spread(p,l,r); lld mid=(l+r)>>1;
	if (x<=mid) add(ls(p),l,mid,x,y,k);
	if (y>mid) add(rs(p),mid+1,r,x,y,k);
	tr[p]=tr[ls(p)]+tr[rs(p)];
	return;
}

lld show(lld p,lld l,lld r,lld x,lld y)
{
	if (x<=l && r<=y) return tr[p];
	spread(p,l,r); lld mid=(l+r)>>1,ans=0;
	if (x<=mid) ans+=show(ls(p),l,mid,x,y);
	if (y>mid) ans+=show(rs(p),mid+1,r,x,y);
	return ans;
}

int main()
{
	lld n,m,r,x,y,k;
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++)
	scanf("%lld",&arr[i]);
	build(1,1,n);
	while (m--)
	{
		scanf("%lld",&r);
		if (r==1)
		{
			scanf("%lld %lld %lld",&x,&y,&k);
			add(1,1,n,x,y,k);
			continue;
		}
		if (r==2)
		{
			scanf("%lld %lld",&x,&y);
			k=show(1,1,n,x,y);
			printf("%lld\n",k);
		}
	}
	return 0;
}