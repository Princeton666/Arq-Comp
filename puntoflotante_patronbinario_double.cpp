#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;




string ConvertirBinario(int num)
{
    string binario = "";
    if (num > 0){
        while ( num > 0){
     if (num % 2 == 0){
                binario = "0" + binario;}
            else { binario = "1" + binario; }
      num = (int) num/2;}
    }
    else if (num == 0) {
        binario = "0";}
    return binario;
}




void Conversor32(double valor){

    int ParteEntera= (int)valor;
    double ParteDecimal= valor-ParteEntera;
    
    if(valor<0){
        ParteEntera=ParteEntera*-1;
        ParteDecimal=ParteDecimal*-1;}
    
    
    int signo[1]={};
    string entero;
    string decimal;
    
    //entero a binario
    //Exponente
    entero=ConvertirBinario(ParteEntera);

   //decimal a binario
   //23 bits
   //Significando
    for(int i=0;i<=52;i++){
        ParteDecimal=ParteDecimal*2;
        if(int(ParteDecimal)==1){
            decimal=decimal+"1";
            ParteDecimal=(ParteDecimal)-1;
        }
        else{
            decimal=decimal+"0";
        
        }
    }
    
    //Tamanio entero
    int tam=entero.size();
    
    //Signo
    //1 bit
    if(valor>0){
        signo[0]=0;
    }
    else{
        signo[0]=1;
    }
    

    
    //Valor Binario
    
    int n=11;
    int VB= (tam-1)+((pow(2,n-1))-1);
    string ValorBinario = ConvertirBinario(VB);
    
    
    


    //Imprimir
    cout<<"Antes del valor binario exponente"<<endl;
    cout<<signo[0]<<" ";
    cout<<entero[0];
    cout<<".";
    for(int i=1;i<=tam;i++){
        cout<<entero[i];
       }
    cout<<decimal;
    cout<<endl;
    cout<<endl;
    
    
    cout<<"Patron Binario"<<endl;
    cout<<signo[0]<<" ";
    cout<<ValorBinario<<" ";
    for(int i=1;i<=tam;i++){
        cout<<entero[i];
       }
    cout<<decimal;
    cout<<endl;
    
    
    
}







int main() {
    double a;
    cout<<"Ingrese un Valor double: ";
    cin>> a;
    Conversor32(a);
    
}