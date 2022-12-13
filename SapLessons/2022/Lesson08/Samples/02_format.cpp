#include <iostream>
#include <vector>

struct BookInfo {
  BookInfo() = default;
  BookInfo(const std::string& title, const std::string& author, int year, int pagesCount)
      : _title(title)
      , _author(author)
      , _year(year)
      , _pagesCount(pagesCount)
  {}

  friend std::ostream& operator<<(std::ostream& os, const BookInfo& info);

private:
  std::string _title;
  std::string _author;
  int _year{ 0 };
  int _pagesCount{ 0 };
};

std::ostream& operator<<(std::ostream& os, const BookInfo& info) {
  os.width(28);
  os << std::left << info._title << " ";

  os << "(";
  os.width(5);
  os << std::right << info._pagesCount << " pp.)";

  os << " written by ";
  os.width(20);
  os << std::left << info._author;
  os << " in " << info._year;

  return os;
}

int main()
{
  std::vector<BookInfo> books = {
      {"The C Programming Language", "Dennis M. Ritchie", 1978, 312},
      {"The C++ Programming Language", "Bjarne Stroustrup", 1988, 1363},
      {"C Primer Plus", "Stephen Prata", 2004, 1080},
      {"Effective Modern C++", "Scott Meyers", 2014, 440},
      {"Modern C++ Design", "Andrei Alexandrescu", 2001, 352}
  };

  for(BookInfo& bookInfo : books) {
    std::cout << bookInfo << std::endl;
  }
}