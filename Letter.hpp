#pragma once
#include <string>

class Letter {
 private:
  char letter_;
  bool terminal_;
 public:
  Letter() {}
  Letter(const Letter& other_letter);
  Letter(char letter);
  bool GetTerminal() const;
  char GetLetter() const;
  void SetLetter(char letter);
  bool operator==(const Letter& other_letter) const;
};
