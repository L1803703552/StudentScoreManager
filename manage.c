#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
int rea();
void welcome1();
void welcome2();
void step1();
void step2();
void step3();
int main()
{
	system("title 学生成绩管理系统V3.2 --by:306-1");
	do{
		if(rea()==0)
			welcome1();
		else
			welcome2();
	}while(1);
	return 0;
} 
int rea()
{
	int n;
	FILE *fp;
	if((fp=fopen("config.db","r"))==NULL)
	{
		n=0;
	}
	else
		n=1;
	fclose(fp); 
	return n;
}
void welcome1()
{
	char str[3];
	int ch;
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("                     ┃           请选择功能           ┃\n");
	printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("                     ┃   ①.设置密码                  ┃\n");
	printf("                     ┃   ②.返回上一级                ┃\n");
	printf("                     ┃   ③.退出系统                  ┃\n");
	printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("                          请输入您的选择(1--3):( )\b\b");
	gets(str);
	if(atoi(str)>3 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("                     ┃           请选择功能           ┃\n");
			printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("                     ┃   ①.设置密码                  ┃\n");
			printf("                     ┃   ②.返回上一级                ┃\n");
			printf("                     ┃   ③.退出系统                  ┃\n");
			printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("                          对不起,请输入1-3这几个数字!!\n");
			printf("                          请输入您的选择(1--3):( )\b\b");
			gets(str);
		}while(atoi(str)>3 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			step1();
			break;
		case 2:
			system("start setup.exe");
			break;
		case 3:
			printf("******************************************************************************\n");
			printf("------------------------<<谢谢您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0);
	}
}
void welcome2()
{
	char str[3];
	int ch;
	system("cls");
	printf("******************************************************************************\n");
	printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
	printf("******************************************************************************\n");
	printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("                     ┃           请选择功能           ┃\n");
	printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("                     ┃   ①.修改密码                  ┃\n");
	printf("                     ┃   ②.删除密码                  ┃\n");
	printf("                     ┃   ③.返回上一级                ┃\n");
	printf("                     ┃   ④.退出系统                  ┃\n");
	printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("                          请输入您的选择(1--4):( )\b\b");
	gets(str);
	if(atoi(str)>4 || atoi(str)<1)
	{
		do{
			system("cls");
			printf("******************************************************************************\n");
			printf("------------------------<<欢迎您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			printf("                     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("                     ┃           请选择功能           ┃\n");
			printf("                     ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("                     ┃   ①.修改密码                  ┃\n");
			printf("                     ┃   ②.删除密码                  ┃\n");
			printf("                     ┃   ③.返回上一级                ┃\n");
			printf("                     ┃   ④.退出系统                  ┃\n");
			printf("                     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("                          对不起,请输入1-4这几个数字!!\n");
			printf("                          请输入您的选择(1--4):( )\b\b");
			gets(str);
		}while(atoi(str)>4 || atoi(str)<1);
	}
	ch=atoi(str);
	switch(ch) {
		case 1:
			step2();
			break;
		case 2:
			step3();
			break;
		case 3:
			system("start setup.exe");
			break;
		case 4:
			printf("******************************************************************************\n");
			printf("------------------------<<谢谢您使用学生成绩管理系统>>------------------------\n");
			printf("******************************************************************************\n");
			Sleep(1500); 
			exit(0);
	}
}
void step1()
{
	FILE *fp;
	int i;
	char s[255],t[255],ch;
	system("cls");
	if((fp=fopen("config.db","w"))==NULL)
	{
		printf("密码创建失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return;
	}
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
	printf("\n请再次输入密码：");
	i=0;
	do{
		t[i]=getch();
		if(t[i]=='\r')
			break;
		if(t[i]=='\b')
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
	}while(t[i]!='\n'&&i<255);
	t[i]=0;
	if(strcmp(s,t)!=0)
	{
		printf("\n两次输入密码不一致，密码创建失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		fclose(fp);
		system("del config.db");
		return; 
	}
	if(s[0]==0)
	{
		fclose(fp);
		system("del config.db");
		return; 
	}
	fprintf(fp,"%s",s); 
	printf("\n密码创建完毕！"); 
	Sleep(1500);
	fclose(fp);
	system("cls");
}
void step2()
{
	FILE *fp;
	int i;
	char s[255],t[255],p[255],ch;
	system("cls");
	if((fp=fopen("config.db","r+"))==NULL)
	{
		printf("文件打开失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return;
	}
	printf("请输入旧密码：");
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
	fgets(p,255,fp);
	if(strcmp(s,p)!=0)
	{
		printf("\n密码错误，按任意键返回...");
		system("pause>nul");
		return; 
	}
	printf("\n请输入新密码：");
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
	printf("\n请再次输入新密码：");
	i=0;
	do{
		t[i]=getch();
		if(t[i]=='\r')
			break;
		if(t[i]=='\b')
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
	}while(t[i]!='\n'&&i<255);
	t[i]=0;
	if(strcmp(s,t)!=0)
	{
		printf("\n两次输入密码不一致，密码修改失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		fclose(fp);
		return; 
	}
	if(s[0]==0)
	{
		fclose(fp);
		system("del config.db");
		return; 
	}
	fclose(fp);
	if((fp=fopen("config.db","w"))==NULL)
	{
		printf("密码修改失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return;
	} 
	fprintf(fp,"%s",s); 
	printf("\n密码修改完毕！"); 
	Sleep(1500); 
	fclose(fp);
	system("cls");
}
void step3()
{
	FILE *fp;
	int i;
	char s[255],p[255],ch;
	system("cls");
	if((fp=fopen("config.db","r+"))==NULL)
	{
		printf("文件打开失败！\n");
		printf("按任意键返回上一级...");
		system("pause>nul");
		return;
	}
	printf("请输入旧密码：");
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
	fgets(p,255,fp);
	if(strcmp(s,p)!=0)
	{
		printf("\n密码错误，按任意键返回...");
		fclose(fp);
		system("pause>nul");
		return; 
	}
	fclose(fp);
	system("del config.db");
	printf("\n密码删除完毕！");
	Sleep(1500);
}
