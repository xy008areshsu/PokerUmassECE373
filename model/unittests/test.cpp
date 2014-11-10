#include "../Card.h"
#include "../Hand.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool test_card_initialization();
bool test_hand_initialization();
bool test_equal_function_in_hand_class();

int main() 
{
  if(test_card_initialization() && test_hand_initialization()
     && test_equal_function_in_hand_class())
    cout << "All tests passed" << endl;

  return 0;
}


bool test_card_initialization() {
  Card card1 {"6C"};
  string expected_card1 = "6C";
  if (expected_card1 != card1.get_card()){
    cout << "Card class initialization failed!" << endl;
    return false;
  }
  
  return true;

}

Hand create_hand(const vector<string>& hand_using_str) {
  vector<Card> cards;
  for(string s: hand_using_str) {
    cards.push_back(Card{s}); 
  }
  Hand hand1{cards};
  return hand1;
}

bool test_hand_initialization() {
  vector<string> sf {"6C", "7C", "8C", "9C", "TC"};
  Hand hand1 = create_hand(sf);

  vector<Card> hand_of_cards = hand1.get_hand();

  for(int i = 0; i < sf.size(); ++i) {
    if (hand_of_cards[i].get_card() != sf[i]) {
     
      cout << "Hand class initialization failed!" << endl;
      return false;	
    }
  }
  return true;
}


bool test_equal_function_in_hand_class() {
  vector<string> sf {"6C", "7C", "8C", "9C", "TC"};
  Hand hand1 = create_hand(sf);

  if(!hand1.equal_to(sf)) {
    cout << "Equal_to function in Hand class failed!" << endl;
    return false;
  }

  if(hand1 != sf or sf != hand1) {
    cout << "== and != for Hand and vector of string failed!" << endl;
    return false;
  }
  return true;
}

