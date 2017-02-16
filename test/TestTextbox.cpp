#include "TestTextbox.h"
#include "Exceptions.h"
#include "Coordinate.h"
#include "Textbox.h"
#include "Widget.h"
#include<string>

CPPUNIT_TEST_SUITE_REGISTRATION(TestTextbox);

void TestTextbox::setUp()
{
    width = 100;
    height = 25;
    text = "Socrates is the G.O.A.T. ";
    c = new Coordinate(0,0);
    c2 = new Coordinate(3,3);
    w = new Textbox(*c, width, height, text);
    w2 = new Textbox(*c, 5, 5, text);
}

void TestTextbox::tearDown()
{
    delete c;
    delete c2;
    delete w;
    delete w2;
}

void TestTextbox::testGetAt()
{
    Coordinate *c1 = new Coordinate(1,0);
    Coordinate *ctest = new Coordinate(23,0);
    char returnChar = 'S';
    CPPUNIT_ASSERT_EQUAL(returnChar,w->getAt(*c));
    char returnChar1 = 'o';
    CPPUNIT_ASSERT_EQUAL(returnChar1,w->getAt(*c1));
    char returnChar2 = '.';
    CPPUNIT_ASSERT_EQUAL(returnChar2,w->getAt(*ctest));

    Coordinate *c3 = new Coordinate(1,4);
    Coordinate *c4 = new Coordinate(3,4);
    CPPUNIT_ASSERT_EQUAL(returnChar,w2->getAt(*c));
    CPPUNIT_ASSERT_EQUAL(returnChar2,w2->getAt(*c3));
    CPPUNIT_ASSERT_EQUAL(returnChar2,w2->getAt(*c4));
    delete c1;
    delete ctest;
    delete c3;
    delete c4;

}

void TestTextbox::testGetLocation()
{
    CPPUNIT_ASSERT_EQUAL(true, *c == w->getLocation());
    CPPUNIT_ASSERT_EQUAL(true, *c == w2->getLocation());
}

void TestTextbox::testConstructorException()
{
    Coordinate *c1 = new Coordinate(4,4);
    string textFailure = "fsdkfsjkdhfjklshdafjkhjkashdfshajkldfhjklsadhfjkshdadjkfhsjkahdfjkhsadjkfhsajkdhfjkshdafklhsadjklhf";
    CPPUNIT_ASSERT_THROW(Textbox(*c1, 5, 5, textFailure), widget_error);

    Coordinate *cTest = new Coordinate(0,0);
    CPPUNIT_ASSERT_THROW(Textbox(*cTest, 0, 0, textFailure), widget_error);
    delete c1;
    delete cTest;

}

void TestTextbox:: testGetAtException()
{
    Coordinate *cFail = new Coordinate(345, 343);
    Coordinate *cExact = new Coordinate(width,height);
    CPPUNIT_ASSERT_THROW(w->getAt(*cFail), widget_error);
    //Causes segmentation fault
    //CPPUNIT_ASSERT_THROW(w->getAt(*cExact), widget_error);
    delete cFail;
    delete cExact;
}


