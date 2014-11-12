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

int Hand::rank() const
{
  if (is_flush() && is_straight())
    return 8;

  return 0; // TODO
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
  return rankings;
}

bool Hand::is_flush() const
{
  string suit = m_cards[0].get_card().substr(1, 1);
  for (Card card: m_cards) {
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
  return -1;
}
