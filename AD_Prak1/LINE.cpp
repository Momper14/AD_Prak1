#include "LINE.h"
#include "cmath"

// Extrahiert Kooridinaten aus gegebenen Punkten und gibt sie zur verarbeitung weiter
LINE::LINE(const POINT *p1, const POINT *p2) : LINE(p1->getX(), p1->getY(), p2->getX(), p2->getY()){
}

// Berechnet den Wert für a, b und c aus Kooridinaten 2er Punkte
LINE::LINE(double x1, double y1, double x2, double y2){
	a = y1 - y2;
	b = x2 - x1;
	c = x1 * y2 - x2*y1;
}

// Berechnet den Schnittpunkt mit der gegebenen Gerade
// @return Schnittpunkt
POINT* LINE::meets(const LINE *l) const{
	double x, y;

	x = (l->b * this->c - l->c * this->b) / (l->a * this->b - this->a * l->b);
	y = (l->c * this->a - l->a * this->c) / (l->a * this->b - this->a * l->b);

	return new POINT(x, y);
}

// Überprüft, ob die gegebene Gerade parallel zu dieser ist
// @return boolean
int LINE::parallelTo(const LINE *l) const{
	return (abs((l->a * this->b - this->a * l->b)) > 0.0001) ? 0 : 1;
}

void LINE::normalize(){
	double a, b, c;
	double wurz = sqrt(pow(this->a, 2) + pow(this->b, 2));

	a = this->a / wurz;
	b = this->b / wurz;
	c = this->c / wurz;

	this->a = a;
	this->b = b;
	this->c = c;
}