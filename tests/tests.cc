// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("True == True", "") { REQUIRE(true == true); }

TEST_CASE("Test Left Diagonal") {
    std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  std::vector<CharPositions> mat_tester;
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).word) == "mat");
  REQUIRE((wss.FindWord("mat").word) == "mat");
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(0).character) == 'm');
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(0).row) == 2);
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(0).col) == 4);
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(1).character) == 'a');
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(1).row) == 3);
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(1).col) == 3);
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(2).character) == 't');
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(2).row) == 4);
  REQUIRE((wss.FindWord("mat", CheckDirection::kLeftDiag).char_positions.at(2).col) == 2);
  REQUIRE((wss.FindWord("mat").char_positions.at(0).row) == 2);
  REQUIRE((wss.FindWord("mat").char_positions.at(0).character) == 'm');
  REQUIRE((wss.FindWord("mat").char_positions.at(0).col) == 4);
  REQUIRE((wss.FindWord("mat").char_positions.at(1).character) == 'a');
  REQUIRE((wss.FindWord("mat").char_positions.at(1).row) == 3);
  REQUIRE((wss.FindWord("mat").char_positions.at(1).col) == 3);
  REQUIRE((wss.FindWord("mat").char_positions.at(2).character) == 't');
  REQUIRE((wss.FindWord("mat").char_positions.at(2).row) == 4);
  REQUIRE((wss.FindWord("mat").char_positions.at(2).col) == 2);

}

TEST_CASE("Test Right Diagonal") {
    std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).word) == "del");
  REQUIRE((wss.FindWord("del").word) == "del");
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(0).character) == 'd');
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(0).row) == 0);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(0).col) == 0);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(1).character) == 'e');
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(1).row) == 1);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(1).col) == 1);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(2).character) == 'l');
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(2).row) == 2);
  REQUIRE((wss.FindWord("del", CheckDirection::kRightDiag).char_positions.at(2).col) == 2);
  REQUIRE((wss.FindWord("del").char_positions.at(0).row) == 0);
  REQUIRE((wss.FindWord("del").char_positions.at(0).character) == 'd');
  REQUIRE((wss.FindWord("del").char_positions.at(0).col) == 0);
  REQUIRE((wss.FindWord("del").char_positions.at(1).character) == 'e');
  REQUIRE((wss.FindWord("del").char_positions.at(1).row) == 1);
  REQUIRE((wss.FindWord("del").char_positions.at(1).col) == 1);
  REQUIRE((wss.FindWord("del").char_positions.at(2).character) == 'l');
  REQUIRE((wss.FindWord("del").char_positions.at(2).row) == 2);
  REQUIRE((wss.FindWord("del").char_positions.at(2).col) == 2);

}

TEST_CASE("Test Horizontal") {
    std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).word) == "cde");
  REQUIRE((wss.FindWord("cde").word) == "cde");
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(0).character) == 'c');
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(0).row) == 5);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(0).col) == 2);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(1).character) == 'd');
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(1).row) == 5);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(1).col) == 3);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(2).character) == 'e');
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(2).row) == 5);
  REQUIRE((wss.FindWord("cde", CheckDirection::kHorizontal).char_positions.at(2).col) == 4);
  REQUIRE((wss.FindWord("cde").char_positions.at(0).row) == 5);
  REQUIRE((wss.FindWord("cde").char_positions.at(0).character) == 'c');
  REQUIRE((wss.FindWord("cde").char_positions.at(0).col) == 2);
  REQUIRE((wss.FindWord("cde").char_positions.at(1).character) == 'd');
  REQUIRE((wss.FindWord("cde").char_positions.at(1).row) == 5);
  REQUIRE((wss.FindWord("cde").char_positions.at(1).col) == 3);
  REQUIRE((wss.FindWord("cde").char_positions.at(2).character) == 'e');
  REQUIRE((wss.FindWord("cde").char_positions.at(2).row) == 5);
  REQUIRE((wss.FindWord("cde").char_positions.at(2).col) == 4);

}

TEST_CASE("Test Vertical") {
    std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).word) == "uue");
  REQUIRE((wss.FindWord("uue").word) == "uue");
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(0).character) == 'u');
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(0).row) == 3);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(0).col) == 4);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(1).character) == 'u');
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(1).row) == 4);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(1).col) == 4);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(2).character) == 'e');
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(2).row) == 5);
  REQUIRE((wss.FindWord("uue", CheckDirection::kVertical).char_positions.at(2).col) == 4);
  REQUIRE((wss.FindWord("uue").char_positions.at(0).row) == 3);
  REQUIRE((wss.FindWord("uue").char_positions.at(0).character) == 'u');
  REQUIRE((wss.FindWord("uue").char_positions.at(0).col) == 4);
  REQUIRE((wss.FindWord("uue").char_positions.at(1).character) == 'u');
  REQUIRE((wss.FindWord("uue").char_positions.at(1).row) == 4);
  REQUIRE((wss.FindWord("uue").char_positions.at(1).col) == 4);
  REQUIRE((wss.FindWord("uue").char_positions.at(2).character) == 'e');
  REQUIRE((wss.FindWord("uue").char_positions.at(2).row) == 5);
  REQUIRE((wss.FindWord("uue").char_positions.at(2).col) == 4);

}

TEST_CASE("Test Word Not Found") {
    std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  REQUIRE_FALSE((wss.FindWord("sean").word) == "sean");
  REQUIRE_FALSE((wss.FindWord("sean", CheckDirection::kHorizontal).word) == "sean");
  REQUIRE_FALSE((wss.FindWord("sean", CheckDirection::kVertical).word) == "sean");
  REQUIRE_FALSE((wss.FindWord("sean", CheckDirection::kRightDiag).word) == "sean");
  REQUIRE_FALSE((wss.FindWord("sean", CheckDirection::kLeftDiag).word) == "sean");


}
/////////////////////////////////////////////////////////////////////////////////////////////
