#include <stack>
#include <queue>
#include "lee_wave_finder.hpp"

namespace cpp_prosto
{
namespace alg_way
{
namespace lee_wave
{

//----------------------- ADDITIONAL FUNCTIONS ---------------------------------
std::pair<point, point> find_start_finish(const WayMatrix&);

//--------------------- WAY MATRIX (two dimension array) -----------------------
//------------------------------------------------------------------------------
WayMatrix::WayMatrix(std::initializer_list<eCell> aList, unsigned aColumns)
{
  mMatrix.reserve(aList.size());
  for(auto i : aList)
    mMatrix.push_back(i);

  mLines   = aList.size() / aColumns;
  mColumns = aColumns;
}
//------------------------------------------------------------------------------
WayMatrix::WayMatrix(unsigned aLines, unsigned aColumns)
{
  mMatrix.reserve(aLines * aColumns);
  mLines   = aLines;
  mColumns = aColumns;
}
//------------------------------------------------------------------------------
void WayMatrix::push(eCell aCell)
{
  if(mMatrix.size() <= mLines * mColumns)
    mMatrix.push_back(aCell);
}
//------------------------------------------------------------------------------
eCell WayMatrix::get(unsigned aLine, unsigned aColumn)const
{
  if((aLine * aColumn) < mMatrix.size())
    return mMatrix[aLine * mColumns + aColumn];
  return eCell::UNFREE;
}
//------------------------------------------------------------------------------
const unsigned &WayMatrix::lines()const
{
  return mLines;
}
//------------------------------------------------------------------------------
const unsigned &WayMatrix::columns()const
{
  return mColumns;
}

//--------------------- WAY FINDER ---------------------------------------------
//------------------------------------------------------------------------------
finder::finder(const WayMatrix &aMatrix)
  :mMatrix(aMatrix)
{
  std::pair<point, point> res;
  res = find_start_finish(aMatrix);
  mStart  = res.first;
  mFinish = res.second;

  mMaxCellCost = aMatrix.columns() * aMatrix.lines();
}
//------------------------------------------------------------------------------
void finder::find(eFindType aType)
{
  std::vector<unsigned> arr;
  arr.resize(mMatrix.lines() * mMatrix.columns(), mMaxCellCost);

  mFindType = aType;

  switch(aType)
  {
    case eFindType::NEUMANN: // 4 neighborhood
    {
      arr[mStart.first * mMatrix.columns() + mStart.second] = 0;

      mIsFound = false;

      _find_neumann(arr);
      if(mIsFound)
        _patch_building(arr);
      break;
    }
    case eFindType::MOORE:   // 8 neighborhood
    {
      break;
    }
  }
}


//------------------------------------------------------------------------------
const bool &finder::isFound()const
{
  return mIsFound;
}
//------------------------------------------------------------------------------
const std::stack<eDirection> &finder::get()const
{
  return mPath;
}
//------------------------------------------------------------------------------
std::pair<bool, point> finder::is_moving_up(std::vector<unsigned> &aArr,
                                            unsigned aL,
                                            unsigned aC)
{
  std::pair<bool, point> res{false,{0,0}};

  auto l   = aL - 1;
  auto val = aArr[aL*mMatrix.columns() + aC] + 1;

  if(mMatrix.get(l, aC) == eCell::FINISH)
    mIsFound = true;

  if(mMatrix.get(l, aC) == eCell::FREE)
  {
    if(aArr[l*mMatrix.columns() + aC] == mMaxCellCost)
    {
      res.first         = true;
      res.second.first  = l;
      res.second.second = aC;
      aArr[l*mMatrix.columns() + aC] = val;
    }
  }

  return res;
}
//------------------------------------------------------------------------------
std::pair<bool, point> finder::is_moving_left(std::vector<unsigned> &aArr,
                                              unsigned aL,
                                              unsigned aC)
{
  std::pair<bool, point> res{false,{0,0}};

  auto c   = aC - 1;
  auto val = aArr[aL*mMatrix.columns() + aC] + 1;

  if(mMatrix.get(aL, c) == eCell::FINISH)
    mIsFound = true;

  if(mMatrix.get(aL, c) == eCell::FREE)
  {
    if(aArr[aL*mMatrix.columns() + c] == mMaxCellCost)
    {
      res.first         = true;
      res.second.first  = aL;
      res.second.second = c;
      aArr[aL*mMatrix.columns() + c] = val;
    }
  }
  return res;
}
//------------------------------------------------------------------------------
std::pair<bool, point> finder::is_moving_right(std::vector<unsigned> &aArr,
                                               unsigned aL,
                                               unsigned aC)
{
  std::pair<bool, point> res{false,{0,0}};

  auto c   = aC + 1;
  auto val = aArr[aL*mMatrix.columns() + aC] + 1;

  if(mMatrix.get(aL, c) == eCell::FINISH)
    mIsFound = true;

  if(mMatrix.get(aL, c) == eCell::FREE)
  {
    if(aArr[aL*mMatrix.columns() + c] == mMaxCellCost)
    {
      res.first         = true;
      res.second.first  = aL;
      res.second.second = c;
      aArr[aL*mMatrix.columns() + c] = val;
    }
  }
  return res;
}
//------------------------------------------------------------------------------
std::pair<bool, point> finder::is_moving_down(std::vector<unsigned> &aArr,
                                              unsigned aL,
                                              unsigned aC)
{
  std::pair<bool, point> res{false,{0,0}};

  auto l   = aL + 1;
  auto val = aArr[aL*mMatrix.columns() + aC] + 1;

  if(mMatrix.get(l, aC) == eCell::FINISH)
    mIsFound = true;

  if(mMatrix.get(l, aC) == eCell::FREE)
  {
    if(aArr[l*mMatrix.columns() + aC] == mMaxCellCost)
    {
      res.first         = true;
      res.second.first  = l;
      res.second.second = aC;
      aArr[l*mMatrix.columns() + aC] = val;
    }
  }
  return res;
}
//------------------------------------------------------------------------------
void finder::_find_neumann(std::vector<unsigned> &aArr)
{
  std::queue<point> _queque;
  _queque.push({mStart.first, mStart.second});

  std::pair<bool, point> res;

  while(_queque.size() > 0)
  {
    point tmp = _queque.front();
    _queque.pop();

    res = is_moving_up(aArr, tmp.first, tmp.second);
    if(res.first == true)
      _queque.push(res.second);

    res = is_moving_right(aArr, tmp.first, tmp.second);
    if(res.first == true)
      _queque.push(res.second);

    res = is_moving_down(aArr, tmp.first, tmp.second);
    if(res.first == true)
      _queque.push(res.second);

    res = is_moving_left(aArr, tmp.first, tmp.second);
    if(res.first == true)
      _queque.push(res.second);
  }
}
//------------------------------------------------------------------------------
void finder::_patch_building(std::vector<unsigned> &aArr)
{
  auto ln   = mFinish.first;
  auto cn   = mFinish.second;
  auto val = mMaxCellCost;
  auto index = 0u;
  auto dl = 0;
  auto dc = 0;

  while(!mPath.empty())
      mPath.pop();

  for(;;)
  {
    index = 0u;

    auto up         = aArr[ (ln - 1)*mMatrix.columns() + cn];
    auto up_right   = aArr[ (ln - 1)*mMatrix.columns() + (cn + 1)];
    auto right      = aArr[ ln*mMatrix.columns()       + (cn + 1)];
    auto down_right = aArr[ (ln + 1)*mMatrix.columns() + (cn + 1)];
    auto down       = aArr[ (ln + 1)*mMatrix.columns() + cn];
    auto down_left  = aArr[ (ln + 1)*mMatrix.columns() + (cn - 1)];
    auto left       = aArr[ ln*mMatrix.columns()       + (cn - 1)];
    auto up_left    = aArr[ (ln - 1)*mMatrix.columns() + (cn - 1)];

    if(up < val)    { val = up;   index = 1; }
    if(right < val) { val = right;index = 3; }
    if(down < val)  { val = down; index = 5; }
    if(left < val)  { val = left; index = 7; }

    if(mFindType == eFindType::MOORE)
    {
      if(up_right < val)  { val = up_right;   index = 2; }
      if(down_right < val){ val = down_right; index = 4; }
      if(down_left < val) { val = down_left;  index = 6; }
      if(up_left < val)   { val = up_left;    index = 8; }
    }

    switch(index)
    {
      case 0:
      {
        return;
      }
      case 1: // up
      {
        dl = -1;
        mPath.push(eDirection::DOWN);
        break;
      }
      case 2: // up right
      {
        dl = -1;
        dc = 1;
        mPath.push(eDirection::DOWN_LEFT);
        break;
      }
      case 3: // right
      {
        dc = 1;
        mPath.push(eDirection::LEFT);
        break;
      }
      case 4: // down right
      {
        dl = 1;
        dc = 1;
        mPath.push(eDirection::UP_LEFT);
        break;
      }
      case 5: // down
      {
        dl = 1;
        mPath.push(eDirection::UP);
        break;
      }
      case 6: // down left
      {
        dl = 1;
        dc = -1;
        mPath.push(eDirection::UP_LEFT);
        break;
      }
      case 7: // left
      {
        dc = -1;
        mPath.push(eDirection::RIGHT);
        break;
      }
      case 8: // up left
      {
        dl = -1;
        dc = -1;
        mPath.push(eDirection::DOWN_RIGHT);
        break;
      }
    }
    ln += dl;
    cn += dc;
    dl = 0;
    dc = 0;
  }
}
//----------------------- ADDITIONAL FUNCTIONS ---------------------------------
std::pair<point, point> find_start_finish(const WayMatrix &aMatrix)
{
  std::pair<point, point> res{{0,0},{0,0}};

  for(unsigned l = 0; l < aMatrix.lines();++l)
    for(unsigned c = 0; c < aMatrix.columns(); ++c)
    {
      if(aMatrix.get(l, c) == eCell::START)
        res.first = {l,c};
      if(aMatrix.get(l, c) == eCell::FINISH)
        res.second = {l,c};
    }
  return res;
}


}
}
}


