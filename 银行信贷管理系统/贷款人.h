#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"人.h"
class 贷款人: public 人
{
public: 
	  virtual void 展示信息() { cout << "名字:"<<this->名字 << " " << "身份证:"<<this->身份证 << " " << "贷款编号:"<<this->贷款编号 << " " <<"贷款金额:"<< this->贷款金额 << " " <<"贷款年限"<< this->贷款年限 << endl;}
	   virtual string 还款人还是贷款人() { return   string ("贷款人"); }
	   贷款人(string 名字, int 身份证, int 贷款编号, int 贷款金额, int 贷款年限){
		  this->名字 = 名字; this->身份证 = 身份证; this->贷款编号 = 贷款编号; this->贷款金额 = 贷款金额; this->贷款年限 = 贷款年限;
	  }
};

