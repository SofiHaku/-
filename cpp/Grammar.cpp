#include "hpp/Grammar.hpp"

Rule::Rule(char terminal, const std::string& rule) {
  terminal_ = terminal;
  for (int i = 0; i < rule.size(); i++) {
    rule_[i] = Letter(rule[i]);
  }
}

Rule::Rule(const std::string& string) {
  terminal_ = string[0];
  for (int i = 3; i < string.size(); i++) {
    rule_[i - 3] = Letter(string[i]);
  }
}

Rule::Rule(const Rule& other_rule) {
  terminal_ = other_rule.terminal_;
  for (int i = 0; i < other_rule.rule_.size(); i++) {
    rule_[i] = other_rule.rule_[i];
  }
}

bool Rule::operator!=(const Rule& other_rule) const {
  return (*this == other_rule);
}

bool Rule::operator==(const Rule& other_rule) const {
  if (terminal_ != other_rule.terminal_) {
    return false;
  }
  if (rule_.size() != other_rule.rule_.size()) {
    return false;
  }
  
  for (int i = 0; i < rule_.size(); i++) {
    if (rule_[i] != other_rule.rule_[i]) {
      return false;
    }
  }
  return true;
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

bool Rule::operator>(const Rule& other_rule) const {
  return (*this < other_rule);
}


Rule Grammar::GetRule(int i) const{
  return rules_[i];
}

void Grammar::SetRule(const std::string& rule) {
  Rule new_rule = Rule(rule);
  rules_.push_back(new_rule);
}

void Grammar::SetRule(const Rule& rule) {
  rules_.push_back(rule);
}