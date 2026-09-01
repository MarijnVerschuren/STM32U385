cmake_minimum_required(VERSION 3.0)

# project name
project(STM32U385 C ASM)

# toolchain
set(CMAKE_TOOLCHAIN_FILE "cmake/arm-none-eabi.cmake")

# select linker script
set(LINKER_SCRIPT "lnk/STM32U385.ld")

# define CPU OPTIONS
set(CPU_OPTIONS -mthumb -mcpu=cortex-m33)

# optimizations (-O0 -O1 -O2 -O3 -Os -Ofast -Og -flto)
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-Ofast -flto")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os -flto")

add_compile_options(
        ${CPU_OPTIONS}
        $<$<COMPILE_LANGUAGE:C>:-std=c11>
        $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
        $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
        -fstrict-volatile-bitfields
        -ffunction-sections

        -Wno-incompatible-pointer-types
#        -Werror
#        -Wall
#        -Wextra
#        -Wcast-align
#        -Wconversion
#        -Wsign-conversion
#        -Wshadow
#        -Wlogical-op
#        -Wsuggest-final-types
#        -Wsuggest-final-methods
#        -pedantic
)

include_directories(
        "inc/"
        "test/"
        "lib/"
)

link_directories(
        ${CMAKE_SOURCE_DIR}
)

# list of modules to build the HAL
add_executable(${PROJECT_NAME}
        ${CMAKE_SOURCE_DIR}/src/vector.S
        ${CMAKE_SOURCE_DIR}/src/startup.S
        ${CMAKE_SOURCE_DIR}/src/syscalls.S
        ${CMAKE_SOURCE_DIR}/src/sys.S
        ${CMAKE_SOURCE_DIR}/src/base.S
        ${CMAKE_SOURCE_DIR}/src/NVIC.S
        ${CMAKE_SOURCE_DIR}/src/GPIO.S

        ${CMAKE_SOURCE_DIR}/src/sys.c
        ${CMAKE_SOURCE_DIR}/src/EXTI.c
        src/TIM.c
        src/base.c
)

# list of modules to build the application
add_library(app_interface INTERFACE)
target_sources(app_interface INTERFACE
    ${CMAKE_SOURCE_DIR}/app/main.c
)


target_link_libraries(${PROJECT_NAME}
        ${CPU_OPTIONS}
        -T${LINKER_SCRIPT}
        -nostartfiles
        -nostdlib
        app_interface
)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINK_DEPENDS ${CMAKE_SOURCE_DIR}/${LINKER_SCRIPT})

include("cmake/flash.cmake")
