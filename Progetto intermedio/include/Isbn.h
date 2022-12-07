/**
 * @file Isbn.h
 * @brief Header Isbn 
 * @author Anello Gioia, Claudio Battistin, Andrea Malvestio
 * @date 2022-11-22
 * 
 */

#ifndef ISBN
#define ISBN
#include <iostream>

constexpr int ISBN_LENGTH=13;       /**< Lunghezza di un isbn*/
/**
 * @brief Classe Isbn usata per la gestione dell'isbn di un libro
 * 
 */
class Isbn
{
    private:
        int n1;     /**< Prima terna di numeri dell'isbn*/
        int n2;     /**< Seconda terna di numeri dell'isbn*/
        int n3;     /**< Terza terna di numeri dell'isbn*/
        char x;     /**< Ultimo carattere dell'isbn*/

        /**
         * @brief Determina se il codice Isbn è valido partendo da 3 int e un char
         * @throw Genera l'eccezione InvalidIsbn se il codice inserito non è valido
         * @return true Se il codice è valido
         * @return false Se il codice non è valido
         */
        bool isValid();

        /**
         * @brief Determina se il codice Isbn e' valido partendo da puntatore a un array di char
         * 
         * @return true Se il codice e' valido
         * @return false Se il codice non e' valido
         */
        bool isValidString(const char* isbn);
        
    public:
        /**
         * @brief Utilizzata come eccezione per Isbn non valido
         * 
         */
        class InvalidIsbn{};

        /**
         * @brief Costruttore di defult Isbn. 
         * 
         */
        Isbn()
            : n1{0}, n2{0}, n3{0}, x{'0'}
        {}

        /**
         * @brief Costruttore Isbn. 
         * 
         * Crea un nuovo oggetto Isbn da 3 int e un char
         * @param v1 Prima terna di numeri dell'isbn
         * @param v2 Seconda terna di numeri dell'isbn
         * @param v3 Terza terna di numeri dell'isbn
         * @param val Ultimo carattere dell'isbn
         */
        Isbn(int v1, int v2, int v3, char val)
            : n1{v1}, n2{v2}, n3{v3}, x{val}
        {
            if(!isValid()) throw InvalidIsbn();     //genera eccezione se l'Isbn inserito non e' valido
        }

        /**
         * @brief Costruttore Isbn. 
         * 
         * Crea un nuovo oggetto Isbn partendo da puntatore a un array di char
         * @param isbn Stringa di lunghezza uguale a quella di isbn
         */
        Isbn(const char* isbn)
        {
            if(!isValidString(isbn)) throw InvalidIsbn();      //genera eccezione se l'Isbn inserito non e' valido
        }
        
        /**
         * @brief Operatore di equivalenza
         * 
         * @param code Codice Isbn di un altro libro
         * @return true Se i 2 codici sono uguali
         * @return false Se i 2 codici sono diversi
         */
        bool operator==(const Isbn& code);

         /**
         * @brief Operatore diverso
         * 
         * @param code Codice Isbn di un altro libro
         * @return true Se i 2 codici sono diversi
         * @return false Se i 2 codici sono uguali
         */
        bool operator!=(const Isbn& code);

        /**
         * @brief Operatore di stampa
         * 
         * @param os 
         * @param isbn 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const Isbn& isbn);
};

#endif