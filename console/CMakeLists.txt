file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(console STATIC ${SRC_FILES})

target_include_directories(console PUBLIC ${CMAKE_SOURCE_DIR}/console)

target_compile_options(console PRIVATE -Wall -Werror)
target_compile_features(console PRIVATE cxx_std_17)
