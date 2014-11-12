
#include "util.h"
using namespace std;

template<class T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& iter)
{
  for(T t: iter)
    os << t << ", ";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
  for(Card card: hand.get_hand())
    os << card.get_card() << ", ";
  return os;
}
