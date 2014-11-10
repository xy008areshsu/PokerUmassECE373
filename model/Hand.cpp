#include "Hand.h"
#include "Card.h"

using namespace std;


bool Hand::equal_to(const vector<string>& vec_s) const
{
  vector<Card> hand_of_cards = this->get_hand();
  if (hand_of_cards.size() != vec_s.size())
    return false;
		    
  for(int i = 0; i < vec_s.size(); ++i) {
    if (hand_of_cards[i].get_card() != vec_s[i]) {
      return false;	
    }
  }
  return true;

}

bool Hand::equal_to(const Hand& rhs) const
{
  vector<Card> hand_lhs = this->get_hand();
  vector<Card> hand_rhs = rhs.get_hand();
  if (hand_lhs.size() != hand_rhs.size())
    return false;
		    
  for(int i = 0; i < hand_lhs.size(); ++i) {
    if (hand_lhs[i].get_card() != hand_rhs[i].get_card()) {
      return false;	
    }
  }
  return true;
  
}
