#pragma once
#include <string>

class Letter {
 private:
 public:
  Letter() {}
  Letter(const Letter& other_letter);
  Letter(char letter);
  bool GetTerminal() const;
  char GetLetter() const;
  void SetLetter(char letter);
  bool operator==(const Letter& other_letter) const;
  bool operator!=(const Letter& other_letter) const;
  char letter_;
  bool terminal_;
};
