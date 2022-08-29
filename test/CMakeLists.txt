set(target ${PROJECT_NAME}_test)

add_executable(${target} main.c)
target_link_libraries(${target} PRIVATE ${PROJECT_NAME}_src)