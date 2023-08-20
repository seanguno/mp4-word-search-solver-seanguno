#include <iostream>
#include <string>
#include <vector>

#include "WordSearchSolver.hpp"

int main() {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'},
                                        {'a', 'b', 'c', 'd', 'e'}};
  WordSearchSolver wss(puzzle);
  std::cout << wss.FindWord("mat", CheckDirection::kLeftDiag);
  std::cout << wss.FindWord("mat");
  std::cout << wss.FindWord("hello", CheckDirection::kHorizontal);
  std::cout << wss.FindWord("hello");
  std::cout << wss.FindWord("lle", CheckDirection::kLeftDiag);
  std::cout << wss.FindWord("lle");
  std::cout << wss.FindWord("hat", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("hat");
  std::cout << wss.FindWord("cat", CheckDirection::kVertical);
  std::cout << wss.FindWord("cat");
  std::cout << wss.FindWord("muu", CheckDirection::kVertical);
  std::cout << wss.FindWord("muu");
  std::cout << wss.FindWord("del", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("del");
  std::cout << wss.FindWord("lau", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("lau");
  std::cout << wss.FindWord("delau", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("delau");
  std::cout << wss.FindWord("au", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("au");
  std::cout << wss.FindWord("u", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("u");
  std::cout << wss.FindWord("ae", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("ae");
  std::cout << wss.FindWord("oo", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("oo");
  std::cout << wss.FindWord("toe", CheckDirection::kRightDiag);
  std::cout << wss.FindWord("toe");


}
