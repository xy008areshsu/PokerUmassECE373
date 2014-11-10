#include "Hand.h"
#include "Card.h"

#include <vector>
#include <string>

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
