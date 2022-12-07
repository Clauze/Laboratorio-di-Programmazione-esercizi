/*
    Anello Gioia, Claudio Battistin, Andrea Malvestio
*/

#include "Date.h"

bool Date::isValid(){
    
    //controllo che l'anno sia minore dell'anno corrente
    if(year > MAXYEAR) return false;

    //controllo che il mese sia compreso tra 1 e 12
    if(month<1 || month>12) return false;
    
    //controllo se l'anno è bisestile
    else if(month==2){
        if( year%4==0 || (year%100==0 && year%400==0)) {
            if(day<1 || day >29) return false;
        }
        else {
            if(day<1 || day>28) return false;
        }
    }

    //divido i mesi in 2 categorie per controllare che sia stato inserito il numero corretto di giorni per ogni mese
    else if(month<=7){                              //nei mesi da 1 a 7 solo i dispari hanno 31 giorni
        if(month%2!=0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }
    else{                                           //nei mesi da 8 a 12 solo i pari hanno 31 giorni
        if(month%2==0){
            if(day<1 || day>31) return false;
        }
        else{
            if(day<1 || day>30) return false;
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& os, const Date& data) {

    return os << data.day << "/" << data.month << "/" << data.year;
}