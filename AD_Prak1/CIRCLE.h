#include "LINE.h"
#include "POINT.h"

#pragma once

class CIRCLE {
public:
	// Extrahiert die Kooridinaten  des Punktes und gibt die Werte zum verarbeiten weiter
	CIRCLE(const POINT*, double);

	// Initialisiert middle mit einem neuen Punkt und r
	CIRCLE(double, double, double);


	// getter f�r Radius
	// @return radius
	double getRadius() const;

	// gibt x-Achsenwert des Mittelpunktes zur�ck
	// @return middle-> x
	double getMiddleX() const;

	// gibt den y-Achsenwert des Mittelpunktes zur�ck
	// @return middle-> y
	double getMiddleY() const;

	// Berechnet die Schnittlinie mit dem gegebenen Kreis
	// @return Schnittlinie
	LINE* intersects(const CIRCLE*) const;


	// l�scht middle
	virtual ~CIRCLE();

private:
	// Mittelpunkt des Kreises
	POINT *middle;
	// Radius des Kreises
	double radius;
};