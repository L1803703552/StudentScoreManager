#include <stdio.h>
#include <windows.h>//����Windows API 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NUM 100 //���ѧ������ 
typedef struct
{
	char name[20];
	char xh[12];
	float sub1;
	float sub2;
	float sub3;
	float sub4;
	float sub5;
	float sub6;
}STUTYPE; 
STUTYPE stu[NUM];
//��������... 
void rea(int *n);//��ȡ 
void welcome1(int *n);//û���� 
void welcome2(int *n);//������ 
void step1(int *n);//���롢���� 
void step2(int *n);//��ʾ 
void step3(int *n);//���� 
void step4(int *n);//���� 
void step5(int *n);//�޸� 
void step6(int *n);//ɾ�� 
void step7(int *n);//���� 
void step8(int *n);//���� 
int main()
{
	int n; 
	//EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED);//���ùرհ�ť --by:����̳� 
	SetConsoleTitle("ѧ���ɼ�����ϵͳV3.2 --by:306-1");//���Ĵ��ڱ��� --by:����̳� 
	
	rea(&n);
	do{
		if(n==0)
			welcome1(&n);
		else
			welcome2(&n);
	}while(1);
	return 0;
}
void rea(int *n)//��ȡ 
{
	FILE *fp;
	int i;
	char s[255],p[255],ch;
	if((fp=fopen("config.db","r"))!=NULL)
	{
		fgets(p,255,fp);
		do{
			printf("���������룺");
			i=0;
			do{
				s[i]=getch();
				if(s[i]=='\r')
					break;
				if(s[i]=='\b')
				{
					if(i==0)
					{
						printf("\a");
						continue;
					}
					i--;
					printf("\b");
					printf(" ");
					printf("\b");
				}
				else
				{
					i++;
					printf("*");
				}
			}while(s[i]!='\n'&&i<255);
			s[i]=0;
			if(strcmp(s,p)!=0)
			{
				printf("\n�������\n");
			}
		}while(strcmp(s,p)!=0);
		fclose(fp); 
	}
	if((fp=fopen("data.txt","r"))==NULL)
	{
		*n=0;
		return;
	}
	fscanf(fp,"%d",n);
	for(i=0;!feof(fp)&&i<NUM;i++)
	{
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%s",stu[i].xh);
		fscanf(fp,"%f",&stu[i].sub1);
		fscanf(fp,"%f",&stu[i].sub2);
		fscanf(fp,"%f",&stu[i].sub3);
		fscanf(fp,"%f",&stu[i].sub4);
		fscanf(fp,"%f",&stu[i].sub5);
		fscanf(fp,"%f",&stu[i].sub6);
	}
	if(i==NUM)//����������� 
		*n=NUM;
	fclose(fp);
}
void welcome1(int *n)//û���� 
{
	char str[3];
	int ch; 
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ����������������������������������������������������������������������\n");
	printf("                     ��    ѧ���ɼ�����ϵͳ���˵�����   ��\n");
	printf("                     �ǩ�������������������������������������������������������������������\n");
	printf("                     ��         ��.����ѧ���ɼ�         ��\n");
	printf("                     ��         ��.������һ��           ��\n");
	printf("                     ��         ��.�˳�ϵͳ             ��\n");
	printf("                     ����������������������������������������������������������������������\n");
	printf("                         ����������ѡ��(1--3):( )\b\b");
	scanf("%s",str);
	if(atoi(str)>3 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ����������������������������������������������������������������������\n");
			printf("                     ��    ѧ���ɼ�����ϵͳ���˵�����   ��\n");
			printf("                     �ǩ�������������������������������������������������������������������\n");
			printf("                     ��         ��.����ѧ���ɼ�         ��\n");
			printf("                     ��         ��.������һ��           ��\n");
			printf("                     ��         ��.�˳�ϵͳ             ��\n");
			printf("                     ����������������������������������������������������������������������\n");
			printf("                        �Բ���,������1-3�⼸������!!!\n");
			printf("                         ����������ѡ��(1--3):( )\b\b");
			gets(str);
		}while(atoi(str)>3 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
			printf("******************************************************************************\n");
			printf("\n -------------<<�뽨��ѧ��������Ϣ��,������������ # �������롣>>-------------\n");
			step1(n);
			break;
		case 2: 
			system("start setup.exe");
			exit(0);
			break;
		case 3:
			printf("******************************************************************************\n");
			printf("------------------------<<лл��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0); 
	}
}
void welcome2(int *n)//������ 
{
	char str[3];
	int ch;
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ����������������������������������������������������������������������\n");
	printf("                     ��    ѧ���ɼ�����ϵͳ���˵�����   ��\n");
	printf("                     �ǩ�������������������������������������������������������������������\n");
	printf("                     ��         ��.����ѧ���ɼ�         ��\n");
	printf("                     ��         ��.��ʾѧ���ɼ�         ��\n");
	printf("                     ��         ��.����ѧ���ɼ�         ��\n");
	printf("                     ��         ��.����ͳ�Ƴɼ�         ��\n");
	printf("                     ��         ��.�޸�ѧ���ɼ�         ��\n");
	printf("                     ��         ��.ɾ��ѧ���ɼ�         ��\n");
	printf("                     ��         ��.�����˳�ϵͳ         ��\n");
	printf("                     ��         ��.����ѧ���ɼ�         ��\n");
	printf("                     ��         ��.������һ��           ��\n");
	printf("                     ��         ��.�˳�ϵͳ             ��\n");
	printf("                     ����������������������������������������������������������������������\n");
	printf("                         ����������ѡ��(1--10):");
	scanf("%s",str);
	if(atoi(str)>10 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<��ӭ��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ����������������������������������������������������������������������\n");
			printf("                     ��    ѧ���ɼ�����ϵͳ���˵�����   ��\n");
			printf("                     �ǩ�������������������������������������������������������������������\n");
			printf("                     ��         ��.����ѧ���ɼ�         ��\n");
			printf("                     ��         ��.��ʾѧ���ɼ�         ��\n");
			printf("                     ��         ��.����ѧ���ɼ�         ��\n");
			printf("                     ��         ��.����ͳ�Ƴɼ�         ��\n");
			printf("                     ��         ��.�޸�ѧ���ɼ�         ��\n");
			printf("                     ��         ��.ɾ��ѧ���ɼ�         ��\n");
			printf("                     ��         ��.�����˳�ϵͳ         ��\n");
			printf("                     ��         ��.����ѧ���ɼ�         ��\n");
			printf("                     ��         ��.������һ��           ��\n");
			printf("                     ��         ��.�˳�ϵͳ             ��\n");
			printf("                     ����������������������������������������������������������������������\n");
			printf("                        �Բ���,������1--10�⼸������!!!\n");
			printf("                         ����������ѡ��(1--10):");
			gets(str);
		}while(atoi(str)>10 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			system("cls");
			printf("----------------<<����������ѧ���ɼ���Ϣ,������������ # �������롣>>----------------\n");
			step1(n);
			break;
		case 2:
			step2(n);
			break;
		case 3:
			step3(n);
			break;
		case 4:
			step4(n);
			break;
		case 5:
			step5(n);
			break; 
		case 6:
			step6(n);
			break; 
		case 7:
			step7(n);
			break; 
		case 8:
			step8(n);
			break; 
		case 9:
			system("start setup.exe");
			exit(0);
			break;
		case 10:
			printf("******************************************************************************\n");
			printf("------------------------<<лл��ʹ��ѧ���ɼ�����ϵͳ>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0); 
	}
}
void step1(int *n)//���롢���� 
{
	int i; 
	if(*n>=NUM)
	{
		system("cls");
		printf("��ǰѧ�������ѱ��ͣ��������������!\n");
		printf("�������������һ��...");
		system("pause>nul");
		return; 
	}
	for(i=*n;i<NUM;i++,(*n)++) 
	{
		printf("������������");
		scanf("%s",stu[i].name);
		if(strcmp(stu[i].name,"#")==0) 
			break;
		printf("������ѧ��(10λ)��");
		scanf("%s",stu[i].xh);
		while(strlen(stu[i].xh)!=10)
		{
			printf("�Բ���,����ȷ����!!!\n");
			scanf("%s",stu[i].xh);
		} 
		printf("������ѧ��1�ĳɼ���");
		scanf("%f",&stu[i].sub1);
		while(stu[i].sub1>100 || stu[i].sub1<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub1);
		}
		printf("������ѧ��2�ĳɼ���");
		scanf("%f",&stu[i].sub2);
		while(stu[i].sub2>100 || stu[i].sub2<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub2);
		}
		printf("������ѧ��3�ĳɼ���");
		scanf("%f",&stu[i].sub3);
		while(stu[i].sub3>100 || stu[i].sub3<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub3);
		}
		printf("������ѧ��4�ĳɼ���");
		scanf("%f",&stu[i].sub4);
		while(stu[i].sub4>100 || stu[i].sub4<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub4);
		}
		printf("������ѧ��5�ĳɼ���");
		scanf("%f",&stu[i].sub5);
		while(stu[i].sub5>100 || stu[i].sub5<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub5);
		}
		printf("������ѧ��6�ĳɼ���");
		scanf("%f",&stu[i].sub6);
		while(stu[i].sub6>100 || stu[i].sub6<0)
		{
			printf("�Բ���,������0-100֮�������!!\n");
			scanf("%f",&stu[i].sub6);
		}
	}
	if(i>=NUM)
	{
		printf("\n��ǰѧ�������ѱ��ͣ��������������!\n");
		printf("�������������һ��...");
		system("pause>nul");
	}
}
void step2(int *n)//��ʾ 
{
	int i;
	system("cls"); 
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf(" *ѧ�����Գɼ���Ϣ��*\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<*n;i++)
	{
		printf(" %-2d   ",i+1); 
		printf("%s  ",stu[i].xh);
		printf("%-12s",stu[i].name);
		printf("%-5.1f     ",stu[i].sub1);
		printf("%-5.1f     ",stu[i].sub2);
		printf("%-5.1f     ",stu[i].sub3);
		printf("%-5.1f     ",stu[i].sub4);
		printf("%-5.1f     ",stu[i].sub5);
		printf("%-5.1f     ",stu[i].sub6);
		printf("%-5.2f      ",(stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6)/6);
		printf("%-5.1f     ",stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6); 
		printf("\n");
	}
	printf("\n�������������һ��...");
	system("pause>nul");
} 
void step3(int *n)//���� 
{
	int p[NUM]={0};
	int i,j;
	char str[20];
	system("cls");
	printf("������ѧ�Ż�������");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("δ�ҵ�ƥ�����ݣ�");
	}
	else
	{
		printf("���ҵ�%d��ƥ������...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<j;i++)
		{
			printf(" %-2d   ",i+1); 
			printf("%s  ",stu[p[i]].xh);
			printf("%-12s",stu[p[i]].name);
			printf("%-5.1f     ",stu[p[i]].sub1);
			printf("%-5.1f     ",stu[p[i]].sub2);
			printf("%-5.1f     ",stu[p[i]].sub3);
			printf("%-5.1f     ",stu[p[i]].sub4);
			printf("%-5.1f     ",stu[p[i]].sub5);
			printf("%-5.1f     ",stu[p[i]].sub6);
			printf("%-5.2f      ",(stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6)/6);
			printf("%-5.1f     ",stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6); 
			printf("\n");
		}
	}
	printf("\n�������������һ��...");
	system("pause>nul"); 
}
void step4(int *n)//���� 
{
	int ch1,ch2;
	int i,j;
	float t,t2[NUM]; 
	char s[NUM][20],t1[20];
	STUTYPE temp;
	system("cls");
	printf("1.ѧ��    2.ѧ��1   3.ѧ��2\n");
	printf("4.ѧ��3   5.ѧ��4   6.ѧ��5\n");
	printf("7.ѧ��6   8.ƽ����  9.�ܷ�\n");
	printf("10.������һ��\n");
	printf("��ѡ����������(1--10)��");
	scanf("%d",&ch1);
	while(ch1>10||ch1<1)
	{
		printf("�Բ���,����ȷ����!!!\n");
		printf("��ѡ����������(1--10)��");
		scanf("%d",&ch1);
	}
	switch(ch1)
	{
		case 1:
			for(i=0;i<*n;i++)
				strcpy(s[i],stu[i].xh);
			break;
		case 2:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub1;
			break;
		case 3:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub2;
			break;
		case 4:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub3;
			break;
		case 5:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub4;
			break;
		case 6:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub5;
			break;
		case 7:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub6;
			break;
		case 8:
			for(i=0;i<*n;i++)
				t2[i]=(stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6)/6;
			break;
		case 9:
			for(i=0;i<*n;i++)
				t2[i]=stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6;
			break;
		case 10:
			return;
	}
	printf("1.����   2.����   3.������һ��\n");
	printf("��ѡ����������(1--3)��");
	scanf("%d",&ch2);
	while(ch2>3||ch2<1)
	{
		printf("�Բ���,����ȷ����!!!\n");
		printf("��ѡ����������(1--3)��");
		scanf("%d",&ch2);
	}
	switch(ch2)//ð������ 
	{
		case 1://���� 
			for(i=0;i<*n-1;i++)
			{
				for(j=0;j<*n-1-i;j++)
				{
					if(ch1==1)//ѧ��Ϊ�ַ������� 
					{
						if(strcmp(s[j],s[j+1])>0)
						{
							strcpy(t1,s[j]);strcpy(s[j],s[j+1]);strcpy(s[j+1],t1);
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
					else//�ɼ���ʵ�� 
					{
						if(t2[j]>t2[j+1])
						{
							t=t2[j];t2[j]=t2[j+1];t2[j+1]=t;
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
				}
			}
			break;
		case 2://���� 
			for(i=0;i<*n-1;i++)
			{
				for(j=0;j<*n-1-i;j++)
				{
					if(ch1==1)//ѧ��Ϊ�ַ������� 
					{
						if(strcmp(s[j],s[j+1])<0)
						{
							strcpy(t1,s[j]);strcpy(s[j],s[j+1]);strcpy(s[j+1],t1);
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
					else//�ɼ���ʵ�� 
					{
						if(t2[j]<t2[j+1])
						{
							t=t2[j];t2[j]=t2[j+1];t2[j+1]=t;
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
				}
			}
			break;
		case 3:
			return;
	}
	system("cls");
	printf("������ϣ�\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<*n;i++)
	{
		printf(" %-2d   ",i+1); 
		printf("%s  ",stu[i].xh);
		printf("%-12s",stu[i].name);
		printf("%-5.1f     ",stu[i].sub1);
		printf("%-5.1f     ",stu[i].sub2);
		printf("%-5.1f     ",stu[i].sub3);
		printf("%-5.1f     ",stu[i].sub4);
		printf("%-5.1f     ",stu[i].sub5);
		printf("%-5.1f     ",stu[i].sub6);
		printf("%-5.2f      ",(stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6)/6);
		printf("%-5.1f     ",stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6); 
		printf("\n");
	}
	printf("\n�������������һ��...");
	system("pause>nul"); 
}
void step5(int *n)//�޸� 
{
	int p[NUM]={0};
	int i,j,flag,ch,ch1;
	char str[20];
	float t;
	system("cls");
	printf("������ѧ�Ż�������");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("δ�ҵ�ƥ�����ݣ�\n");
		printf("�������������һ��...");
		system("pause>nul");
	}
	else
	{
		printf("���ҵ�%d��ƥ������...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<j;i++)
		{
			printf(" %-2d   ",i+1); 
			printf("%s  ",stu[p[i]].xh);
			printf("%-12s",stu[p[i]].name);
			printf("%-5.1f     ",stu[p[i]].sub1);
			printf("%-5.1f     ",stu[p[i]].sub2);
			printf("%-5.1f     ",stu[p[i]].sub3);
			printf("%-5.1f     ",stu[p[i]].sub4);
			printf("%-5.1f     ",stu[p[i]].sub5);
			printf("%-5.1f     ",stu[p[i]].sub6);
			printf("%-5.2f      ",(stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6)/6);
			printf("%-5.1f     ",stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6); 
			printf("\n");
		}
		if(j>1)
		{
			printf("\n��Զ����Ŀ����ѡ�����������0�������β�������");
			scanf("%d",&ch); 
			if(ch>j||ch<0)
			{
				while(ch>j||ch<0)
				{
					printf("�Բ�������ȷ����!!!\n");
					printf("��Զ����Ŀ����ѡ�����������0�������β�������");
					scanf("%d",&ch); 
				}
			}
			if(ch==0)
			{
				printf("������ȡ����");
				printf("\n�������������һ��...");
				system("pause>nul");
				return; 
			}
			ch=p[ch-1];
		}
		else
			ch=p[0];
		//��ʱ��Ҫ�޸ĵ���һ���±��Ѿ�����ch����
		flag=1;
		while(flag)
		{
			printf("\n"); 
			printf("1.ѧ��   2.����   3.ѧ��1   4.ѧ��2   5.ѧ��3   6.ѧ��4   7.ѧ��5   8.ѧ��6   9.������һ��\n");
			printf("��ѡ��Ҫ�޸ĵ�����(1--9)��");
			scanf("%d",&ch1);
			while(ch1>9||ch1<1)
			{
				printf("�Բ���,����ȷ����!!!\n");
				printf("��ѡ��Ҫ�޸ĵ�����(1--9)��");
				scanf("%d",&ch1);
			}
			switch(ch1)
			{
				case 1:
				{
					printf("������ѧ��(10λ)������0����������");
					scanf("%s",str);
					while(!(str[0]=='0'||strlen(str)==10))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",str);
					}
					if(str[0]=='0')
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					} 
					else
					{
						strcpy(stu[ch].xh,str);
						printf("�޸���ϣ��밴���������..."); 
						system("pause>nul");
					}
					break;
				}
				case 2:
				{
					printf("����������������0����������");
					scanf("%s",str);
					if(str[0]=='0')
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						strcpy(stu[ch].name,str);
						printf("�޸���ϣ������������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 3:
				{
					printf("������ѧ��1�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub1=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 4:
				{
					printf("������ѧ��2�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub2=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 5:
				{
					printf("������ѧ��3�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub3=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 6:
				{
					printf("������ѧ��4�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub4=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 7:
				{
					printf("������ѧ��5�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub5=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 8:
				{
					printf("������ѧ��6�ĳɼ�������-1����������");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("�Բ���,����ȷ����!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("������ȡ�����밴���������...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub6=t;
						printf("�޸���ϣ����������..."); 
						system("pause>nul");
					} 
					break;
				}
				case 9:
					flag=0;
					break; 
			}
			printf("\n");
		} 
	}
}
void step6(int *n)//ɾ�� 
{
	char str[12];
	int p[NUM]={0};
	int i,j,ch;
	system("cls");
	printf("������ѧ�Ż�������");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("δ�ҵ�ƥ�����ݣ�\n");
		printf("�������������һ��...");
		system("pause>nul");
	}
	else
	{
		printf("���ҵ�%d��ƥ������...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
		printf("----------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<j;i++)
		{
			printf(" %-2d   ",i+1); 
			printf("%s  ",stu[p[i]].xh);
			printf("%-12s",stu[p[i]].name);
			printf("%-5.1f     ",stu[p[i]].sub1);
			printf("%-5.1f     ",stu[p[i]].sub2);
			printf("%-5.1f     ",stu[p[i]].sub3);
			printf("%-5.1f     ",stu[p[i]].sub4);
			printf("%-5.1f     ",stu[p[i]].sub5);
			printf("%-5.1f     ",stu[p[i]].sub6);
			printf("%-5.2f      ",(stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6)/6);
			printf("%-5.1f     ",stu[p[i]].sub1+stu[p[i]].sub2+stu[p[i]].sub3+stu[p[i]].sub4+stu[p[i]].sub5+stu[p[i]].sub6); 
			printf("\n");
		}
		if(j>1)
		{
			printf("\n��Զ����Ŀ����ѡ�����������0�������β�������");
			scanf("%d",&ch); 
			if(ch>j||ch<0)
			{
				while(ch>j||ch<0)
				{
					printf("�Բ�������ȷ����!!!\n");
					printf("��Զ����Ŀ����ѡ�����������0�������β�������");
					scanf("%d",&ch); 
				}
			}
			if(ch==0)
			{
				printf("������ȡ����");
				printf("\n�������������һ��...");
				system("pause>nul");
				return; 
			}
			ch=p[ch-1];
		}
		else
			ch=p[0];
		printf("\n�Ƿ�ɾ����ѧ���ɼ���������0�������β�������������ֵ������");
		scanf("%d",&j);
		if(j==0)
		{
			printf("������ȡ����");
			printf("\n�������������һ��...");
			system("pause>nul");
			return; 
		}
		for(i=ch;i<*n;i++)
		{
			stu[i]=stu[i+1];
		} 
	}
	(*n)--;
}
void step7(int *n)//���� 
{
	FILE *fp;
	int i;
	system("cls");
	if((fp=fopen("data.txt","w+"))==NULL)
	{
		printf("�����ļ�ʧ�ܣ�");
		Sleep(1500);
		exit(0);
	}
	fprintf(fp,"%d\n",*n);//������ 
	for(i=0;i<*n;i++)
	{
		fprintf(fp,"%s\n",stu[i].name);
		fprintf(fp,"%s\n",stu[i].xh);
		fprintf(fp,"%.1f %.1f %.1f %.1f %.1f %.1f\n",stu[i].sub1,stu[i].sub2,stu[i].sub3,stu[i].sub4,stu[i].sub5,stu[i].sub6);
	}
	printf("����ɹ���\n�밴������˳�...");
	system("pause>nul");
	exit(0);
} 
void step8(int *n)//���� 
{
	char s[500]={0};
	system("cls");
	printf("�������ļ�����");
	gets(s);
	gets(s);
	strcat(s,".txt");
	FILE *fp;
	if((fp=fopen(s,"w+"))==NULL)
	{
		printf("�����ļ�ʧ�ܣ���ע���ļ������Ƿ��зǷ��ַ�������Ƿ�������\n");
		printf("�������������һ��...");
		system("pause>nul");
		return;
	}
	else
	{
		fprintf(fp,"----------------------------------------------------------------------------------------------------------\n");
		fprintf(fp," *ѧ�����Գɼ���Ϣ��*\n");
		fprintf(fp,"----------------------------------------------------------------------------------------------------------\n");
		fprintf(fp,"���  ѧ��        ����        ѧ��1     ѧ��2     ѧ��3     ѧ��4     ѧ��5     ѧ��6     ƽ����     �ܷ�\n");
		fprintf(fp,"----------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<*n;i++)
		{
			fprintf(fp," %-2d   ",i+1); 
			fprintf(fp,"%s  ",stu[i].xh);
			fprintf(fp,"%-12s",stu[i].name);
			fprintf(fp,"%-5.1f     ",stu[i].sub1);
			fprintf(fp,"%-5.1f     ",stu[i].sub2);
			fprintf(fp,"%-5.1f     ",stu[i].sub3);
			fprintf(fp,"%-5.1f     ",stu[i].sub4);
			fprintf(fp,"%-5.1f     ",stu[i].sub5);
			fprintf(fp,"%-5.1f     ",stu[i].sub6);
			fprintf(fp,"%-5.2f      ",(stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6)/6);
			fprintf(fp,"%-5.1f     ",stu[i].sub1+stu[i].sub2+stu[i].sub3+stu[i].sub4+stu[i].sub5+stu[i].sub6); 
			fprintf(fp,"\n");
		}
	}
	fclose(fp);
	//����Windows����������ƶ��ļ������� 
	FILE *temp;
	temp=fopen("tmp.bat","w");
	fprintf(temp,"@echo off\n");
	fprintf(temp,"copy \"%s\" %%userprofile%%\\desktop\n",s);
	fprintf(temp,"del \"%s\"\n",s);
	fprintf(temp,"del tmp.bat&exit\n");
	fclose(temp); 
	system("start tmp.bat"); 
	printf("�ļ��ѵ��������棡");
	printf("\n�������������һ��...");
	system("pause>nul");
}
