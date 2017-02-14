#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "Window.h"
#include "AsciiWindow.h"
#include "Widget.h"
#include "Textbox.h"
#include "Image.h"


using namespace std;

int main()
{
   // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
                                                       std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

    Window* w = new AsciiWindow(10,10);

    Widget* t = new Textbox(Coordinate(1,1), 5, 1, "Hello");
    Widget* i = new Image(Coordinate(5,5), 3,3);
    w->addWidget(i);
    w->addWidget(t);
    w->draw();


  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
