#include <string>
#include <iostream>
#include <algorithm>

std::string StringReplacer(const std::string& inputStr, const std::string& src, const std::string& dst)
{
  std::string result{ inputStr };

  size_t pos = result.find(src);
  while(pos != std::string::npos) {
    result.replace(pos, src.size(), dst);
    pos += dst.size();
    pos = result.find(src, pos);
  }

  return result;
}

int main()
{
  std::string str = "<t>Header</t><t>Description section</t>";
  str = StringReplacer(str, "<t>", "<text>");
  str = StringReplacer(str, "</t>", "<end text>");
  std::cout << "Result string: " << str << std::endl;
}