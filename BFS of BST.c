#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node* ls;
	struct node* rs;
};

typedef struct node stu;
typedef struct node* ptr;

ptr bulid(char c)
{
	ptr p;
	if (c=='*') return NULL;
	p=(ptr)malloc(sizeof(stu));
	p->data=c;
	p->ls=p->rs=NULL;
	return p;
}

ptr find(ptr p,char c)
{
	ptr ans=NULL;
	if (p->data==c) return p;
	if (p->ls) ans=find(p->ls,c);
	if (ans) return ans;
	if (p->rs) ans=find(p->rs,c);
	if (ans) return ans;
	return NULL;
}

stu que[50];

void bfs(ptr p)
{
	que[0]=*p;
	int head=0,tail=1;
	while (head<tail)
	{
		putchar(que[head].data);
		if (que[head].ls) que[tail++]=*que[head].ls;
		if (que[head].rs) que[tail++]=*que[head].rs;
		head++;
	}
	return;
}

int main()
{
	char s[5];
	ptr p,f; int n;
	scanf("%d",&n);
	scanf("%s",s);
	p=(ptr)malloc(sizeof(stu));
	p->data=s[0];
	p->ls=bulid(s[1]);
	p->rs=bulid(s[2]);
	for (int i=1;i<n;i++)
	{
		scanf("%s",s);
		f=find(p,s[0]);
		f->ls=bulid(s[1]);
		f->rs=bulid(s[2]);
	}
	bfs(p),puts("");
	return 0;
}