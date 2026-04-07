# lang-en-uk-nouns

Link UK English nouns into C++.

## Requirements

- CMake 3.23+
- C++17-compatible compiler
- Linux or macOS

## Minimal usage (FetchContent)

```cmake
include(FetchContent)

FetchContent_Declare(
  english_nouns
  GIT_REPOSITORY https://github.com/v-val/lang-en-uk-nouns.git
  GIT_TAG v0.2.3
)
FetchContent_MakeAvailable(english_nouns)

target_link_libraries(your_target PRIVATE lang-en-uk-nouns)
```

```cpp
#include <lang/en/uk/nouns.hpp>

...

for (auto & s : lang::en::uk::NOUNS) {
    // ...
}
```

## Current limitations

1. Only Linux and macOS are supported; other OSes fail configuration.
2. Data is downloaded from a remote URL during the configure stage if cache is missing (network required).
3. Linux conversion currently assumes specific `objcopy` output format/architecture flags `elf64-x86-64`.
