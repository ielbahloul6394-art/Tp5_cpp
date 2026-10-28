#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;
    static int nbUtilisateursConnectes;

public:
    Utilisateur(string n, string r) {
        nom = n;
        role = r;
        nbUtilisateursConnectes++;
    }

    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }
};

int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Nombre connectes : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u1 = new Utilisateur("Imane", "admin");
    cout << "Apres connexion de u1 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u2 = new Utilisateur("Sara", "visiteur");
    cout << "Apres connexion de u2 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur* u3 = new Utilisateur("Yassine", "visiteur");
    cout << "Apres connexion de u3 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    delete u2;
    cout << "Apres deconnexion de u2 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    delete u1;
    cout << "Apres deconnexion de u1 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    delete u3;
    cout << "Apres deconnexion de u3 : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}