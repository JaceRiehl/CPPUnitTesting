#ifndef TESTCOORDINATE_H
#define TESTCOORDINATE_H
#include "Coordinate.h"

#include <cppunit/extensions/HelperMacros.h>

class TestCoordinate : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( TestCoordinate );
    CPPUNIT_TEST( testConstructor );
    CPPUNIT_TEST( testEquals );
    CPPUNIT_TEST( testOstream );
    CPPUNIT_TEST(testNotEquals);
    CPPUNIT_TEST_SUITE_END();

    public:
    /**
    * Sets up the Coordinate pointers
    */
    void setUp();
    /**
    * Destructor for window
    */
    void tearDown();
    /**
    * Tests the constructor to make sure the values are being assigned properly to the x and y coordinates
    */
    void testConstructor();
    /**
    * Tests the equivalence overloaded operator to ensure that it does correctly check if two Coordinate objects are the same
    */
    void testEquals();
    /**
    * Tests that the ostream operator is working and is outputting the correct Coordinate using stringstream
    */
    void testOstream();
    void testNotEquals();

    private:
        Coordinate *testOne, *testTwo, *testThree, *testFour, *testFive;
};

#endif // TESTCOORDINATE_H
