#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

/*struct Zombie {
    std::string nazwa;
    int dmg;
    int hp;
    int max_hp;

    Zombie() {}

    Zombie(std::string nazwa, int hp, int max_hp, int dmg) {
       this->nazwa = nazwa;
       this->dmg = dmg;
       this->max_hp = max_hp;
       this->hp = hp;
    }
};*/

int leczenie = 0;
int postac = 0;
int hp = 0;
int max_hp = 0;
int dmg = 0;
int szansa_trafienie_mele = 0;
int szansa_trafienie_gun = 0;
int szansa_unik = 0;
int obrona = 0;
int krytyk = 2;
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

int hp_zombie = 15;
int maxhp_zombie = 15;
int atak_zombie = 3;
int krytyk_zombie = 2;
int szansa_krytyk_zombie = 1;
int szansa_trafienie_zombie = 80;

int los();
void akcja_poczatkowa();
void miejsca();
static void eq(int b);
static void stats(int a);
void lotnisko();
void komisariat();
void szkola();
void apteka();
void walka();
void akcja_walka();
void atak();
void ucieczka();
void przeszukanie();

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
        stats(1);
        break;
    case 2:
        eq(1);
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
    std::cout << "2.Komisariat\n";
    std::cout << "3.Szkola\n";
    std::cout << "4.Apteka\n";
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

static void eq(int b)
{
    int wybor = -1;
    system("cls");
    std::cout << "Twoj ekwipunek:\n";
    std::cout << "Ilosc drewna: " << drewno << std::endl;
    std::cout << "Ilosc kamienia: " << kamien << std::endl;
    std::cout << "Ilosc metalu: " << metal << std::endl;
    std::cout << "Ilosc pieniedzy: " << pieniadze << std::endl;
    std::cout << "(Wpisz jakakolwiek cyfre aby wrocic) ";
    std::cin >> wybor;
    if (wybor == 0 or wybor == 1 or wybor == 2 or wybor == 3 or wybor == 4 or wybor == 5 or wybor == 6 or wybor == 7 or wybor == 8 or wybor == 9) {
        wybor = -1;
        switch (b) {
        case 1:
            akcja_poczatkowa();
            break;
        case 2:
            apteka();
            break;
        case 3:
            szkola();
            break;
        case 4:
            komisariat();
            break;
        case 5:
            lotnisko();
            break;
        }
        }

    }



static void stats(int a)
{
    int wybor = -1;
    system("cls");
    std::cout << "Twoje statystyki:\n";
    std::cout << "Zycie: " << hp << "/" << max_hp << std::endl;
    std::cout << "Obrazenia: " << dmg << std::endl;
    std::cout << "Szansa na unik: " << szansa_unik << "%" << std::endl;
    std::cout << "Szansa na trafienie krytyczne: " << szansa_krytyk << "%" << std::endl;
    std::cout << "Obrazenia krytyczne: " <<"x"<< krytyk << std::endl;
    std::cout << "Szansa na trafenie bronia palna: " << szansa_trafienie_gun << "%" << std::endl;
    std::cout << "Szansa na trafenie bronia biala: " << szansa_trafienie_mele << "%" << std::endl;
    std::cout << "(Wpisz jakakolwiek cyfre aby wrocic) ";
    std::cin >> wybor;
    if (wybor == 0 or wybor == 1 or wybor == 2 or wybor == 3 or wybor == 4 or wybor == 5 or wybor == 6 or wybor == 7 or wybor == 8 or wybor == 9) {
        wybor = -1;
        switch (a) {
        case 1:
            akcja_poczatkowa();
            break;
        case 2:
            apteka();
            break;
        case 3:
            szkola();
            break;
        case 4:
            komisariat();
            break;
        case 5:
            lotnisko();
            break;
        }
    }

}

void lotnisko()
{
    system("cls");
    int szansa = los();
    if (szansa >= 1 or szansa <= 300) {
        walka();
    }
    int wybor = 0;
    std::cout << "Wybierz co chcesz zrobic (wpisz numer):\n";
    std::cout << "1.Wyswietl statystyki\n";
    std::cout << "2.Wyswietl ekwipunek\n";
    std::cout << "3.Przeszukaj miejsce\n";
    std::cout << "4.Wroc do obozu\n";
    std::cin >> wybor;
            switch (wybor) {
        case 1:
            stats(5);
            break;
        case 2:
            eq(5);
            break;
        case 3:
            przeszukanie();
            break;
        case 4:
            system("cls");
            akcja_poczatkowa();
            break;
        }
    szansa = 0;
}

void komisariat()
{
    system("cls");
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    int wybor = 0;
    std::cout << "Wybierz co chcesz zrobic (wpisz numer):\n";
    std::cout << "1.Wyswietl statystyki\n";
    std::cout << "2.Wyswietl ekwipunek\n";
    std::cout << "3.Przeszukaj miejsce\n";
    std::cout << "4.Wroc do obozu\n";
    std::cin >> wybor;
            switch (wybor) {
        case 1:
            stats(4);
            break;
        case 2:
            eq(4);
            break;
        case 3:
            przeszukanie();
            break;
        case 4:
            system("cls");
            akcja_poczatkowa();
            break;
        }
    szansa = 0;
}

