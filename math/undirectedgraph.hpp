#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <map>
#include <vector>

namespace cpp_prosto
{
namespace math
{

struct undirectedGraph
{
  undirectedGraph();

  undirectedGraph(const undirectedGraph&) = delete;
  undirectedGraph &operator=(const undirectedGraph&) = delete;

  void connect_nodes(unsigned aNode1, unsigned aNode2, unsigned aCost = 1);
  void change_cost(unsigned aNode1, unsigned aNode2, unsigned aCost);

  void block(unsigned aNode);
  void unblock(unsigned aNode);

  unsigned cost(unsigned aNode1, unsigned aNode2);

  bool is_exist(unsigned aNode);
  bool is_blocked(unsigned aNode);
  bool is_connected(unsigned aNode1, unsigned aNode2);

private:
  std::map<unsigned, std::vector<std::pair<unsigned, unsigned> > > mNodes;
  std::map<unsigned, bool> mBlockedNodes;
};

}
}
#endif // UNDIRECTEDGRAPH_H
