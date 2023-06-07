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
  for (int left = 0; left < word_.size() - size_word + 1; left++) {
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

bool ParserCYK::Check_word(std::string &word, Grammar& grammar) {
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

  return dp.at('S')[0][word_.size() - 1];
}