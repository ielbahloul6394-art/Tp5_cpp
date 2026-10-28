#include <iostream>
using namespace std;

class Boite {
private:
    double longueur;
    double largeur;
    double hauteur;

    static int nbBoites;

public:
    Boite(double l, double la, double h) {
        longueur = l;
        largeur = la;
        hauteur = h;
        nbBoites++;
    }

    ~Boite() {
        nbBoites--;
    }

    static int getNombreBoites() {
        return nbBoites;
    }
};

int Boite::nbBoites = 0;

int main() {
    Boite b1(10, 5, 3);
    Boite b2(8, 4, 2);
    Boite b3(6, 3, 2);

    cout << "Nombre de boites : "
         << Boite::getNombreBoites() << endl;

    return 0;
}