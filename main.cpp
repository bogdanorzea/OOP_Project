//Sa se definească o clasă generică pentru fracţii cu numărător şi numitor de un tip T neprecizat (parametru):
// * operatorii =, ==, operatorii aritmetici, +, - (unar si binar), * şi / să fie supraîncărcaţi pentru operaţiile obişnuite cu fracţii
// * operatorul (tip) de conversie a tipurilor să fie supraîncărcat pentru a efectua conversia unui obiect de tipul T la o fracţie care are ca numitor "unitatea" din tipul T (element neutru la *), care poate fi elementul construit de un anume constructor al clasei T, având argument de tip int, care să dea sens declaraţiei cu iniţializare T a=1 (ca şi declaraţiei cu iniţializare T a=0, din care va rezulta elementul "zero" din tipul T, neutru la +).
//Se vor da exemple de creare şi utilizare de obiecte pentru diferite tipuri ale numărătorului şi numitorului : int, întregi Gauss, adică numere complexe cu părţile reală şi imaginară de tip int (după definirea acestora ca o clasă separată), etc.

#include "stdio"
#include "string"

using namespace std;

struct MyStruct
{
  int i;
  int b;
  inc d;
};

int main(){
  MyStruct ana;
  ana.d = 5;
  
  int i=6;
  string a = "Mama";
  cout >> i;
  
}