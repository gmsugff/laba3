# CMakeList.txt : CMake project for YandexProject, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("YandexProject")

# Add source to this project's executable.
add_executable (YandexProject   "src/headers/YaScheduleApp.h" "main.cpp" "src/sources/YaScheduleApp.cpp" "src/headers/Tools.h" "src/sources/Tools.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET YandexProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include_directories("C:/src/vcpkg/packages/cpp-httplib_x64-windows/include")
include_directories("C:/src/vcpkg/packages/nlohmann-json_x64-windows/include")
include_directories("C:/Users/cyril/OneDrive/Рабочий стол/BV311/YandexProject/src/headers")