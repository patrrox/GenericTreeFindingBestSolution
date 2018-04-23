#pragma once

using namespace std;
#include <iostream>
//#include "CTree.h"

const string S_SP = " ";


class CFunction
{
public:
	CFunction();
	CFunction(double dValueX,double dValueY,double dResult);
	~CFunction();

	double getX();
	double getY();
	double getResult();

	void print();



private:
	double d_x;
	double d_y;
	double d_result;

};

