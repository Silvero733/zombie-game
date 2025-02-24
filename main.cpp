#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

int leczenie = 0; //Statystyki gracza
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

int hp_zombie = 15; //Statystyki przeciwnika
int maxhp_zombie = 15;
int atak_zombie = 7;
int krytyk_zombie = 2;
int szansa_krytyk_zombie = 1;
int szansa_trafienie_zombie = 80;

int lokacja = 0;

int los(); //Biblioteka funkcji
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
void cheaty();

int main() //FUNKCJA
{
    std::cout << "Wybierz postac (wpisz numer):\n";
    std::cout << "1.Medyk:\n";
    std::cout << "2.Zolnierz:\n";
    std::cout << "3.Kulturysta:\n";
    std::cout << "4.Ninja:\n";
    std::cin >> postac;
    std::cout << "Wybrano postac!\n";
    switch (postac) {
    case 1: //Medyk
        hp = 35;
        max_hp = 35;
        dmg = 2;
        szansa_trafienie_mele = 50;
        szansa_trafienie_gun = 50;
        szansa_unik = 7;
        obrona = 1;
        pieniadze = 200;
        leczenie = 15;
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 2: //Zolnierz
        hp = 42;
        max_hp = 42;
        dmg = 4;
        szansa_trafienie_mele = 65;
        szansa_trafienie_gun = 75;
        szansa_unik = 17;
        obrona = 6;
        pieniadze = 50;
        leczenie = 11;
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 3: //Kulturysta
        hp = 50;
        max_hp = 50;
        dmg = 6;
        szansa_trafienie_mele = 90;
        szansa_trafienie_gun = 5;
        szansa_unik = 10;
        obrona = 3;
        pieniadze = 50;
        leczenie = 5;
        Sleep(1000);
        akcja_poczatkowa();
        break;
    case 4: //Ninja
        hp = 27;
        max_hp = 27;
        dmg = 4;
        szansa_trafienie_mele = 70;
        szansa_trafienie_gun = 1;
        szansa_unik = 35;
        obrona = 2;
        krytyk = 2.3;
        pieniadze = 70;
        szansa_krytyk = 4;
        leczenie = 6;
        Sleep(1000);
        akcja_poczatkowa();
        break;
    }




}
int los() //FUNKCJA
{
    int liczba = 0;
    srand(time(NULL));
    rand();
    liczba = rand() % 1000 + 1;

    return liczba;
}
void akcja_poczatkowa()//FUNKCJA
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
        {
        system("cls");
        int uzdrowienie = rand()%20+10;
        hp += uzdrowienie;
        std::cout << "Uleczyles " << uzdrowienie << " punktow zycia!\n";
        if (hp > max_hp) {
            std::cout << "Zmarnowane hp: " << hp - max_hp << std::endl;
            hp = max_hp;
        }
        std::cout << "Twoje hp: " << hp << "\n";
        Sleep(3000);
        akcja_poczatkowa();
        break;
        }
    case 375:
        cheaty();
        break;
    }
}

void miejsca()//FUNKCJA
{
    int wybor = -1;
    lokacja=0;
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
        lokacja = 1;
        break;
    case 2:
        komisariat();
        lokacja = 2;
        break;
    case 3:
        szkola();
        lokacja = 3;
        break;
    case 4:
        apteka();
        lokacja = 4;
        break;
    case 5:
        akcja_poczatkowa();
        break;
    }
}

static void eq(int b)//FUNKCJA
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



static void stats(int a)//FUNKCJA
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

