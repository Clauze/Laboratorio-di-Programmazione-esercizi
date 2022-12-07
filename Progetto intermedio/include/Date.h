/**
 * @file Date.h
 * @brief Header Date
 * @author Anello Gioia,Claudio Battistin, Andrea Malvestio 
 * @date 2022-11-22
 * 
 */

#ifndef DATE
#define DATE
#include <iostream>

constexpr int MAXYEAR=2022;         /**<Anno massimo inseribile*/


/**
 * @brief Classe Date usata per la manipolazione delle date
 * 
 */

class Date
{
    public:
        /**
         * @brief Utilizzata come eccezione per data non valida
         * 
         */
        class InvalidDate{};

        /**
         * @brief Enum contentente tutti i mesi dell'anno 
         * 
         */
        enum Month{ 
            jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
        };

        /**
         * @brief Costruttore di default
         * 
         */
        Date()
        :year{1970}, month{jan}, day{1}
        {}

        /**
         * @brief Costruttore oggetto Date
         * @throw Genera l'eccezione InvalidDate se la data inserito non è valido
         * @param yy anno
         * @param mm mese
         * @param dd giorno
         */
        Date(int yy, Month mm, int dd)
        :year{yy}, month{mm}, day{dd}
        {
            if(!isValid()) throw InvalidDate();//genera eccezione se la data inserita non è valida
        }


        /**
         * @brief Operatore di stampa
         * @throw Genera l'eccezione InvalidDate se la data inserito non è valido
         * @param os 
         * @param data 
         * @return std::ostream& 
         */
        friend std::ostream& operator<<(std::ostream& os, const Date& data);

    private:
        int day;/**!<Giorno inserito */
        Month month;/**!<Mese inserito */
        int year;/**!< Anno inserito*/
        
        /**
         * @brief Determina se la data inserita è valida
         * 
         * @return true Se la data è valida
         * @return false Se la data non è valida
         */
        bool isValid();
};

#endif