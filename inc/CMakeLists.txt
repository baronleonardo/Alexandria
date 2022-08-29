set(target ${PROJECT_NAME}_inc)

add_library(${target} INTERFACE)
target_sources(${target}
    PUBLIC
        alexandria.h
        alexandria/helpers.h
        alexandria/define.h
        alexandria/typedef.h
)
set_target_properties(${target} PROPERTIES LINKER_LANGUAGE C)
target_include_directories(${target} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})