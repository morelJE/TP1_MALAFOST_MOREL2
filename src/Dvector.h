#ifndef DVECTOR_H_
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

    friend Dvector operator +(const Dvector& n, const Dvector& v);

    friend Dvector operator -(const Dvector& n, const Dvector& v);

    Dvector operator -();

    Dvector operator >>(double o);

    Dvector operator <<(double o);

    Dvector operator +=(double o);

    Dvector operator -=(double o);

    Dvector operator *=(double o);

    Dvector operator /=(double o);

    Dvector operator =(const Dvector &V);

    friend bool operator ==(const Dvector& n, const Dvector& v);

    Dvector resize(int taille, double valeur = 0.);
};

#endif
