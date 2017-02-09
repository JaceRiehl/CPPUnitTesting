#ifndef TESTIMAGE_H
#define TESTIMAGE_H
#include "Coordinate.h"
#include <cppunit/extensions/HelperMacros.h>
#include "Image.h"
#include "Widget.h"

class TestImage : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestImage);
    CPPUNIT_TEST(testGetAt);
    CPPUNIT_TEST(testGetLocation);
    CPPUNIT_TEST(testException);
    CPPUNIT_TEST_SUITE_END();

    public:
     /**
     * Sets up parameters
     */
        void setUp();
     /**
     * Deletes pointers
     */
        void tearDown();
     /**
     * Tests the range of values for getAt - located in Image class
     */
        void testGetAt();
     /**
     * tests that the the location of the widget is correct - located in Widget class
     */
        void testGetLocation();
     /**
     * Tests that the widget_error exception is called when the Coordinate is out of bounds
     */
        void testException();
    private:
        Coordinate *c;
        Widget *w, *w1;
        unsigned int width, height, x, y;

};

#endif // TESTIMAGE_H
