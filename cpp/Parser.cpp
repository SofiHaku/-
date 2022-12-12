#include "../hpp/Parser.hpp"

bool ParserCYK::Check_word(const std::string& word, Grammar grammar) {
  dp.resize(grammar.GetAlph());
  for (size_t i = 0; i < grammar.GetAlph(); i++) {
    dp[i].resize(word.size());
    for ( size_t j = 0; j < word.size(); j++) {
      dp[i][j].resize(word.size(), false);
    }
  }

  if (word == "") {
    grammar.CheckRule("S->1");
  }

  InitOneLetters();

  for (size_t size_word = 2; size_word < word.size() + 1; size_word++) {
    ProcessWord(size_word);
  }

  return dp[][0][word.size()];
}

void ParserCYK::InitOneLetters() {

}

void ParserCYK::ProcessWord(size_t size_word) {
  
}

