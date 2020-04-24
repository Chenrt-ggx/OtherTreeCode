#include <stdio.h>
#include <string.h>

int tim,con;
long long int ans=1;
char fst[30],lst[30],flg[30];

void cal(int lfst,int rfst,int llst,int rlst)
{
	if (lfst==rfst) return;
	if (fst[lfst+1]==lst[rlst-1])
	{
		ans<<=1,tim++;
		cal(lfst+1,rfst,llst,rlst-1);
		return;
	}
	int pos; for (int i=0;fst[i];i++)
	if (fst[i]==lst[rlst-1]) {pos=i; break;}
	cal(lfst+1,pos-1,llst,llst+pos-lfst-2);
	cal(pos,rfst,rlst+pos-rfst-1,rlst-1);
	return;
}

void solve(int lfst,int rfst,int llst,int rlst)
{
	if (lfst==rfst)
	{putchar(fst[lfst]); return;}
	if (fst[lfst+1]==lst[rlst-1])
	{
		if (flg[con++])
		{
			solve(lfst+1,rfst,llst,rlst-1);
			putchar(fst[lfst]);
		}
		else
		{
			putchar(fst[lfst]);
			solve(lfst+1,rfst,llst,rlst-1);
		}
		return;
	}
	int pos; for (int i=0;fst[i];i++)
	if (fst[i]==lst[rlst-1]) {pos=i; break;}
	solve(lfst+1,pos-1,llst,llst+pos-lfst-2);
	putchar(fst[lfst]);
	solve(pos,rfst,rlst+pos-rfst-1,rlst-1);
	return;
}

int main()
{
	scanf("%s",fst);
	scanf("%s",lst);
	int len=strlen(fst)-1;
	cal(0,len,0,len);
	printf("%lld\n",ans);
	for (int i=0;i<ans;i++)
	{
		int t=i; con=0;
		for (int j=0;j<tim;j++)
		flg[j]=t&1,t>>=1;
		solve(0,len,0,len);
		printf("\n");
	}
	return 0;
}