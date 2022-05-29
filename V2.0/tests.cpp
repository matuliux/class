#include "header.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Sumos skaiciavimas") 
{
	Studentas a;
	a.addSum(5);
	a.addSum(10);
	a.addSum(4);

	REQUIRE(a.getSum() > 5);
}

TEST_CASE("Testuojamas naujas atvejis su klase") //med = 9, vid = 8
{
	Studentas a;
	a.addSum(5); a.setNd(5);
	a.addSum(9); a.setNd(9);
	a.addSum(10); a.setNd(10); 
	a.setEgz(5);

	vidurkis(a);
	mediana(a);
	
	REQUIRE(a.getRez() == 6.2);
	REQUIRE(a.getMed() == 6.6);
	REQUIRE(a.getNauj() == 6.4);

}

TEST_CASE("Teisingas moksleiviu padalinimas")
{
	Studentas a, b, c;
	vector <Studentas> protingi, vargsiukai;
	double f;

	a.setMed(6); b.setMed(4); c.setMed(10);
	a.setRez(6); b.setRez(4); c.setRez(10);
	

	protingi.push_back(a); protingi.push_back(b); protingi.push_back(c);

	vertinimas(protingi, vargsiukai, f);

	REQUIRE(protingi.size() == 2);
	REQUIRE(vargsiukai.size() == 1);
	
}