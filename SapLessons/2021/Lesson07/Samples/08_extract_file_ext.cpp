#include <iostream>
#include <string>

const std::string FILE_NAMES[] = {
    "main.cpp",
    "humor_001.jpeg",
    "svn.",
    "test",
    "file2.exe.zip",
    "20211102.tmp"
};

std::string GetFilenameExt(const std::string& fileName) {
  const size_t dotPos = fileName.rfind(".");
  if(dotPos != std::string::npos) {
    return fileName.substr(dotPos + 1, fileName.size() - dotPos) ;
  }

  return {};
}

int main() {
  for(const std::string& fileName : FILE_NAMES) {
    std::cout << "File \"" << fileName << "\" has \"" << GetFilenameExt(fileName) << "\" extension" << std::endl;
  }
}