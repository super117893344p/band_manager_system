#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"��.h"
class ������:public   ��
{
public:  virtual void չʾ��Ϣ() { cout <<"����:"<< this->���� << " " <<"���֤:"<< this->���֤ << " " <<"������:"<< this->������ << " " <<"������:"<< this->������ << " " <<"��������:"<< this->�������� << endl; }
	  virtual string   �����˻��Ǵ�����() {  return  string( "������"); }
	  ������(string ����, int ���֤, int ������, int ������, int ��������) {
		  this->���� = ����; this->���֤ = ���֤; this->������ = ������; this->������ = ������; this->�������� = ��������;
	  }
};

