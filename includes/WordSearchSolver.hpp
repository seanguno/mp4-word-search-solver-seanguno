#ifndef WORDSEARCHSOLVER_HPP
#define WORDSEARCHSOLVER_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "WordLocation.hpp"

enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

class WordSearchSolver {
public:
  WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
  WordLocation FindWord(const std::string& word);
  WordLocation FindWord(const std::string& word, CheckDirection direction);

private:
  bool LocationInBounds(size_t row, size_t col) const;
  std::vector<std::vector<char>> puzzle_;
  size_t puzzle_height_;
  size_t puzzle_width_;
  bool HorizHelper(const std::string& word, size_t starting_row, size_t starting_col);
  WordLocation HorizWord(size_t starting_row, const std::string& word, size_t starting_col);
  WordLocation FindHorizWord(const std::string& word);
  bool VertHelper(const std::string& word, size_t starting_row, size_t starting_col);
  WordLocation VertWord(size_t starting_row, const std::string& word, size_t starting_col);
  WordLocation FindVertWord(const std::string& word);
  bool RightDiagHelper(const std::string& word, size_t starting_row, size_t starting_col);
  WordLocation RightDiagWord(const std::string& word, size_t starting_row, size_t starting_col); 
  WordLocation FindRightDiagWord(const std::string& word);
  bool LeftDiagHelper(const std::string& word, size_t starting_row, size_t starting_col);
  WordLocation LeftDiagWord(const std::string& word, size_t starting_row, size_t starting_col); 
  WordLocation FindLeftDiagWord(const std::string& word);
};

#endif
