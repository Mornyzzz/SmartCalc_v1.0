cmake_minimum_required(VERSION 3.26)
project(C7_SmartCalc_v1_0_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(C7_SmartCalc_v1_0_1
        src/functions/calc.c
        src/data_structures/queue.c
        src/data_structures/stack.c
        src/functions/expr_to_lexems.c
        src/functions/help_funcs.c
        src/functions/lexems_to_postfix.c
        src/functions/op_calc.c)
