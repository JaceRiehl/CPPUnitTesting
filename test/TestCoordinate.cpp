#include "TestCoordinate.h"
#include "Coordinate.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestCoordinate );

    void TestCoordinate::setUp()
    {

        testOne = new Coordinate();
        testTwo = new Coordinate();
        testThree = new Coordinate(5);
        testFour = new Coordinate(5,10);
        testFive = new Coordinate(5,10);

    }

	void TestCoordinate::tearDown()
    {
        delete testOne;
        delete testTwo;
        delete testThree;
        delete testFour;
        delete testFive;
    }

	void TestCoordinate::testConstructor()
	{
	    const unsigned int testDefault = 0;
	    const unsigned int testX = 5;
	    const unsigned int testY = 10;
	    //test one
	    CPPUNIT_ASSERT_EQUAL(testDefault, testOne->x);
	    CPPUNIT_ASSERT_EQUAL(testDefault, testOne->y);
	    //test two
	    CPPUNIT_ASSERT_EQUAL(testX, testThree->x);
	    CPPUNIT_ASSERT_EQUAL(testDefault, testThree->y);
	    //test three
	    CPPUNIT_ASSERT_EQUAL(testX, testFour->x);
	    CPPUNIT_ASSERT_EQUAL(testY, testFour->y);

	}

	void TestCoordinate::testEquals()
	{
	    //tests
        CPPUNIT_ASSERT_EQUAL(true, (*testOne == *testTwo));
        CPPUNIT_ASSERT_EQUAL(false, (*testOne == *testThree));
        CPPUNIT_ASSERT_EQUAL(true, (*testFour == *testFive));
        CPPUNIT_ASSERT_EQUAL(false, (*testFour == *testThree));
        CPPUNIT_ASSERT_EQUAL(false, (*testOne == *testFour));

	}

	void TestCoordinate::testOstream()
	{
	    //setup
        stringstream out1, out2, out3;
        out1 << *testOne;
        const string test1 = "[0,0]";
	    const string test2 = "[5,0]";
	    const string test3 = "[5,10]";
	    //tests
	    CPPUNIT_ASSERT(out1.str() == test1);
	    out2 << *testThree;
	    CPPUNIT_ASSERT(out2.str() == test2);
        out3 << *testFive;
	    CPPUNIT_ASSERT(out3.str() == test3);
	}

	void TestCoordinate::testNotEquals()
	{
	    CPPUNIT_ASSERT_EQUAL(true, (*testOne != *testThree));
	    CPPUNIT_ASSERT_EQUAL(false, (*testOne != *testTwo));

	}
