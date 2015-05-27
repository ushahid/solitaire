#include <string>
#include "constants.h"
#include "pilecard.h"
#include "cloud.h"
#include "game.h"

using namespace std;

pileCard::pileCard(cardRank _rank, cardSuit _suit, cardOrientation or, sf::Sprite _sprite): card(_rank, _suit), orientation(or), sprite(_sprite){
	texture = game::getTexture(*this);
	sprite.setTexture(*texture);
	sf::Vector2u size = texture->getSize();
	sprite.setScale(float(WIDTH)/size.x, float(HEIGHT)/size.y);
}

pileCard::pileCard(const pileCard& obj):card(obj){
	orientation = obj.orientation;
	texture = obj.texture;
	sprite.setTexture(*texture);
	sf::Vector2u size = texture->getSize();
	sprite.setScale(float(WIDTH)/size.x, float(HEIGHT)/size.y);
}

card pileCard::getCard() const{
	return card(rank, suit);
}

pileCard::cardOrientation pileCard::getOrientation() const{
	return orientation;
}

pileCard pileCard::operator=(const pileCard& rhs){
	if(this == &rhs)
		return (*this);
	orientation = rhs.orientation;
	texture = rhs.texture;
	sprite.setTexture(*texture);
	sf::Vector2u size = texture->getSize();
	sprite.setScale(float(WIDTH)/size.x, float(HEIGHT)/size.y);
	return *this;
}


void pileCard::draw(sf::RenderWindow& window){
	window.draw(sprite);
}


void pileCard::flip(){
	orientation = cardOrientation(!orientation);
	texture = game::getTexture(*this);
	sprite.setTexture(*texture);
}

void pileCard::setOffset(const sf::Vector2i& offset){
	sprite.setPosition(float(offset.x), float(offset.y));
}

pileCard::~pileCard(void){
}
