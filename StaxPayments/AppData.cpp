
#include "AppData.h"

StaxPayments::StaxData::StaxData()
{
}
StaxPayments::StaxData::StaxData(int id, const std::string& info)
{
  _id = id;
  _info = info;
}
bool StaxPayments::StaxData::operator==(const StaxData& rhs) const
{
  bool match = false;
  if (rhs._id == this->_id && rhs._info == this->_info)
    match = true;
  return match;
}

int StaxPayments::StaxData::GetId() const
{
  return _id;
}
void StaxPayments::StaxData::SetId(int id)
{
  _id = id;
}
std::string StaxPayments::StaxData::GetInfo() const
{
  return _info;
}
void StaxPayments::StaxData::SetInfo(const std::string& info)
{
  _info = info;
}


StaxPayments::AppData::AppData()
{
}
const std::list<StaxPayments::StaxData>& StaxPayments::AppData::GetDataList() const
{
  return _staxList;
}

void StaxPayments::AppData::InsertDataItem(const StaxData& item)
{
  _staxList.push_back(item);
}
/// <summary>
/// Remove first item with the id passed in. Ignores info.
/// </summary>
/// <param name="id"></param>
/// <returns></returns>
bool StaxPayments::AppData::RemoveDataItem(int id)
{
  bool fnd  = false;

  auto it = _staxList.begin();
  while (it != _staxList.end())
  {
    if (it->GetId() == id)
    {
      _staxList.erase(it);
      fnd = true;
      break;
    }
    ++it;
  }
  return fnd;
}
/// <summary>
/// Remove the item matching toRemove
/// </summary>
/// <param name="toRemove"></param>
/// <returns></returns>
bool StaxPayments::AppData::RemoveDataItem(const StaxData& toRemove)
{
  bool fnd = false;
  auto it = _staxList.begin();
  while (it != _staxList.end())
  {
    if (it->GetId() == toRemove.GetId() && it->GetInfo() == toRemove.GetInfo())
    {
      _staxList.erase(it);
      fnd = true;
      break;
    }
    ++it;
  }
  return fnd;
}