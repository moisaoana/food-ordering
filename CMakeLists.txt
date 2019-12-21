cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c displayData.h displayData.c order.h order.c dataInput.h dataInput.c  customerData.h customerData.c food.h food.c type.h type.c)