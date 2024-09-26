#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <string>

struct Zombie {
    std::string nazwa;
    int dmg;
    int hp;
    int max_hp;

    Zombie() {}

    Zombie(std::string nazwa_,int hp_, int max_hp_, int dmg_) {
        nazwa = nazwa_;
        dmg = dmg_;
        max_hp = max_hp_;
        hp = hp_;
    }
};

int leczenie = 0;
int postac = 0;
int hp = 0;
int max_hp = 0;
int dmg = 0;
int szansa_trafienie_mele = 0;
int szansa_trafienie_gun = 0;
int szansa_unik = 0;
int obrona = 0;
double krytyk = 2.0;
int szansa_krytyk = 1;
int drewno = 0;
int kamien = 0;
int metal = 0;
int pieniadze = 0;
std::string glowa = "";
std::string klata = "";
std::string spodnie = "";
std::string buty = "";
std::string rodzaj_broni = "";

int los();
void akcja_poczatkowa();
void miejsca();
void eq();
void stats();
void lotnisko();
void komisariat();
void szkola();
void apteka();
void walka();
void akcja_walka();
void atak();
void ucieczka();

int main()
{
    std::cout << "Wybierz postac (wpisz numer):\n";
    std::cout << "1.Medyk:\n";
    std::cout << "2.Zolnierz:\n";
    std::cout << "3.Kulturysta:\n";
    std::cout << "4.Ninja:\n";
    std::cin >> postac;
    switch (postac) {
    case 1:
        hp = 20;
        max_hp = 20;
        dmg = 1;
        szansa_trafienie_mele = 50;
        szansa_trafienie_gun = 50;
        szansa_unik = 30;
        obrona = 1;
        pieniadze = 200;
        leczenie = 20;
        std::cout << "Wybrano postac!\n";
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 2:
        hp = 30;
        max_hp = 30;
        dmg = 2;
        szansa_trafienie_mele = 65;
        szansa_trafienie_gun = 75;
        szansa_unik = 17;
        obrona = 6;
        pieniadze = 50;
        leczenie = 13;
        std::cout << "Wybrano postac!\n";
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 3:
        hp = 40;
        max_hp = 40;
        dmg = 5;
        szansa_trafienie_mele = 90;
        szansa_trafienie_gun = 5;
        szansa_unik = 10;
        obrona = 3;
        pieniadze = 50;
        leczenie = 5;
        std::cout << "Wybrano postac!\n";
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 4:
        hp = 25;
        max_hp = 25;
        dmg = 1;
        szansa_trafienie_mele = 70;
        szansa_trafienie_gun = 1;
        szansa_unik = 50;
        obrona = 2;
        krytyk = 2.3;
        pieniadze = 70;
        szansa_krytyk = 4;
        leczenie = 7;
        std::cout << "Wybrano postac!\n";
        std::cout << "";
        Sleep(1000);
        akcja_poczatkowa();
        break;
    }




}
int los() {
    int liczba = 0;
    srand(time(NULL));
    rand();
    liczba = rand() % 1000 + 1;

    return liczba;
}
void akcja_poczatkowa()
{
    system("cls");
    int numer = 0;
    std::cout << "Wybierz co chcesz zrobic (wpisz numer):\n";
    std::cout << "1.Wyswietl statystyki\n";
    std::cout << "2.Wyswietl ekwipunek\n";
    std::cout << "3.Podrozoj\n";
    std::cout << "4.Odpocznij\n";
    std::cin >> numer;

    switch (numer) {
    case 1:
        stats();
        break;
    case 2:
        eq();
        break;
    case 3:
        miejsca();
        break;
    case 4:
        system("cls");
        hp += leczenie;
        std::cout << "Uleczyles " << leczenie << " punktow zycia!\n";
        if (hp > max_hp) {
            std::cout << "Zmarnowane hp: " << hp - max_hp << std::endl;
            hp = max_hp;
        }
        std::cout << "Twoje hp: " << hp << "\n";
        Sleep(3000);
        akcja_poczatkowa();
        break;
    }
}

