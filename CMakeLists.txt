 # ================================================================
 # Author   : German Mundinger
 # Date     : 2020
 # ================================================================

add_library(std_error INTERFACE)
target_include_directories(std_error
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_sources(std_error
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/std_error/std_error.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/std_error/std_error.c"
)

add_library(node INTERFACE)
target_include_directories(node
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_sources(node
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/node/node.types.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/node/node.command.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/node/node.list.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/node/node.list.c"
)

add_library(vs1838_control INTERFACE)
target_include_directories(vs1838_control
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_sources(vs1838_control
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/devices/vs1838_control.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/devices/vs1838_control.c"
)
