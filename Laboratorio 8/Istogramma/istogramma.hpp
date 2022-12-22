#ifndef istogramma_hpp
#define istogramma_hpp

istogramma::istogramma(string file)
{
    ifstream myfile (file);
	if(myfile.is_open()){
        string s;
        while(getline(myfile,s)){
            for (size_t i = 0; i < s.size(); i++)
            {
                isto[s[i]]++;
            }
            
        }
        printIsto();
    }
}


void istogramma::printIsto(){
    for (char i = 65; i < 90; i++)
    {
        if(isto[i]!=0){
            cout<<"\n"<<i<<" valore: "<<isto[i];
        }
    }
    for (char i = 97; i < 122; i++)
    {
        if(isto[i]!=0){
            cout<<"\n"<<i<<" valore: "<<isto[i];
        }
    }
    
}

#endif