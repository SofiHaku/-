#pragma once
#include "../hpp/Grammar.hpp"
#include "../hpp/Letter.hpp"
#include <set>
#include <vector>
#include <unordered_map>
#include <iostream>

class ParserCYK {
 private:
  std::string word_;
  Grammar grammar_;
  std::unordered_map<char, std::vector<std::vector<bool>>> dp;
  void InitOneLetters();
  void ProcessWord(size_t size_word);

 public:
  bool Check_word(std::string &word, Grammar& grammar);
  ParserCYK() {}
};