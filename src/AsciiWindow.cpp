#include "AsciiWindow.h"
#include "Window.h"
#include "Widget.h"
#include<iomanip>
#include<vector>

        AsciiWindow::~AsciiWindow()
        {

        }

        void AsciiWindow::Window::draw()
        {

            Widget* t = new Textbox(Coordinate(1,1), 5, 1, "Hello");
            Widget* i = new Image(Coordinate(5,5), 3,3);

            std::vector<Widget*> content = getWidgets();
            for(int i = 0; i < width; i++)
                cout << "-";

            for(int j = 0; j < height; j++)
            {
                cout << "|";
                for(int k = 0; k < width; k++)
                {
                    Coordinate *get = new Coordinate (i,j)
                    if(content[i].getAt(*get != ''))
                    cout << content[i].getAt(*get);
                    else
                        cout << " ";
                    delete get;

                }
                cout << "|" << end;'
            }
              for(int i = 0; i < width; i++)
                cout << "-";
        }
