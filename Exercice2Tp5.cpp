#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    float prixHT;
    static float tauxTVA;

public:
    Produit(string n, float prix) {
        nom = n;
        prixHT = prix;
    }

    float getPrixTTC() {
        return prixHT * (1 + tauxTVA / 100);
    }

    static void modifierTVA(float nouveauTaux) {
        tauxTVA = nouveauTaux;
    }

    void afficher() {
        cout << "Produit : " << nom << endl;
        cout << "Prix TTC : " << getPrixTTC() << " DH" << endl;
    }
};

float Produit::tauxTVA = 20.0;

int main() {
    Produit p1("Ordinateur", 5000);
    Produit p2("Telephone", 2000);
    Produit p3("Clavier", 300);

    cout << "--- TVA initiale : 20% ---" << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    Produit::modifierTVA(10);

    cout << "\n--- TVA modifiee : 10% ---" << endl;
    p1.afficher();
    p2.afficher();
    p3.afficher();

    return 0;
}