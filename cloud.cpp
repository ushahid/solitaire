#include "cloud.h"

using namespace std;

sf::Texture loadTexture(string relativePath){
	sf::Texture texture;

	if(!texture.loadFromFile(relativePath.c_str())){
		string error =  "Cannot load texture from '" + relativePath + "'...\n";
		throw error;
	}

	texture.setSmooth(true);
	texture.setRepeated(false);
	return texture;
}