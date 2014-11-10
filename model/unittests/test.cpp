#include "../Card.h"
#include "../Hand.h"
#include "../Poker.h"

#include <iostream>

using namespace std;

bool test_card_initialization();
bool test_hand_initialization();
bool test_equal_function_in_hand_class();
bool test_poker_init_set_and_get();

// Helper functions
vector<Hand> create_hands(const vector<vector<string> >& hands_using_str);
Hand create_hand(const vector<string>& hand_using_str);

int main() 
{
  if(test_card_initialization() && test_hand_initialization()
     && test_equal_function_in_hand_class()
     && test_poker_init_set_and_get())
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

vector<Hand> create_hands(const vector<vector<string> >& hands_using_str)
{
  vector<Hand> hands;
  for (vector<string> hand_str: hands_using_str) {
    hands.push_back(create_hand(hand_str));
  }
  return hands;
}

bool test_poker_init_set_and_get()
{
  vector<string> sf {"6C", "7C", "8C", "9C", "TC"};
  vector<string> fk {"9D", "9H", "9S", "9C", "7D"};
  vector<string> fh {"TD", "TC", "TH", "7C", "7D"};
  vector<string> fh2{"9D", "9C", "9H", "7C", "7D"};
  vector< vector<string> > hands_str {sf, fk, fh};
  vector<vector<string> > hands_str2 {sf, fk, fh2};
  vector<Hand> hands = create_hands(hands_str);
  vector<Hand> hands2 = create_hands(hands_str2);
  
  Poker poker_controller{hands};
  vector<Hand> hands_got_from_poker_controller = poker_controller.get_hands();
  for (int i = 0; i < hands_got_from_poker_controller.size(); ++i) {
    if (hands_got_from_poker_controller[i] != hands[i]) {
      cout << "Poker class init or getter failed!" << endl;
      return false;
    }
  }
  
  poker_controller.set_hands(hands2);
  hands_got_from_poker_controller.clear();
  hands_got_from_poker_controller = poker_controller.get_hands();
  for (int i = 0; i < hands_got_from_poker_controller.size(); ++i) {
    if (hands_got_from_poker_controller[i] != hands2[i]) {
      cout << "Poker class setter failed!" << endl;
      return false;
    }
  }
  
  return true;
  
}









