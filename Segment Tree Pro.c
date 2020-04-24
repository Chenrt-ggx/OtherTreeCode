#include <stdio.h>

typedef long long int lld;
lld ls(lld x) {return x<<1;}
lld rs(lld x) {return x<<1|1;}
lld n,c,a[100010],tr[400010],tag1[400010],tag2[400010];

void build(lld p,lld l,lld r)
{
	if (l==r) {tr[p]=a[l]; return;}
	lld mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	tr[p]=(tr[ls(p)]+tr[rs(p)])%c;
	return;
}

void spread(lld p,lld l,lld r)
{
	lld mid=(l+r)>>1;
	tr[ls(p)]=(tr[ls(p)]*tag2[p]+(mid-l+1)*tag1[p])%c;
	tr[rs(p)]=(tr[rs(p)]*tag2[p]+(r-mid)*tag1[p])%c;
	tag2[ls(p)]*=tag2[p],tag2[ls(p)]%=c;
	tag2[rs(p)]*=tag2[p],tag2[rs(p)]%=c;
	tag1[ls(p)]=(tag1[ls(p)]*tag2[p]+tag1[p])%c;
	tag1[rs(p)]=(tag1[rs(p)]*tag2[p]+tag1[p])%c;
	tag1[p]=0,tag2[p]=1;
	return;
}

void pow(lld p,lld l,lld r,lld x,lld y,lld k)
{
	if (x<=l && r<=y)
	{
		tr[p]*=k,tr[p]%=c;
		tag1[p]*=k,tag1[p]%=c;
		tag2[p]*=k,tag2[p]%=c;
		return;
	}
	spread(p,l,r); lld mid=(l+r)>>1;
	if (x<=mid) pow(ls(p),l,mid,x,y,k);
	if (y>mid) pow(rs(p),mid+1,r,x,y,k);
	tr[p]=(tr[ls(p)]+tr[rs(p)])%c;
	return;
}

void add(lld p,lld l,lld r,lld x,lld y,lld k)
{
	if (x<=l && r<=y)
	{
		tr[p]+=(r-l+1)*k,tr[p]%=c;
		tag1[p]+=k,tag1[p]%=c;
		return;
	}
	spread(p,l,r); lld mid=(l+r)>>1;
	if (x<=mid) add(ls(p),l,mid,x,y,k);
	if (y>mid) add(rs(p),mid+1,r,x,y,k);
	tr[p]=(tr[ls(p)]+tr[rs(p)])%c;
	return;
}

lld show(lld p,lld l,lld r,lld x,lld y)
{
	if (x<=l && r<=y) return tr[p]%c;
	spread(p,l,r); lld mid=(l+r)>>1,ans=0;
	if (x<=mid) ans+=show(ls(p),l,mid,x,y);
	if (y>mid) ans+=show(rs(p),mid+1,r,x,y);
	return ans%c;
}

int main()
{
	lld m,r,x,y,k;
	scanf("%lld %lld %lld",&n,&m,&c);
	for (lld i=1;i<=n;i++)
	scanf("%lld",&a[i]),a[i]%=c;
	build(1,1,n);
	for (lld i=0;i<=(n<<2);i++)
	tag1[i]=0,tag2[i]=1;
	while (m--)
	{
		scanf("%lld",&r);
		if (r==1)
		{
			scanf("%lld %lld %lld",&x,&y,&k);
			pow(1,1,n,x,y,k);
			continue;
		}
		if (r==2)
		{
			scanf("%lld %lld %lld",&x,&y,&k);
			add(1,1,n,x,y,k);
			continue;
		}
		if (r==3)
		{
			scanf("%lld %lld",&x,&y);
			k=show(1,1,n,x,y);
			printf("%lld\n",k);
		}
	}
	return 0;
}