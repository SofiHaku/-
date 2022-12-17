#include "../hpp/Grammar.hpp"
#include <iostream>

Rule::Rule(const std::string& string) {
  terminal_.SetLetter(string[0]);
  rule_.resize(string.size() - 3);
  for (int i = 3; i < string.size(); i++) {
    rule_[i - 3] = Letter(string[i]);
  }
}

Rule::Rule(const Rule& other_rule) {
  // оператор кописрования
  terminal_ = other_rule.terminal_;
  rule_.resize(other_rule.rule_.size());
  for (int i = 0; i < other_rule.rule_.size(); i++) {
    rule_[i] = other_rule.rule_[i];
  }
}

bool Rule::operator<(const Rule& other_rule) const {
  if (terminal_.GetLetter() < other_rule.terminal_.GetLetter()) {
    return true;
  } else if (terminal_.GetLetter() > other_rule.terminal_.GetLetter()) {
    return false;
  }

  int min = rule_.size();

  if (rule_.size() > other_rule.rule_.size()) {
    min = other_rule.rule_.size();
  }

  for (int i = 0; i < min; i++) {
    if (rule_[i].GetLetter() < other_rule.rule_[i].GetLetter()) {
      return true;
    }
  }

  if (rule_.size() < other_rule.rule_.size()) {
    return true;
  }

  return false;
}

void Grammar::SetRule(const std::string& rule) {
  Rule new_rule = Rule(rule);
  rules_.push_back(new_rule);

  std::vector<Letter> rul = new_rule.GetRule();

  if (terminal_.find(new_rule.GetTerminal()) == terminal_.end()) {
    terminal_.insert(new_rule.GetTerminal());
  }
}

void Grammar::SetRule(const Rule& rule) {
  rules_.push_back(rule);
}

int Rule::GetSizeRule() const {
  return rule_.size();
}

std::vector<Rule> Grammar::GetRules() const {
  return rules_;
}

Letter Rule::GetLetterRight(int index) const {
  return rule_[index];
}

char Rule::GetTerminal() const {
  return terminal_.GetLetter();
}

void Grammar::PrintRules() {
  for (size_t i = 0; i < rules_.size(); i++) {
    std::cout << rules_[i].GetTerminal() << "->";
    for (size_t j = 0; j < rules_[i].GetRule().size(); j++) {
      std::cout << rules_[i].GetRule()[j].GetLetter();
    }
    std::cout << "\n";
  }
}

std::vector<Letter> Rule::GetRule() const {
  return rule_;
}

size_t Grammar::GetTerminal() const {
  return terminal_.size();
}


bool Grammar::CheckRule(const Rule& other_rule) const {
  for (int i = 0; i < rules_.size(); i++) {
    if ((rules_[i].GetTerminal() == other_rule.GetTerminal()) && (rules_[i].GetRule() == other_rule.GetRule())) {
      return true;
    }
  }
  return false;
}