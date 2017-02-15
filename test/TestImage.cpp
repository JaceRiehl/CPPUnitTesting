#include "TestImage.h"
#include "Exceptions.h"
#include "Coordinate.h"
#include "Image.h"
#include "Widget.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TestImage);

void TestImage::setUp()
{
    width = 100;
    height = 25;
    x = 6;
    y = 5;
    c = new Coordinate(x,y);
    w = new Image(*c, width, height);
}
void TestImage::tearDown()
{
    delete c;
    delete w;
}

void TestImage::testGetAt()
{
    Coordinate *c1 = new Coordinate();
    w1 = new Image(*c1, 0, 0);
    char returnChar = 'I';
    CPPUNIT_ASSERT_EQUAL(returnChar,w->getAt(*c));
    CPPUNIT_ASSERT_EQUAL(returnChar,w1->getAt(*c1));
}

void TestImage::testGetLocation()
{
    Coordinate *c1 = new Coordinate();
    w1 = new Image(*c1, 0, 0);
    CPPUNIT_ASSERT_EQUAL(true, *c == w->getLocation());
    CPPUNIT_ASSERT_EQUAL(true, *c1 == w1->getLocation());
}

void TestImage::testException()
{
    unsigned int xFail = 4000;
    unsigned int yFail = 5000;
    Coordinate *e = new Coordinate(xFail, yFail);
    Coordinate *eMax = new Coordinate(width,height);

    CPPUNIT_ASSERT_THROW(w->getAt(*e), widget_error);
    CPPUNIT_ASSERT_THROW(w->getAt(*eMax), widget_error);
}
