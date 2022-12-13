#include <iostream>
#include <string>

int main() {
  const std::string delims = "\t:.,;";
  std::string text = "He appears to have retired to Stratford around 1613 at age 49, where he died three years later. Few records of Shakespeare's private life survive; there has been considerable speculation about such matters as his physical appearance, sexuality, religious beliefs, and whether the works attributed to him were written by others.";

  size_t start_pos(0);
  size_t delim_pos = text.find_first_of(delims);
  while(delim_pos != std::string::npos) {
    std::string line = text.substr(start_pos, delim_pos - start_pos);
    std::cout << line << std::endl;

    start_pos = text.find_first_not_of(delims, delim_pos);
    delim_pos = text.find_first_of(delims, start_pos);
  }
}