//
// Otto Crawford & Evgeny Ilin
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace::std;

int main() {
//	// Check of iemand oud genoeg is
//	datum geboorteDatum;// = {2001, 4, 2};
//	//gegenereerd met figlet -f DOS\ Rebel.flf "LIACS"| sed "s/$/\t\\\n/g" | sed -z "s/\n//g"	
//	cout << "hallo";
//	char message[] = "hallo";
//	cout << message << endl;
	
	int geboortejaar;
	cout << "In welk jaar ben je geboren?" << endl; //vraagt het geboortejaar op
	cin >> geboortejaar; //slaat geboortejaar op als integer onder het label: geboortejaar
	 if (geboortejaar>2014 || geboortejaar<1915){
	cout << "ongeldige leeftijd"<< endl;
	return 1;}
	
	int geboortemaand;
	if(geboortejaar <1995){ //checkt of de persoon 30+ is
		cout << "In welke maand bent u geboren?" << endl; //vraagt de geboortemaand op
		cin >> geboortemaand;
	} else{
	cout << "In welke maand ben je geboren?" << endl; //vraagt de geboortemaand op
	cin >> geboortemaand;//slaat geboortemaand op als integer onder het label: geboortemaand
	}
	if (geboortejaar > 2015 && geboortemaand > 10 || geboortejaar < 1915 && geboortemaand < 9){
	cout << "ongeldige leeftijd" << endl;
	return 1;}
	
	int geboortedag;
	if (geboortejaar <=1995 && geboortemaand > 9){
		cout << "Op welke dag van de maand bent u geboren?" << endl;
		cin >> geboortedag;
	} else{
	cout << "Op welke dag van de maand ben je geboren?" << endl;
	cin >> geboortedag;
	}
	if (geboortejaar > 2015 && geboortemaand > 9 && geboortedag > 21 || geboortejaar < 1915 && geboortemaand < 9 && geboortedag < 22){
	cout << "ongeldige leeftijd" << endl;
	return 1;}
	
	int jaren_tot_referentie;
	jaren_tot_referentie = (geboortejaar-1901); //hoeveel jaar ben je verwijderd van het referentiejaar 1901?
	int maanden_tot_referentie;
	maanden_tot_referentie = (geboortemaand - 1); //hoeveel volle maanden zitten er tussen het begin van het jaar en de geboortemaand?
	int dagen_tot_referentie;
	dagen_tot_referentie = (geboortedag-1); //Hoeveel dagen is je geboortedatum verwijderd je van de eerste dag van de maand?
	int compensatie_schikkeljaar;
	compensatie_schikkeljaar = ((jaren_tot_referentie+1)/4); //hoeveel schikkeljaren zijn er geweest? 
	int dagen_in_totaal; //hoeveel dagen zijn er in totaal voorbij vanaf de referentiedatum tot je geboorte?
	dagen_in_totaal = jaren_tot_referentie * 365 + dagen_tot_referentie + compensatie_schikkeljaar; //dagen tot referentiedatum voor iemand geboren in januaFnavri (maanden worden dus nog niet verrekend)
//Met een serie if-statements zullen we nu berekenen wat de dagen_in_totaal zijn voor iemand uit een andere maand:

	if (geboortemaand > 12 || geboortemaand < 1){ //Gebruikers kunnen geen ongeldige maand invoeren.
	cout << "Ongeldige geboortemaand, we werken met het Gregoriaans kalender he!" << endl;
	return 1;
	} 
		
	if (maanden_tot_referentie == 0){
	dagen_in_totaal = dagen_in_totaal; //de dagen zijn al goed berekend als iemand in januari is geboren.
	} else if (maanden_tot_referentie == 1){
		dagen_in_totaal += 31; //de +31 dagen om voor januari te compenseren. 
	} else if(maanden_tot_referentie == 2){
		dagen_in_totaal += (31 + 28); // iemand geboren in maart, we compenseren voor januari en februati
	} else if(maanden_tot_referentie == 3){
		dagen_in_totaal += (31 + 28 + 31);
	} else if(maanden_tot_referentie == 4){
		dagen_in_totaal += (31 + 28 + 31 + 30);
	} else if(maanden_tot_referentie == 5){
		dagen_in_totaal += (31 + 28 + 31 + 30 + 31);
	} else if(maanden_tot_referentie == 6){
		dagen_in_totaal += (31 + 28 + 31 + 30 + 31 + 30);
	} else if(maanden_tot_referentie == 7){
		dagen_in_totaal += (31 + 28 + 31+ 30 + 31 + 30 + 31); 
	} else if(maanden_tot_referentie == 8){
		dagen_in_totaal += (31 + 28 + 31+ 30 + 31 + 30 + 31 + 31);//Augustus heeft 31 dagen!
	} else if(maanden_tot_referentie == 9){
		dagen_in_totaal += (31 + 28 + 31+ 30 + 31 + 30 + 31 + 31 + 30);
	} else if(maanden_tot_referentie == 10){
		dagen_in_totaal += (31 + 28 + 31+ 30 + 31 + 30 + 31 + 31 + 30 + 31);
	} else{
		dagen_in_totaal += (31 + 28 + 31+ 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
	}

	//Nu moet alleen nog de dag berekend worden. De referentdatum was een dinsdag.
	//De dag berekenen we met een modulo deling, waarbij dinsdag = 0, woensdag = 1, donderdag = 2 etc.
	int index_geboortedag; //de deling zal uiteraard een getal opleveren.
	index_geboortedag = dagen_in_totaal % 7;
	
	int verwachte_geboortedag_index; // op welke dag van de week denkt de gebruiker te zijn geboren als index.
	char verwachte_geboortedag_letter;// op welke dag denkt de gebruiker te zijn geboren (eerste letter)

	if(geboortejaar <= 1995){ //check of de persoon 30+ is
		if(geboortemaand == 9){
			if (geboortedag > 21){
			cout << "Op welke dag van de week bent u geboren? (opties: m, d, w, d, v, z, z)" << endl;
			cin >> verwachte_geboortedag_letter; 
			}
		} else if(geboortemaand > 9){
			cout << "Op welke dag van de week bent u geboren? (opties: m, d, w, d, v, z, z)" << endl;
			cin >> verwachte_geboortedag_letter; 
		}
	}
	else{
		cout << "Op welke dag van de week ben jij geboren? (opties: m, d, w, d, v, z, z)" << endl;
		cin >> verwachte_geboortedag_letter; 
		}

	if (verwachte_geboortedag_letter == 'm'){
	verwachte_geboortedag_index = 6; //6 omdat dinsdag de referentiedag is.
	} else if (verwachte_geboortedag_letter == 'w'){
	verwachte_geboortedag_index = 1;
	} else if (verwachte_geboortedag_letter == 'v'){
	verwachte_geboortedag_index = 3;
	} else if (verwachte_geboortedag_letter == 'd'){
	cout << "Dinsdag of donderdag? typ: i of o" << endl; //twee dagen beginnen met d
	cin >> verwachte_geboortedag_letter;
		if (verwachte_geboortedag_letter == 'i'){
			verwachte_geboortedag_index = 0;} //dinsdag heeft index 0
		else{
			verwachte_geboortedag_index = 2; //als het niet dinsdag is, moet het donderdag zijn
			} 
	}
	else {
		cout << "Zaterdag of zondag? typ: a of o" << endl;
		cin >> verwachte_geboortedag_letter;
		if (verwachte_geboortedag_letter == 'a'){
			verwachte_geboortedag_index = 4;
			} else{
			verwachte_geboortedag_index = 5;
			}
		}
	
	if (index_geboortedag == verwachte_geboortedag_index){
		if (index_geboortedag == 0){
			cout << "Dinsdag is correct!" << endl;
		} else if (index_geboortedag == 1){
			cout << "Woensdag is correct!" << endl;
		} else if (index_geboortedag == 2){
			cout << "Donderdag is correct!" << endl;
		} else if (index_geboortedag == 3){
			cout << "Vrijdag is correct!" << endl;
		} else if (index_geboortedag == 4){
			cout << "Zaterdag is correct!" << endl;
		} else if (index_geboortedag == 5){
			cout << "Zondag is correct!" << endl;
		} else if (index_geboortedag == 6){
			cout << "Maandag is correct!" << endl;
		} 
	}else{
		cout << "Oei, ik zou het mama nog eens navragen..." << endl;
		return 1;
	}
	
	return 0;
}
