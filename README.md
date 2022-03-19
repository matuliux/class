V0.1  
Pirma, programa paprašo studentų kiekio  
Žinodama studentų kiekį, ji paprašo įvesti pirmojo vardą ir pavardę  
Programa paprašo pasirinkti ar šio studento pažymiai bus įvedami ranka, ar random funkcija  
Jeigu pažymiai įvedami ranka:
  1. Programa paprašys įvesti pirmąjį pažymį
  2. Paklaus ar dar yra pažymių
  3. Bus vedami pažymiai, kol naudotojas parašys, kad jų nebėra
  4. Programa paprašys įvesti egzamino pažymį

Jeigu pažymiai įvedami random funkcija:
  1. Programa paklaus kiek pažymių gavo studentas
  2. Sugeneruos pažymius ir egzamino įvertį
Programa išves 2 studento rezultatus atsižvelgama į pažymių vidurkį ir medianą

Apsaugojimas nuo bugų:
  1. Programa tikrina ar įvestas teisingo tipo kintamasis
  2. Programa tikrina ar įvestas logiškas pažymys arba egzamino rezultatas
  3. Pragrama tikrina ar įvestas teisingas pasirinkimas pažymių generacijai arba jų kiekiui
 
 V0.2  
 Jeigu pazymiai skaitomi is failo  
   1. Atidaromas failas kursiokai.txt
   2. Nuskaitomos eilutes ir suzinoma kiek yra studentu
   3. Nuskaitomi stulpeliai ir suzinoma kiek jie turi pazymiu
   4. Failai vedami i struktura Studentas
   5. Apskaiciuojama moda ir vidurkis
   6. Is namu darbu vektoriaus panaikinami pazymiai del vietos taupymo
   7. Struktura perkeliama i vektoriu list
   8. List isrusiuojamas pagal vardus arba pavardes
   9. Isvedami rezultatai i faila arba terminala
 
 V0.3  
 Prideta  
   1. Try / throw / catch irasant duomenis is failo sienkiant informatuoti zmogu apie galimai istikusia klaida
   2. Bibliotekos ir funkciju aprasymai perdeti i header failus
   3. Funkcijos perkeltos i 2 atskirus failus - irasant ranka ir is failo 

V0.4  
  1. Programa kuria duomenu faila
  2. Studentai rusiuojami i protingus ir vargsiukus
  3. Isveda juos i du skirtingus failus
  4. Atlieka spartos analize

Greiciai su 1000:  
  Failo generavimas 3.17s  
  Duomenu nuskaitymas is failo 0.008s  
  Duomenu isrusiavimas 0.000007s  
  Protingu isvedimas uztruko 0.0024s  
  Vargsiuku isvedimas uztruko 0.0024s  
  Visa programa uztruko 8.89s  

Greiciai su 10000:  
  Failo generavimas 4.14s  
  Duomenu nuskaitymas is failo 0.08s  
  Duomenu isrusiavimas 0.000069s  
  Protingu isvedimas uztruko 0.019s  
  Vargsiuku isvedimas uztruko 0.019s  
  Visa programa uztruko 10.14s  

Greiciai su 100000:  
  Failo generavimas 4.63s  
  Duomenu nuskaitymas is failo 0.84s  
  Duomenu isrusiavimas 0.0011s  
  Protingu isvedimas uztruko 0.20s  
  Vargsiuku isvedimas uztruko 0.20s  
  Visa programa uztruko 12s  

Greiciai su 1000000:  
  Failo generavimas 10.96s  
  Duomenu nuskaitymas is failo 9.02s  
  Duomenu isrusiavimas 0.01s  
  Protingu isvedimas uztruko 2.0s  
  Vargsiuku isvedimas uztruko 2.0s  
  Visa programa uztruko 28.14s  

Greiciai su 10000000:  
  Failo generavimas 51.72s  
  Duomenu nuskaitymas is failo 53.30s  
  Duomenu isrusiavimas 0.13s  
  Protingu isvedimas uztruko 11.69s  
  Vargsiuku isvedimas uztruko 11.69s  
  Visa programa uztruko 189.832s  
