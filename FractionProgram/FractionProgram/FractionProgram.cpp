// Subiectul 1
// Sa se definească o clasă generică pentru fracţii cu numărător şi 
// numitor de un tip T neprecizat(parametru):
// overload =
// overload ==
// overload +, - (unar)
// overload +, - (binar)
// overload *, / 
//overload operatorul (tip) de conversie a tipurilor să fie supraîncărcat pentru a
//efectua conversia unui obiect de tipul T la o fracţie care are ca numitor "unitatea" din 
//tipul T (element neutru la *), care poate fi elementul construit de un anume constructor 
//al clasei T, având argument de tip int, care să dea sens declaraţiei cu iniţializare 
//T a=1 (ca şi declaraţiei cu iniţializare T a=0, din care va rezulta elementul "zero" din tipul T, 
//neutru la +).
//
// Se vor da exemple de creare şi utilizare de obiecte pentru diferite tipuri ale numărătorului 
// şi numitorului : int, întregi Gauss, adică numere complexe cu părţile reală şi imaginară de 
// tip int (după definirea acestora ca o clasă separată), etc.
//
// De facut suplimentar:
// Constructor copiere
// Operatori unari ++, -- pre si post


#include "FractionClass.h"
#include "ComplexClass.h"
#define	SIGN(x) ((x < 0) ? ("") : ("+"))

using namespace std;

Fraction<Complex<int>> getFractionFromUser();
void printFunction(Fraction<Complex<int>>);


int main() {
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+ Program facut de Bogdan Orzea (Anul I ID, 2015-2016) +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;


	cout << "Definirea primei fractii:" << endl;
	Fraction<Complex<int>> temp1 = getFractionFromUser();
	cout << "Numarul introdus este:";
	printFunction(temp1);
	cout << endl;

	cout << endl << "Definirea celei de-a doua fractii:" << endl;
	Fraction<Complex<int>> temp2 = getFractionFromUser();
	cout << "Numarul introdus este:";
	printFunction(temp2);
	cout << endl;

	cout << "Rezultatul adunarii celor doua fractii este:" << endl;
	printFunction(temp1 + temp2);
	cout << endl;


	cout << "Rezultatul scaderii celor doua fractii este:" << endl;
	printFunction(temp1 - temp2);
	cout << endl;

	return 0;
}

Fraction<Complex<int>> getFractionFromUser() {
	int a, b, c, d;
	cout << "Va rog introduceti numaratorul fractiei:" << endl;
	cout << "Partea reala a numaratorului: ";
	cin >> a;
	cout << "Partea imaginara a numaratorului: ";
	cin >> b;
	cout << "Va rog introduceti numitorul fractiei:" << endl;
	cout << "Partea reala a numitorului: ";
	cin >> c;
	cout << "Partea imaginara a numitorului: ";
	cin >> d;
	return Fraction<Complex<int>>(Complex<int>(a, b), Complex<int>(c, d));
}

void printFunction(Fraction<Complex<int>> _fraction) {
	int a = _fraction.Numerator().Real();
	int b = _fraction.Numerator().Imaginary();
	int c = _fraction.Denominator().Real();
	int d = _fraction.Denominator().Imaginary();

	cout << "(" << a << SIGN(b) << b << "i)" <<
		" / (" << c << SIGN(d) << d << "i)";
}