#include "../hpp/Letter.hpp"

Letter::Letter(char letter) {
  char letter_ = letter;
  // Если буква большая, то терминал
  bool terminal_ = isupper(letter);
}

Letter::Letter(const Letter& other_letter) {
  char letter_ = other_letter.letter_;
  bool terminal_ = other_letter.letter_;
}

bool Letter::operator==(const Letter& other_letter) const {
  if ((letter_ == other_letter.letter_) && (terminal_ == other_letter.terminal_)) {
    return true;
  }
  return false;
}

bool Letter::operator!=(const Letter& other_letter) const {
  if ((letter_ == other_letter.letter_) && (terminal_ == other_letter.terminal_)) {
    return false;
  }
  return true;
}

bool Letter::GetTerminal() const {
  return terminal_;
}

char Letter::GetLetter() const{
  return letter_;
}

void Letter::SetLetter(char letter) {
  letter_ = letter;
  bool terminal_ = isupper(letter);
}