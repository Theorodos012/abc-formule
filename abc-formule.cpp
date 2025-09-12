//
// Otto Crawford & Evgeny Ilin
//
#include <iostream>
#include <cstdlib>

using namespace::std;

struct datum {
	int jaar;
	int maand;
	int dag;
};
int dagenInMaand[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dagenTussenData(datum datumVan, datum datumTot) {
	/*********************************************************************
	 _    _         _       __
	| | _| | ___ __(_) ___ / _|
	| |/ / |/ / '__| |/ _ \ |_
	|   <|   <| |  | |  __/  _|
	|_|\_\_|\_\_| _/ |\___|_|
	             |__/

	**********************************************************************/
	
	int dagen = 0;
	int i;
	datum iDatum = datumVan;	// iDatum = iteratie datum

	while (1) {
		// pass
		dagen++;
		iDatum.dag++;
		if ((iDatum.dag == datumTot.dag) && (iDatum.maand == datumTot.maand) && (iDatum.jaar == datumTot.jaar)) {
			break;
		}
		// dus als het februari is op een schrikkeljaar, negeer de 
		// gewone logica over maanden
		if (iDatum.maand == 2 && iDatum.jaar % 4 == 0) {
			if (iDatum.dag == 29) {
				iDatum.dag = 0;
				iDatum.maand++;
			}
		} else if (dagenInMaand[iDatum.maand - 1] == iDatum.dag) {
			iDatum.dag = 0; // want volgende loop wordt het dan 1
			iDatum.maand++;
		}
		if (iDatum.maand == 13) {
			iDatum.maand = 1;
			iDatum.jaar++;
		}
		// cout << iDatum.dag << "/" << iDatum.maand << "/" << iDatum.jaar << "\t\t" << dagen <<"\n";
	}
	return dagen;
}

int datumNaarDag(datum geboorteDatum) {
	datum referentie = {
		2007,
		8,
		10,
	};
	
	// De dag als referentie-waarde zal mijn (Otto's) verjaardag zijn:
	// Vrijdag 10 augustus 2007
	int verschilDagen;
	
	// DagenTussenData % 7 geeft de "offset" t.o.v. de referentiedag, 
	// vrijdag. Als we hier 3 aan toevoegen is het de "offset" t.o.v.
	// maandag, dus 0 = maandag, 1 = dinsdag, etc.
	// Deze representatie van dagen werkt best prima
	return (dagenTussenData(geboorteDatum, referentie) + 3) % 7;
}

int main() {
	// Check of iemand oud genoeg is
	datum geboorteDatum;// = {2001, 4, 2};
	cin >> geboorteDatum.jaar >> geboorteDatum.maand >> geboorteDatum.dag;
	cout << datumNaarDag(geboorteDatum) << endl;
	return 0;
}
