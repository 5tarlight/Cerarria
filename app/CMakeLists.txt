file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(program ${SRC_FILES})

target_link_libraries(program cpr::cpr)
target_link_libraries(program console)
target_link_libraries(program nlohmann_json::nlohmann_json)