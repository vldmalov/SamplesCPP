#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

unsigned COUNT_ITEMS = 1;

typedef std::pair<std::string, unsigned> word_count_pair;
typedef std::vector<word_count_pair> str_counter_vec;
typedef std::map<std::string, unsigned> str_counter_map;

bool predicate(const word_count_pair& lhs, const word_count_pair& rhs)
{
    return lhs.second > rhs.second;
}

int main()
{
    std::string input_str = "AAA BBB CCC AA BB CC AAA AAA BB BB BB C C";

    std::istringstream iss(input_str);

    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              back_inserter(words));

    str_counter_map words_dictionary;
    for(std::vector<std::string>::const_iterator it = words.begin(), it_end = words.end(); it != it_end; ++it)
    {
        ++words_dictionary[*it]; 
    }

    str_counter_vec result_vec;
    for(str_counter_map::const_iterator it = words_dictionary.begin(), it_end = words_dictionary.end(); it != it_end; ++it)
    {
        result_vec.push_back(std::make_pair(it->first, it->second));
    }

    std::partial_sort(result_vec.begin(), result_vec.begin() + COUNT_ITEMS, result_vec.end(), predicate);

    std::cout << "Result:" << std::endl;
    for(str_counter_vec::const_iterator it = result_vec.begin(), it_end = result_vec.end(); it != it_end; ++it)
    {
        std::cout << it->first << " has been found " << it->second << " times" << std::endl;
    }

    return 0;
}