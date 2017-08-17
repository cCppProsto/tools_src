#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <vector>
#include <stack>

namespace cpp_prosto
{
namespace application
{

struct MenuValue final
{
  unsigned     id;
  std::string  text;
};

struct MenuItem final
{
  MenuItem(MenuValue aValue);
  ~MenuItem();

  void set(MenuValue aValue);
  MenuItem &add(MenuValue aValue);

  const MenuValue &value()const;
  std::vector<MenuItem> &items();

private:
  MenuValue             mValue;
  std::vector<MenuItem> mItems;
};

struct Menu final
{
  Menu();
  ~Menu();

  MenuItem &add(MenuValue aValue);

  const MenuValue &current()const;
  const unsigned &currentIndex()const;

  unsigned amount()const;
  const MenuItem &getItem(unsigned)const;

  void up();
  void down();
  bool enter();
  void leave();

private:
  using stack = std::stack<std::pair<std::vector<MenuItem>*, unsigned> >;

  unsigned              mCurrentIndex{0};
  std::vector<MenuItem> mItems;
  MenuValue             mCurrentItem;
  stack                 mStack;
};


}
}

#endif // MAINMENU_H
