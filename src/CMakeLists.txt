# Add all header files to this set
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/template_demo/library.h")

# Add all source files to this set
set(SOURCE_FILES library.c)

add_library(template_library ${SOURCE_FILES} ${HEADER_LIST})
target_include_directories(template_library PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(template_library PUBLIC c_std_11)

source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST}
)
