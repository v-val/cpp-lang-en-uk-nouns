//
// Created by Valerii Valeev on 4/7/26.
//
#include <regex>

#include "nouns.hpp"


extern "C" {
#ifdef LANG_EN_UK_NOUNS_WITH_OBJCOPY
extern const char _binary_lang_en_uk_nouns_txt_start[];
extern const char _binary_lang_en_uk_nouns_txt_end[];
extern const char _binary_lang_en_uk_nouns_txt_size[];
#else
extern const char* _binary_lang_en_uk_nouns_txt_start;
extern const char* _binary_lang_en_uk_nouns_txt_end;
extern unsigned int _binary_lang_en_uk_nouns_txt_size;
#endif
} // extern "C"


namespace lang::en::uk {


const std::vector<std::string_view> NOUNS = [] {
    static const auto n = _binary_lang_en_uk_nouns_txt_end-_binary_lang_en_uk_nouns_txt_start;
    static const std::regex WORD{"\\S+"};
    std::vector<std::string_view> r{};
    auto b = _binary_lang_en_uk_nouns_txt_start;
    for ( std::cmatch m; std::regex_search(b, _binary_lang_en_uk_nouns_txt_end, m, WORD) ; b = m[0].second )
        r.emplace_back(m[0].first, m[0].length());
    return r;
}();


} // namespace lang::en::uk
