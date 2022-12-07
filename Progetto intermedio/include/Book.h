/**
 * @file Book.h
 * @brief Header Book 
 * @author Anello Gioia, Claudio Battistin, Andrea Malvestio
 * @date 2022-11-22
 * 
 */

#ifndef BOOK
#define BOOK
#include <iostream>
#include "Date.h"
#include "Isbn.h"

/**
 * @brief Classe Book usata per la gestione di un libro
 * 
 */
class Book
{
    private:
        Isbn isbn;                  /**< Codice identificativo del libro*/
        std::string titolo;         /**< Titolo del libro*/
        std::string nome;           /**< Nome autore*/
        std::string cognome;        /**< Cognome autore*/
        Date dataCopyright;         /**< Data copyright*/
        bool stato;                 /**< Stato del libro(true se disponibile o false se in prestito)*/

    public:
        /**
         * @brief Costruttore di default
         * 
         */
        Book()
            : titolo{""}, nome{""}, cognome{""}, stato{true}, dataCopyright{Date()}, isbn{Isbn()}
        {}

        /**
         * @brief Costruttore con parametri e Isbn passato come oggetto
         * 
         * @param nom nome autore
         * @param cog cognome autore
         * @param tit titolo libro
         * @param sta stato del libro
         * @param dataCop data copyright
         * @param i codice identificativo libro isbn
         */
        Book(const std::string& nom, const std::string& cog, const std::string& tit, bool sta, Date dataCop, Isbn i)
            : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{i}
        {}

        /**
         * @brief Costruttore con parametri e Isbn passato come puntatore char
         * 
         * @param nom nome autore
         * @param cog cognome autore
         * @param tit titolo libro
         * @param sta stato del libro
         * @param dataCop data copyright
         * @param is codice identificativo libro isbn
         */
        Book(const std::string& nom, const std::string& cog, const std::string& tit, const char* is = "000-000-000-0", bool sta = true, Date dataCop = Date())
            : titolo{tit}, nome{nom}, cognome{cog}, stato{sta}, dataCopyright{dataCop}, isbn{Isbn{is}}
        {}
        
        /**
         * @brief Ritorna titolo del libro
         * 
         * @return nome del libro 
         */
        std::string getTitolo(){ return this->titolo; }

        /**
         * @brief Ritorna nome autore del libro
         * 
         * @return nome autore
         */
        std::string getNome() { return this->nome; }

        /**
         * @brief Ritorna cognome autore del libro
         * 
         * @return cognome autore
         */
        std::string getCognome(){ return this->cognome; }

        /**
         * @brief Ritorna lo stato del libro
         * 
         * @return true Se il libro e' disponibile
         * @return false Se il libro e' prestito
         */
        bool getStato() { return this->stato; }

        /**
         * @brief Imposta il prestito del libro
         * 
         * @return true Se e' possibile impostare il prestito del libro
         * @return false Se non e' possibile impostare il prestito del libro
         */
        bool prestito();

        /**
         * @brief Imposta la restituzione dal prestito del libro
         * 
         * @return true Se e' possibile impostare la restituzione del libro
         * @return false Se non e' possibile impostare la restituzione del libro
         */
        bool restituzione();

        /**
         * @brief Operatore di equivalenza
         * 
         * @param libro Libro da confrontare
         * @return true Se i libri sono uguali
         * @return false Se i libri sono diversi
         */
        bool operator==(const Book& libro);

        /**
         * @brief Operatore diverso
         * 
         * @param libro Libro da confrontare
         * @return true Se i libri sono diversi
         * @return false Se i libri sono uguali
         */
        bool operator!=(const Book& libro);

        /**
         * @brief Operatore di stampa
         * 
         * @param os 
         * @param libro 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const Book& libro);
};

#endif