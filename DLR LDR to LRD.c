#include <stdio.h>
#include <string.h>

char fst[30],mid[30];

void solve(int lfst,int rfst,int lmid,int rmid)
{
	int pos; for (int i=0;mid[i];i++)
	if (mid[i]==fst[lfst]) {pos=i; break;}
	if (pos>lmid) solve(lfst+1,lfst+pos-lmid,lmid,pos-1);
	if (pos<rmid) solve(rfst+pos-rmid+1,rfst,pos+1,rmid);
	putchar(fst[lfst]);
	return;
}

int main()
{
	scanf("%s",fst);
	scanf("%s",mid);
	int len=strlen(fst);
	solve(0,len-1,0,len-1);
	return 0;
}