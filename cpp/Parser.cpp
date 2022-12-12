#include "../hpp/Parser.hpp"

bool ParserEarley::Earley(const std::string& word, Grammar grammar) {
  word_ = word;
  grammar_ = grammar;
  
  situation_.clear();
  situation_.resize(word.size() + 1);

  grammar.SetRule(Rule("S->S"));
  situation_[0].insert(Situation(Rule("S->S"), 0, 0));

  for (int i = 0; i < word.size() + 1; i++) {
    Scan(i);
    size_t old_situation_list_size = 0;
    
    do {
      old_situation_list_size = situation_[i].size();
      Complete(i);
      Predict(i);
    } while (situation_[i].size() != old_situation_list_size);
  }

  Situation final_situation = Situation(Rule("S->S"), 0, 0).GetNextSituation();
  const std::set<Situation>& last_situation_list = situation_[word.size()];
  return (last_situation_list.find(final_situation) != last_situation_list.end());
}


void ParserEarley::Scan(int index) {
  if (index == 0) {
    return;
  }

  for (const Situation& situation : situation_[index - 1]) {
    if (index == situation.Size()) {
      continue;
    }
    if (situation.IsTerminal(index)) {
      continue;
    }

    if (situation.GetNextLetter() == word_[index - 1]) {
      situation_[index].insert(situation.GetNextSituation());
    }
  }
}

void ParserEarley::Predict(int index) {
  for (Situation situation : situation_[index]) {
    if (index != situation.Size()) {
      continue;
    }
    if (!situation.IsTerminal(index)) {
      continue;
    }
    for (const Rule& rule : grammar_.GetRules()) {
      if (situation.GetNextLetter() == rule.GetTerminal()) {
        situation_[index].emplace(rule, index, 0);
      }
    }
  }
}

void ParserEarley::Complete(int index) {
  for (const Situation& situation : situation_[index]) {
    if (index == situation.Size()) {
      continue;
    }
    if (situation.IsTerminal(index)) {
      continue;
    }
    for (const Situation& other_situation : situation_[situation.GetParent()]) {
      if (index != other_situation.Size()) {
        continue;
      }
      
      if (other_situation.GetNextLetter() == situation.GetRule().GetTerminal()) {
        situation_[index].insert(other_situation.GetNextSituation());
      }
    }
  }
}