void szkola()
{
    system("cls");
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    int wybor = 0;
    std::cout << "Wybierz co chcesz zrobic (wpisz numer):\n";
    std::cout << "1.Wyswietl statystyki\n";
    std::cout << "2.Wyswietl ekwipunek\n";
    std::cout << "3.Przeszukaj miejsce\n";
    std::cout << "4.Wroc do obozu\n";
    std::cin >> wybor;
            switch (wybor) {
        case 1:
            stats(3);
            break;
        case 2:
            eq(3);
            break;
        case 3:
            przeszukanie();
            break;
        case 4:
            system("cls");
            akcja_poczatkowa();
            break;
        }
    szansa = 0;
}

void apteka()
{
    system("cls");
    int szansa = los();
    if (szansa >= 1 and szansa <= 300) {
        walka();
    }
    else {
        int wybor = 0;
        std::cout << "Wybierz co chcesz zrobic (wpisz numer):\n";
        std::cout << "1.Wyswietl statystyki\n";
        std::cout << "2.Wyswietl ekwipunek\n";
        std::cout << "3.Przeszukaj miejsce\n";
        std::cout << "4.Wroc do obozu\n";
        std::cin >> wybor;
        switch (wybor) {
        case 1:
            stats(2);
            break;
        case 2:
            eq(2);
            break;
        case 3:
            przeszukanie();
            break;
        case 4:
            system("cls");
            akcja_poczatkowa();
            break;
        }
    }
    szansa = 0;
}

void walka()
{
        /*Zombie rodzaj[3] = {
        Zombie("zwykly",15,15,3),
        Zombie("zwykly",15,15,3),
        Zombie("zwykly",15,15,3)
    };*/
    system("cls");
    int wybor = -1;
    int szansa = 0;
    int ucieczka = 0;

    std::cout << "Zostales zaatakowany!!!\n";
    Sleep(3000);
    while (hp_zombie > 0) {
        system("cls");
        std::cout << "Co chcesz zrobic?: \n";
        std::cout << "1.Atakuj\n";
        std::cout << "2.Uciekaj\n";
        std::cout << "3.Ulecz sie\n";
        std::cout << "Twoje hp: " << hp << "/" << max_hp << std::endl;
        std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
        std::cin >> wybor;
        switch (wybor) {
            case 1:
                szansa = los();
                if (szansa>=1 and szansa <= szansa_trafienie_mele*10){
                    szansa = los();
                    if (szansa>=1 and szansa <= szansa_krytyk*10){
                        system("cls");
                        std::cout<<"Trafienie krytyczne!"<<std::endl;
                        std::cout<<"Obrazenia krytyczne x"<< krytyk << std::endl;
                        hp_zombie-=dmg*krytyk;
                        std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                        std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                        Sleep(3000);
                    }
                    else {
                        system("cls");
                        std::cout<<"Trafienie!"<<std::endl;
                        hp_zombie-=dmg;
                        std::cout<<"Zadano "<< dmg << " obrazen!" << std::endl;
                        std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                        std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                        Sleep(3000);
                    }
                }
                else {
                    system("cls");
                    std::cout<<"Chybienie!"<<std::endl;
                    std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                    std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                    Sleep(3000);
                }
                break;
            case 2:
                szansa = los();
                if (szansa >= 1 and szansa <= 200){
                    system("cls");
                    std::cout<<"Ucieczka udana!"<<std::endl;
                    Sleep(3000);
                    system("cls");
                    akcja_poczatkowa();
                }
                else {
                    system("cls");
                    std::cout<<"Ucieczka nieudana"<<std::endl;
                    Sleep(3000);
                    system("cls");
                }
                break;
            case 3:
        };

        std::cout<<"Przeciwnik atakuje!";
        szansa = los();
        if (szansa>=1 and szansa <= szansa_trafienie_zombie*10){
            szansa = los();
            if (szansa>=1 and szansa <= szansa_krytyk_zombie*10){
                system("cls");
                std::cout<<"Przeciwnik wykonal atak krytyczny!"<<std::endl;
                std::cout<<"Obrazenia krytyczne x"<< krytyk_zombie << std::endl;
                hp-=atak_zombie*krytyk_zombie;
                std::cout<<"Przeciwnik zadal "<< atak_zombie*krytyk_zombie  << " obrazen!" << std::endl;
                std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                Sleep(3000);
            }
            else {
                system("cls");
                std::cout<<"Przeciwnik atakuje!"<<std::endl;
                hp-=atak_zombie;
                std::cout<<"Zadano "<< atak_zombie << " obrazen!" << std::endl;
                std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                Sleep(3000);
            }
        }
            else {
                system("cls");
                std::cout<<"Przeciwnik chybil!"<<std::endl;
                std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;
                Sleep(3000);
            }

        wybor = -1;
    }

}
void przeszukanie(){
    system("cls");
        int szansa = los();
        if (szansa >=1 and szansa <333){
            kamien +=3;
            std::cout<<"Zyskano 3 kamienie!";
            Sleep(2500);
            akcja_poczatkowa();
        }
        if (szansa >=333 and szansa <666){
            drewno +=3;
            std::cout<<"Zyskano 3 kawalki drewna!";
            Sleep(2500);
            akcja_poczatkowa();
        }
        if (szansa >=666 and szansa <=1000){
            metal +=3;
            std::cout<<"Zyskano 3 rudy metalu!";
            Sleep(2500);
            akcja_poczatkowa();
        }
}
