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

            for(int i = 0; i < content.size(); i++)
            {

                for(int j = 0; j < getWidth(); j++)
                {
                    cout << "|";

                    for(int k = 0; k < getHeight(); k++)
                    {

                        if(content[i]->getLocation().x <= k && content[i]->getWidth() + content[i]->getLocation().x > k
                           && content[i]->getLocation().y <= j && content[i]->getWidth() + content[i]->getLocation().y > j)
                        {
                            Coordinate *get = new Coordinate ((k - content[i]->getLocation().x) , j - (content[i]->getLocation().y));
                            cout << content[i]->getAt(*get);
                            delete get;
                        }

                        //need to change this to relative coordionate to the coord

                        else
                            cout << " ";

                    }
                    cout << "|" << endl;
                }

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
