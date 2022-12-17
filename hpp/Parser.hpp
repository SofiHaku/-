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
  bool Check_word(std::string &word, Grammar grammar);
  ParserCYK() {}
};

bool ParserCYK::Check_word(std::string &word, Grammar grammar) {
  word_ = word;
  grammar_ = grammar;

  dp.clear();

  for (auto i : grammar.terminal_) {
    std::pair<char, std::vector<std::vector<bool>>> new_pair(
        i.GetLetter(), std::vector<std::vector<bool>>(
               word.size() + 1, std::vector<bool>(word.size() + 1, false)));
    dp.insert(new_pair);
  }

  if (word_ == "") {
    return grammar_.CheckRule(Rule("S->"));
  }

  InitOneLetters();

  for (size_t size_word = 2; size_word < word_.size() + 1; size_word++) {
    ProcessWord(size_word);
  }

  /*
  std::cout << "A\n";
  for (int i = 0; i < word_.size() + 1; i++) {
    for (int j = 0; j < word_.size() + 1; j++) {
      std::cout << dp.at('A')[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "B\n"; 
  for (int i = 0; i < word_.size() + 1; i++) {
    for (int j = 0; j < word_.size() + 1; j++) {
      std::cout << dp.at('B')[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "S\n";
  for (int i = 0; i < word_.size() + 1; i++) {
    for (int j = 0; j < word_.size() + 1; j++) {
      std::cout << dp.at('S')[i][j] << " ";
    }
    std::cout << "\n";
  } */

  return dp.at('S')[0][word_.size() - 1];
}