cmake_minimum_required(VERSION 3.11)

# DOWNLOAD_EXTRACT_TIMESTAMP
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.24)
	cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)

project(x64dbgplugin)

FetchContent_Declare(x64dbg
	URL https://downloads.sourceforge.net/project/x64dbg/snapshots/snapshot_2024-07-12_00-03.zip
	URL_HASH SHA256=d38e3d8b21e733cb8f40472dc5ae788cc41ff122c2aa16b670f83cccb9bbcc1b
)

FetchContent_MakeAvailable(x64dbg)

add_library(x64dbgplugin SHARED src/plugin.c)

target_compile_options(x64dbgplugin PRIVATE
	"/W4"
)
target_include_directories(x64dbgplugin PRIVATE
	${x64dbg_SOURCE_DIR}/pluginsdk
)
if(CMAKE_VS_PLATFORM_NAME STREQUAL "Win32")
	target_link_libraries(x64dbgplugin PRIVATE ${x64dbg_SOURCE_DIR}/pluginsdk/x32dbg.lib)
elseif(CMAKE_VS_PLATFORM_NAME STREQUAL "x64")
	target_link_libraries(x64dbgplugin PRIVATE ${x64dbg_SOURCE_DIR}/pluginsdk/x64dbg.lib)
endif()
