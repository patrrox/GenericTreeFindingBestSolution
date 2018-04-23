#include "stdafx.h"
#include "CVariable.h"


CVariable::CVariable()
{

}//CVariable::CVariable()
CVariable :: CVariable(string sName)
{
	s_name = sName;
	i_value = 0;
}//CVariable :: CVariable(string sName)


CVariable::~CVariable()
{

}//CVariable::~CVariable()


void CVariable::setValue(int iValue)
{
	i_value = iValue;
}//void CVariable::setValue(int iValue)

int CVariable::getValue()
{
	return i_value;
}//int CVariable::getValue()

void CVariable::setName(string sName)
{
	s_name = sName;
}//void CVariable::setName(string sName)
string CVariable::getName()
{
	return s_name;
}//string CVariable::getName()

