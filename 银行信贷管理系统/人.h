#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;

class  人 
{
public:int  身份证 = 0; string  名字; int 贷款金额 = 0; int  贷款年限 = 0; int 贷款编号 = 0; int 还款金额=0; int 还款年限=0; int 还款编号=0;
	  virtual void  展示信息() = 0; virtual string  还款人还是贷款人() = 0;//构造函数需要实例不可进行抽象化
};


