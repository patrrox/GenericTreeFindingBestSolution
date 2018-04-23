#include "stdafx.h"
#include "CFunction.h"


CFunction::CFunction()
{
}//CFunction::CFunction()

CFunction::CFunction(double dValueX, double dValueY, double dResult)
{
	d_x = dValueX;
	d_y = dValueY;
	d_result = dResult;
}//CFunction::CFunction(double dValueX, double dValueY, double dResult)


CFunction::~CFunction()
{
}//CFunction::~CFunction()



double CFunction::getX()
{
	return d_x;
}//double CFunction::getX()
double CFunction::getY()
{
	return d_y;
}//double CFunction::getY()
double CFunction::getResult()
{
	return d_result;
}//double CFunction::getResult()

void CFunction :: print()
{
	cout << d_x << " " << d_y << " " << d_result<<endl;
}//void CFunction :: print()