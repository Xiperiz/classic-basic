cmake_minimum_required(VERSION 3.10)

project(classic_basic C)

add_executable(classic_basic src/main.c src/helpers/print_info.c src/interpreter/node.c src/interpreter/interpreter.c src/tokenizer/file_io.c src/tokenizer/tokenizer.c)

target_compile_options(classic_basic PRIVATE -Werror -Wall -Wextra -Wfloat-equal -Wshadow -Wunreachable-code -Wformat=2)