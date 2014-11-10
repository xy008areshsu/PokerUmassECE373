#ifndef CARD_H
#define CARD_H

#include <string>


class Card {

 public:
 Card(const std::string& s): m_repr{s} {}

  std::string get_card() const {return m_repr;}
  void set_card(const std::string& s){m_repr = s;}

  
  



 private:
  std::string m_repr;
};


#endif
