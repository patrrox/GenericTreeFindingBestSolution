#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CVariable
{
public:
	CVariable();
	CVariable(string cName);
	~CVariable();

	void setValue(int iValue);
	int getValue();
	void setName(string sName);
	string getName();


private:
	string s_name;
	int i_value;
};

