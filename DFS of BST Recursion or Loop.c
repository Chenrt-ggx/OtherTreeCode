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

void fst_digui(ptr p)
{
	putchar(p->data);
	if (p->ls) fst_digui(p->ls);
	if (p->rs) fst_digui(p->rs);
	return;
}

void fst_xunhuan(ptr p)
{
	int tot=0; ptr stk[30];
	while (p || tot)
	{
		while (p)
		{
			putchar(p->data);
			stk[tot++]=p;
			p=p->ls;
		}
		p=stk[--tot];
		p=p->rs;
	}
	return;
}

void mid_digui(ptr p)
{
	if (p->ls) mid_digui(p->ls);
	putchar(p->data);
	if (p->rs) mid_digui(p->rs);
	return;
}

void mid_xunhuan(ptr p)
{
	int tot=0; ptr stk[30];
	while (p || tot)
	{
		while (p)
		{
			stk[tot++]=p;
			p=p->ls;
		}
		p=stk[--tot];
		putchar(p->data);
		p=p->rs;
	}
	return;
}

void lst_digui(ptr p)
{
	if (p->ls) lst_digui(p->ls);
	if (p->rs) lst_digui(p->rs);
	putchar(p->data);
	return;
}

void lst_xunhuan(ptr p)
{
	int tot1=0,tot2=0;
	ptr stk1[30],stk2[30];
	while (p || tot1)
	{
		while (p)
		{
			stk1[tot1++]=p;
			stk2[tot2++]=p;
			p=p->rs;
		}
		p=stk1[--tot1];
		p=p->ls;
	}
	while (tot2)
	putchar(stk2[--tot2]->data);
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
	fst_digui(p),puts("");
	fst_xunhuan(p),puts("");
	mid_digui(p),puts("");
	mid_xunhuan(p),puts("");
	lst_digui(p),puts("");
	lst_xunhuan(p),puts("");
	return 0;
}