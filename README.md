Course exersizes System Engineering 2
===============

This repo includes all exersizes from System Engineering 2



#Python weetjes

- Indien er een klasse aangemaakt wordt, dan moet deze altijd de klassenaam bevatten. Een constructor mag
- Indien je een klasse instantieerd, zorg ervoor dat je het bestand importeert, zoals: import SecondScript. Hierna instanteer je doormiddel van: SecondScript.SecondScript()
- In een klasse dien je altijd bij functions de (self) parameter mee te geven!!!
- Aan het begin van elke script vul je: #! /usr/bin/python in!
- Indien je een main functie hebt, roep deze aan doormiddel van: if__name__ == "__main__": main()



#C++ weetjes

- Je begint altijd met: using namespace: std
- Met #inlcudes kun je verschillende modules toevoegen
- Pointers maak je aan doormiddel met: int *kjell; en wijs je toe aan een andere int: *kjell = j;
- Een referentie maak je aan doormiddel met: int &kjell; en wijs je toe met een andere int: &kjell = j;
- Referenties en pointers wijzen naar een stuk geheugen
- Het verschil tussen een referentie en een pointer is dat een pointer van geheugen kan veranderen, meer eigenlijk niet
- Je kan met referenties en pointers combineren, bijvoorbeeld in een functie
- Met enums is het mogelijk om getallen om te zetten naar letters, zodat deze gemakkelijk te lezen zijn in functies. Bijvoorbeeld:

````c++
// Geeft enum LOLLIKLOP met een waarde 1, maar is gemmakelijker te lezen voor een programmeur.
enum TestCase {LOLLIEPOP, LOLLIKLOP};

if(eten == LOLLIKLOP){
  Doe iets
}
```
