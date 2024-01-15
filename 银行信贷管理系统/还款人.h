#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"人.h"
class 还款人:public   人
{
public:  virtual void 展示信息() { cout <<"名字:"<< this->名字 << " " <<"身份证:"<< this->身份证 << " " <<"还款编号:"<< this->还款编号 << " " <<"还款金额:"<< this->还款金额 << " " <<"还款年限:"<< this->还款年限 << endl; }
	  virtual string   还款人还是贷款人() {  return  string( "还款人"); }
	  还款人(string 名字, int 身份证, int 还款编号, int 还款金额, int 还款年限) {
		  this->名字 = 名字; this->身份证 = 身份证; this->还款编号 = 还款编号; this->还款金额 = 还款金额; this->还款年限 = 还款年限;
	  }
};

