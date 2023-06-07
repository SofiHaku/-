#pragma once
#include "./hpp/Grammar.hpp"
#include "./hpp/Parser.hpp"
#include <gtest/gtest.h>
#include <random>
#include <iostream>
#include <vector>

std::string CreateWord(bool* is_normal, int size) {
  std::string word;
  int max = 0;
  int now = 0;
  *is_normal = true;
  bool exit_b = false;
  if (size % 2 == 0) {
    *is_normal = false;
  }

  for (int i = 0; i < size; i++) {
    if (random() % 2 == 1) {
      word.push_back('a');
      now++;
    } else {
      word.push_back('b');
      now--;
      exit_b = true;
    }
    max = (now > max) && (!exit_b) ? now : max;
  }
  if (max < size / 2) {
    *is_normal = false;
  }
  if (!exit_b) {
    *is_normal = false;
  }
  return word;
}

Grammar CreateGrammar1() {
  Grammar grammar;
	grammar.SetRule("S->BA");
	grammar.SetRule("S->b");
	grammar.SetRule("B->AS");
  grammar.SetRule("A->a");
  return grammar;
}

TEST(Normal, TrueTest) {
	Grammar grammar = CreateGrammar1();
  ParserCYK parser;
  std::string word = "aaaabaaaa";
  EXPECT_TRUE(parser.Check_word(word, grammar));

  word = "aba";
  EXPECT_TRUE(parser.Check_word(word, grammar));

  word = "b";
  EXPECT_TRUE(parser.Check_word(word, grammar));

  word = "aabaa";
  EXPECT_TRUE(parser.Check_word(word, grammar));

  word = "aaaaaabaaaaaa";
  EXPECT_TRUE(parser.Check_word(word, grammar));

  word = "aaaaaaaaabaaaaaaaaa";
  EXPECT_TRUE(parser.Check_word(word, grammar));
}

TEST(Normal, FalseTest) {
	Grammar grammar = CreateGrammar1();
  ParserCYK parser;
  std::string word = "a";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "bas";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "baba";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "abbabab";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "abababaab";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "bababba";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "aaaaabbaaaa";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "aaaaaa";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "aabbbbbaaa";
  EXPECT_FALSE(parser.Check_word(word, grammar));

  word = "abbababababbabaabbab";
  EXPECT_FALSE(parser.Check_word(word, grammar));
}

TEST(Normal, BIG) {
	Grammar grammar_test3;
	grammar_test3.SetRule("S->BA");
	grammar_test3.SetRule("S->b");
	grammar_test3.SetRule("B->AS");
  grammar_test3.SetRule("A->a");

  ParserCYK parser_1_test3;

  for (int i = 0; i < 100; i++) {
    bool is_normal = true;
    std::string word_1_test3 = CreateWord(&is_normal, i);
    if (is_normal) {
      std::cout << word_1_test3 << "\n";
      EXPECT_TRUE(parser_1_test3.Check_word(word_1_test3, grammar_test3));
    } else {
      EXPECT_FALSE(parser_1_test3.Check_word(word_1_test3, grammar_test3));
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}