#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node;
typedef struct node
	{
		char no[12];
		char name[40];
		char author[40];
		char publisher[40];
		int number;
		float price;
		float total;
		struct node* next;
	}Node;
void caculateInformation(Node List);
void deleteInformation(Node List);
void reviseInformation(Node List);
void searchIformation(Node List);
void *creatist(Node *List,int n);
void Node *resetList(Node *List);
void inputInformation(Node *p,int i);
void BuildStorageSpace(Node *List);

//建立储存结构 
	void BuildStorageSpace(Node *List) {
		Node *p = List->next;
		FILE *fp;
		fp = fopen("D:\\教材征订.txt","w+");
		if (fp == NULL)
		{
			printf("文件打开出错!");
			exit(0);
		}
		fprintf(fp,"书号\t书名\t作者\t出版社\t数量\t单价\t金额\n");
		for ( i = 0; i < N; i++) {
			fprintf(fp,"%s\t",p->no);
			fprintf(fp,"%s\t",p->name);
			fprintf(fp,"%s\t",p->author);
			fprintf(fp,"%s\t",p->publisher);
			fprintf(fp,"%d\t",p->number);
			fprintf(fp,"%f\t",p->price);
			fprintf(fp,"%f\t",p->total);
			fprintf(fp,"\n");
			p=p->next;
			fclose(fp);
		}
	//录入教材征订信息
	void inputInformation(Node *p,int i) 
	{
		printf("请输入第%d本书号：",i+1);
		scanf("%s",p->no); 
		printf("请输入第%d本书名：",i+1);
		scanf("%s",p->name); 
		printf("请输入第%d本书作者：",i+1);
		scanf("%s",p->author); 
		printf("请输入第%d本书出版商：",i+1);
		scanf("%s",p->publisher); 
		printf("请输入第%d本书数量：",i+1);
		scanf("%d",p->number); 
		printf("请输入第%d本单价：",i+1);
		scanf("%f",p->price); 
		printf("请输入第%d本金额：",i+1);
		scanf("%f",p->total); 
	}
	//初始化链表
	Node *resetList(Node *List) 
	{
		Node *head = NULL;
		head=(Node)*malloc(sezeof(Node));
		if(!head)
		  return false;
		  head->next=NULL;
		  List = head;
		  return List;
	}
//创建链表
void *creatist(Node *List,int n)
{
	Node *p = NULL;
	for(int i;i<n;i++)
	{
		p=(Node*)malloc(sizeof(Node));
		inputInformation(p,i);
		p->next=List->next;
		List->next=p;
	}
	return List;
 } 
 //查找教材信息
 void searchIformation(Node *List) 
 {
 	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("链表为空无法查询！");
		return;
	}
	printf("请输入要查找的书名:");
    scanf("%s",&n);
	printf("\n");
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("未查询到该书");
			return;
		}
		} 
			printf("请输入第%d本书号：",i+1);
		scanf("%s",p->no); 
		printf("请输入第%d本书名：",i+1);
		scanf("%s",p->name); 
		printf("请输入第%d本书作者：",i+1);
		scanf("%s",p->author); 
		printf("请输入第%d本书出版商：",i+1);
		scanf("%s",p->publisher); 
		printf("请输入第%d本书数量：",i+1);
		scanf("%d",p->number); 
		printf("请输入第%d本单价：",i+1);
		scanf("%f",p->price); 
		printf("请输入第%d本金额：",i+1);
		scanf("%f",p->total); 
 }

// 修改教材的征订数量
void reviseInformation(Node List)
{
	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("链表为空无修改！");
		return;
    }
    printf("请输入需要修改教材的名称：");
    scanf("%s",n);
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("暂无此书信息！");
			return;
		}
	} 
	printf("请输入修改后的数量");
	scanf("%s",p->number);
	printf("修改成功\n");
 } 
//删除某本教材的相关信息
void deleteInformation(Node List)
{
	char n[40];
	Node *p=List->next,*q=NULL;
	if(p==NULL)
	{
		printf("链表为空无法删除！");
		return;
	}
	printf("请输入要删除的书名");
    scanf("%s",n);
	for(q=List;(strcmp(n,p->name)!=0)&&p;p=p->next)
		q=p;
	if(p==NULL)
	{
		printf("暂无此书信息！");
		return;
	}
	q->next=p->next;
	free(p);
	printf("删除成功\n");
 } 
 //计算征订总数、金额
 void caculateInformation(Node List)
 {
 	Node *p;
 	int sum,total = 0;
 	p=head;
 	while(p!=NULL)
 	{
 		sum+=p->number;
 		total+=(p->number)*(p->price);
 		p=p->next;
 		
	 }
	 printf("共有%d本书：",sum);
	 printf("总金额为%d元：",total);
  } 
  
 void main()
 {
 	void caculateInformation(Node List);
void deleteInformation(Node List);
void reviseInformation(Node List);
void searchIformation(Node List);
void *creatist(Node *List,int n);
void Node *resetList(Node *List);
void inputInformation(Node *p,int i);
void BuildStorageSpace(Node *List);

 }

