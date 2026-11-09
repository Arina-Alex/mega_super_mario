add_subdirectory(os_api)
add_subdirectory(qt)

if(GAME_TYPE STREQUAL "WindowsConsole")
    add_subdirectory(windows)
elseif(GAME_TYPE STREQUAL "LinuxConsole")
    add_subdirectory(linux)
endif()
