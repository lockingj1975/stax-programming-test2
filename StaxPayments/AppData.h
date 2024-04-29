#ifndef APPDATA_H
#define APPDATA_H

#include <list>
#include <string>

namespace StaxPayments
{
  class StaxData
  {
  public: 
    StaxData();
    StaxData(int id, const std::string& info);
    bool operator==(const StaxData& rhs) const;

    int GetId() const;
    void SetId(int id);

    std::string GetInfo() const;
    void SetInfo(const std::string& info);

  protected: 
    int _id = 0;
    std::string _info = "";
  };

  class AppData
  {
  public:
    AppData();
    const std::list<StaxData>& GetDataList() const;
    void InsertDataItem(const StaxData& item);
    bool RemoveDataItem(int id);
    bool RemoveDataItem(const StaxData& toRemove);
  protected:
    std::list<StaxData> _staxList;
  };
}
#endif