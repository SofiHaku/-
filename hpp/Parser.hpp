#include "../hpp/Grammar.hpp"
#include "../hpp/Situation.hpp"
#include <set>

class ParserEarley {
 private:
  std::string word_;
  Grammar grammar_;
  std::vector<std::set<Situation>> situation_;

  // читаем букву
  void Scan(int index);
  // спускаемся вниз
  void Predict(int index);
  // поднимаемся вверх
  void Complete(int index);
  Situation GetFakeStartSituation();

 public:
  bool Earley(const std::string& word, Grammar grammar);
};