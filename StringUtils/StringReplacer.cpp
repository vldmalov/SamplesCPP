#include <iostream>
#include <algorithm>

std::string StringReplacer(const std::string& inputStr, const std::string& src, const std::string& dst)
{
    std::string result(inputStr);

    size_t pos = result.find(src);
    while(pos != std::string::npos) {
        result.replace(pos, src.size(), dst);
        pos = result.find(src, pos);
    }

    return result;
}

int main(int argc, char **argv)
{
    std::string str = "<i>asd</i><i>qwe</i>";
    std::string res = StringReplacer(str, "<i>", "<italic>");
    std::string res2 = StringReplacer(res, "</i>", "<end italic>");
    std::cout << "Result string: " << res2 << std::endl;

    return 0;
}