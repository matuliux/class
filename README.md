#V2.0

V1.0 programa naudojanti vektorius ir 2 rusiavimo strategija modifikuota pakeiciant struct i class.  
Programoje realizuoti set'eriai ir get'eriai suteikia programai universalumo.  
Programos paleidžiamąjį failą source.exe galima sukurti atsidarius konsolę visų failų aplanke ir parašyti komandą make vector.  

Programos greciai lyginant struct ir class:  
![image](https://user-images.githubusercontent.com/100164021/167272156-65b4fc72-ca1e-424c-9075-fec3456c14c9.png)  

Programos greciai lyginant optimizacijos budus:  
![image](https://user-images.githubusercontent.com/100164021/167272168-348176e1-9847-412e-a166-d7bfb465f278.png) ![image](https://user-images.githubusercontent.com/100164021/167272176-f62f9b03-825c-4b59-81a7-b82fc7c2f01c.png)  
![image](https://user-images.githubusercontent.com/100164021/167272200-6328992e-e743-4a3f-ba40-d5d20fb37c86.png)  

Header failai:  
bibliotekos.h - aprasytos bibliotekos ir kiti include'ai  
Header.h - aprasyta klase Studentas ir funkciju sablonai  

Cpp failai:  
file_gen.cpp: aprasyta funkcija generuojanti duomenu faila  
funkcijos_file.cpp: aprasytos funkcijos naudojamos dirbant su failais ir bendros funkcijos naudojamos su ivedimu is failo ir ranka  
funkcijos_manual.cpp: aprasytos funkcijos naudojamos dirbant su duomenimis ivestais ranka  
Source.cpp: Programos paleidimo funkcija

V1.2
Studentas klasei sukurtas distruktorius, kopijavimo konstruktorius ir priskirimo kontruktorius  
Sie atnaujinimai padaro programa universalesne, palengvina programuotoju darba su ta pacia programa  
![image](https://user-images.githubusercontent.com/100164021/167295617-4f8ce693-e820-47b7-82f1-c0c88f6706f8.png)  

V1.5  
Sukurta abstrakcioji klase Zmogus  
Klase Studentas - klases Zmogus delivered klase  
![image](https://user-images.githubusercontent.com/100164021/168154156-2e80d72d-f830-4bd1-8aeb-aeac791409fa.png)  

V2.0  
Sukurta Doxygen dokumentacija.  
Sukurtas msi idiegimo failas.  
Parasyti 3 unit testai su catch 2 framework.  
