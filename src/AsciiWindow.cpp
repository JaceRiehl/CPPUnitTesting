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

                        if(content[k]->getLocation().x <= i && content[k]->getWidth() + content[k]->getLocation().x > i
                           && content[k]->getLocation().y <= j && content[k]->getWidth() + content[k]->getLocation().y > j)
                        {
                            Coordinate *get = new Coordinate (j,i);
                            cout << content[k]->getAt(*get);
                            delete get;
                        }

                        //need to change this to relative coordionate to the coord
                       // Coordinate *get = new Coordinate (j,i);
                      //  delete get;
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

          //Coordinate *get = new Coordinate (i,j);
                        //if(content[k]->getWidth() < i && content[k]->getHeight() < j && content[k]->getLocation().x >= i && content[k]->getLocation().y >= j)
                       // if( content[k]->getLocation().x >= i && content[k]->getLocation().y >= j)
                       //   cout << content[k]->getAt(*get);
                       // else
                         //   cout << " ";

                        /*
                        if((content[k]->getAt(*get)) != '\0')
                        cout << content[k]->getAt(*get);
                        else
                            cout << " ";
                        */
                      //  delete get;
