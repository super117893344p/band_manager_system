#pragma once
#include<iostream>
#include<string>
#include"贷款人.h"
#include"人.h"
#include"还款人.h"
#define   filename "bankfile.txt"
#include<fstream>
using namespace std;

class 银行操作系统
{
public:bool TorF;  int 办理业务人个数 = 0; 人** 办理业务人数组=nullptr	;//指针初始化指向空
	  void 申请贷款() {
		  cout << "请输入多少人申请贷款" << endl; int T; cin >> T;
		  if (T>0)
		  {
			  int newsize = T + this->当前办理业务人数(); 人** newspace = nullptr;newspace= new 人* [newsize * (sizeof(人))];
			  if (this->办理业务人数组!=NULL)
			  {
				  for (int  i = 0; i < this->当前办理业务人数(); i++)
				  {
					  newspace[i] = this->办理业务人数组[i];
				  }
			  }
			  for (int   i = 0; i < T; i++)
			  {
				  int a, b, c, d; string name; 人* person = NULL;
				  cout << "请输入第" << i+1<< "个贷款	人名字	"; cin >> name;
				  cout << "请输入第" << i +1<< "个贷款	人身份证	"; cin >> a;
				  cout << "请输入第" << i+1 << "个贷款	人的贷款编号	"; cin >> b;
				  cout << "请输入第" << i +1<< "个贷款人的贷款金额	"; cin >> c;
				  cout << "请输入第" << i+1 << "个贷款人的贷款期限	"; cin >> d;
				  person = new 贷款人(name, a, b, c, d); newspace[this->当前办理业务人数() + i]=person;
			  }delete[] this->办理业务人数组; this->办理业务人数组 = newspace; this->办理业务人个数 = newsize;
			  cout << "成功添加" << T  << "位贷款人" << endl; this->保存(); system("pause");
		  }
		  else
		  {
			  cout << "输入有误" << endl;
		  }
		  
	  };
	  void  还贷款(){
		  cout << "请输入需记录还款人个数" << endl; int a; cin >> a; ifstream ifs; ifs.open(filename, ios::in);
		  if (a > 0)
		  {
			  int newsize = a + this->当前办理业务人数();  人** newspace = nullptr;newspace= new 人* [newsize *sizeof( 人)]; 
			  if (this->办理业务人数组 != nullptr)//定义变量和指针才初始化;
			  {
				  for (int i = 0; i < this->当前办理业务人数(); i++)
				  {
					   newspace[i] = this->办理业务人数组[i];
				  }
			  } 
			  for (int i = 0; i < a; i++)
			  {
				  int a, b, c, d; string name; 人* person = nullptr; int p=0;
				  cout << "请输入第" << i +1 << "个还款	人名字	"; cin >> name;
				  cout << "请输入第" << i+1 << "个还款	人身份证	"; cin >> a;
				  cout << "请输入第" << i+1 << "个还款	人的还款编号	"; cin >> b;
				  cout << "请输入第" << i+1 << "个还款人的还款金额	"; cin >> c;
				  cout << "请输入第" << i+1  << "个还款人的还款期限	"; cin >> d;
				  for (int i = 0; i < this->当前办理业务人数(); i++)
				  {
					  if ( this->办理业务人数组[i]->名字==name) {
						  delete this->办理业务人数组[i]; this->办理业务人数组[i] = new  还款人(name, a, b, c, d); newspace[i] = this->办理业务人数组[i]; break;
					  }
					  else
					  {
						    person = new  还款人(name, a, b, c, d); newspace[this->办理业务人个数 + i] = person;
					  }
				  }
			
			  }delete[] this->办理业务人数组; this->办理业务人数组 = newspace; this->办理业务人个数 = newsize;
			  cout << "成功记录" << a << "位还款人信息" << endl;   this->保存(); ifs.close();
		  }
		  else
		  {
			  cout << "不存在此人还款记录	" << endl;
		  }
	  }
	  void 查询贷款记录(){
		  cout << "请输入贷款人的贷款名字" << endl; string  a; cin >> a; 人* person = NULL; TorF = false;
		  for (int  i = 0; i <  this->当前办理业务人数(); i++)
		  {
			  if (a == this->办理业务人数组[i]->名字) { this->办理业务人数组[i]->展示信息(); TorF = true; system("pause"); break; }
		  }
		  if (TorF==false)
		  {
			  cout << "信息不存在,此人并没有办理贷款" << endl;
		  }
	  }//变量声明后一定要提前空实现
	  void 查询还款记录(){
		  cout << "请输入还款人的还款名字" << endl; string  a; cin >> a; 人* person = NULL; TorF = false;
		  for (int i = 0; i < this->当前办理业务人数(); i++)
		  {
			  if (a == this->办理业务人数组[i]->名字) { this->办理业务人数组[i]->展示信息(); TorF = true; system("pause"); break; }
		  }
		  if (TorF == false)
		  {
			  cout << "信息不存在,此人并没有还款业务" << endl;
		  }
	  }
	  void 目录() {
		   cout << "欢迎来到银行信贷管理系统,输入数字执行以下操作" << endl;
		   cout << "0---退出系统" << endl; cout << "1--申请贷款" << endl; cout << "2--还贷款" << endl;
		   cout << "3--查询贷款记录" << endl; cout << "4--查询还款记录" << endl; cout << "5--清空记录" << endl;
		   cout << "6--删除人员" << endl; cout << "7--显示成员" << endl;
	  };
	  void 保存(){
		  ofstream ofs; ofs.open("bankfile.txt", ios::out);
		  for (int  i = 0; i < this->办理业务人个数; i++)
		  {
			  if (this->办理业务人数组[i]->还款人还是贷款人() == "贷款人") {
				  ofs << this->办理业务人数组[i]->名字 << " " << this->办理业务人数组[i]->身份证 << " " << this->办理业务人数组[i]->贷款编号 << " " << this->办理业务人数组[i]->贷款金额 << " " << this->办理业务人数组[i]->贷款年限 << " 贷款人" << endl;
			  }
			  if(this->办理业务人数组[i]->还款人还是贷款人()=="还款人")
			  {
				  ofs << this->办理业务人数组[i]->名字 << " " << this->办理业务人数组[i]->身份证 << " " << this->办理业务人数组[i]->还款编号 << " " << this->办理业务人数组[i]->还款金额 << " " << this->办理业务人数组[i]->还款年限 <<"还款人" << endl;
			  } }ofs.close();
		  }
	  
