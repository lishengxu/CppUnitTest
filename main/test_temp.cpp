/*
 * test_temp.cpp
 *
 *  Created on: Jan 3, 2019
 *      Author: lsx
 */


#include "gtest/gtest.h"
#include <string.h>
#include "mystring.h"


/**
 * 空类型实例占有的内存大小为1
 * 构造函数和析构函数只需要通过类型指向指针，本身在实例中不占有内存
 * 存在虚拟函数，编译器会为每个实例添加一个指向虚函数表的指针，占用指针长度的内存
 */
TEST(nullclasssizeoftest, positive) {
	class a {

	};
	EXPECT_EQ(1, sizeof(a));

	class b {
	public:
		b();
		~b();
	};

	EXPECT_EQ(1, sizeof(b));

	class c {
	public:
		c();
		virtual ~c();
	};

	EXPECT_EQ(8, sizeof(c));
}

TEST(operatorcopytest, positive) {
	class MyString {
	public:
		MyString(char *pData = NULL) {
			if (pData != NULL) {
				mPData = new char[strlen(pData) + 1];
				strcpy(mPData, pData);
			}
		}

		MyString(const MyString &str) {
			if (str.mPData != NULL) {
				mPData = new char[strlen(str.mPData) + 1];
				strcpy(mPData, str.mPData);
			}
		}

		MyString& operator = (const MyString &str) {
			if (this != &str) {
				MyString temp(str);
				char *tempString = temp.mPData;
				temp.mPData = mPData;
				mPData = tempString;
			}

			return *this;
		}

		~MyString() {
			if (mPData != NULL) {
				delete[] mPData;
			}
		}

		char* getData() {
			return mPData;
		}
	private:
		char *mPData;
	};

	char a[] = "abcdefg";
	char b[] = "hijklmn";
	MyString temp1(a);
	EXPECT_STREQ(a, temp1.getData());

	MyString temp2(b);
	EXPECT_STREQ(b, temp2.getData());

	MyString temp3(temp1);
	EXPECT_STREQ(a, temp3.getData());

	MyString temp4 = temp2;
	EXPECT_STREQ(b, temp4.getData());

	MyString temp5 = temp4 = temp1;
	EXPECT_STREQ(a, temp4.getData());
	EXPECT_STREQ(a, temp5.getData());

	temp5 = temp4 = temp2;
	EXPECT_STREQ(b, temp4.getData());
	EXPECT_STREQ(b, temp5.getData());
}
