#include "POINT.h"

#pragma once

class LINE{
public:
	// Extrahiert Kooridinaten aus gegebenen Punkten und gibt sie zur verarbeitung weiter
	LINE(const POINT *p1, const POINT *p2);

	// Berechnet den Wert für a, b und c aus Kooridinaten 2er Punkte
	LINE(double x1, double y1, double x2, double y2);


	// Berechnet den Schnittpunkt mit der gegebenen Gerade
	// @return Schnittpunkt
	POINT* meets(const LINE *l) const;

	// Überprüft, ob die gegebene Gerade parallel zu dieser ist
	// @return boolean
	int parallelTo(const LINE *l) const;

private:
	// Werte der Geraden
	double a, b, c;

	void normalize();
};

