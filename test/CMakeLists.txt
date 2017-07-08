include_directories(SYSTEM
	${CMAKE_SOURCE_DIR}/googletest/googlemock/include)

include_directories(..)

enable_testing()

SET(TEST_SRC
	testCart.cpp
	testCartItem.cpp
        MockDataResult.h
        MockDataResult.cpp
        MockDataStore.cpp MockDataStore.h)

SET(UNIT_UNDER_TEST_SRC
        ../Cart.cpp ../CartItem.cpp ../CartItem.h ../DataStore.h ../DataResult.h )

SET(TEST_NAME ${PROJECT_NAME}-test)
ADD_EXECUTABLE(${TEST_NAME}
	${TEST_SRC}
	${UNIT_UNDER_TEST_SRC})

SET_PROPERTY(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 14)
TARGET_LINK_LIBRARIES(${TEST_NAME}
	gmock
	gtest
	gtest_main)

TARGET_COMPILE_FEATURES(${TEST_NAME} PUBLIC cxx_override)
ADD_TEST(UnitTest ${TEST_NAME})
