#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


string l[] = {"movies", "actors", "singers", "brands", "physics", "anime", "cities"};


vector <string> themes[7];
int used[256];

void words () {
	themes[0] = {"THE GODFATHER", "THE SHAWSHANK REDEMPTION", "SCHINDLERS LIST", "ZOOTOPIA", "HELL OR HIGH WATER", "MOANA", "KUBO", "FINDING DORY", "TWILIGHT", "50 SHADES OF GREY"};
	themes[1] = {"MARTIN FREEMAN", "KEANU REEVES", "ANGELINA JOLIE", "BRAD PITT", "BENEDICT CUMBERBATCH", "EMILIA CLARKE", "JOHNNY DEPP", "TOM CRUISE", "LIAM NEESON", "SCARLETT JOHANSSON"};
	themes[2] = {"MILEY CYRUS", "JUSTIN BIEBER", "BRUNO MARS", "MARLIN MENSON", "ELVIS PRESLEY", "ELTON JOHN", "SELENA GOMEZ", "NICKI MINAJ", "EMINEM", "SIA"};
	themes[3] = {"GUCCI", "LOUIS VUITON", "CHANEL", "APPLE", "YAHOO", "PRADA", "KFC", "MERCEDES", "ASUS"};
	themes[4] = {"KINEMATICS", "DINAMICS", "NEWTON", "VECTOR", "SCALAR", "JOULE", "TESLA", "WATT", "OHM", "AMPERE"};
	themes[5] = {"NARUTO", "PARASYTE", "TOKYO GHOUL", "ATTACK ON TITAN", "DEATH NOTE", "FAIRY TAIL", "NORAGAMI", "BLEACH", "SHAMAN KING", "BLACK BUTLER"};
	themes[6] = {"TOKYO", "SEOUL", "ASTANA", "ALMATY", "LONDON", "PARIS", "MADRID", "BRAZILIA", "WASHINGTON", "ZHEZKAZGAN"};
}




void START_THE_FGAME (int theme) {
	int seed = rand () % 10;
	string a;
	for (int i = 0; i < themes[theme][seed].size (); ++i) {
		if ('A' <= themes[theme][seed][i] && themes[theme][seed][i] <= 'Z')
			a += '_';
		else
			a += themes[theme][seed][i];
	}
	for (int i = 0; i < 256; ++i)
		used[i] = 0;
	int hp = 5;
	while (1) {
		int oops = 0;
		for (int i = 0; i < themes[theme][seed].size (); ++i) {
			oops += (a[i] == '_');
		}
		if (oops == 0)
			break;
		char t;
		
		cout << "\n";

		for (int i = 0; i < a.size (); ++i)

			cout << a[i] << " ";
		cout << "\n";
		cout << "Input character: ";
		cin >> t;

		if (used[t]) {
			cout << "Already tried\n";
			continue;
		}
		used[t] = 1;
		int cnt = 0;
		for (int i = 0; i < themes[theme][seed].size (); ++i) {
			if (themes[theme][seed][i] == t)
				++cnt, a[i] = themes[theme][seed][i];
		}
		if (cnt == 0)
			--hp;
		if (hp == 4) {
		    cout << ".....\n";
			cout << ".....\n";
			cout << ".....\n";
			cout << ".....\n";
			cout << "..^..\n";
			}
		if (hp == 3) {
		   
		    cout << ".....\n";
			cout << ".....\n";
			cout << ".....\n";
			cout << "..|..\n";
			cout << "..^..\n";
			}
		if (hp == 2) {
		    
		    cout << ".....\n";
			cout << ".....\n";
			cout << "._-_.\n";
			cout << "..|..\n";
			cout << "..^..\n";
               }               
        if (hp == 1) {

            
		    cout << ".....\n";
			cout << "..O..\n";
			cout << "._-_.\n";
			cout << "..|..\n";
			cout << "..^..\n";
			     }
 

     	if (hp == 0) {
			cout << "YOU ARE DEAD\n";
			cout << "..|..\n";
			cout << "..O..\n";
			cout << "._-_.\n";
			cout << "..|..\n";
			cout << "..^..\n";

			return;
		}
	
	}
	cout << "CONGRATULATIONS, YOU WON!!!\n";

}	

int main () {

	srand (time (0));
	words ();
	
	while (1) {
		cout << "Choose category or print help to list them\n";
		string q;
		cin >> q;
		if (q == "help") {
			for (int i = 0; i < 7; ++i) {
				cout << l[i] << " ";
			}
			cout << "\n";
			continue;                                      
		}
		for (int i = 0; i < 7; ++i) {
			if (q == l[i]) {
				START_THE_FGAME (i);
			}
		}
	}


	return 0;
}