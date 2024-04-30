// StaxPayments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\StaxAppData\AppData.h"
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

using namespace StaxPayments;

int main()
{
  AppData myData;
  int ids[] = { 0,3,5,7,5,8,10 };
  StaxData testOtherRemove;
  for (auto id : ids)
  {
    std::stringstream ss;
    ss << "myId ";
    ss << id;

    StaxData item(id,ss.str());
    if (id == 10)
    {
      testOtherRemove.SetId(id);
      testOtherRemove.SetInfo(ss.str());
    }
    myData.InsertDataItem(item);
  }
  myData.RemoveDataItem(5);
  myData.RemoveDataItem(5);
  myData.RemoveDataItem(testOtherRemove);

  const std::list<StaxData>& newList = myData.GetDataList();
  for (auto sd : newList)
  {
    cout << "List item {" << sd.GetId() << "} info: " << sd.GetInfo() << endl;
  }
}