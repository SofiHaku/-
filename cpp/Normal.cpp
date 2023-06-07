#include "../hpp/Normal.hpp"

Grammar &DeleteLong(const Grammar &grammar) {
  std::vector<Letter> letters = {
      Letter('Q'), Letter('W'), Letter('E'), Letter('R'), Letter('T'),
      Letter('Y'), Letter('U'), Letter('I'), Letter('O'), Letter('P'),
      Letter('A'), Letter('S'), Letter('D'), Letter('F'), Letter('G'),
      Letter('H'), Letter('J'), Letter('K'), Letter('L'), Letter('Z'),
      Letter('X'), Letter('V'), Letter('B'), Letter('N'), Letter('M')};
  Grammar new_grammar = grammar;
  for (int i = 0; i < grammar.rules_.size(); i++) {
    if (grammar.rules_[i].GetRule().size() > 2) {
      Rule new_rule;
      new_rule.terminal_ = grammar.rules_[i].terminal_;
      for (int j = 0; j < letters.size(); j++) {
        if (grammar.terminal_.find(letters[i]) == grammar.terminal_.end()) {
          new_rule.rule_.push_back(letters[i]);
          new_rule.rule_.push_back(grammar.rules_[i].GetRule()[grammar.rules_[i].GetRule().size() - 1]);
          grammar.rules_.push_back(new_rule);
        }
      }
    }
  }
}