#ifndef TESTWINDOW_H
#define TESTWINDOW_H
#include "Coordinate.h"
#include <cppunit/extensions/HelperMacros.h>
#include "BaseWindow.h"
#include "Window.h"
#include "Image.h"
#include <string>
#include "Textbox.h"

class TestWindow : public CppUnit::TestFixture
{

    CPPUNIT_TEST_SUITE(TestWindow);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testAddWidget);
    CPPUNIT_TEST(testGetHeight);
    CPPUNIT_TEST(testGetWidgets);
    CPPUNIT_TEST(testGetWidth);
    CPPUNIT_TEST(testRemoveWidget);
    CPPUNIT_TEST(testResize);
    CPPUNIT_TEST(testIllegalSizeError);
    CPPUNIT_TEST(testResizeException);
    CPPUNIT_TEST(testWidgetOperationFailedError);
    CPPUNIT_TEST(testMaximumSizeDeclaration);
    CPPUNIT_TEST(testAscii);
    CPPUNIT_TEST_SUITE_END();

    public:
     /**
     * Sets up parameters
     */
        void setUp();
     /**
     * Tears down parameters
     */
        void tearDown();
     /**
     * Tests to ensure the constructor is assigning values correctly
     */
        void testConstructor();
     /**
     * Will add multiple widgets to the window, tests them using getWidget
     */
        void testAddWidget();
     /**
     * Tests the height of the window to ensure it was correctly passed by the constructor
     */
        void testGetHeight();
     /**
     * Tests to ensure that the Widgets are returned and the widgets in the window are put in the vector are in the correct order
     */
        void testGetWidgets();
     /**
     * Tests the width of the window to ensure it was correctly passed by the constructor
     */
        void testGetWidth();
     /**
     * Ensures removeWidget correctly removes the widgets from the window
     */
        void testRemoveWidget();
     /**
     * Makes sure the window can be resized and is resized correctly
     */
        void testResize();
     /**
     * Tests the illegal_size_error caused if a Window object is declared that is larger than the the maximum height or width
     */
        void testIllegalSizeError();
     /**
     * Testing the widget_operation_failed_error to make sure this error is caught when two widgets are attemtped to be added on top of each other
     */
        void testWidgetOperationFailedError();
     /**
     * Tests the illegal_size_error that happens when the window is resized larger than the maximum size of the window
     */
        void testResizeException();
     /**
     * This is a seperate function for the bug that happens when the maximum size for the window is declared but will cause an illegal size error
     * (creates an object with the maximum size)
     */
        void testMaximumSizeDeclaration();
        void testAscii();


    private:
        unsigned int he,wi, defaultValue;
        Window *w, *w1, *w2;
        Coordinate *c, *c1;
};

#endif // TESTWINDOW_H
