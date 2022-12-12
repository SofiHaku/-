#include "Grammar.hpp"

/*
  В терминологии лектора -
  index - заполненная точка
  parent_index - пустая точка
*/

class Situation {
 private:
  Rule rule_;
  int index_;
  int parent_index_;

 public:
  Situation(const Rule& rule, int index, int parent_index);
  Situation(const Situation& other);
  int Size() const;
  bool IsTerminal(int index) const;
  char GetNextLetter() const;
  Situation GetNextSituation() const;
  int GetParent() const { return parent_index_; };
  Rule GetRule() const { return rule_; };
  bool operator<(const Situation& other) const;
};