void lotnisko()//FUNKCJA
{
    system("cls");
        int szansa = los();
        if (szansa >= 1 and szansa <= 1000) {
            walka();
            szansa = 0;
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
}

void komisariat()//FUNKCJA
{
    system("cls");

        int szansa = los();
        if (szansa >= 1 and szansa <= 450) {
            walka();
            szansa = 0;
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
}

void szkola() //FUNKCJA
{
    system("cls");
        int szansa = los();
        if (szansa >= 1 and szansa <= 300) {
            walka();
            szansa = 0;
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
}

void apteka() //FUNKCJA
{
    system("cls");
        int szansa = los();
        if (szansa >= 1 and szansa <= 300) {
            walka();
            szansa = 0;
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

void walka()  //FUNKCJA
{
    hp_zombie = 15;
    if (hp>0){
        system("cls");

        int wybor = -1;
        int szansa = 0;
        bool ucieczka = 0;

        std::cout << "Zostales zaatakowany!!!\n";

        Sleep(3000);

        while (hp_zombie > 0) {
            start:

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

                            if (hp_zombie<0){
                                hp_zombie = 0;
                            }
                            std::cout<<"Twoje HP: "<< hp << "/" << max_hp << std::endl;
                            std::cout << "hp przeciwnika: " << hp_zombie << "/" << maxhp_zombie << std::endl;

                            Sleep(6000);
                        }
                        else {
                            system("cls");

                            std::cout<<"Trafienie!"<<std::endl;

                            hp_zombie-=dmg;

                            if (hp_zombie<0){
                                hp_zombie = 0;
                            }
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

                    if (ucieczka==true){
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

                            ucieczka = false;
                            Sleep(3000);
                            system("cls");
                            goto start;
                        }
                    }
                    else {
                        system("cls");

                        std::cout<<"Probowales juz uciekac w tej turze!"<<std::endl;

                        Sleep(3000);
                        goto start;
                    }
                    break;
                case 3:
                    system("cls");

                        hp += leczenie;

                        std::cout << "Uleczyles " << leczenie << " punktow zycia!\n";

                        if (hp > max_hp) {
                            std::cout << "Zmarnowane hp: " << hp - max_hp << std::endl;

                            hp = max_hp;
                        }
                        std::cout << "Twoje hp: " << hp << "/"<< max_hp<< std::endl;

                        Sleep(3000);
                    break;
            };
            if(hp_zombie<=0){
            std::cout<<"Przeciwnik nie zyje!";

            Sleep(3000);

            system("cls");

                        switch (lokacja){
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
                        }
                        }
            else {
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

                        Sleep(6000);
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
            ucieczka = true;
            wybor = -1;

        }
        }
    }
    else {
        std::cout<<"Nie zyjesz!\n";
        std::cout<<"Koniec gry!";
    }

}

void przeszukanie()  //FUNKCJA
{
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

void cheaty() //FUNKCJA
{
    int kod = 0;
    std::cout<<"Podaj kod: ";
    std::cin>>kod;
        if (kod==8477){
            system("cls");
            int wybor = -1;
            std::cout<<"Witaj podrozniku!, jesli dotarles do tego miejsca oznacza to ze masz za soba ciezka droge a kroczac nia stoczyles wiele bitw.\n";
            Sleep(4500);
            std::cout<<"Twoj wysilek zostanie jednak wynagrodzony! Za chwile zobaczysz cos czego nikt inny przed toba nie widzial. Starozytni stworcy nazwali to zjawisko 'Menu Cheatow'\n";
            Sleep(3500);
            std::cout<<"\n";
            std::cout<<"Co chcesz zmienic?\n";
            std::cout<<"1.Wartosc leczenia\n";
            std::cout<<"2.Maksymalne hp\n";
            std::cout<<"3.Obrazenia\n";
            std::cout<<"4.Szansa trafienia bronia biala\n";
            std::cout<<"5.Szansa trafienia bronia palna\n";
            std::cout<<"6.Szansa na unik\n";
            std::cout<<"7.Obrona\n";
            std::cout<<"8.Obrazenia krytyczne\n";
            std::cout<<"9.Szansa na atak krytyczny\n";
            std::cout<<"10.ilosc drewna\n";
            std::cout<<"11.ilosc kamienia\n";
            std::cout<<"12.ilosc metalu\n";
            std::cout<<"13.ilosc pieniedzy\n";
        }
        else {
            system("cls");
            std::cout<<"Dziecko, idz do swojej piaskownicy\n";
            Sleep(2000);
            std::cout<<"TUTAJ BAWIA SIE DOROSLI";
            Sleep(1300);
            system("cls");
            akcja_poczatkowa();
        }
}
