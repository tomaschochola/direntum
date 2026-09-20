include(CheckPIESupported)

check_pie_supported(LANGUAGES C)

add_library(direntum_core STATIC)

target_sources(
    direntum_core
    PRIVATE
        todo.c
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES todo.h
)

target_compile_features(
    direntum_core
    PUBLIC
        c_std_23
)

set_target_properties(
    direntum_core
    PROPERTIES
        C_EXTENSIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(
    direntum_core
    PRIVATE
        direntum_warnings
)

add_executable(direntum)

target_sources(
    direntum
    PRIVATE
        main.c
)

target_compile_features(
    direntum
    PRIVATE
        c_std_23
)

set_target_properties(
    direntum
    PROPERTIES
        C_EXTENSIONS OFF
        C_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON
        OUTPUT_NAME "direntum"
)

target_link_libraries(
    direntum
    PRIVATE
        direntum_core
        direntum_warnings
)

install(
    TARGETS direntum
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
