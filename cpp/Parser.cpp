#include "../hpp/Parser.hpp"
#include <iostream>

void ParserCYK::InitOneLetters() {
  for (int i = 0; i < word_.size(); i++) {
    std::vector<Rule> rules = grammar_.GetRules();
    for (int j = 0; j < rules.size(); j++) {
      if ((rules[j].GetRule().size() == 1) &&
          (rules[j].GetRule()[0] == word_[i])) {
        dp[rules[j].GetTerminal()][i][i] = true;
      }
    }
  }
}

void ParserCYK::ProcessWord(size_t size_word) {
  for (int left = 0; left < word_.size() + 1; left++) {
    int right = left + size_word - 1;
    std::vector<Rule> rules = grammar_.GetRules();
    for (int j = 0; j < rules.size(); j++) {
      if (rules[j].GetRule().size() == 2) {
        for (int center = left; center < right; center++) {
          if ((dp[rules[j].GetRule()[0].GetLetter()][left][center]) &&
              (dp[rules[j].GetRule()[1].GetLetter()][center + 1][right])) {
            dp[rules[j].GetTerminal()][left][right] = true;
          }
        }
      }
    }
  }
}
