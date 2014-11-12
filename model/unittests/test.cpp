#include "../Card.h"
#include "../Hand.h"
#include "../Poker.h"
#include "../../utility/util.h"

#include <iostream>

using namespace std;


bool test_card_initialization();
bool test_hand_initialization();
bool test_equal_function_in_hand_class();
bool test_poker_init_set_and_get();
bool test_poker_best_hand();
bool test_cards_ranking();
bool test_hand_is_flush();
bool test_hand_is_straight();
bool test_hand_is_kind_of();
bool test_hand_is_two_pairs();

// Helper functions
vector<Hand> create_hands(const vector<vector<string> >& hands_using_str);
Hand create_hand(const vector<string>& hand_using_str);

template<class T1, class T2>
bool assert_equal(T1 output, T2 expected, string promt); 



int main() 
{
  if(test_hand_is_two_pairs()
     && test_hand_is_kind_of()
     && test_hand_is_flush()
     && test_hand_is_straight()
     && test_card_initialization() 
     && test_hand_initialization()
     && test_equal_function_in_hand_class()
     && test_poker_init_set_and_get()
     && test_poker_best_hand()
     && test_cards_ranking())
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


bool test_poker_best_hand()
{
  
  vector<string> sf {"6C", "7C", "8C", "9C", "TC"};
  vector<string> fk {"9D", "9H", "9S", "9C", "7D"};
  vector<string> fh {"TD", "TC", "TH", "7C", "7D"};
  vector<vector<string> > hands_str {sf, fk, fh};
  vector<vector<string> > hands_str2 {fk, fh};
  vector<vector<string> > hands_str3 {fh, fh};
  vector<vector<string> > hands_str4 {fh};
  vector<vector<string> > hands_str5 {sf};
  for(int i = 0; i < 100; ++i)
    hands_str5.push_back(fh);
  vector<Hand> hands = create_hands(hands_str);
  vector<Hand> hands2 = create_hands(hands_str2);
  vector<Hand> hands3 = create_hands(hands_str3);
  vector<Hand> hands4 = create_hands(hands_str4);
  vector<Hand> hands5 = create_hands(hands_str5);
  
  
  Poker p {hands};

  
  Hand best_hand = p.best_hand();
  if(!assert_equal(best_hand, sf, "Best hand function failed"))
    return false;
  
  p.set_hands(hands2);
  best_hand = p.best_hand();
  if(!assert_equal(best_hand, fk, "Best hand function failed"))
    return false;
  
  p.set_hands(hands3);
  best_hand = p.best_hand();
  if(!assert_equal(best_hand, fh, "Best hand function failed"))
    return false;

  p.set_hands(hands4);
  best_hand = p.best_hand();
  if(!assert_equal(best_hand, fh, "Best hand function failed"))
    return false;

  p.set_hands(hands5);
  best_hand = p.best_hand();
  if(!assert_equal(best_hand, sf, "Best hand function failed"))
    return false;
  
  return true;

}

template<class T1, class T2>
bool assert_equal(T1 output, T2 expected, string promt) 
{
  if (output != expected) {
    cout << promt << endl << "expected to be: " << expected << endl << "Actual output: " << output << endl;
    return false;
  }
  return true;
}
  
bool test_cards_ranking()
{
  Hand h1 = create_hand({"AC", "3D", "4S", "KH"});

  vector<int> expected_rankings {14, 13, 4, 3};

  vector<int> actual_rankings = h1.cards_ranking();

  if(!assert_equal(actual_rankings, expected_rankings, "Cards Ranking Failed!"))
    return false;
  return true;
}
 
bool test_hand_is_flush()
{
  vector<string> sf {"6C", "7C", "8C", "9C", "TC"};
  vector<string> fk {"9D", "9H", "9S", "9C", "7D"};

  Hand h1 = create_hand(sf);
  Hand h2 = create_hand(fk);
  string promt {"Is Flush function failed!"};
  if(!assert_equal(h1.is_flush(), true, promt))
    return false;
  if(!assert_equal(h2.is_flush(), false, promt))
    return false;

  return true;

}

bool test_hand_is_straight()
{
  vector<string> cards {"9C", "8C", "7C", "6C", "5C"};
  vector<string> cards2 {"9C", "8C", "8H", "6C", "5C"};

  Hand h1 = create_hand(cards);
  Hand h2 = create_hand(cards2);
  string promt = "Is Straight function failed";
  if(!assert_equal(h1.is_straight(), true, promt))
    return false;

  if(!assert_equal(h2.is_straight(), false, promt))
    return false;

  return true;
  
  
}

bool test_hand_is_kind_of()
{
  
  vector<string> cards {"9D", "9H", "9S", "9C", "7D"};
  Hand fk = create_hand(cards);
  
  string promt {"Is Kind function failed"};

  if(!assert_equal(fk.is_kind_of(4), 9, promt))
    return false;

  if(!assert_equal(fk.is_kind_of(1), 7, promt))
    return false;
  
  if(!assert_equal(fk.is_kind_of(3), 0, promt))
    return false;

  return true;
  
}

bool test_hand_is_two_pairs()
{

  vector<string> cards {"5S", "5D", "9H", "9C", "6S"};
  vector<string> cards2 {"1s", "2D", "9H", "8C", "6S"};
  Hand sp = create_hand(cards);
  Hand h = create_hand(cards2);

  string promt {"Is two pairs function failed"};

  vector<int> expected_pairs {9, 5};
  vector<int> expected_pairs2 {0, 0};

  vector<int> actual_pairs = sp.is_two_pairs();
  vector<int> actual_pairs2 = h.is_two_pairs();

  if(!assert_equal(actual_pairs, expected_pairs, promt))
    return false;

  if(!assert_equal(actual_pairs2, expected_pairs2, promt))
    return false;

  return true;

}




