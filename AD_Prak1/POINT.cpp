#include "POINT.h"
#include "cmath"

// Initialisiert x und y;
POINT::POINT(double x, double y){
	this->x = x;
	this->y = y;
}


// getter für x
// @return x
double POINT::getX() const{
	return x;
}

// getter für y
// @retrun y
double POINT::getY() const{
	return y;
}


// Prüft, ob der gegebene Punkt gleich diesem ist
// @return boolean
int POINT::equal_to(const POINT *p) const{
	return (abs(x - p->x) + abs(y - p->y) > 0.0001) ? 0 : 1;
}

// Berechnet die Distanz zum gegebenen Punkt
// @retrun Distanz
double POINT::distance_to(const POINT *p) const{
	return sqrt((x - p->x)*(x - p->x) + (y - p->y)*(y - p->y));
}

// Gibt das Quadrat des Betrages zurück
// @return Betrag^2
double POINT::bet2() const{
	return this->x * this->x + this->y * this->y;
}


// Überlagern der Rechenoperatoren
double POINT::operator*(const POINT &p) const{
	return (this->x * p.x + this->y * p.y);
}

POINT* POINT::operator-(const POINT &p) const{
	return new POINT(this->x - p.x, this->y - p.y);
}

POINT* POINT::operator+(const POINT &p) const{
	return new POINT(this->x + p.x, this->y + p.y);
}

POINT* operator*(const POINT &p, int mult) {
	return (new POINT(p.x * mult, p.y * mult));
}

POINT* operator*(int mult, const POINT &p){
	return (new POINT(p.x * mult, p.y * mult));
}

POINT* operator*(const POINT &p, double mult){
	return (new POINT(p.x * mult, p.y * mult));
}

POINT* operator*(double mult, const POINT &p){
	return (new POINT(p.x * mult, p.y * mult));
}