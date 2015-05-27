#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "cloud.h"
#include "deck.h"
#include "card.h"
#include "stickyPile.h"

class game
{
public:
	game(void);

	static sf::Texture textures[card::KING+1][card::CLUBS+1];
	static sf::Texture faceDown;

	void draw(sf::RenderWindow&);
	void onMouseDown(const sf::Vector2i&);
	void onMouseUp();
	bool isWin();
	bool isLose();
	static void loadTextures();
	static sf::Texture* getTexture(const pileCard&);
	void onMouseMove(const sf::Vector2i&);
	~game(void);

private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
	vector<pile*> piles;
	sf::Vector2i mouseOffset;
	stickyPile * sPile;
	void resetPiles();
	static std::string getTexturePath(const card&);
};

