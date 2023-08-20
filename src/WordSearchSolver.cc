#include "WordSearchSolver.hpp"

bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}

WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle) : 
puzzle_(puzzle), puzzle_height_(puzzle.size()), puzzle_width_(puzzle.at(0).size()) { }

bool WordSearchSolver::HorizHelper(const std::string& word, size_t starting_row, size_t starting_col) {
  for (size_t i = 0; i < word.length(); ++i) {
    if (word.at(i) != puzzle_.at(starting_row).at(starting_col + i)) {
      return false;
    }
  }
  return true;
}

WordLocation WordSearchSolver::HorizWord(size_t starting_row, const std::string& word, size_t starting_col) {
  WordLocation to_return;
  to_return.word = word;
  std::vector<CharPositions> solution;
  for (size_t i = starting_col; i < starting_col + word.length(); ++i) {
    solution.push_back({puzzle_.at(starting_row).at(i), starting_row, i});
  }
  to_return.char_positions = solution;
  return to_return;
}

bool WordSearchSolver::VertHelper(const std::string& word, size_t starting_row, size_t starting_col) {
  for (size_t i = 0; i < word.length(); ++i) {
    if (word.at(i) != puzzle_.at(starting_row + i).at(starting_col)) {
      return false;
    }
  }
  return true;
}

WordLocation WordSearchSolver::VertWord(size_t starting_row, const std::string& word, size_t starting_col) {
  WordLocation to_return;
  to_return.word = word;
  std::vector<CharPositions> solution;
  for (size_t i = starting_row; i < starting_row + word.length(); ++i) {
    solution.push_back({puzzle_.at(i).at(starting_col), i, starting_col});
  }
  to_return.char_positions = solution;
  return to_return;
}

bool WordSearchSolver::RightDiagHelper(const std::string& word, size_t starting_row, size_t starting_col) {
  for (size_t i = 0; i < word.length(); ++i) {
    if (word.at(i) != puzzle_.at(starting_row + i).at(starting_col + i)) {
      return false;
    }
  }
  return true;
}

WordLocation WordSearchSolver::RightDiagWord(const std::string& word, size_t starting_row, size_t starting_col) {
  WordLocation to_return;
  to_return.word = word;
  std::vector<CharPositions> solution;
  for (size_t i = 0; i < word.length(); ++i) {
    solution.push_back({puzzle_.at(starting_row + i).at(starting_col + i), starting_row + i, starting_col + i});
  }
  to_return.char_positions = solution;
  return to_return;
}


bool WordSearchSolver::LeftDiagHelper(const std::string& word, size_t starting_row, size_t starting_col) {
  for (size_t i = 0; i < word.length(); ++i) {
    if (word.at(i) != puzzle_.at(starting_row + i).at(starting_col - i)) {
      return false;
    }
  }
  return true;
}

WordLocation WordSearchSolver::LeftDiagWord(const std::string& word, size_t starting_row, size_t starting_col) {
  WordLocation to_return;
  to_return.word = word;
  std::vector<CharPositions> solution;
  for (size_t i = 0; i < word.length(); ++i) {
    solution.push_back({puzzle_.at(starting_row + i).at(starting_col - i), starting_row + i, starting_col - i});
  }
  to_return.char_positions = solution;
  return to_return;
}

WordLocation WordSearchSolver::FindHorizWord(const std::string& word) {
  bool word_found = false;
  std::vector<CharPositions> empty;
  for (size_t i = 0; i < puzzle_height_; ++i) {
        for (size_t j = 0; j < puzzle_width_ - word.length() + 1; ++j) {
          if (puzzle_.at(i).at(j) == word.at(0)) {
            word_found = WordSearchSolver::HorizHelper(word, i, j);
          }
          if (word_found) {
            return WordSearchSolver::HorizWord(i, word, j);
          }
        }
      }
      return {"", empty};
}

WordLocation WordSearchSolver::FindVertWord(const std::string& word) {
  bool word_found = false;
  std::vector<CharPositions> empty;
  for (size_t i = 0; i < puzzle_height_ - word.length() + 1; ++i) {
        for (size_t j = 0; j < puzzle_width_; ++j) {
          if (puzzle_.at(i).at(j) == word.at(0)) {
            word_found = WordSearchSolver::VertHelper(word, i, j);
          }
          if (word_found) {
            return WordSearchSolver::VertWord(i, word, j);
          }
        }
      }
      return {"", empty};
}

WordLocation WordSearchSolver::FindRightDiagWord(const std::string& word) {
  bool word_found = false;
  std::vector<CharPositions> empty;
  for (size_t i = 0; i < puzzle_height_ - word.length() + 1; ++i) {
        for (size_t j = 0; j < puzzle_width_ - word.length() + 1; ++j) {
          if (puzzle_.at(i).at(j) == word.at(0)) {
            word_found = WordSearchSolver::RightDiagHelper(word, i, j);
          }
          if (word_found) {
            return WordSearchSolver::RightDiagWord(word, i, j);
          }
        }
      }
      return {"", empty};
}

WordLocation WordSearchSolver::FindLeftDiagWord(const std::string& word) {
  bool word_found = false;
  std::vector<CharPositions> empty;
  for (size_t i = 0; i < puzzle_height_ - word.length() + 1; ++i) {
        for (size_t j = word.length() - 1; j < puzzle_width_; ++j) {
          if (puzzle_.at(i).at(j) == word.at(0)) {
            word_found = WordSearchSolver::LeftDiagHelper(word, i, j);
          }
          if (word_found) {
            return WordSearchSolver::LeftDiagWord(word, i, j);
          }
        }
      }
      return {"", empty};
}

WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  switch (direction) {
    case (CheckDirection::kHorizontal) :
      return WordSearchSolver::FindHorizWord(word);
      break;
    case (CheckDirection::kVertical) :
      return WordSearchSolver::FindVertWord(word);
      break;
    case (CheckDirection::kRightDiag) :
      return WordSearchSolver::FindRightDiagWord(word);
      break;
    case (CheckDirection::kLeftDiag) :
      return WordSearchSolver::FindLeftDiagWord(word);
      break;
  }
}

WordLocation WordSearchSolver::FindWord(const std::string& word) {
  std::vector<CharPositions> empty;
  if (WordSearchSolver::FindWord(word, CheckDirection::kHorizontal).word == word) {
    return WordSearchSolver::FindWord(word, CheckDirection::kHorizontal);
  }
 if (WordSearchSolver::FindWord(word, CheckDirection::kVertical).word == word) {
    return WordSearchSolver::FindWord(word, CheckDirection::kVertical);
  }
  if (WordSearchSolver::FindWord(word, CheckDirection::kRightDiag).word == word) {
    return WordSearchSolver::FindWord(word, CheckDirection::kRightDiag);
  }
  if (WordSearchSolver::FindWord(word, CheckDirection::kLeftDiag).word == word) {
    return WordSearchSolver::FindWord(word, CheckDirection::kLeftDiag);
  }
  return {"", empty};
}
