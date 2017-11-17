#pragma once

class POINT {

	friend POINT* operator*(const POINT &p, int mult);
	friend POINT* operator*(int mult, const POINT &p);
	friend POINT* operator*(const POINT &p, double mult);
	friend POINT* operator*(double mult, const POINT &p);

public:
	// Initialisiert x und y;
	POINT(double, double);


	// getter f�r x
	// @return x
	double getX() const;

	// getter f�r y
	// @retrun y
	double getY() const;

	// Pr�ft, ob der gegebene Punkt gleich diesem ist
	// @return boolean
	int equal_to(const POINT*) const;

	// Berechnet die Distanz zum gegebenen Punkt
	// @retrun Distanz
	double distance_to(const POINT*) const;

	// Gibt das Quadrat des Betrages zur�ck
	// @return Betrag^2
	double bet2() const;


	// �berlagern der Rechenoperatoren
	double operator*(const POINT&) const;
	POINT* operator-(const POINT&) const;
	POINT* operator+(const POINT&) const;

private:
	// x-Achsenwert des Punktes
	double x;

	// y-Achsenwert des Punktes
	double y;

};

// �berlagern der Rechenoperatoren
POINT* operator*(const POINT &p, int mult);
POINT* operator*(int mult, const POINT &p);
POINT* operator*(const POINT &p, double mult);
POINT* operator*(double mult, const POINT &p);