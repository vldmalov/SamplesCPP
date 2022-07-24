#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<float> ExtractDataValues(const std::string& srcStr, const std::string& startTag, const std::string& endTag)
{
  std::vector<float> dataValues;

  size_t dataValueStartPos = srcStr.find(startTag);
  while(dataValueStartPos != std::string::npos) {
    dataValueStartPos += startTag.size();
    size_t dataValueEndPos = srcStr.find(endTag, dataValueStartPos);
    if(dataValueEndPos == std::string::npos) {
      std::cerr << "Invalid input data!" << std::endl;
      break;
    }

    std::string data = srcStr.substr(dataValueStartPos, dataValueEndPos - dataValueStartPos);
    dataValues.push_back(std::stof(data));
    dataValueStartPos = dataValueEndPos + endTag.size();
    dataValueStartPos = srcStr.find(startTag, dataValueStartPos);
  }

  return dataValues;
}

int main()
{
  std::string str = "<text>Header</text><value>3.14</value><text>Description section</text><value>512</value><value>-10.01</value>";
  std::vector<float> result = ExtractDataValues(str, "<value>", "</value>");

  std::cout << "Result:" << std::endl;
  for(float value : result) {
    std::cout << value << std::endl;
  }
}