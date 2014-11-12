#include "Poker.h"
#include <algorithm>

using namespace std;

//Private helper functions
bool hand_rank(const Hand& h1, const Hand& h2);

void Poker::create_hands(const std::vector<Hand>& hands)
{
  m_hands.clear();
  for(Hand hand: hands) {
    m_hands.push_back(hand);
  }
}

Hand Poker::best_hand() const
{
  return m_hands[1];
  auto max_pt = max_element(begin(m_hands), end(m_hands), hand_rank); // max_element returns an iterator, not a value
  
  return *max_pt;
}

bool hand_rank(const Hand& h1, const Hand& h2)
{
  return h1.rank() < h2.rank();
}