void miejsca()
{
    int wybor = -1;
    system("cls");
    std::cout << "Wybierz gdzie chcesz isc:\n";
    std::cout << "1.Lotnisko\n";
    std::cout << "2.Komisariat:\n";
    std::cout << "3.Szkola:\n";
    std::cout << "4.Apteka:\n";
    std::cout << "5.Powrot\n";
    std::cin >> wybor;
    switch (wybor) {
    case 1:
        lotnisko();
        break;
    case 2:
        komisariat();
        break;
    case 3:
        szkola();
        break;
    case 4:
        apteka();
        break;
    case 5:
        akcja_poczatkowa();
        break;
    }
}

void eq()
{
    int wybor = -1;
    system("cls");
    std::cout << "Twoj ekwipunek:\n";
    std::cout << "Ilosc drewna: "<< drewno << std::endl;
    std::cout << "Ilosc kamienia: " << kamien << std::endl;
    std::cout << "Ilosc metalu: " << metal << std::endl;
    std::cout << "Ilosc pieniedzy: " << pieniadze << std::endl;
    std::cout << "(Wpisz jakakolwiek cyfre aby wrocic) ";
    std::cin >> wybor;
    if (wybor == 0 or wybor == 1 or wybor == 2 or wybor == 3 or wybor == 4 or wybor == 5 or wybor == 6 or wybor == 7 or wybor == 8 or wybor == 9) {
        wybor = -1;
        akcja_poczatkowa();
    }

}

void stats()
{
    int wybor=-1;
    system("cls");
    std::cout << "Twoje statystyki:\n";
    std::cout <<"Zycie: "<< hp << "/" << max_hp<<std::endl;
    std::cout <<"Obrazenia: " << dmg << std::endl;
    std::cout << "Szansa na unik: " << szansa_unik << "%" << std::endl;
    std::cout << "Szansa na trafienie krytyczne: " << szansa_krytyk << "%" << std::endl;
    std::cout << "Obrazenia krytyczne: " << krytyk << std::endl;
    std::cout << "Szansa na trafenie bronia palna: " << szansa_trafienie_gun << "%" << std::endl;
    std::cout << "Szansa na trafenie bronia biala: " << szansa_trafienie_mele << "%" << std::endl;
    std::cout << "(Wpisz jakakolwiek cyfre aby wrocic) ";
    std::cin >> wybor;
    if (wybor == 0 or wybor == 1 or wybor == 2 or wybor == 3 or wybor == 4 or wybor == 5 or wybor == 6 or wybor == 7 or wybor == 8 or wybor == 9) {
        wybor = -1;
        akcja_poczatkowa();
    }

}

void lotnisko()
{
    int szansa = los();
    if (szansa >= 1 or szansa <= 300) {
        walka();
    }
    szansa = 0;
}

void komisariat()
{
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    szansa = 0;
}

void szkola()
{
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    szansa = 0;
}

void apteka()
{
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    szansa = 0;
}

void walka()
{
    int wybor = -1;
    system("cls");
    Zombie rodzaj[3] = {
        Zombie("zwykly",15,15,3),
        Zombie("zwykly",15,15,3),
        Zombie("zwykly",15,15,3)
    };
    std::cout << "Zostales zaatakowany!!!\n";
    while (rodzaj[0].hp > 0) {
        std::cout << "Co chcesz zrobic?: \n";
        std::cout << "1.Atakuj\n";
        std::cout << "2.Uciekaj\n";
        std::cout << "Twoje hp: " << hp << "/" << max_hp<<std::endl;
        std::cout << "hp przeciwnika: " << rodzaj[0].hp << "/" << rodzaj[0].max_hp << std::endl;
        std::cin >> wybor;
        switch (wybor) {
        case 1:
            break;
        case 2:
            break;
        };
        wybor = -1;
    }

}


