#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include "Card.h"

class Hand {
 public:
 Hand(const std::vector<Card> hand): m_cards{hand} {}

  std::vector<Card> get_hand() const {return m_cards;}
  void set_hand(const std::vector<Card>& hand) {m_cards = hand;} 

  bool equal_to(const std::vector<std::string>& vec_s) const;
  bool equal_to(const Hand& rhs) const;
  

 private:
  std::vector<Card> m_cards;


};

inline bool operator==(const Hand& lhs, const std::vector<std::string>& rhs){return lhs.equal_to(rhs); }
inline bool operator!=(const Hand& lhs, const std::vector<std::string>& rhs){return !(lhs == rhs);}

inline bool operator==(const  std::vector<std::string>& lhs, const Hand& rhs){ return rhs.equal_to(lhs); }
inline bool operator!=(const  std::vector<std::string>& lhs, const Hand& rhs){return !(lhs == rhs);}

inline bool operator==(const Hand& lhs, const Hand& rhs){ return rhs.equal_to(lhs); }
inline bool operator!=(const Hand& lhs, const Hand& rhs){return !(lhs == rhs);}

#endif
