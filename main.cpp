#include <iostream>
#include "./hpp/Grammar.hpp"
#include "./hpp/Parser.hpp"

int main() {
  Grammar gram;
  gram.SetRule("S->(S)");
  gram.SetRule("S->()");

  ParserEarley earley;
  std::cout << "YES ==";
  if (earley.Check(gram, "()")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "NO ==";
  if (earley.Check(gram, "")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "YES ==";
  if (earley.Check(gram, "(())")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }


  std::cout << "No ==";
  if (earley.Check(gram, "(()")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "No ==";
  if (earley.Check(gram, "())")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "YES ==";
  if (earley.Check(gram, "(((((())))))")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  Grammar gram2;
  gram2.SetRule("S->ASB");
  gram2.SetRule("S->");
  gram2.SetRule("A->a");
  gram2.SetRule("B->b");

  std::cout << "YES ==";
  if (earley.Check(gram2, "ab")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "YES ==";
  if (earley.Check(gram2, "aaabbb")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "YES ==";
  if (earley.Check(gram2, "")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  std::cout << "No ==";
  if (earley.Check(gram2, "aabbb")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}