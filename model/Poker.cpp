#include "Poker.h"


using namespace std;

void Poker::create_hands(const std::vector<Hand>& hands)
{
  m_hands.clear();
  for(Hand hand: hands) {
    m_hands.push_back(hand);
  }
}

Hand Poker::best_hand() const
{
  return m_hands[0]; // TODO
}
