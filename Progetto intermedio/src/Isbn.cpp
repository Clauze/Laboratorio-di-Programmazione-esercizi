/*
    Anello Gioia, Claudio Battistin, Andrea Malvestio
*/

#include "Isbn.h"

//gestisco Isbn passato come puntatore a un array di char
bool Isbn::isValidString(const char* isbn){
    int size=0;
    std::string s="";
    
    //calcolo la dimensione dell'Isbn
    while(isbn[size]!='\0') {
        size++;
    }
    
    //controllo che la dimensione dell'isbn sia di 13 char e che i campi siano divisi dal trattino
    if(size!=ISBN_LENGTH || isbn[3]!='-' || isbn[7]!='-' || isbn[11]!='-') return false;
    else {

        //controllo che i caratteri passati nelle tre terne siano solo numeri
        int i=0;
        while(i<(ISBN_LENGTH-2)) { 
            if(i==3 || i==7) i++;                    //nella posizione dei trattini incremento solo l'indice perche' gia' controllati
            if(isbn[i]>=48 && isbn[i]<=57) i++;      //se il carattere e' un numero tra 0 e 9 (codice ASCII) e' corretto e incremento l'indice
            else return false;                       //esce se uno dei caratteri nelle terne non e' un intero
        }
        
        //converto i caratteri controllati in interi usando il codice ASCII
        n1 = (isbn[0]-'0')*100 + (isbn[1]-'0')*10 + (isbn[2]-'0');
    	n2 = (isbn[4]-'0')*100 + (isbn[5]-'0')*10 + (isbn[6]-'0');
    	n3 = (isbn[8]-'0')*100 + (isbn[9]-'0')*10 + (isbn[10]-'0');
		
		//controllo con codice ASCII se l'ultimo carattere e' un numero o una lettera maiuscola o minuscola, se minuscola cambio in maiuscola
		if((isbn[12]>=48 && isbn[12]<=57) || (isbn[12]>=65 && isbn[12]<=90)) x = isbn[12];
		else if(isbn[12]>=97 && isbn[12]<=122) x = isbn[12]-32;
		else return false;
		
		return true;
	}
}

//gestisco Isbn passato come tre int e un char
bool Isbn::isValid(){

    //controllo che Isbn sia correttamente formattato con numeri di massimo 3 cifre
    if((n1<0 || n1>999) || (n2<0 || n2>999) || (n3<0 || n3>999)) return false;
    
    //controllo con codice ASCII che l'ultimo carattere sia un numero o una lettera (maiuscola o minuscola)
    if(x<48 || (x>57 && x<65) || (x>90 && x<97) || x>122) return false;
    
    //se l'ultimo carattere e' una lettera minuscola cambio in maiuscola (codice ASCII)
    if(x>=97 && x<=122) x = x-32;

    return true;        //ritorna true se l'Isbn e' valido
}

bool Isbn::operator==(const Isbn& code){

    if((this->n1 == code.n1) && (this->n2 == code.n2) && (this->n3 == code.n3) && (this->x == code.x)) return true;
    else return false;
}

bool Isbn::operator!=(const Isbn& code){

    if((this->n1 != code.n1) || (this->n2 != code.n2) || (this->n3 != code.n3) || (this->x != code.x)) return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os, const Isbn& isbn){

    if(isbn.n1>=0 && isbn.n1<=9) os << "00" << isbn.n1;             //aggiungo 2 zeri se il numero ha una sola cifra
    else if(isbn.n1>=10 && isbn.n1<=99) os << "0" << isbn.n1;       //aggiungo 1 zero se il numero ha 2 cifre
    else os << isbn.n1;

    if(isbn.n2>=0 && isbn.n2<=9) os << "-00" << isbn.n2;            //aggiungo 2 zeri se il numero ha una sola cifra
    else if(isbn.n2>=10 && isbn.n2<=99) os << "-0" << isbn.n2;      //aggiungo 1 zero se il numero ha 2 cifre
    else os << "-" << isbn.n2;

    if(isbn.n3>=0 && isbn.n3<=9) os << "-00" << isbn.n3;            //aggiungo 2 zeri se il numero ha una sola cifra
    else if(isbn.n3>=10 && isbn.n3<=99) os << "-0" << isbn.n3;      //aggiungo 1 zero se il numero ha 2 cifre
    else os << "-" << isbn.n3;

    return os << "-" << isbn.x << "\n";
}