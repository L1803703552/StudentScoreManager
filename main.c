#include <stdio.h>
#include <windows.h>//调用Windows API 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NUM 100 //最大学生数量 
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
//函数声明... 
void rea(int *n);//读取 
void welcome1(int *n);//没数据 
void welcome2(int *n);//有数据 
void step1(int *n);//输入、增加 
void step2(int *n);//显示 
void step3(int *n);//查找 
void step4(int *n);//排序 
void step5(int *n);//修改 
void step6(int *n);//删除 
void step7(int *n);//保存 
void step8(int *n);//导出 
int main()
{
	int n; 
	//EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED);//禁用关闭按钮 --by:菜鸟教程 
	SetConsoleTitle("学生成绩管理系统V3.2 --by:306-1");//更改窗口标题 --by:菜鸟教程 
	
	rea(&n);
	do{
		if(n==0)
			welcome1(&n);
		else
			welcome2(&n);
	}while(1);
	return 0;
}
void rea(int *n)//读取 
{
	FILE *fp;
	int i;
	char s[255],p[255],ch;
	if((fp=fopen("config.db","r"))!=NULL)
	{
		fgets(p,255,fp);
		do{
			printf("请输入密码：");
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
				printf("\n密码错误！\n");
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
	if(i==NUM)//避免数组溢出 
		*n=NUM;
	fclose(fp);
}
void welcome1(int *n)//没数据 
{
	char str[3];
	int ch; 
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("                     ┃    学生成绩管理系统主菜单界面   ┃\n");
	printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("                     ┃         ①.输入学生成绩         ┃\n");
	printf("                     ┃         ②.返回上一级           ┃\n");
	printf("                     ┃         ③.退出系统             ┃\n");
	printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("                         请输入您的选择(1--3):( )\b\b");
	scanf("%s",str);
	if(atoi(str)>3 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("                     ┃    学生成绩管理系统主菜单界面   ┃\n");
			printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("                     ┃         ①.输入学生成绩         ┃\n");
			printf("                     ┃         ②.返回上一级           ┃\n");
			printf("                     ┃         ③.退出系统             ┃\n");
			printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("                        对不起,请输入1-3这几个数字!!!\n");
			printf("                         请输入您的选择(1--3):( )\b\b");
			gets(str);
		}while(atoi(str)>3 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			printf("\n -------------<<请建立学生考试信息表,在姓名处键以 # 结束输入。>>-------------\n");
			step1(n);
			break;
		case 2: 
			system("start setup.exe");
			exit(0);
			break;
		case 3:
			printf("******************************************************************************\n");
			printf("------------------------<<谢谢您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0); 
	}
}
void welcome2(int *n)//有数据 
{
	char str[3];
	int ch;
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("                     ┃    学生成绩管理系统主菜单界面   ┃\n");
	printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("                     ┃         ①.增加学生成绩         ┃\n");
	printf("                     ┃         ②.显示学生成绩         ┃\n");
	printf("                     ┃         ③.查找学生成绩         ┃\n");
	printf("                     ┃         ④.排序统计成绩         ┃\n");
	printf("                     ┃         ⑤.修改学生成绩         ┃\n");
	printf("                     ┃         ⑥.删除学生成绩         ┃\n");
	printf("                     ┃         ⑦.保存退出系统         ┃\n");
	printf("                     ┃         ⑧.导出学生成绩         ┃\n");
	printf("                     ┃         ⑨.返回上一级           ┃\n");
	printf("                     ┃         ⑩.退出系统             ┃\n");
	printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("                         请输入您的选择(1--10):");
	scanf("%s",str);
	if(atoi(str)>10 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("                     ┃    学生成绩管理系统主菜单界面   ┃\n");
			printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("                     ┃         ①.增加学生成绩         ┃\n");
			printf("                     ┃         ②.显示学生成绩         ┃\n");
			printf("                     ┃         ③.查找学生成绩         ┃\n");
			printf("                     ┃         ④.排序统计成绩         ┃\n");
			printf("                     ┃         ⑤.修改学生成绩         ┃\n");
			printf("                     ┃         ⑥.删除学生成绩         ┃\n");
			printf("                     ┃         ⑦.保存退出系统         ┃\n");
			printf("                     ┃         ⑧.导出学生成绩         ┃\n");
			printf("                     ┃         ⑨.返回上一级           ┃\n");
			printf("                     ┃         ⑩.退出系统             ┃\n");
			printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("                        对不起,请输入1--10这几个数字!!!\n");
			printf("                         请输入您的选择(1--10):");
			gets(str);
		}while(atoi(str)>10 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			system("cls");
			printf("----------------<<请输入新增学生成绩信息,在姓名处键以 # 结束输入。>>----------------\n");
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
			printf("------------------------<<谢谢您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0); 
	}
}
void step1(int *n)//输入、增加 
{
	int i; 
	if(*n>=NUM)
	{
		system("cls");
		printf("当前学生数量已饱和，请进行其他操作!\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return; 
	}
	for(i=*n;i<NUM;i++,(*n)++) 
	{
		printf("请输入姓名：");
		scanf("%s",stu[i].name);
		if(strcmp(stu[i].name,"#")==0) 
			break;
		printf("请输入学号(10位)：");
		scanf("%s",stu[i].xh);
		while(strlen(stu[i].xh)!=10)
		{
			printf("对不起,请正确输入!!!\n");
			scanf("%s",stu[i].xh);
		} 
		printf("请输入学科1的成绩：");
		scanf("%f",&stu[i].sub1);
		while(stu[i].sub1>100 || stu[i].sub1<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub1);
		}
		printf("请输入学科2的成绩：");
		scanf("%f",&stu[i].sub2);
		while(stu[i].sub2>100 || stu[i].sub2<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub2);
		}
		printf("请输入学科3的成绩：");
		scanf("%f",&stu[i].sub3);
		while(stu[i].sub3>100 || stu[i].sub3<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub3);
		}
		printf("请输入学科4的成绩：");
		scanf("%f",&stu[i].sub4);
		while(stu[i].sub4>100 || stu[i].sub4<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub4);
		}
		printf("请输入学科5的成绩：");
		scanf("%f",&stu[i].sub5);
		while(stu[i].sub5>100 || stu[i].sub5<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub5);
		}
		printf("请输入学科6的成绩：");
		scanf("%f",&stu[i].sub6);
		while(stu[i].sub6>100 || stu[i].sub6<0)
		{
			printf("对不起,请输入0-100之间的数字!!\n");
			scanf("%f",&stu[i].sub6);
		}
	}
	if(i>=NUM)
	{
		printf("\n当前学生数量已饱和，请进行其他操作!\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
	}
}
void step2(int *n)//显示 
{
	int i;
	system("cls"); 
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf(" *学生考试成绩信息表*\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
	printf("\n按任意键返回上一级...");
	system("pause>nul");
} 
void step3(int *n)//查找 
{
	int p[NUM]={0};
	int i,j;
	char str[20];
	system("cls");
	printf("请输入学号或姓名：");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("未找到匹配数据！");
	}
	else
	{
		printf("已找到%d项匹配数据...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
	printf("\n按任意键返回上一级...");
	system("pause>nul"); 
}
void step4(int *n)//排序 
{
	int ch1,ch2;
	int i,j;
	float t,t2[NUM]; 
	char s[NUM][20],t1[20];
	STUTYPE temp;
	system("cls");
	printf("1.学号    2.学科1   3.学科2\n");
	printf("4.学科3   5.学科4   6.学科5\n");
	printf("7.学科6   8.平均分  9.总分\n");
	printf("10.返回上一级\n");
	printf("请选择排序索引(1--10)：");
	scanf("%d",&ch1);
	while(ch1>10||ch1<1)
	{
		printf("对不起,请正确输入!!!\n");
		printf("请选择排序索引(1--10)：");
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
	printf("1.升序   2.降序   3.返回上一级\n");
	printf("请选择排序序列(1--3)：");
	scanf("%d",&ch2);
	while(ch2>3||ch2<1)
	{
		printf("对不起,请正确输入!!!\n");
		printf("请选择排序序列(1--3)：");
		scanf("%d",&ch2);
	}
	switch(ch2)//冒泡排序 
	{
		case 1://升序 
			for(i=0;i<*n-1;i++)
			{
				for(j=0;j<*n-1-i;j++)
				{
					if(ch1==1)//学号为字符串类型 
					{
						if(strcmp(s[j],s[j+1])>0)
						{
							strcpy(t1,s[j]);strcpy(s[j],s[j+1]);strcpy(s[j+1],t1);
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
					else//成绩是实型 
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
		case 2://降序 
			for(i=0;i<*n-1;i++)
			{
				for(j=0;j<*n-1-i;j++)
				{
					if(ch1==1)//学号为字符串类型 
					{
						if(strcmp(s[j],s[j+1])<0)
						{
							strcpy(t1,s[j]);strcpy(s[j],s[j+1]);strcpy(s[j+1],t1);
							temp=stu[j];stu[j]=stu[j+1];stu[j+1]=temp; 
						}
					}
					else//成绩是实型 
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
	printf("排序完毕！\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
	printf("\n按任意键返回上一级...");
	system("pause>nul"); 
}
void step5(int *n)//修改 
{
	int p[NUM]={0};
	int i,j,flag,ch,ch1;
	char str[20];
	float t;
	system("cls");
	printf("请输入学号或姓名：");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("未找到匹配数据！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
	}
	else
	{
		printf("已找到%d项匹配数据...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
			printf("\n请对多个项目进行选择操作（输入0撤销本次操作）：");
			scanf("%d",&ch); 
			if(ch>j||ch<0)
			{
				while(ch>j||ch<0)
				{
					printf("对不起，请正确输入!!!\n");
					printf("请对多个项目进行选择操作（输入0撤销本次操作）：");
					scanf("%d",&ch); 
				}
			}
			if(ch==0)
			{
				printf("操作已取消。");
				printf("\n按任意键返回上一级...");
				system("pause>nul");
				return; 
			}
			ch=p[ch-1];
		}
		else
			ch=p[0];
		//此时，要修改的那一条下标已经存在ch里面
		flag=1;
		while(flag)
		{
			printf("\n"); 
			printf("1.学号   2.姓名   3.学科1   4.学科2   5.学科3   6.学科4   7.学科5   8.学科6   9.返回上一级\n");
			printf("请选择要修改的索引(1--9)：");
			scanf("%d",&ch1);
			while(ch1>9||ch1<1)
			{
				printf("对不起,请正确输入!!!\n");
				printf("请选择要修改的索引(1--9)：");
				scanf("%d",&ch1);
			}
			switch(ch1)
			{
				case 1:
				{
					printf("请输入学号(10位)，输入0撤销操作：");
					scanf("%s",str);
					while(!(str[0]=='0'||strlen(str)==10))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",str);
					}
					if(str[0]=='0')
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					} 
					else
					{
						strcpy(stu[ch].xh,str);
						printf("修改完毕，请按任意键继续..."); 
						system("pause>nul");
					}
					break;
				}
				case 2:
				{
					printf("请输入姓名，输入0撤销操作：");
					scanf("%s",str);
					if(str[0]=='0')
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						strcpy(stu[ch].name,str);
						printf("修改完毕，按任意键继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 3:
				{
					printf("请输入学科1的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub1=t;
						printf("修改完毕，按任意继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 4:
				{
					printf("请输入学科2的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub2=t;
						printf("修改完毕，按任意继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 5:
				{
					printf("请输入学科3的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub3=t;
						printf("修改完毕，按任意继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 6:
				{
					printf("请输入学科4的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub4=t;
						printf("修改完毕，按任意继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 7:
				{
					printf("请输入学科5的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub5=t;
						printf("修改完毕，按任意继续..."); 
						system("pause>nul");
					} 
					break;
				}
				case 8:
				{
					printf("请输入学科6的成绩，输入-1撤销操作：");
					scanf("%f",&t);
					while(!(t==-1||(t>=0||t<=100)))
					{
						printf("对不起,请正确输入!!!\n");
						scanf("%s",&t);
					}
					if(t==-1)
					{
						printf("操作已取消，请按任意键继续...");
						system("pause>nul");
					}
					else
					{
						stu[ch].sub6=t;
						printf("修改完毕，按任意继续..."); 
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
void step6(int *n)//删除 
{
	char str[12];
	int p[NUM]={0};
	int i,j,ch;
	system("cls");
	printf("请输入学号或姓名：");
	scanf("%s",str);
	for(i=j=0;i<*n;i++)
	{
		if(strcmp(str,stu[i].xh)==0||strcmp(str,stu[i].name)==0)
			p[j++]=i;
	}
	if(j==0)
	{
		printf("未找到匹配数据！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
	}
	else
	{
		printf("已找到%d项匹配数据...\n",j);
		printf("----------------------------------------------------------------------------------------------------------\n");
		printf("序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
			printf("\n请对多个项目进行选择操作（输入0撤销本次操作）：");
			scanf("%d",&ch); 
			if(ch>j||ch<0)
			{
				while(ch>j||ch<0)
				{
					printf("对不起，请正确输入!!!\n");
					printf("请对多个项目进行选择操作（输入0撤销本次操作）：");
					scanf("%d",&ch); 
				}
			}
			if(ch==0)
			{
				printf("操作已取消。");
				printf("\n按任意键返回上一级...");
				system("pause>nul");
				return; 
			}
			ch=p[ch-1];
		}
		else
			ch=p[0];
		printf("\n是否删除该学生成绩？（输入0撤销本次操作，输入其他值继续）");
		scanf("%d",&j);
		if(j==0)
		{
			printf("操作已取消。");
			printf("\n按任意键返回上一级...");
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
void step7(int *n)//保存 
{
	FILE *fp;
	int i;
	system("cls");
	if((fp=fopen("data.txt","w+"))==NULL)
	{
		printf("保存文件失败！");
		Sleep(1500);
		exit(0);
	}
	fprintf(fp,"%d\n",*n);//总人数 
	for(i=0;i<*n;i++)
	{
		fprintf(fp,"%s\n",stu[i].name);
		fprintf(fp,"%s\n",stu[i].xh);
		fprintf(fp,"%.1f %.1f %.1f %.1f %.1f %.1f\n",stu[i].sub1,stu[i].sub2,stu[i].sub3,stu[i].sub4,stu[i].sub5,stu[i].sub6);
	}
	printf("保存成功！\n请按任意键退出...");
	system("pause>nul");
	exit(0);
} 
void step8(int *n)//导出 
{
	char s[500]={0};
	system("cls");
	printf("请输入文件名：");
	gets(s);
	gets(s);
	strcat(s,".txt");
	FILE *fp;
	if((fp=fopen(s,"w+"))==NULL)
	{
		printf("创建文件失败，请注意文件名中是否含有非法字符或磁盘是否已满！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return;
	}
	else
	{
		fprintf(fp,"----------------------------------------------------------------------------------------------------------\n");
		fprintf(fp," *学生考试成绩信息表*\n");
		fprintf(fp,"----------------------------------------------------------------------------------------------------------\n");
		fprintf(fp,"序号  学号        姓名        学科1     学科2     学科3     学科4     学科5     学科6     平均分     总分\n");
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
	//利用Windows批处理程序移动文件到桌面 
	FILE *temp;
	temp=fopen("tmp.bat","w");
	fprintf(temp,"@echo off\n");
	fprintf(temp,"copy \"%s\" %%userprofile%%\\desktop\n",s);
	fprintf(temp,"del \"%s\"\n",s);
	fprintf(temp,"del tmp.bat&exit\n");
	fclose(temp); 
	system("start tmp.bat"); 
	printf("文件已导出到桌面！");
	printf("\n按任意键返回上一级...");
	system("pause>nul");
}
