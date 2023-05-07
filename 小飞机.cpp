#include<iostream>
#include<string>	
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include"windows.h"
using namespace std;
int i = 1;
typedef struct date {//时间结构体
	string t1,t2;//起飞落地时间
}date,*d;
typedef struct place //地点结构体
{
	string pbegin;//起飞地点
	string parrive;//降落地点
}place,*p;
typedef struct plane{
	string planenum;//飞机航班号
	date da;//飞机的时间信息
	place pl;//飞机的出发抵达地点
	int price;//票价
	int count;//飞机上剩余座位
	int people;//飞机人数
	int contain;//飞机总座位数
}plane,*pla;
void buy(plane*& p)
{
	int n = 1;
	while (n == 1) {
	cout << "当前航班信息如下" << endl;
	for (int j = 1; j < i; j++)
	{
		cout << "航班号:" << p[j].planenum << " 航班起飞地点:" << p[j].pl.pbegin << " 航班抵达地点:" << p[j].pl.parrive << " 航班起飞时间:" << p[j].da.t1 << " 航班抵达时间:" << p[j].da.t2 << endl;
		cout << "票价:" << p[j].price << " 当前折扣:" << p[j].count << " 剩余票数" << p[j].contain - p[j].people << endl;
	}
		int m = 0,u=0;
		cout << "请输入您要购买的航班号:";
		string c;
		cin >> c;
		for (int j = 1; j <= i; j++)
		{
			n = 0;
			if (c == p[j].planenum || c == p[j].pl.parrive || c == p[j].pl.pbegin || c == p[j].da.t1 || c == p[j].da.t2)
			{
				u++;
				if (p[j].contain == p[j].people)
				{
					m++;
					cout << "航班已满员，重新购买输入1，否则输入2" << endl;
					cin >> n;
					system("cls");
				}
				else {
					p[j].people++;
					cout << "购买成功！" << endl;
				}
			}
		}
		if (m==0&&u!=0) {
			cout << "继续购买输入请按1" << "停止购买输入请按2" << endl;
			cin >> n;
			system("cls");
		}
		if (u == 0)
		{
			cout << "航班不存在，重新购买输入1，否则输入2" << endl;
			cin >> n;
			system("cls");
		}
	}
	system("cls");
	cout << "录入成功!" << endl;
	cout << "请继续选择操作" << endl << endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl;
	cout << "5.退票" << endl;
	cout << "0.退出系统" << endl;
}
void giveback(plane*& p)
{
	cout << "请输入您要退改航班的航班号:";
	string c;
	cin >> c;
	for (int j = 1; j <= i; j++)
	{
		if (c == p[j].planenum || c == p[j].pl.parrive || c == p[j].pl.pbegin || c == p[j].da.t1 || c == p[j].da.t2)
		{
			p[j].people--;
			cout << "退票成功！" << endl;
		}
	}
	/*system("cls");
	cout << "录入成功!" << endl;*/
	cout << "请继续选择操作" << endl << endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl;
	cout << "5.退票" << endl;
	cout << "0.退出系统" << endl;
}
void correct(plane*& p)
{
	cout << "当前航班信息如下" << endl;
	for (int j = 1; j < i; j++)
	{
			cout << "航班号:" << p[j].planenum << " 航班起飞地点:" << p[j].pl.pbegin << " 航班抵达地点:" << p[j].pl.parrive << " 航班起飞时间:" << p[j].da.t1 << " 航班抵达时间:" << p[j].da.t2 << endl;
			cout << "票价:" << p[j].price << " 当前折扣:" << p[j].count << " 剩余票数" << p[j].contain - p[j].people << endl;
	}
	int n = 1;
	while (n == 1) {
		cout << "请输入您要修改信息的航班号:";
		string c;
		cin >> c;
		for (int j = 1; j <= i; j++)
		{
			if (c == p[j].planenum || c == p[j].pl.parrive || c == p[j].pl.pbegin || c == p[j].da.t1 || c == p[j].da.t2)
			{
				cout << "请依次输入飞机航班号,起降时间，起飞抵达城市，航班票价，票价折扣，飞机座位数" << endl;
				cin >> p[j].planenum;
				cin >> p[j].da.t1;
				cin >> p[j].da.t2;
				cin >> p[j].pl.pbegin;
				cin >> p[j].pl.parrive;
				cin >> p[j].price >> p[j].count >> p[j].contain;
				cout << "已修改成功" << endl;
			}
		}
		n = 0;
		cout << "继续修改输入请按1" << "停止修改输入请按2" << endl;
		cin >> n;
	}
	system("cls");
	cout << "录入成功!" << endl;
	cout << "请继续选择操作" << endl << endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl;
	cout << "5.退票" << endl;
	cout << "0.退出系统" << endl;
}
void resavefile(plane* p)
{
	ofstream fout("data.txt");
	 for (int j = 1; j < i; j++)
	 {
		 fout << "航班信息"<<endl;
		 fout << "航班号:" << p[j].planenum << " 航班起飞地点:" << p[j].pl.pbegin << " 航班抵达地点:" << p[j].pl.parrive << " 航班起飞时间:" << p[j].da.t1 << " 航班抵达时间:" << p[j].da.t2 << endl;
		 fout << "票价:" << p[j].price << " 当前折扣:" << p[j].count << " 剩余票数" << p[j].contain - p[j].people << endl;
	 }
	 fout.close();
}
void creat(plane* &p)
{
	int n;
	cout << "请依次输入飞机航班号,起降时间，起飞抵达城市，航班票价，票价折扣，飞机座位数" << endl;
    do
	{
		cin >> p[i].planenum;
		cin>>p[i].da.t1;
		cin >> p[i].da.t2;
		cin >> p[i].pl.pbegin;
		cin >> p[i].pl.parrive;
		cin>> p[i].price >> p[i].count >> p[i].contain;
		p[i].people = 0;
		cout << "已录入航班信息数" << " " << i << endl;
		cout << "继续输入请按1" << "停止输入请按2"<<endl;
		cin >> n;
		i++;
	} while (n!=2);
	system("cls");
	cout << "录入成功!" << endl;
	cout << "请继续选择操作" << endl << endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl;
	cout << "5.退票" << endl;
	cout << "0.退出系统" << endl;
}
void search(plane* p)
{
	int r = 1;
	while (r == 1) {
		cout << "请输入查询信息" << endl;
		string c;
		cin >> c;
		int m = 0;
		for (int j = 1; j <i; j++)
		{
			if (c == p[j].planenum || c == p[j].pl.parrive || c == p[j].pl.pbegin || c == p[j].da.t1 || c == p[j].da.t2)
			{
				m++;
				if (m == 1)
					cout << "已为您查找到如下航班" << endl;
				r = 0;
				cout << "航班号:" << p[j].planenum << " 航班起飞地点:" << p[j].pl.pbegin << " 航班抵达地点:" << p[j].pl.parrive << " 航班起飞时间:" << p[j].da.t1 << " 航班抵达时间:" << p[j].da.t2 << endl;
				cout << "票价:" << p[j].price << " 当前折扣:" << p[j].count << " 剩余票数" << p[j].contain - p[j].people << endl;
			}
		}
		if (m == 0)
		{
			cout << "查找失败,是否重新查找?按'1'是，按'2'否" << endl;
			cin >> r;
			system("cls");
		}
		else
			cout << "查找结束" << endl;
	}
	//system("cls");
	cout << "请继续选择操作" << endl << endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl;
	cout << "5.退票" << endl;
	cout << "0.退出系统" << endl;
}
int main()
{
	int n=1;
	plane *flight=new plane[30];
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);*/
	cout << "***********************************************" << endl;
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);*/
	cout << "欢迎进入飞机订票系统" << endl<<endl;
	cout << "1.写入航班信息" << endl;
	cout << "2.修改航班信息" << endl;
	cout << "3.查询航班信息" << endl;
	cout << "4.买票" << endl; 
	cout << "5.退票" << endl;
	cout << "0.退出系统"<<endl;
	while (n != 0) {
		cin >> n;
		if (n == 1)
		{
			cout << "1.写入航班信息"<<endl;
			creat(flight);
			resavefile(flight);
		}
		if (n == 2)
		{
			cout << "2.修改航班信息" << endl;
			correct(flight);
			string filePath = "C:/Users/zhang/source/repos/Project43/Project43/data.txt";
			DeleteFileA(filePath.c_str());
			resavefile(flight);
		}
		if (n == 3)
		{
			cout << "3.查询航班信息" << endl;
			search(flight);
			string filePath = "C:/Users/zhang/source/repos/Project43/Project43/data.txt";
			DeleteFileA(filePath.c_str());
			resavefile(flight);
		}
		if (n == 4)
		{
			cout << "4.买票" << endl;
			buy(flight);
			string filePath = "C:/Users/zhang/source/repos/Project43/Project43/data.txt";
			DeleteFileA(filePath.c_str());
			resavefile(flight);
		}
		if (n == 5)
		{
			cout << "5.退票" << endl;
			giveback(flight);
			string filePath = "C:/Users/zhang/source/repos/Project43/Project43/data.txt";
			DeleteFileA(filePath.c_str());
			resavefile(flight);
		}
	}
	cout << "***********************************************" << endl;
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);*/
}