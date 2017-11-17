#include "CIRCLE.h"
#include "cmath"

// Extrahiert die Kooridinaten  des Punktes und gibt die Werte zum verarbeiten weiter
CIRCLE::CIRCLE(const POINT *m, double r) : CIRCLE(m->getX(), m->getY(), r){
}

// Initialisiert middle mit einem neuen Punkt und r
CIRCLE::CIRCLE(double x, double y, double r){
	middle = new POINT(x, y);
	radius = r;
}


// getter für Radius
// @return radius
double CIRCLE::getRadius() const{
	return radius;
}

// gibt x-Achsenwert des Mittelpunktes zurück
// @return middle-> x
double CIRCLE::getMiddleX() const{
	return middle->getX();
}

// gibt den y-Achsenwert des Mittelpunktes zurück
// @return middle-> y
double CIRCLE::getMiddleY() const{
	return middle->getY();
}


// Berechnet die Schnittlinie mit dem gegebenen Kreis
// @return Schnittlinie
LINE* CIRCLE::intersects(const CIRCLE *cir) const{
	// hilfsvariablen
		// u = mü; l = lambda
	double c, u1, u2, p, q, ls, r1, r2;
	POINT *n1, *n2, *s1, *s2, *m1, *m2;
	// rückgabeobjekt
	LINE *ret;

	// zuweisung der Werte für m und r
	m1 = this->middle;
	m2 = cir->middle;
	r1 = this->radius;
	r2 = cir->radius;

	// n1 = (a, b) = 2 * (m1 - m2)
	n1 = 2 * *(*m1 - *m2);
	// n2 = (b, -a)
	n2 = new POINT(n1->getY(), -n1->getX());

	// c = (m2^2 - m1^2) - (r2^2 - r1^2)
	c = (m2->bet2() - m1->bet2()) - (pow(r2, 2) - pow(r1, 2));

	//		     c
	// ls = - ------
	//		  |n1|^2
	ls = -(c / n1->bet2());
	
	//	    n2 * m1
	// p = ---------
	//	    |n1|^2
	p = (*n2 * *m1) / n1->bet2();
	
	//	      c^2      2c*n1*m1     m1^2 - r1^2
	// q = -------- + ---------- + -------------
	//      |n1|^4      |n1|^4         |n1|^2
	q = (pow(c, 2) 
		  / pow(n1->bet2(), 2)) 
								+ ((2 * c * (*n1 * *m1))
								 	 / pow(n1->bet2(), 2)) 
														   + ((m1->bet2() - pow(r1, 2))
															    / n1->bet2());

	//             _________
	// u = p +/- \/ p^2 - q |
	u1 = (p + sqrt(pow(p, 2) - q));
	u2 = (p - sqrt(pow(p, 2) - q));

	// s1 = ls * n1 + u1 * n2
	s1 = *(ls * *n1) + *(u1 * *n2);

	// s2 = ls * n1 + u2 * n2
	s2 = *(ls * *n1) + *(u2 * *n2);

	// erstellen der Schnittlinie aus den Schnittpunkten s1 und s2
	ret = new LINE(s1, s2);

	// Löschen der Hilfsobjekte
	delete n1, n2;
	delete s1, s2;

	return ret;
}


// löscht middle
CIRCLE::~CIRCLE(){
	delete middle;
}