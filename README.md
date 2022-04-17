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
  
 V0.5:  
 Vector konteineris pakeistas i deque ir list kontenerius  
 Greiciu pasikeitimai:  
 ![image](https://user-images.githubusercontent.com/100164021/163675641-6fb4be12-73f8-4bc5-9871-7a29c1baffbc.png)   
 Testavimo parametrai:  
 CPU: Intel i5-10300H 2.50GHz  
 RAM: 8GB  
 SSD: 512GB 

V1.0:  
Analizuojami 6 skirtingi programos realizavimo variantai:  
1. Naudojami vektoriai ir skirstant studentus is vieno konteinerio perkeliama i 2 kitus  
2. Naudojami deque ir skirstant studentus is vieno konteinerio perkeliama i 2 kitus  
3. Naudojami list ir skirstant studentus is vieno konteinerio perkeliama i 2 kitus  
4. Naudojami vektoriai ir skirstant studentus is vieno konteinerio mazesni elementai perkeliami i kita konteineri  
5. Naudojami deque ir skirstant studentus is vieno konteinerio mazesni elementai perkeliami i kita konteineri  
6. Naudojami list ir skirstant studentus is vieno konteinerio mazesni elementai perkeliami i kita konteineri  

Rasant 2 strategija buvo panaudota optimizacija remove_if panaikinant mazesnius elementus is konteinerio  

Naudojimo intrukcija:  
1. Paleidziama programa  
2. Pasirenkama ar programa ims duomenis is terminalo arba failo  
3. Pasirenkama ar kurti nauja faila  
4. Ivedamas naujo failo pavadinimas arba esamo failo pavadinimas  
5. Pasirenkamas duomenu isvedimas i faila arba terminala  

Programa parodo:  
1. Kiek laiko buvo kuriamas naujas failas  
2. Kiek laiko buvo skanuojami duomenys  
3. Kiek laiko uztruko duomenu nuskanavimas  
4. Kiek laiko uztruko duomenu isvedimas  

Programa padaro:  
1. Sukuria nauja duomenu faila  
2. Nuskaito duomenis i konteineri  
3. Isrusiuoja duomenis pagal pasiekimo lygi  
4. Isrusiuoja duomenis pagal pavarde  
5. Isveda duomenis i du naujus failus  
