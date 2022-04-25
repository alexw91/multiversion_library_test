cmake_minimum_required(VERSION 3.0)

project(B)

set(SOURCES
  B.c
)

include_directories(
  ${LIBC_V2_DIR}
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}.static C_v2.static)


add_library(${PROJECT_NAME}.shared SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}.shared PRIVATE C_v2.shared)

