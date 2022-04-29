#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class CustomSprite : public sf::Sprite
 {
  public:

    void setSpeed(int xspeed, int yspeed)
     {
      m_speed_x = xspeed;
      m_speed_y = yspeed;
     }

    void setBounds(int left, int right, int top, int bottom)
     {
      bound_top = top;
      bound_bottom = bottom;
      bound_right = right;
      bound_left = left;
     }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key)
     {
      sf::FloatRect rectangle_bounds = getGlobalBounds();

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rectangle_bounds.top > bound_top)
       {
        move(0, -m_speed_y*elapsed.asSeconds());
       }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rectangle_bounds.top+rectangle_bounds.height < bound_bottom)
       {
        move(0, m_speed_y*elapsed.asSeconds());
       }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rectangle_bounds.left + rectangle_bounds.width < bound_right)
       {
        move(m_speed_x*elapsed.asSeconds(), 0);
       }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && rectangle_bounds.left > bound_left)
       {
        move(-m_speed_x*elapsed.asSeconds(), 0);
       }
     }


  private:
    int m_speed_x = 200;
    int m_speed_y = 200;
    int bound_top = 0;
    int bound_bottom = 0;
    int bound_left = 0;
    int bound_right = 0;
 };

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Clock clock;

    sf::Texture guy_tex;
    if (!guy_tex.loadFromFile("guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Texture grass_tex;
    if (!grass_tex.loadFromFile("grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    grass_tex.setRepeated(true);

    sf::Texture wall_tex;
    if (!wall_tex.loadFromFile("wall.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    wall_tex.setRepeated(true);


    CustomSprite guy;
    guy.setTexture(guy_tex);

    sf::Sprite grass;
    grass.setTexture(grass_tex);
    grass.setScale(1, 1);
    grass.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    sf::Sprite wall1;
    wall1.setTexture(wall_tex);
    wall1.setScale(0.3, 0.3);
    wall1.setTextureRect(sf::IntRect(0, 0, 100, 900));
    wall1.setPosition(200, 100);

    sf::Sprite wall2;
    wall2.setTexture(wall_tex);
    wall2.setScale(0.3, 0.3);
    wall2.setTextureRect(sf::IntRect(0, 0, 700, 100));
    wall2.setPosition(230, 250);

    sf::Sprite wall3;
    wall3.setTexture(wall_tex);
    wall3.setScale(0.3, 0.3);
    wall3.setTextureRect(sf::IntRect(0, 0, 100, 1100));
    wall3.setPosition(440, 220);

    sf::Sprite wall4;
    wall4.setTexture(wall_tex);
    wall4.setScale(0.3, 0.3);
    wall4.setTextureRect(sf::IntRect(0, 0, 100, 1000));
    wall4.setPosition(570, 110);

    sf::Sprite wall5;
    wall5.setTexture(wall_tex);
    wall5.setScale(0.3, 0.3);
    wall5.setTextureRect(sf::IntRect(0, 0, 600, 100));
    wall5.setPosition(570, 410);

    sf::Sprite wall6;
    wall6.setTexture(wall_tex);
    wall6.setScale(0.3, 0.3);
    wall6.setTextureRect(sf::IntRect(0, 0, 700, 100));
    wall6.setPosition(100, 460);

    guy.setBounds(0, window.getSize().x, 0, window.getSize().y);


    while (window.isOpen())
     {
      sf::Time elapsed = clock.restart();

      sf::Event event;
      while (window.pollEvent(event))
       {

        if (event.type == sf::Event::Closed)
         {
          window.close();
         }

       }

      window.clear(sf::Color::Black);
      window.draw(grass);
      window.draw(guy);
      window.draw(wall1);
      window.draw(wall2);
      window.draw(wall3);
      window.draw(wall4);
      window.draw(wall5);
      window.draw(wall6);

      guy.moveInDirection(elapsed, event.key.code);

      window.display();
     }
    return 0;
}
