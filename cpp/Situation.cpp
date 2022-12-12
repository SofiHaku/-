#include "../hpp/Situation.hpp"
#include <tuple>


Situation::Situation(const Rule& rule, int index, int parent_index) {
  rule_ = rule;
  index_ = index;
  parent_index_ = parent_index;
}

Situation::Situation(const Situation& other) {
  rule_ = other.rule_;
  index_ = other.index_;
  parent_index_ = other.parent_index_;
}

int Situation::Size() const {
  return rule_.Size();
}

bool Situation::IsTerminal(int index) const {
  return (rule_.GetLetter(index)).GetTerminal();
}

char Situation::GetNextLetter() const {
  return (rule_.GetLetter(index_)).GetLetter();
}

Situation Situation::GetNextSituation() const {
  return Situation(rule_, index_ + 1, parent_index_);
}

bool Situation::operator<(const Situation& other) const {
  return std::make_tuple(rule_, parent_index_, other.index_)
      < std::make_tuple(other.rule_, other.parent_index_, other.index_);
}