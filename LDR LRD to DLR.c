#include <stdio.h>
#include <string.h>

char mid[30],lst[30];

void solve(int lmid,int rmid,int llst,int rlst)
{
	int pos;
	putchar(lst[rlst]);
	for (int i=0;mid[i];i++)
	if (mid[i]==lst[rlst]) {pos=i; break;}
	if (pos>lmid) solve(lmid,pos-1,llst,rlst-rmid+pos-1);
	if (pos<rmid) solve(pos+1,rmid,llst-lmid+pos,rlst-1);
	return;
}

int main()
{
	scanf("%s",mid);
	scanf("%s",lst);
	int len=strlen(mid);
	solve(0,len-1,0,len-1);
	return 0;
}