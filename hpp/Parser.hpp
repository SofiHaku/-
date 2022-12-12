#include "../hpp/Grammar.hpp"
#include <set>
#include <vector>

class ParserCYK {
 private:
  std::string word_;
  Grammar grammar_;
  std::vector<std::vector<std::vector<bool>>> dp;
  void InitOneLetters();
  void ProcessWord(size_t size_word);

 public:
  bool Check_word(const std::string& word, Grammar grammar);
};