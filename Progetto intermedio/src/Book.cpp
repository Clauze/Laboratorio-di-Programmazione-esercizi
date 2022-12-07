/*
    Anello Gioia, Claudio Battistin, Andrea Malvestio
*/

#include <iostream>
#include "Book.h"

bool Book::prestito(){

    if(!this->stato) return false;      //se lo stato era già impostato come prestito, non faccio nulla
    else{
        this->stato = false;            //imposta lo stato in false per indicare che il libro è in prestito
        return true;                    //ritorna true per la corretta esecuzione dell'operazione
    }
}

bool Book::restituzione(){

    if(this->stato) return false;       //se lo stato era già impostato come disponibile, non faccio nulla
    else{
        this->stato = true;             //imposta lo stato in ture per indicare che il libro è disponibile
        return true;                    //ritorna true per la corretta esecuzione dell'operazione
    }
}

bool Book::operator==(const Book& libro){

    if(this->isbn==libro.isbn) return true;
    else return false;
}

bool Book::operator!=(const Book& libro){

    if(this->isbn!=libro.isbn) return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os, const Book& libro){

    os << "\n\n\t\tTitolo: " << libro.titolo << "\n\t\tAutore: " << libro.nome << " " << libro.cognome;

    if(libro.stato) os << "\n\t\tStato: disponibile"; 
    else os << "\n\t\tStato: in prestito";

    os << "\n\t\tData copyright: " << libro.dataCopyright << "\n\t\tISBN: " << libro.isbn; 

    return os;
}