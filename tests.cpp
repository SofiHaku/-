#include "./hpp/Grammar.hpp"
#include "./hpp/Parser.hpp"
#include <gtest/gtest.h>
#include <random>

std::string CreateBracketSequence(size_t size, bool* coorect) {
	std::string result;
	*coorect = true;
	int count = 0;
	result.resize(size);
	for (int i = 0; i < size; i++) {
		if (random() % 2 == 0) {
			result[i] = '(';
			count += 1;
		} else {
			result[i] = ')';
			count -= 1;
		}
		if (count < 0) {
			*coorect = false;
		}
	}
	if (count > 0) {
		*coorect = false;
	}
	return result;
}

TEST(СorrectBracketSequence, SmallTrue) {
	Grammar grammar;
	grammar.SetRule("S->");
	grammar.SetRule("S->(S)");
	grammar.SetRule("S->SS");
	ParserEarley parser;
	EXPECT_TRUE(parser.Earley("()", grammar));
	EXPECT_TRUE(parser.Earley("()()", grammar));
	EXPECT_TRUE(parser.Earley("()()()", grammar));
	EXPECT_TRUE(parser.Earley("(())", grammar));
	EXPECT_TRUE(parser.Earley("((()))", grammar));
}

TEST(СorrectBracketSequence, SmallFalse) {
	Grammar grammar;
	grammar.SetRule("S->");
	grammar.SetRule("S->(S)");
	grammar.SetRule("S->SS");
	ParserEarley parser;
	EXPECT_FALSE(parser.Earley("(", grammar));
	EXPECT_FALSE(parser.Earley("(()", grammar));
	EXPECT_FALSE(parser.Earley("))", grammar));
	EXPECT_FALSE(parser.Earley("())", grammar));
	EXPECT_FALSE(parser.Earley(")()()(", grammar));
}

TEST(СorrectBracketSequence, EMPLY) {
	Grammar grammar;
	grammar.SetRule("S->");
	grammar.SetRule("S->(S)");
	grammar.SetRule("S->SS");
	ParserEarley parser;
	EXPECT_TRUE(parser.Earley("", grammar));
}

TEST(СorrectBracketSequence, BIGTEST) {
	Grammar grammar;
	grammar.SetRule("S->");
	grammar.SetRule("S->(S)");
	grammar.SetRule("S->SS");
	ParserEarley parser;
	for (size_t i = 0; i < 1000; i++) {
		bool coorect = true;
		std::string str = CreateBracketSequence(i, &coorect);
		if (coorect) {
			EXPECT_TRUE(parser.Earley(str, grammar));
		} else {
			EXPECT_FALSE(parser.Earley(str, grammar));
		}
	}
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
