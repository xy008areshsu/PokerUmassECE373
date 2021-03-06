#ifndef POKER_H
#define POKER_H

#include <vector>
#include "Hand.h"

class Poker 
{
 public:
  Poker(const std::vector<Hand>& hands) {create_hands(hands);}
  std::vector<Hand> get_hands() const {return m_hands;}
  void set_hands(const std::vector<Hand>& new_hands) {create_hands(new_hands);}


  Hand best_hand() const;



 private:
  std::vector<Hand> m_hands;
  void create_hands(const std::vector<Hand>& hands);

};


#endif
