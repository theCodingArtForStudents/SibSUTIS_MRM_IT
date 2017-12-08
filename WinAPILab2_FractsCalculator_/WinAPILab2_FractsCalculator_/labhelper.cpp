#include "labhelper.h"

std::string LabHelper::IntToString(int value)
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}

int LabHelper::StrToInt(std::string str)
{
  return atoi(str.c_str());
}

LabHelper::LabHelper()
{

}
