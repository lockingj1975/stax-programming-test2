#include "pch.h"
#include <CppUnitTest.h>
#include "..\StaxAppData\AppData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StaxPayments
{

  //TEST(TestCaseName, TestName) {
  //  EXPECT_EQ(1, 1);
  //  EXPECT_TRUE(true);
  //}

  TEST_CLASS(TestAddingNewStaxData)
  {
  public:
    TEST_METHOD(AddItemsVerifyTheyExist)
    {
      AppData myData;
      int ids[] = { 0,3,5,7,8,10 };
      for (auto id : ids)
      {
        std::stringstream ss;
        ss << "myId ";
        ss << id;

        StaxData item(id, ss.str());
        myData.InsertDataItem(item);
      }
      Assert::AreEqual(6, myData.GetListCount());
    }
  };
}