#pragma once
#include <vector>
#include <string>
#include "Letter.hpp"
#include <set>

class Rule {
private:
  Letter terminal_;
  std::vector<Letter> rule_;
public:
  Rule() {};
  Rule(const std::string& string);
  Rule(const Rule& other_rule);

  // используется в итераторе 
  bool operator<(const Rule& other_rule) const;

  Letter GetLetterRight(int index) const;
  char GetTerminal() const;
  std::vector<Letter> GetRule() const;
  int GetSizeRule() const;
};

class Grammar {
public:
  std::set<Letter> terminal_;
  std::vector<Rule> rules_;
  void SetRule(const std::string& rule);
  void SetRule(const Rule& rule);
  void PrintRules();
  size_t GetTerminal() const;
  bool CheckRule(const Rule& other_rule) const;
  std::vector<Rule> GetRules() const;
};