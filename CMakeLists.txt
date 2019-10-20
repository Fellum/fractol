cmake_minimum_required(VERSION 3.14)
project(fractol C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-lmlx -framework OpenGL -framework AppKit -lm")

aux_source_directory(src src)
include_directories(include)
include_directories(lib/libft/include)
include_directories(lib/minilibx)

add_subdirectory(lib/libft)

add_executable(fractol ${src})

target_link_libraries(fractol libft)

