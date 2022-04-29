#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CustomRectangleShape : public sf::RectangleShape
 {
  public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(size)
     {
      setPosition(position);
     }

    void setSpeed(int xspeed, int yspeed, int rspeed)
     {
      m_speed_x = xspeed;
      m_speed_y = yspeed;
      m_speed_r = rspeed;
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
     int m_speed_x = 4185;
     int m_speed_y = 5271;
     int m_speed_r = 121;
     int bound_top = 0;
     int bound_bottom = 0;
     int bound_left = 0;
     int bound_right = 0;
//     bool selected = 0;
 };

class CustomSprite : public sf::Sprite
 {
  public:
//    CustomSprite();

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

    CustomSprite guy;
    guy.setTexture(guy_tex);

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
      window.draw(guy);





      guy.moveInDirection(elapsed, event.key.code);

      window.display();
     }
    return 0;
}
