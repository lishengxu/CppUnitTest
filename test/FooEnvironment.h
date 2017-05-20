/*
 * FooEnvironment.h
 *
 *  Created on: May 20, 2017
 *      Author: lsx
 */

#ifndef FOOENVIRONMENT_H_
#define FOOENVIRONMENT_H_

#include <gtest/gtest.h>

class FooEnvironment: public testing::Environment {
public:
	FooEnvironment();
	virtual ~FooEnvironment();
	virtual void SetUp() {
		std::cout << "Foo FooEnvironment SetUP" << std::endl;
	}
	virtual void TearDown() {
		std::cout << "Foo FooEnvironment TearDown" << std::endl;
	}
};

#endif /* FOOENVIRONMENT_H_ */
