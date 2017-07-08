cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES "./src/*.c" "./includes/*.h" "./libft/src/ft_printf/*.c"
        "./libft/src/get_next_line/*.c" "./libft/src/libft/*.c")
add_executable(lem_in ${SOURCE_FILES})
target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/libft/libft.a)