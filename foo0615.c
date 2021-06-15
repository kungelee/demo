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

//��������ṹ 
	void BuildStorageSpace(Node *List) {
		Node *p = List->next;
		FILE *fp;
		fp = fopen("D:\\�̲�����.txt","w+");
		if (fp == NULL)
		{
			printf("�ļ��򿪳���!");
			exit(0);
		}
		fprintf(fp,"���\t����\t����\t������\t����\t����\t���\n");
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
	//¼��̲�������Ϣ
	void inputInformation(Node *p,int i) 
	{
		printf("�������%d����ţ�",i+1);
		scanf("%s",p->no); 
		printf("�������%d��������",i+1);
		scanf("%s",p->name); 
		printf("�������%d�������ߣ�",i+1);
		scanf("%s",p->author); 
		printf("�������%d��������̣�",i+1);
		scanf("%s",p->publisher); 
		printf("�������%d����������",i+1);
		scanf("%d",p->number); 
		printf("�������%d�����ۣ�",i+1);
		scanf("%f",p->price); 
		printf("�������%d����",i+1);
		scanf("%f",p->total); 
	}
	//��ʼ������
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
//��������
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
 //���ҽ̲���Ϣ
 void searchIformation(Node *List) 
 {
 	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("����Ϊ���޷���ѯ��");
		return;
	}
	printf("������Ҫ���ҵ�����:");
    scanf("%s",&n);
	printf("\n");
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("δ��ѯ������");
			return;
		}
		} 
			printf("�������%d����ţ�",i+1);
		scanf("%s",p->no); 
		printf("�������%d��������",i+1);
		scanf("%s",p->name); 
		printf("�������%d�������ߣ�",i+1);
		scanf("%s",p->author); 
		printf("�������%d��������̣�",i+1);
		scanf("%s",p->publisher); 
		printf("�������%d����������",i+1);
		scanf("%d",p->number); 
		printf("�������%d�����ۣ�",i+1);
		scanf("%f",p->price); 
		printf("�������%d����",i+1);
		scanf("%f",p->total); 
 }

// �޸Ľ̲ĵ���������
void reviseInformation(Node List)
{
	char n[40];
	Node *p=List->next;
	if(p==NULL)
	{
		printf("����Ϊ�����޸ģ�");
		return;
    }
    printf("��������Ҫ�޸Ľ̲ĵ����ƣ�");
    scanf("%s",n);
	while(strcmp(n,p->name)!=0)
	{
		p=p->next;
		if(p==NULL)
		{
			printf("���޴�����Ϣ��");
			return;
		}
	} 
	printf("�������޸ĺ������");
	scanf("%s",p->number);
	printf("�޸ĳɹ�\n");
 } 
//ɾ��ĳ���̲ĵ������Ϣ
void deleteInformation(Node List)
{
	char n[40];
	Node *p=List->next,*q=NULL;
	if(p==NULL)
	{
		printf("����Ϊ���޷�ɾ����");
		return;
	}
	printf("������Ҫɾ��������");
    scanf("%s",n);
	for(q=List;(strcmp(n,p->name)!=0)&&p;p=p->next)
		q=p;
	if(p==NULL)
	{
		printf("���޴�����Ϣ��");
		return;
	}
	q->next=p->next;
	free(p);
	printf("ɾ���ɹ�\n");
 } 
 //�����������������
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
	 printf("����%d���飺",sum);
	 printf("�ܽ��Ϊ%dԪ��",total);
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

