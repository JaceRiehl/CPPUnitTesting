#include "TestWindow.h"
#include "Exceptions.h"
#include "BaseWindow.h"
#include "Widget.h"
#include "Window.h"
#include "AsciiWindow.h"
#include<vector>

CPPUNIT_TEST_SUITE_REGISTRATION(TestWindow);

void TestWindow::setUp()
{

    wi = 200;
    he = 300;
    defaultValue = 100;
    c = new Coordinate(5,5);
    c1 = new Coordinate();
    w = new BaseWindow();
    w1 = new BaseWindow(wi,he);

}
void TestWindow::tearDown()
{
    delete c;
    delete c1;
    delete w;
    delete w1;
}

void TestWindow::testConstructor()
{
    Window *w = new BaseWindow();
    //testing with no parameters
    CPPUNIT_ASSERT_EQUAL(defaultValue, w->getHeight());
    CPPUNIT_ASSERT_EQUAL(defaultValue, w->getWidth());

    //testing with parameters
    CPPUNIT_ASSERT_EQUAL(he, w1->getHeight());
    CPPUNIT_ASSERT_EQUAL(wi, w1->getWidth());
}

void TestWindow::testAddWidget()
{
    Widget* wig = new Image(*c, 20,20);
    Widget* wig2 = new Image(*c1, 22, 25);
    w1->addWidget(wig);
    CPPUNIT_ASSERT_EQUAL(wig, w1->getWidgets()[0]);
    w1->addWidget(wig2);
    CPPUNIT_ASSERT_EQUAL(wig2, w1->getWidgets()[1]);
}



void TestWindow::testGetHeight()
{
    Window *w = new BaseWindow();
    CPPUNIT_ASSERT_EQUAL(he, w1->getHeight());
    CPPUNIT_ASSERT_EQUAL(defaultValue, w->getHeight());

}


void TestWindow::testGetWidgets()
{
    Widget* wig = new Image(*c, 20,20);
    Widget* wig2 = new Image(*c1, 22, 25);
    w1->addWidget(wig);
    CPPUNIT_ASSERT_EQUAL(wig, w1->getWidgets()[0]);
    w1->addWidget(wig2);
    CPPUNIT_ASSERT_EQUAL(wig2, w1->getWidgets()[1]);
}

void TestWindow::testGetWidth()
{
    Window *w = new BaseWindow();
    CPPUNIT_ASSERT_EQUAL(100u, w->getHeight());
    CPPUNIT_ASSERT_EQUAL(100u, w->getWidth());
}

void TestWindow::testRemoveWidget()
{
    Widget* wig = new Image(*c, 20,20);
    Widget* wig2 = new Image(*c1, 22, 25);
    w1->addWidget(wig);
    CPPUNIT_ASSERT_EQUAL(wig, w1->getWidgets()[0]);
    w1->addWidget(wig2);
    CPPUNIT_ASSERT_EQUAL(wig2, w1->getWidgets()[1]);
    w1->removeWidget(wig);
    CPPUNIT_ASSERT(wig !=w1->getWidgets()[0]);
}

void TestWindow::testResize()
{
    unsigned int wResize, hResize;
    wResize = 500;
    hResize = 600;
    w1->resize(wResize,hResize);
    CPPUNIT_ASSERT_EQUAL(wResize, w1->getWidth());
    CPPUNIT_ASSERT_EQUAL(hResize, w1->getHeight());
}

void TestWindow::testIllegalSizeError()
{
    Window *wFail;
    CPPUNIT_ASSERT_THROW(wFail = new BaseWindow(1050, 1050), illegal_size_error);
    CPPUNIT_ASSERT_THROW(wFail = new BaseWindow(1000, 1050), illegal_size_error);
    CPPUNIT_ASSERT_THROW(wFail = new BaseWindow(1050, 1000), illegal_size_error);
}


void TestWindow::testResizeException()
{
    //testing resizing both out of bounds
    unsigned int wResize, hResize, zero;
    wResize = 5467;
    hResize = 10645;
    CPPUNIT_ASSERT_THROW(w1->resize(wResize,hResize), illegal_size_error);
    //testing height independent
    wResize = 576;
    hResize = 10645;
    CPPUNIT_ASSERT_THROW(w1->resize(wResize,hResize), illegal_size_error);
    //Testing width independent
    wResize = 5766;
    hResize = 106;
    CPPUNIT_ASSERT_THROW(w1->resize(wResize,hResize), illegal_size_error);
    //testing cutting off a widget
    Widget* wig = new Image(*c, 20,20);
    Widget* wig2 = new Image(*c1, 22, 25);
    w1->addWidget(wig);
    w1->addWidget(wig2);
    zero = 0;
    CPPUNIT_ASSERT_THROW(w1->resize(zero,zero), illegal_size_error);

}

void TestWindow::testWidgetOperationFailedError()
{
    Widget* wig = new Image(*c, 20,20);
    Widget* wig2 = new Image(*c, 20, 20);
    w1->addWidget(wig);
    CPPUNIT_ASSERT_THROW(w1->addWidget(wig2), widget_operation_failed_error);
}

void TestWindow::testMaximumSizeDeclaration()
{
    Window *widgetMax;
    //testing width
    CPPUNIT_ASSERT_NO_THROW(BaseWindow(1024,500));
    //testing height
    CPPUNIT_ASSERT_NO_THROW(BaseWindow(500,1024));
    //testing both
    CPPUNIT_ASSERT_NO_THROW(BaseWindow(1024,1024));
}
void TestWindow::testAscii()
{
    cout << endl;
    Window* w = new AsciiWindow(10,10);

    Widget* t = new Textbox(Coordinate(1,1), 5, 1, "Hello");
    Widget* i = new Image(Coordinate(5,5), 3,3);
    w->addWidget(i);
    w->addWidget(t);
    //cout << t->getAt(Coordinate(4,0));
    w->draw();
}


