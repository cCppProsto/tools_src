#ifndef LEE_WAVE_FINDER_H
#define LEE_WAVE_FINDER_H

#include <vector>
#include <stack>
#include <initializer_list>
#include <utility>

namespace cpp_prosto
{
namespace alg_way
{
namespace lee_wave
{

enum class eCell
{
  START
 ,FINISH
 ,FREE
 ,UNFREE
};

enum class eDirection
{
  UP
 ,UP_RIGHT
 ,RIGHT
 ,DOWN_RIGHT
 ,DOWN
 ,DOWN_LEFT
 ,LEFT
 ,UP_LEFT
};

enum class eFindType
{
  NEUMANN   // 4 neighborhood
 ,MOORE     // 8 neighborhood
};

struct WayMatrix
{
  WayMatrix(std::initializer_list<eCell>, unsigned aColumns);
  WayMatrix(unsigned aLines, unsigned aColumns);
  ~WayMatrix() = default;

  WayMatrix(const WayMatrix &) = delete;
  WayMatrix &operator=(const WayMatrix &) = delete;
  WayMatrix(const WayMatrix &&) = delete;
  WayMatrix &operator=(const WayMatrix &&) = delete;

  eCell get(unsigned, unsigned)const;

  void push(eCell);

  const unsigned &lines()const;
  const unsigned &columns()const;

private:
  unsigned mLines{0};
  unsigned mColumns{0};
  std::vector<eCell> mMatrix;
};


using point = std::pair<unsigned, unsigned>;

typedef void (*pf_next)();

struct finder
{
  finder(const WayMatrix&);
  finder(const finder &) = delete;
  finder &operator=(const finder &) = delete;

  void find(eFindType);

  const bool &isFound()const;

  const std::stack<eDirection> &get()const;

private:
  void _find_neumann(std::vector<unsigned>&);
  void _patch_building(std::vector<unsigned>&);

  std::pair<bool, point> is_moving_up(std::vector<unsigned>&, unsigned, unsigned);
  std::pair<bool, point> is_moving_left(std::vector<unsigned>&, unsigned, unsigned);
  std::pair<bool, point> is_moving_right(std::vector<unsigned>&, unsigned, unsigned);
  std::pair<bool, point> is_moving_down(std::vector<unsigned>&, unsigned, unsigned);

private:
  unsigned                mMaxCellCost;
  bool                    mIsFound{false};
  eFindType               mFindType{eFindType::NEUMANN};
  point                   mStart{0,0};
  point                   mFinish{0,0};
  const WayMatrix        &mMatrix;
  std::stack<eDirection>  mPath;
};

}
}
}
#endif // LEE_WAVE_FINDER_H
