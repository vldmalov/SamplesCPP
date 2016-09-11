#include <iostream>
#include <string>

const std::string FILE_NAMES[] = {
    "aaaa.cpp",
    "file1.jpeg",
    "svn.",
    "test",
    "file2.zip",
    "temp.tmp"
};

bool get_filename_new_ext(const std::string& new_extension,
                          const std::string& source_file_name,
                          std::string& processed_file_name)
{
    if(source_file_name.empty()) return false;
    
    size_t found_pos = source_file_name.find(".");
    if(found_pos == std::string::npos) {
        processed_file_name = source_file_name + "." + new_extension;
    } else {
        processed_file_name = source_file_name.substr(0, found_pos + 1) + new_extension;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {

    for(std::string source_file_name : FILE_NAMES) {
        std::string processed_file_name;
        get_filename_new_ext("png", source_file_name, processed_file_name);
        
        std::cout << "source file name " << source_file_name
                  << " processed file name " << processed_file_name << "\n";
    }
    
    std::string country_name = "Denmark";
    const char* c_country_name = country_name.data();
    std::cout << "Country " << c_country_name << "\n";
    
    for(const char& ch : country_name) {
        std::cout << (const char)toupper(ch);
    }
    std::cout << std::endl;
    
    for(size_t idx = 0, idx_max = country_name.length(); idx != idx_max; ++idx) {
        std::cout << (const char)tolower(country_name[idx]);
    }
    std::cout << std::endl;
    
    for(std::string::reverse_iterator it = country_name.rbegin(), it_end = country_name.rend(); it != it_end; ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    //------------------
    const std::string delims = "\t:.,;";
    std::string text = "He appears to have retired to Stratford around 1613 at age 49, where he died three years later. Few records of Shakespeare's private life survive; there has been considerable speculation about such matters as his physical appearance, sexuality, religious beliefs, and whether the works attributed to him were written by others.";
    
    size_t start_pos(0);
    size_t delim_pos = text.find_first_of(delims);
    while(delim_pos != std::string::npos) {
        std::string line = text.substr(start_pos, delim_pos - start_pos);
        std::cout << line << "\n";
        
        start_pos = text.find_first_not_of(delims, delim_pos);
        delim_pos = text.find_first_of(delims, start_pos);
    }
    //-----------------
    {
        const std::string SUBSTRING_FOR_REPLACE = "Few records";
        const std::string NEW_SUBSTRING = "Many new tails";
        size_t find_pos = text.find(SUBSTRING_FOR_REPLACE);;
        if(find_pos != std::string::npos) {
            text.replace(begin(text) + find_pos, begin(text) + find_pos + SUBSTRING_FOR_REPLACE.length(),
                         NEW_SUBSTRING.begin(), NEW_SUBSTRING.end());
        }
        
        std::cout << "New text :\n" << text << std::endl;
    }
    
    return 0;
}
