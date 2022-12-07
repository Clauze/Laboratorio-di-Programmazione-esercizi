/*
    Anello Gioia, Claudio Battistin, Andrea Malvestio
*/

#include "Book.h"
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    
    cout << "\n TEST DATE";
    
    try {
        Date data {2022, Date::Month::aug, 31};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 31/8/2022";
    }
    
    try {
        Date data {1462, Date::Month::jan, -5};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> -5/1/1462";
    }

    try {
        Date data {2015, Date::Month::jun, 31};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 31/6/2015";
    }
    
    try {
        Date data {2009, (Date::Month)13, 26};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 26/13/2009";
    }
    
    try {
        Date data {2023, (Date::Month)3, 31};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 31/3/2023";
    }
    
    try {
        Date data {1834, (Date::Month)9, 56};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 56/9/1834";
    }

    try {
        Date data {2021, Date::Month::feb, 29};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 29/2/2021";
    }
    
    try {
        Date data {2000, (Date::Month)2, 29};
        cout << "\n\n\t Data valida: " << data;
    }
    catch(Date::InvalidDate){
        cerr << "\n\n\t Data non valida!\n\t  --> 29/2/2000";
    }
    
    cout << "\n\n\n--------------------------------------------------------------------------------------";
    cout << "\n\n TEST ISBN";
    
    try {
        Isbn i {9, 561, 150, 't'};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 9-561-150-T";
    }

    try {
        Isbn i {9, 561, 150, '-'};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\t ISBN non valido!\n\t  --> 9-561-150--";
    }

    try {
        Isbn i {2000, 758, 1, '5'};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 2000-758-1-5";
    }

    try {
        Isbn i {"012-569-005-D"};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 012-569-005-D";
    }

    try {
        Isbn i {"35u-456-005-l"};
        cout << "\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\t ISBN non valido!\n\t  --> 35u-456-005-l";
    }
    
    try {
        Isbn i {"3564-456-45-l"};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 3564-456-45-l";
    }
    
    try {
        Isbn i {"356456453l"};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 356456453l";
    }
    
    try {
        Isbn i {"3564564-053-l"};
        cout << "\n\n\t ISBN valido: " << i;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\n\t ISBN non valido!\n\t  --> 3564564-053-l";
    }
    
    cout << "\n\n\n--------------------------------------------------------------------------------------";
    cout << "\n\n TEST PRESTITO e RESTITUZIONE";

    try{
        Book b2 {"Marco", "Rossi", "c++", true, Date{2000,Date::Month::feb,29}, Isbn{9,561,150,'Z'}};
        
        cout << "\n\n\n\t Con libro disponibile" << b2;

        if(b2.restituzione()){
            cout << "\t\tRichiesta RESTITUZIONE\n\t\t   --> Libro correttamente restituito.";
        }
        else cout << "\n\n\t\tRichiesta RESTITUZIONE\n\t\t   --> Restituzione fallita! Libro gia' disponibile.";
        
        if(b2.prestito()){
            cout << "\n\n\t\tRichiesta PRESTITO\n\t\t   --> Libro correttamente preso in prestito.";
        }
        else cout << "\n\n\t\tRichiesta PRESTITO\n\t\t   --> Impossibile effettuare il prestito. Libro non disponibile!";

        if(b2.restituzione()){
            cout << "\n\n\t\tRichiesta RESTITUZIONE\n\t\t   --> Libro correttamente restituito.";
        }
        else cout << "\n\n\t\tRichiesta RESTITUZIONE\n\t\t   --> Restituzione fallita! Libro gia' disponibile.";
    }
    catch(Date::InvalidDate){
        cerr << "\n\t Data non valida!";
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\t ISBN non valido!";
    }

    try{
        Book b{"Luigi", "Verdi", "g++", false, Date{2015,Date::Month::nov,14}, Isbn{056,4,15,'6'}};

        cout << "\n\n\n\n\t Con libro in prestito" << b;

        if(b.prestito()){
            cout << "\t\tRichiesta PRESTITO\n\t\t   --> Libro correttamente preso in prestito.";
        }
        else cout << "\n\n\t\tRichiesta PRESTITO\n\t\t   --> Impossibile effettuare il prestito! Libro non disponibile.";

        if(b.restituzione()){
            cout << "\n\n\t\tRichiesta RESTITUZIONE\n\t\t   --> Libro correttamente restituito.";
        }
        else cout << "\n\n\t\tRichiesta RESTITUZIONE\n\t\t   --> Restituzione fallita! Libro gia' disponibile.";

        if(b.prestito()){
            cout << "\n\n\t\tRichiesta PRESTITO\n\t\t   --> Libro correttamente preso in prestito.";
        }
        else cout << "\n\n\t\tRichiesta PRESTITO\n\t\t   --> Impossibile effettuare il prestito! Libro non disponibile.";
    }
    catch(Date::InvalidDate){
        cerr << "\n\t Data non valida!";
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\t ISBN non valido!";
    }

    cout << "\n\n\n--------------------------------------------------------------------------------------";
    cout << "\n\n TEST operator== e operator!=\n";
    
    try {
        Isbn i1 {56,58,789,'r'};
        Isbn i2 {89,560,7,'H'};
        Isbn i3 {"089-560-007-h"};

        Book b1{"Mario", "Di Bianco", "Ciao 123", false, Date{1958,Date::Month::oct,31}, i1};
        Book b2{"Carlo", "Bianchi", "Informatica",true, Date{1498,Date::Month::may,22}, i2};
        Book b3{"Carlo", "Bianchi", "Informatica",true, Date{1498,Date::Month::may,22}, i3};

        cout << "\n\n\t --> Libro n1:" << b1;
        cout << "\n\n\t --> Libro n2:" << b2;
        cout << "\n\n\t --> Libro n3:" << b3;

        if(b1==b2) cout << "\n\n\t --> Libri n1 e n2 uguali!\n\t\t\tISBN libro n1: " << i1 << "\t\tISBN libro n2: " << i2;
        else cout << "\n\n\t --> Libri n1 e n2 diversi!\n\t\tISBN libro n1: " << i1 << "\t\tISBN libro n2: " << i2;
        
        if(b2!=b3) cout << "\n\n\t --> Libri n2 e n3 diversi!\n\t\tISBN libro n2: " << i2 << "\t\tISBN libro n3: " << i3;
        else cout << "\n\n\t --> Libri n2 e n3 uguali!\n\t\tISBN libro n2: " << i2 << "\t\tISBN libro n3: " << i3;
    }
    catch(Date::InvalidDate){
        cerr << "\n\tData non valida!";
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\tISBN non valido!";
    }
    
    cout << "\n\n\n--------------------------------------------------------------------------------------";

    vector<Book> shelf(10);

    try{
        Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "999-999-150-Z");
        cout << "\n\n IL MIO LIBRO PREFERITO" << my_favourite_book;
    }
    catch(Isbn::InvalidIsbn){
        cerr << "\n\tISBN non valido!";
    }
    
    cout<<"\n\n";

    return 0;
}
