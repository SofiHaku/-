#pragma once
#include <vector>
#include <string>
#include "Letter.hpp"


class Grammar {
private:
  std::vector<Rule> rules_;
public:
  Rule GetRule(int i) const;
  void SetRule(const std::string& rule);
  void SetRule(const Rule& rule);
};

class Rule {
private:
  Letter terminal_;
  std::vector<Letter> rule_;

public:
  Rule(char terminal, const std::string& rule);
  Rule(const std::string& string);
  Rule(const Rule& other_rule);
  bool operator==(const Rule& other_rule) const;
  bool operator!=(const Rule& other_rule) const;
  bool operator>(const Rule& other_rule) const;
  bool operator<(const Rule& other_rule) const;
};