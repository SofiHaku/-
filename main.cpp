#include <iostream>
#include "./hpp/Grammar.hpp"

int main() {
  Grammar gram;
  gram.SetRule("S->()");
  gram.SetRule("S->(S)");
  return 0;
}