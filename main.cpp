#include <Typewriter.hpp>
#include <DataTables.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>

#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600,32), "NEUREXUS Profiles", sf::Style::Default);
    sf::Event e;

    std::vector<EnemyProfileData> myData = initializeEnemyProfileData();

    std::map<sf::Uint32, std::string> myInfo;
    myInfo[0] = myData[0].name + "\n\n" + myData[0].description;

    myInfo[1] = myData[1].name + "\n\n" + myData[1].description;
    myInfo[2] = myData[2].name + "\n\n" + myData[2].description;
    myInfo[3] = myData[3].name + "\n\n" + myData[3].description;

    std::size_t currItem = 0;
    std::size_t maxIter = myInfo.size()-1;
    std::cout<<maxIter<<std::endl;

    sf::Font myfont;
    if(!myfont.loadFromFile("resources/fonts/contb.ttf"))
    {
        std::cerr<<"Could not load font"<<std::endl;
    }

    Typewriter myTypewriter("empty", myfont, 32, .05f);
    myTypewriter.setPosition(sf::Vector2f(400.f, 300.f));

    while(window.isOpen())
    {
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }

            if(e.type == sf::Event::KeyPressed)
            {
                switch(e.key.code)
                {
                    case sf::Keyboard::Escape:
                    {
                        window.close();
                        return 0;
                    }
                    break;

                    case sf::Keyboard::Left:
                    {
                        if(currItem <= 0)
                            currItem = 0;
                        else
                            currItem--;

                        myTypewriter.reset();
                    }
                    break;

                    case sf::Keyboard::Right:
                    {
                        if(currItem >= maxIter)
                            currItem = maxIter;
                        else
                            currItem++;

                        myTypewriter.reset();
                    }
                    break;

                    default:
                        break;
                }
            }
        }

        myTypewriter.setString(myInfo[currItem]);
        myTypewriter.write();

        //show number of images in window title
        window.setTitle("Enemies: " + std::to_string(myInfo.size()) + " -------- Current Enemy: " + myData[currItem].name);

        window.clear();

        window.draw(myTypewriter);

        window.display();
    }
    return 0;
}