	  void 删除人员(){
		  cout << "请输入删除人的名字	" << endl; string name; cin >> name; bool  m=false;
		  for (int i = 0; i < this->当前办理业务人数(); i++)
		  {
			  if (name == this->办理业务人数组[i]->名字) {
				  m = true ;
				  for (int j = i; j < this->当前办理业务人数()-1; j++)
				  {
					  this->办理业务人数组[j] = this->办理业务人数组[j + 1];
				  }this->办理业务人个数--; cout << "删除成功" << endl; this->保存(); 
			  }
		  }
		  if (m == false ) { cout << "你要删除的人不存在" << endl; }
	  }
	  void 清空文档() {
		  ofstream ofs; ofs.open(filename, ios::trunc); ofs.close();//文件夹清空重建;
		  cout << "是否确定清空" << endl << "1-是" << endl << "2-否" << endl; int a; cin >> a;
		  if (a == 1) {
			  for (int i = 0; i < 办理业务人个数; i++)
			  {
				  delete this->办理业务人数组[i]; this->办理业务人数组[i] = nullptr;
			  } delete[]this->办理业务人数组; this->办理业务人数组 = nullptr; cout << "清空完毕" << endl;
		  }
	  }
	  void 退出程序() {
		  cout << "退出成功";  system("pause"); exit(0);
	  };
	  int  当前办理业务人数(){
		  ifstream ifs; ifs.open(filename, ios::in); int num = 0; int a, b, c, d; string name; string str;
		  while (ifs>>name&&ifs>>a&&ifs>>b&&ifs>>c&&ifs>>d&&ifs>>str)
		  {
			  num++;
		  }
		  ifs.close(); return num;
	  };
	  void 显示所有人() {
		  for (int i = 0; i < this->当前办理业务人数(); i++)
		  {
			  this->办理业务人数组[i]->展示信息(); cout << " " << this->办理业务人数组[i]->还款人还是贷款人() << endl;
		  }
	  }
	  银行操作系统() {
		  this->TorF = true; this->办理业务人数组 = NULL; ifstream ifs; ifs.open(filename, ios::in);
		  if (!ifs.is_open())
		  {
			  cout << "文件不存在" << endl; this->办理业务人个数 = 0; this->TorF= true; this->办理业务人数组= NULL;
			  ifs.close(); return;
		  }
		  char ch; ifs >> ch;//读取时是>>写入<<
		  if (ifs.eof())//只读一个字符如果这一个字符是文件结束符0XFF则返回TRUE
		  {
			  cout << "文件为空" << endl;  this->办理业务人个数 = 0; this->TorF = true; this->办理业务人数组 = NULL;
			   ifs.close(); return;
		  }
		  int num = this->当前办理业务人数(); cout << "职工个数为" << num << endl; this->办理业务人个数 = num;
		  this->办理业务人数组 = new 人 * [this->办理业务人个数]; this->获取文档数据();
		  for (int i = 0; i < this->办理业务人个数; i++)
		  {
			  //	cout << "职工编号:" << this->m_emparray[i]->m_ID << "   " << "姓名:" << this->m_emparray[i]->m_name <<"	 "<<"职位属于" << this->m_emparray[i]->getworkname() << endl;
		  }ifs.close();
	  }
	  ~银行操作系统() {
		  if (this->办理业务人数组!=NULL)
		  {
			  delete[]this->办理业务人数组; this->办理业务人数组 = NULL;
		  }
	  };
	  void 获取文档数据() {
		  ifstream ifs; ifs.open(filename, ios::in); int a, b, c, d; string name; int dex=0; string str;
		  while (ifs >> name && ifs >> a && ifs >> b && ifs >> c && ifs >> d && ifs >> str)
		  {
			  人* person = NULL; if (str == "贷款人") { person = new 贷款人(name, a, b, c, d); }
			  if (str == "还款人") { person = new  还款人(name, a, b, c, d); }
			  this->办理业务人数组[dex] = person; dex++;
		  }
	  }
};

