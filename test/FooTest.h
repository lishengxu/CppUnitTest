/*
 * FooTest.h
 *
 *  Created on: May 21, 2017
 *      Author: lsx
 */

#ifndef FOOTEST_H_
#define FOOTEST_H_

#include <gtest/gtest.h>

class FooTest: public testing::Test {
public:
	FooTest();
	virtual ~FooTest();
protected:
	virtual void SetUp() {
		mFoo = 2;
		std::cout << "Foo FooTest SetUp" << std::endl;
	}
	virtual void TearDown() {
		std::cout << "Foo FooTest TearDown" << std::endl;
	}
	static void SetUpTestCase() {
		my_shared_resource_ = 1;
		std::cout << "Foo FooTest SetUpTestCase" << std::endl;
	}
	static void TearDownTestCase() {
		std::cout << "Foo FooTest TearDownTestCase" << std::endl;
	}

	static int my_shared_resource_;
	int mFoo;
};

#endif /* FOOTEST_H_ */
