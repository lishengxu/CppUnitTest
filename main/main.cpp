/*
 * main.cpp
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */
#include <stdio.h>
#include "gtest/gtest.h"
#include "FooEnvironment.h"

GTEST_API_ int main(int argc, char **argv) {
	//testing::AddGlobalTestEnvironment(new FooEnvironment);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

