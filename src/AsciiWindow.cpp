#include "AsciiWindow.h"
#include "Window.h"
#include "Widget.h"
#include<iomanip>
#include<vector>



        void AsciiWindow::draw()
        {

            //calling out of bounds because its checking for a coordinate outside
            std::vector<Widget*> content = getWidgets();
            cout << " ";
            for(int i = 0; i < getWidth(); i++)
                cout << "-";
                cout << endl;

            for(int i = 0; i < getWidth(); i++)
            {
                cout << "|";

                for(int j = 0; j < getHeight(); j++)
                {

                    for(int k = 0; k < content.size(); k++)
                    {

                        if(content[k]->getLocation().x <= j && content[k]->getWidth() + content[k]->getLocation().x > j
                           && content[k]->getLocation().y <= i && content[k]->getHeight() + content[k]->getLocation().y > i)
                        {
                            Coordinate *get = new Coordinate ((j - content[k]->getLocation().x) , i - (content[k]->getLocation().y));
                            cout << content[k]->getAt(*get);
                            delete get;

                        }


                        else
                            cout << " ";


                    }

                }
            cout << "|" << endl;
            }

            cout << " ";
              for(int i = 0; i < getWidth(); i++)
                cout << "-";
        }


