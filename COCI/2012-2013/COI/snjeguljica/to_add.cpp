using namespace std;
int TL;
inline void TLE () {
	if (TL <= clock() * 1000 / CLOCKS_PER_SEC)
    	exit(1);		
}
int main (int argc, char *argv[]) {
	TL = atoi(argv[1]);
    if (TLE()) {
    	exit (1);
    }
	exit (0);
}