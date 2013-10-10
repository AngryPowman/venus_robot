//
// ExpireCacheTest.cpp
//
// $Id: //poco/1.4/Foundation/testsuite/src/ExpireCacheTest.cpp#1 $
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "ExpireCacheTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Exception.h"
#include "Poco/ExpireCache.h"
#include "Poco/AccessExpireCache.h"
#include "Poco/Bugcheck.h"
#include "Poco/Thread.h"


using namespace Poco;


#define DURSLEEP 250
#define DURHALFSLEEP DURSLEEP / 2
#define DURWAIT  300


ExpireCacheTest::ExpireCacheTest(const std::string& name): CppUnit::TestCase(name)
{
}


ExpireCacheTest::~ExpireCacheTest()
{
}


void ExpireCacheTest::testClear()
{
	ExpireCache<int, int> aCache(DURSLEEP);
	aCache.add(1, 2);
	aCache.add(3, 4);
	aCache.add(5, 6);
	assert (aCache.has(1));
	assert (aCache.has(3));
	assert (aCache.has(5));
	assert (*aCache.get(1) == 2);
	assert (*aCache.get(3) == 4);
	assert (*aCache.get(5) == 6);
	aCache.clear();
	assert (!aCache.has(1));
	assert (!aCache.has(3));
	assert (!aCache.has(5));
}


void ExpireCacheTest::testExpire0()
{
	try
	{
		ExpireCache<int, int> aCache(24);
		failmsg("cache expire lower than 25 is illegal, test should fail");
	}
	catch (Poco::InvalidArgumentException&)
	{
	}
}


void ExpireCacheTest::testExpireN()
{
	// 3-1 represents the cache sorted by age, elements get replaced at the end of the list
	// 3-1|5 -> 5 gets removed
	ExpireCache<int, int> aCache(DURSLEEP);
	aCache.add(1, 2); // 1
	assert (aCache.has(1));
	SharedPtr<int> tmp = aCache.get(1);
	assert (!tmp.isNull());
	assert (*tmp == 2);
	assert (aCache.size() == 1);
	Thread::sleep(DURWAIT);
	assert (aCache.size() == 0);
	assert (!aCache.has(1));

	// tmp must still be valid, access it
	assert (*tmp == 2);
	tmp = aCache.get(1);
	assert (!tmp);

	aCache.add(1, 2); // 1
	Thread::sleep(DURHALFSLEEP);
	aCache.add(3, 4); // 3-1
	assert (aCache.has(1));
	assert (aCache.has(3));
	tmp = aCache.get(1);
	SharedPtr<int> tmp2 = aCache.get(3);
	assert (*tmp == 2); 
	assert (*tmp2 == 4);

	Thread::sleep(DURHALFSLEEP+25); //3|1
	assert (!aCache.has(1));
	assert (aCache.has(3));
	assert (*tmp == 2); // 1-3
	assert (*tmp2 == 4); // 3-1
	tmp2 = aCache.get(3);
	assert (*tmp2 == 4);
	Thread::sleep(DURHALFSLEEP+25); //3|1
	assert (!aCache.has(3));
	assert (*tmp2 == 4);
	tmp = aCache.get(1);
	tmp2 = aCache.get(3);
	assert (!tmp);
	assert (!tmp2);

	// removing illegal entries should work too
	aCache.remove(666);

	aCache.clear();
	assert (!aCache.has(5));
	assert (!aCache.has(3));
}


void ExpireCacheTest::testDuplicateAdd()
{
	ExpireCache<int, int> aCache(DURSLEEP);
	aCache.add(1, 2); // 1
	assert (aCache.has(1));
	assert (*aCache.get(1) == 2);
	aCache.add(1, 3);
	assert (aCache.has(1));
	assert (*aCache.get(1) == 3);
}



void ExpireCacheTest::testAccessExpireN()
{
	// 3-1 represents the cache sorted by age, elements get replaced at the end of the list
	// 3-1|5 -> 5 gets removed
	AccessExpireCache<int, int> aCache(DURSLEEP);
	aCache.add(1, 2); // 1
	assert (aCache.has(1));
	SharedPtr<int> tmp = aCache.get(1);
	assert (!tmp.isNull());
	assert (*tmp == 2);
	assert (aCache.size() == 1);
	Thread::sleep(DURWAIT);
	assert (aCache.size() == 0);
	assert (!aCache.has(1));

	// tmp must still be valid, access it
	assert (*tmp == 2);
	tmp = aCache.get(1);
	assert (!tmp);

	aCache.add(1, 2); // 1
	Thread::sleep(DURHALFSLEEP);
	aCache.add(3, 4); // 3-1
	assert (aCache.has(1));
	assert (aCache.has(3));

	Thread::sleep(DURHALFSLEEP+50); //3|1
	assert (!aCache.has(1));
	assert (*aCache.get(3) == 4);
	Thread::sleep(DURHALFSLEEP+25); //3|1
	assert (*aCache.get(3) == 4);
	// removing illegal entries should work too
	aCache.remove(666);

	aCache.clear();
	assert (!aCache.has(5));
	assert (!aCache.has(3));
}


void ExpireCacheTest::testExpireWithHas()
{
	// 3-1 represents the cache sorted by age, elements get replaced at the end of the list
	// 3-1|5 -> 5 gets removed
	ExpireCache<int, int> aCache(DURSLEEP);
	aCache.add(1, 2); // 1
	assert (aCache.has(1));
	Thread::sleep(DURWAIT);
	assert (!aCache.has(1));
}


void ExpireCacheTest::setUp()
{
}


void ExpireCacheTest::tearDown()
{
}


CppUnit::Test* ExpireCacheTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ExpireCacheTest");

	CppUnit_addTest(pSuite, ExpireCacheTest, testClear);
	CppUnit_addTest(pSuite, ExpireCacheTest, testExpire0);
	CppUnit_addTest(pSuite, ExpireCacheTest, testExpireN);
	CppUnit_addTest(pSuite, ExpireCacheTest, testDuplicateAdd);
	CppUnit_addTest(pSuite, ExpireCacheTest, testAccessExpireN);
	CppUnit_addTest(pSuite, ExpireCacheTest, testExpireWithHas);

	return pSuite;
}
