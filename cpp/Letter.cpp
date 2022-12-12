#include "../hpp/Letter.hpp"

Letter::Letter(char letter) {
  letter_ = letter;
  // Если буква большая, то терминал
  terminal_ = !isupper(letter);
}

Letter::Letter(const Letter& other_letter) {
  letter_ = other_letter.letter_;
  terminal_ = other_letter.terminal_;
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
  terminal_ = !isupper(letter);
}