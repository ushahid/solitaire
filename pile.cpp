#include "pile.h"
#include "stickyPile.h"

pile::pile(sf::Vector2i _offset) : offset(_offset){
	emptyCardTexture = loadTexture("textures//empty.png");
	emptyCard.setTexture(emptyCardTexture);
	sf::Vector2u size = emptyCardTexture.getSize();
	emptyCard.setScale(float(pileCard::WIDTH)/size.x, float(pileCard::HEIGHT)/size.y);
	emptyCard.setPosition(float(offset.x), float(offset.y));
}

sf::Vector2i pile::getOffset() const{
	return offset;
}

void pile::appendPile(const pile& p){
	for(unsigned int i = 0; i < p.getSize(); i++)
		cards.push_back(p.cards[i]);
	resetCardPositions();
}

stickyPile * pile::splitPile(const sf::Vector2i& mousePos){
	int result = this->getCardAt(mousePos);
	stickyPile * ptr = nullptr;
	if(canSplit(result)){
		ptr = new stickyPile(this, result, getCardPosition(result));
	}
	return ptr;
}

bool pile::containsPoint(const sf::Vector2i& point){
	return (point.x >= offset.x && point.x <= offset.x + int(getWidth())) && (point.y >= offset.y && point.y <= offset.y + int(getHeight()));
}

bool pile::isOverlapping(const pile& p){
	int thisWidth = getWidth();
	int thisHeight = getHeight();
	int pWidth = p.getWidth();
	int pHeight = p.getHeight();
	bool overlappingOnX = offset.x < p.offset.x + pWidth && offset.x + thisWidth > p.offset.x;
	bool overlappingOnY = offset.y < p.offset.y + pHeight && offset.y + thisHeight > p.offset.y;
	return (overlappingOnX && overlappingOnY);
}

card pile::getCard(unsigned int cardIndex) const{
	if(cardIndex >= getSize())
		throw string("Card index invalid...\n");
	return cards[cardIndex].getCard();
}

void pile::setPosition(sf::Vector2i _offset){
	offset = _offset;
	resetCardPositions();
}

void pile::appendCard(pileCard card){
	cards.push_back(card);
	resetCardPositions();
}

bool pile::commonSplitTest(unsigned int cardIndex){
	return cardIndex >= 0 && cardIndex < getSize() && cards[cardIndex].getOrientation() == pileCard::FACE_UP;
}

bool pile::commonAppendTest(const pile& p) const{
	return p.getSize()  > 0 && p.cards[0].getOrientation() == pileCard::FACE_UP;
}

void pile::drawEmpty(sf::RenderWindow& window){
	emptyCard.setPosition(float(offset.x), float(offset.y));
	window.draw(emptyCard);
}

unsigned int pile::getSize() const{
	return cards.size();
}


pile::~pile(void){
}
