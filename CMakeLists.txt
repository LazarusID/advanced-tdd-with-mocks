cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
PROJECT(Cart)

add_subdirectory(googletest)
add_subdirectory(test)

set(APP_SOURCE
        Cart.cpp Cart.h CartItem.cpp CartItem.h DataStore.h DataResult.h)


add_executable(${PROJECT_NAME}
	main.cpp
	${APP_SOURCE}
	)
