#ifndef TESTTEXTBOX_H
#define TESTTEXTBOX_H
#include <cppunit/extensions/HelperMacros.h>
#include "Textbox.h"
#include<string>

class TestTextbox : public CppUnit::TestFixture
{
        CPPUNIT_TEST_SUITE(TestTextbox);
        CPPUNIT_TEST(testGetAt);
        CPPUNIT_TEST(testGetLocation);
        CPPUNIT_TEST(testConstructorException);
        CPPUNIT_TEST(testGetAtException);
        CPPUNIT_TEST_SUITE_END();

    public:
     /**
     * Sets up parameters
     */
        void setUp();
     /**
     * Deletes the pointers
     */
        void tearDown();
     /**
     * Tests the Textbox version of the getAt, makes sure the correct letter or space is in the right space.
     */
        void testGetAt();
     /**
     * Tests the location of the Widget, to make sure its at the location of the inputted coordinate (tests the Widget class)
     */
        void testGetLocation();
     /**
     * Testing the widget_error exception to ensure if text entered is longer than the textbox can hold then the program won't crash
     */
        void testConstructorException();
     /**
     * Tests to ensure the widget_error occurs if the coordinate inputted to getAt is outside the bounds of the textbox
     */
        void testGetAtException();


    private:
        Coordinate *c,*c2;
        Widget *w,*w2;
        string text;
        unsigned int width, height;
};

#endif // TESTTEXTBOX_H
