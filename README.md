# lang-en-uk-nouns

Link UK English nouns into C++.

The build downloads a nouns list and exposes it as an object target named `lang-en-uk-nouns`,
so downstream code can link and read the embedded bytes.

## Minimal usage (FetchContent)

```cmake
include(FetchContent)

FetchContent_Declare(
  lang_en_uk_nouns
  GIT_REPOSITORY https://github.com/v-val/lang-en-uk-nouns.git
  GIT_TAG main
)
FetchContent_MakeAvailable(lang_en_uk_nouns)

target_link_libraries(your_target PRIVATE lang-en-uk-nouns)
```

```cpp
extern "C" {
extern const char* _binary_lang_en_uk_nouns_txt_start;
extern const char* _binary_lang_en_uk_nouns_txt_end;
extern unsigned int _binary_lang_en_uk_nouns_txt_size;
}

// Example: view the embedded text as a byte range.
const char* begin = _binary_lang_en_uk_nouns_txt_start;
const char* end = _binary_lang_en_uk_nouns_txt_end;
unsigned int size = _binary_lang_en_uk_nouns_txt_size;
```

## Current limitations

1. Supports only Linux and macOS paths in `CMakeLists.txt`; other OSes fail configuration.
2. Downloads data from a remote URL during configure if cache is missing (network required).
3. Linux conversion currently assumes specific `objcopy` output format/architecture flags.
