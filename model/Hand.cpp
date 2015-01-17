#include "Hand.h"
#include "Card.h"
#include <algorithm>
#include <unordered_set>


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

vector<int> Hand::rank() const
{
  vector<int> card_ranks = cards_ranking();
  vector<int> not_two_pairs {0,0};
  if (is_flush() && is_straight()){  // straight flush
    vector<int> res {8, card_ranks[0]};
    return res;
  }
  else if (is_kind_of(4) != 0) { // 4 of a kind
    vector<int> res {7, is_kind_of(4), is_kind_of(1)};
    return res;
  }
  else if (is_kind_of(2) != 0 && is_kind_of(3) != 0) { // full house
    vector<int> res {6, is_kind_of(3), is_kind_of(2)};
    return res;  
  }
  else if(is_flush()) { // flush
    vector<int> res {5};
    copy(begin(card_ranks), end(card_ranks), back_inserter(res));
    return res;
  }
  else if(is_straight()) { // straight
    vector<int> res {4, card_ranks[0]};
    return res;
  }
  else if(is_kind_of(3) != 0) { // 3 of a kind
    vector<int> res {3, is_kind_of(3)};
    copy(begin(card_ranks), end(card_ranks), back_inserter(res));
    return res;
  }
  else if(is_two_pairs() != not_two_pairs) { // 2 of a kind
    vector<int> res {2, is_two_pairs()[0], is_two_pairs()[1]};
    copy(begin(card_ranks), end(card_ranks), back_inserter(res));
    return res;
  }
  else if(is_kind_of(2)!= 0) { // one pair
    vector<int> res {1, is_kind_of(2)};
    copy(begin(card_ranks), end(card_ranks), back_inserter(res));
    return res;
  }
  else { // nothing
    vector<int> res {0};
    copy(begin(card_ranks), end(card_ranks), back_inserter(res));
    return res;
  }

}

vector<int> Hand::cards_ranking() const
{
  std::vector<int> rankings;
  for (auto card: m_cards) {
    string rank = card.get_card().substr(0, 1);
    if (rank == "A")
      rank = "14";
    else if(rank == "T")
      rank = "10";
    else if(rank == "J")
      rank = "11";
    else if(rank == "Q")
      rank = "12";
    else if(rank == "K")
      rank = "13";
    
    int rank_int = atoi(rank.c_str());    

    rankings.push_back(rank_int);
  }
  sort(begin(rankings), end(rankings), greater<int>());
  vector<int> r {14, 5, 4, 3, 2};
  vector<int> r2 {5, 4, 3, 2, 1};
  if (rankings == r)
    rankings = r2;

  return rankings;
}

bool Hand::is_flush() const
{
  string suit = m_cards[0].get_card().substr(1, 1);
  for (auto card: m_cards) {
    string suit2 = card.get_card().substr(1, 1);
    if (suit != suit2)
      return false;
  }

  return true;
}

bool Hand::is_straight() const
{
  // just check for a 5-card hand
  vector<int> cards_rankings = cards_ranking();
  unordered_set<int> rankings_set {begin(cards_rankings), end(cards_rankings)};
  
  return ((*max_element(begin(cards_rankings), end(cards_rankings)) - *min_element(begin(cards_rankings), end(cards_rankings))) == 4) && (rankings_set.size() == 5);
  
}

int Hand::is_kind_of(int kind) const
{
  vector<int> ranks = cards_ranking();
  for(auto rank: ranks) {
    if(count(begin(ranks), end(ranks), rank) == kind)
      return rank;
  }
  return 0;
}

int Hand::is_kind_of(int kind, const vector<int>& ranks) const
{
  for(auto rank: ranks) {
    if(count(begin(ranks), end(ranks), rank) == kind)
      return rank;
  }
  return 0;  
}

vector<int> Hand::is_two_pairs() const
{
  
  vector<int> reversed_ranks = cards_ranking();
  int high_pair = is_kind_of(2);
  reverse(begin(reversed_ranks), end(reversed_ranks));
  int low_pair = is_kind_of(2, reversed_ranks);
  if (low_pair != high_pair) {
    vector<int> pairs {high_pair, low_pair};
    return pairs;
  } 
  vector<int> p {0, 0};
  return p;
}
