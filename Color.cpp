#include "Color.h"


Color::Color(Uint8 Red, Uint8 Green, Uint8 Blue, Uint8 Alpha) : Red(Red), Green(Green), Blue(Blue), Alpha(Alpha) {

}

Color::Color() : Red(0), Green(0), Blue(0), Alpha(255) {
	
}

void Color::setRed(Uint8 amount) {
	this->Red = amount;
}

void Color::setGreen(Uint8 amount) {
	this->Green = amount;
}

void Color::setBlue(Uint8 amount) {
	this->Blue = amount;
}

void Color::setAlpha(Uint8 amount) {
	this->Alpha = amount;
}

Uint8 Color::getRed() {
	return this->Red;
}

Uint8 Color::getGreen() {
	return this->Green;
}

Uint8 Color::getBlue() {
	return this->Blue;
}

Uint8 Color::getAlpha() {
	return this->Alpha;
}