#include "mainmenu.hpp"
namespace cpp_prosto
{
namespace application
{


//---------------------- MENU ITEM ---------------------------------------------
//------------------------------------------------------------------------------
MenuItem::MenuItem(MenuValue aValue)
  :mValue(aValue)
{
}
//------------------------------------------------------------------------------
MenuItem::~MenuItem()
{
}
//------------------------------------------------------------------------------
void MenuItem::set(MenuValue aValue)
{
  mValue = aValue;
}
//------------------------------------------------------------------------------
MenuItem &MenuItem::add(MenuValue aValue)
{
  mItems.push_back(aValue);
  return mItems.back();
}
//------------------------------------------------------------------------------
const MenuValue &MenuItem::value()const
{
  return mValue;
}
//------------------------------------------------------------------------------
std::vector<MenuItem> &MenuItem::items()
{
  return mItems;
}

//------------------------- MENU -----------------------------------------------
//------------------------------------------------------------------------------
Menu::Menu()
{
  mStack.push({&mItems, mCurrentIndex});
}
//------------------------------------------------------------------------------
Menu::~Menu()
{
}
//------------------------------------------------------------------------------
MenuItem &Menu::add(MenuValue aValue)
{
  mItems.push_back(aValue);
  return mItems.back();
}
//------------------------------------------------------------------------------
const MenuValue &Menu::current()const
{
  return mCurrentItem;
}
//------------------------------------------------------------------------------
const unsigned &Menu::currentIndex()const
{
  return mCurrentIndex;
}
//------------------------------------------------------------------------------
unsigned Menu::amount()const
{
  auto &top = *(mStack.top().first);
  return top.size();
}
//------------------------------------------------------------------------------
const MenuItem &Menu::getItem(unsigned aIndex)const
{
  auto &top = *(mStack.top().first);
  return top[aIndex];
}
//------------------------------------------------------------------------------
void Menu::up()
{
  auto &top = *(mStack.top().first);

  if(top.empty())
    return;

  mCurrentIndex = (mCurrentIndex == 0) ? top.size() - 1 : mCurrentIndex - 1;
  mCurrentItem = top[mCurrentIndex].value();
}
//------------------------------------------------------------------------------
void Menu::down()
{
  auto &top = *(mStack.top().first);

  if(top.empty())
    return;

  mCurrentIndex = (mCurrentIndex == top.size() - 1) ? 0 : mCurrentIndex + 1;
  mCurrentItem =  top[mCurrentIndex].value();
}
//------------------------------------------------------------------------------
bool Menu::enter()
{
  auto &top = *(mStack.top().first);

  if(top.size() > 0)
  {
    auto &sub = top[mCurrentIndex].items();
    if(sub.size() > 0)
    {
      mStack.top().second = mCurrentIndex;
      mStack.push({&sub, 0});
      mCurrentIndex = 0;
      return true;
    }
    mCurrentItem = top[mCurrentIndex].value();
  }
  return false;
}
//------------------------------------------------------------------------------
void Menu::leave()
{
  if(mStack.size() > 1)
  {
    mStack.pop();

    auto &items = *(mStack.top().first);
    auto index  = (mStack.top().second);
    mCurrentIndex = index;
    mCurrentItem  = items[mCurrentIndex].value();
  }
}


}
}
