set(target ${PROJECT_NAME}_src)

add_library(${target} ${LIB_TYPE}
    alexandria.c
    window.c
)
target_link_libraries(${target} ${PROJECT_NAME}_inc)

INCLUDE(FindPkgConfig)

find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(libdecor REQUIRED libdecor-0)
target_link_libraries(${target} SDL2::SDL2 ${SDL2_image_LIBRARIES} ${libdecor_LIBRARIES})
target_include_directories(${target} PRIVATE SDL2::SDL2_INCLUDE_DIRS ${SDL2_image_INCLUDE_DIRS} ${libdecor_INCLUDE_DIRS})