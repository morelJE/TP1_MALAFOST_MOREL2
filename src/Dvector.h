M#ifndef DVECTOR_H_
#define DVECTOR_H_
//!
//! \file Dvector.h
//! \brief fichier contenant la classe Dvector
//! \author morel2-malafost
//!

#include <iostream>
using namespace std;


//! \class Dvector
//! \brief classe implémentant des vecteurs et les opérations allant avec

class Dvector
{
private:

    double *pCor; //!<tableau de double, contenant les données du vecteur, alloué dynamiquement

public:

    int taille; //!<taille du tableau

    //! \brief constructeur par défaut de Dvector

    Dvector();

    //! \brief accesseur pour le paramètre taille
    //! \return entier contenant la taille
    int size();

    //! \brief constructeur par copie
    //! \param V : Un Dvector passé par référence
    Dvector(const Dvector & V);

    //! \brief constructeur avec paramètres
    //! \param s : entier contenant la taille;
    //! \param p (optionnel) : double servant à initialiser les valeurs du tableau
    Dvector(int s,double p = 0);

    //! \brief constructeur à partir d'une chaine
    //! \param string : chaîne de caractère passée par référence, contenant des caractères qui seront tradutis en ASCII dans le tableau
    Dvector(std::string&);

    //! \brief affichage des données du tableau sur un flux
    //! \param str : flux sur lequel sera affiché le contenu du tableau, par exemple std::cout
    void display(std::ostream& str);

    //! \brief rempli un vecteur par des nombres aléatoires
    void fillRandomly();

    //! \brief destructeur pour la classe Dvector
    ~Dvector();

    //! \brief Surcharge de l'opérateur d'accession par écriture et lecture
    //! \param i : entier par référence, correspond à l'élément du tableau auquel on va accèder. nb : l'indexage commence à 1 (au lieu de 0 pour les indices du tableau)
    //! \return l'adresse du double contenant la valeur attendue, il peut donc servir en écriture et en lecture
    double& operator ()(const int& i) const;

    //! \brief Surcharge de l'opérateur +, pour additionner un double à tous les éléments du tableau
    //! \param o : double contenant la valeur à ajouter
    //! \return le nouveau Dvector résultant de l'addition
    Dvector operator +(double o);

    //! \brief Surcharge de l'opérateur -, pour soustraire un double à tous les éléments du tableau
    //! \param o : double contenant la valeur à soustraire
    //! \return le nouveau Dvector résultant de la soustraction
    Dvector operator -(double o);

    //! \brief Surcharge de l'opérateur *, pour  multiplier par un double tous les éléments du tableau
    //! \param o : double contenant le multiplicateur
    //! \return le nouveau Dvector résultant de la multiplication
    Dvector operator *(double o);

    //! \brief Surcharge de l'opérateur /, pour diviser par un double tous les éléments du tableau
    //! \param o : double contenant le diviseur
    //! \return le nouveau Dvector résultant de la division
    Dvector operator /(double o);

    //! \brief Surcharge de l'opérateur +, pour additionner 2 tableaux membre par membre.
    //! \param n : Le membre gauche de l'addtion
    //! \param v : Le membre droit de l'addtion
    //! \return le nouveau Dvector résultant de l'addition
    friend Dvector operator +(const Dvector& n, const Dvector& v);

    //! \brief Surcharge de l'opérateur +, pour soustraire 2 tableaux membre par membre.
    //! \param n : Le membre gauche de la soustraction
    //! \param v : Le membre droit de la soustraction
    //! \return le nouveau Dvector résultant de la soustraction
    friend Dvector operator -(const Dvector& n, const Dvector& v);

    //! \brief Surcharge de l'opérateur - unaire
    //! \return l'inverse membre par membre du tableau
    Dvector operator -();

    //! \brief Surcharge de l'opérateur >>, décalant le tableau vers la droite
    //! \param o : taille du décalage
    //! \return le tableau décalé
    Dvector operator >>(double o);

    //! \brief Surcharge de l'opérateur <<, décalant le tableau vers la gauche
    //! \param o : taille du décalage
    //! \return le tableau décalé
    Dvector operator <<(double o);

    //! \brief Surcharge de l'opérateur +=
    //! \param o : L'entier a additionner à chaque membre du tableau
    //! \return le nouveau Dvector résultant de l'addition
    Dvector operator +=(double o);

    //! \brief Surcharge de l'opérateur -=
    //! \param o : L'entier a soustraire à chaque membre du tableau
    //! \return le nouveau Dvector résultant de la soustraction
    Dvector operator -=(double o);

    //! \brief Surcharge de l'opérateur *=
    //! \param o : L'entier a multiplier à chaque membre du tableau
    //! \return le nouveau Dvector résultant de la multiplication
    Dvector operator *=(double o);

    //! \brief Surcharge de l'opérateur /=
    //! \param o : L'entier a diviser à chaque membre du tableau
    //! \return le nouveau Dvector résultant de la division
    Dvector operator /=(double o);

    //! \brief Surcharge de l'opérateur d'affectation
    //! \param V : le Dvector que l'on affecte
    //! \return le nouveau Dvector résultant de l'affectation
    Dvector operator =(const Dvector &V);

    //! \brief Surcharge de l'opérateur d'égalité ==
    //! \param v : le membre gauche
    //! \param n : le membre droit
    //! \return le booleén qui dit si les 2 tableaux sont égaux ou non
    friend bool operator ==(const Dvector& n, const Dvector& v);

    //! \brief fonction changeant la taille d'un Dvector.
    //! \param taille : la nouvelle taille du tableau
    //! \param valeur (optionnel) : si on agrandit le tableau, la valeur à la quelle seront initialiser les cases
    //! \return le Dvector de la bonne taille
    Dvector resize(int taille, double valeur = 0.);
};

#endif
