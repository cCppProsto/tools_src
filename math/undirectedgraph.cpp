#include <limits>

#include "undirectedgraph.hpp"

namespace cpp_prosto
{
namespace math
{

undirectedGraph::undirectedGraph()
{
}
//------------------------------------------------------------------------------
void undirectedGraph::connect_nodes(unsigned aNode1, unsigned aNode2, unsigned aCost)
{
  if(!is_exist(aNode1))
  {
    std::vector<std::pair<unsigned, unsigned> > v;
    v.reserve(8);
    mNodes[aNode1] = std::move(v);
    mBlockedNodes[aNode1] = false;
  }

  if(!is_exist(aNode2))
  {
    std::vector<std::pair<unsigned, unsigned> > v;
    v.reserve(8);
    mNodes[aNode2] = std::move(v);
    mBlockedNodes[aNode2] = false;
  }

  if(!is_connected(aNode1, aNode2))
    mNodes[aNode1].push_back(std::pair<unsigned, unsigned>(aCost, aNode2));
  else
    change_cost(aNode2, aNode1, aCost);

  if(!is_connected(aNode2, aNode1))
    mNodes[aNode2].push_back(std::pair<unsigned, unsigned>(aCost, aNode1));
  else
    change_cost(aNode1, aNode2, aCost);
}
//------------------------------------------------------------------------------
bool undirectedGraph::is_exist(unsigned aNode)
{
  return (mNodes.find(aNode) != mNodes.end());
}
//------------------------------------------------------------------------------
bool undirectedGraph::is_blocked(unsigned aNode)
{
  if(!is_exist(aNode))
    return true;
  return mBlockedNodes[aNode];
}
//------------------------------------------------------------------------------
void undirectedGraph::block(unsigned aNode)
{
  if(!is_exist(aNode))
    return;
  mBlockedNodes[aNode] = true;
}
//------------------------------------------------------------------------------
void undirectedGraph::unblock(unsigned aNode)
{
  if(!is_exist(aNode))
    return;
  mBlockedNodes[aNode] = false;
}
//------------------------------------------------------------------------------
bool undirectedGraph::is_connected(unsigned aNode1, unsigned aNode2)
{
  if(!is_exist(aNode1))
    return false;

  if(!is_exist(aNode2))
    return false;

  const auto &neighbors = mNodes[aNode1];

  for(const auto &neighbor : neighbors)
    if(aNode2 == neighbor.second)
      return true;
  return false;
}
//------------------------------------------------------------------------------
unsigned undirectedGraph::cost(unsigned aNode1, unsigned aNode2)
{
  unsigned max = std::numeric_limits<unsigned int>::max();

  if(!is_exist(aNode1))
    return max;

  if(!is_exist(aNode2))
    return max;

  const auto &neighbors = mNodes[aNode1];

  for(const auto &neighbor : neighbors)
    if(aNode2 == neighbor.second)
      return neighbor.first;

  return max;
}
//------------------------------------------------------------------------------
void undirectedGraph::change_cost(unsigned aNode1, unsigned aNode2, unsigned aCost)
{
  if(!is_exist(aNode1))
    return;

  if(!is_exist(aNode2))
    return;

  auto &neighbors = mNodes[aNode1];

  for(auto &neighbor : neighbors)
    if(aNode2 == neighbor.second)
    {
      neighbor.first = aCost;
      return;
    }
}

}
}
