#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "game.h"

using namespace std;



int main(int argc, char* argv[]){
	srand(time(0));
	sf::RenderWindow window;
	window.create(sf::VideoMode(winWidth, winHeight), "Solitaire", sf::Style::Close);
	window.setPosition(sf::Vector2i(50, 0));
	game::loadTextures();
	game g;
	bool win = g.isWin(), lost = g.isLose();
	
	while(window.isOpen() && !win && !lost){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
			else if(event.type ==  sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				g.onMouseDown(sf::Mouse::getPosition(window));
			else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
				g.onMouseUp();
				win = g.isWin();
				lost = g.isLose();
			}
			else if(event.type == sf::Event::MouseMoved && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				g.onMouseMove(sf::Mouse::getPosition(window));
		}

		window.clear(sf::Color::White);
		g.draw(window);
		window.display();		
	}
	return 0;
}