#include "POINT.h"
#include "CIRCLE.h"
#include "LINE.h"
#include "iostream"

const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);

using namespace std;

void cinclear(){
	cin.clear();
	cin.ignore(10000, '\n');
}

int main(int argc, const char* argv[]){
	double x, y;
	char exit = 0;
	POINT *p1, *p2, *p3, *meet;
	CIRCLE *p1p2, *p2p1, *p1p3, *p3p1, *ergebnis;
	LINE *lp1p2, *lp1p3;

	do{
		// einlesen von p1
		cout << "Bitte x und y f" << ue << "r P1 eingeben: " << endl;
		cin >> x >> y;
		cinclear();
		p1 = new POINT(x, y);

		// einlesen von p2
		cout << "Bitte x und y f" << ue << "r P2 eingeben: " << endl;
		cin >> x >> y;
		cinclear();
		p2 = new POINT(x, y);

		// prüfen ob p2 = p1
		if(p2->equal_to(p1)){
			cout << "P2 identisch zu P1" << endl
				<< "Bitte erneut versuchen" << endl;

			delete p1, p2;

			continue;
		}

		// einlesen von p3
		cout << "Bitte x und y f" << ue << "r P3 eingeben: " << endl;
		cin >> x >> y;
		cinclear();
		p3 = new POINT(x, y);

		// prüfen ob p3 = p1;
		if(p3->equal_to(p1)){
			cout << "P3 identisch zu P1" << endl
				<< " Bitte erneut versuchen" << endl;

			delete p1, p2, p3;

			continue;
		}

		// prüfen ob p3 = p2
		if(p3->equal_to(p2)){
			cout << "P3 identisch zu P2" << endl
				<< "Bitte erneut versuchen" << endl;

			delete p1, p2, p3;

			continue;
		}

		// erstellen der Hilfskreise
		p1p2 = new CIRCLE(p1, p1->distance_to(p2));
		p2p1 = new CIRCLE(p2, p2->distance_to(p1));
		p1p3 = new CIRCLE(p1, p1->distance_to(p3));
		p3p1 = new CIRCLE(p3, p3->distance_to(p1));

		// berechnen der Schnittlinien der Hilfskreise
		lp1p2 = p1p2->intersects(p2p1);
		lp1p3 = p1p3->intersects(p3p1);

		// prüfen ob Schnittlinien paralel sind
		if(lp1p2->parallelTo(lp1p3)){
			cout << "Schnittgeraden Parallel" << endl
				<< "Bitte erneut versuchen" << endl;

			delete p1p2, p2p1, p1p3, p3p1;
			delete lp1p2, lp1p3;
			delete p1, p2, p3;

			continue;
		}

		// berechnen des Schnittpunktes der Schnittlinien
		meet = lp1p2->meets(lp1p3);

		// erstellen des Kreises, der die 3 angegebenen Punkte umfasst
		ergebnis = new CIRCLE(meet, meet->distance_to(p1));

		// Ausgabe des ergebniskreises
		cout << "Kreis: (" << ergebnis->getMiddleX() << ", " << ergebnis->getMiddleY() << ") Radius: " << ergebnis->getRadius() << endl;

		// Abfrage ob neuer Kreis berechnet werden soll
		cout << "Neuen Kreis berechnen ? n f" << ue << "r nein, beliebig f" << ue << "r ja" << endl;
		cin >> exit;
		cinclear();

		// Löschen der Objekte
		delete p1p2, p2p1, p1p3, p3p1, ergebnis;
		delete lp1p2, lp1p3;
		delete p1, p2, p3, meet;

	} while(exit != 'n' && exit != 'N');
}
