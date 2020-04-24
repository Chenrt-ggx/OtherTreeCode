#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 2147483647

struct tree
{
	struct tree* ls;
	struct tree* rs;
	char c; int weight;
};

typedef struct tree stu;
typedef struct tree* ptr;

int cnt[128];
char code[128][32];
char buffer[11111111];
ptr root; FILE *in,*out;

void count()
{
	char c; cnt[0]++;
	while ((c=fgetc(in))!=EOF)
	if (c!='\n') cnt[(int)c]++;
	return;
}

void bulid()
{
	ptr lft,rht; int m1,m2,n1,n2,tot=0,vis[260]={0};
	for(int i=0;i<128;i++) if(cnt[i]) tot++;
	ptr* tree=(ptr*)malloc((2*tot-1)*sizeof(ptr));
	tot=0; for(int i=0;i<128;i++) if(cnt[i])
	{
		tree[tot]=(ptr)malloc(sizeof(stu));
		tree[tot]->c=i,tree[tot]->weight=cnt[i];
		tree[tot]->ls=tree[tot]->rs=NULL,tot++;
	}
	for (int t=tot;t<2*tot-1;t++)
	{
		n1=n2=0,m1=m2=INF,lft=rht=NULL;
		for (int i=0;i<t;i++) if (!vis[i])
		{
			if (tree[i]->weight<m1) n2=n1,m2=m1,rht=lft,
			n1=i,m1=tree[i]->weight,lft=tree[i];
			else if (tree[i]->weight<m2)
			n2=i,m2=tree[i]->weight,rht=tree[i];
		}
		vis[n1]=vis[n2]=1;
		tree[t]=(ptr)malloc(sizeof(stu));
		tree[t]->ls=lft,tree[t]->rs=rht;
		tree[t]->c=0,tree[t]->weight=m1+m2;
	}
	root=tree[2*tot-2]; return;
}

void dfs(ptr now,int pos,char s[])
{
	if (now->ls==NULL && now->rs==NULL)
	{strcpy(code[(int)now->c],s); return;}
	if (now->ls) s[pos]='0',dfs(now->ls,pos+1,s),s[pos]=0;
	if (now->rs) s[pos]='1',dfs(now->rs,pos+1,s),s[pos]=0;
	return;
}

void solve() {char s[32]={0}; dfs(root,0,s); return;}

void print()
{
	int i,con=0,ans=0;
	char c=0; rewind(in);
	while ((c=fgetc(in))!=EOF) if (c!='\n')
	strcat(buffer,code[(int)c]);
	strcat(buffer,code[0]);
	//puts(buffer);
	for (i=8;buffer[i];i+=8)
	{
		ans=0; for (int j=8;j;j--)
		ans<<=1,ans|=(buffer[i-j]-'0');
		fputc(ans,out),printf("%x",ans);
	}
	ans=0,i-=8; while (buffer[i])
	con++,ans<<=1,ans|=(buffer[i++]-'0');
	ans<<=(8-con),fputc(ans,out);
	printf("%x\n",ans); return;
}

void show1()
{
	printf("NUL:1\n");
	for (int i=1;i<128;i++) if (cnt[i])
	printf("%c:%d\n",i,cnt[i]); return;
}

void fst(ptr p)
{
	if (p==NULL) return;
	if (p->ls==NULL && p->rs==NULL) 
	switch (p->c)
	{
		case 0: printf("NUL "); break;
		case 32: printf("SP "); break;
		case '\t': printf("TAB "); break;
		case '\n': printf("CR "); break;
		default : printf("%c ",p->c); break;
	}
	fst(p->ls),fst(p->rs);
	return;
}

void show2() {fst(root),puts(""); return;}

void show3()
{
	for (int i=0;i<128;i++) if (code[i][0])
	{
		switch (i)
		{
			case 0: printf("NUL:"); break;
			case 32: printf("SP:"); break;
			case '\t': printf("TAB:"); break;
			case '\n': printf("CR:"); break;
			default : printf("%c:",i); break;
		}
		puts(code[i]);
	}
	return;
}

void show4()
{
	long int sizin,sizout;
	fseek(in,0,SEEK_END);
	fseek(out,0,SEEK_END);
	sizin=ftell(in),sizout=ftell(out);
	printf("\n原文件大小：%ldB\n",sizin);
	printf("压缩后文件大小：%ldB\n",sizout);
	printf("压缩率：%.2f%%\n",(double)(sizin-sizout)*100/sizin);
	return;
}

int main()
{
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	count(); //show1();
	bulid(); //show2();
	solve(); //show3();
	print(); //show4();
	fclose(in),fclose(out);
	return 0;
}