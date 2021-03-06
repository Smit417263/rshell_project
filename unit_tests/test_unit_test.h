#ifndef TEST_UNIT_TEST_H_
#define TEST_UNIT_TEST_H_

#include "gtest/gtest.h"

#include "../header/CMD.h"
#include "../header/Token.h"
#include "../header/Connector.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/Semicolon.h"
#include "../header/Exit.h"
#include "../header/Test.h"

#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unistd.h>
using namespace std;

TEST(TestClass, Word_Test){
char arr[10];
strcpy(arr, "test src/");
char  arr1[25];
strcpy(arr1, "test ajosf/");

CMD* temp  = new TestClass(arr);
CMD* t = new TestClass(arr1);
EXPECT_EQ(temp->run(), true);
EXPECT_EQ(t->run(), false);
}

TEST(TestClass, Bracket_Test){
char arr[10];
strcpy(arr, "[ src/]");
char  arr1[10];
strcpy(arr1, "[ajosf/]");

CMD* t = new TestClass(arr1);
CMD* temp  = new TestClass(arr);
EXPECT_EQ(temp->run(), true);
EXPECT_EQ(t->run(), false);
}

TEST(TestClass, E_FLAG_Test){
char arr[64];
strcpy(arr, "[ -e src/]");
char  arr1[64];
strcpy(arr1, "[head/]");

CMD* t = new TestClass(arr1);
CMD* temp  = new TestClass(arr);
EXPECT_EQ(temp->run(), true);
EXPECT_EQ(t->run(), false);
}

TEST(TestClass, D_FLAG_Test){
char arr[64];
strcpy(arr, "[ -d src/]");
char  arr1[64];
strcpy(arr1, "[-d main.cpp]");

CMD* t = new TestClass(arr1);
CMD* temp  = new TestClass(arr);
EXPECT_EQ(temp->run(), true);
EXPECT_EQ(t->run(), false);
}

TEST(TestClass, F_FLAG_Test){
char arr[64];
strcpy(arr, "[ -f src/Token.cpp]");
char  arr1[64];
strcpy(arr1, "[-f src/]");

CMD* t = new TestClass(arr1);
CMD* temp  = new TestClass(arr);
EXPECT_EQ(temp->run(), true);
EXPECT_EQ(t->run(), false);
}

#endif
