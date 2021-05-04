#ifndef GARA_H
#define GARA_H
#include "veicolo.h"
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

class Gara
{
    int durata, n_partecipanti, n_iscritti;
    void controlla(int t);
    //init degli array dei veicoli
    Veicolo ** veicoli;

    public:

    Gara(int durata, int partecipanti) : durata(durata), n_partecipanti(n_partecipanti)
    {
        veicoli = new Veicolo*[n_partecipanti];
        n_iscritti = 0;
    }   
        //distruttore
        ~Gara()
        {
            delete [] veicoli;
        }
        void partenza();
        void stampa_classifica();
        void agg_partecipante(Veicolo& v);
};
#endif

void Gara::agg_partecipante(Veicolo& v)
{
    veicoli[n_iscritti ++] = &v;
}

void Gara::controlla(int t) 
{
    int max_temp = veicoli[0]->getVelocita();
    //oppure
    //int max_temp = -1;

    //segnamo l'indice del veicolo piu veloce
    int ind_max = 0;

    for(int i=1; i<n_iscritti; i++)
    {
        //estrarre la velocità di ogni veicolo e verificare chi è piu avanti
        //implementare algoritmo di ricerca, stampare ogni volta la classifica
        if(veicoli[i]->getVelocita() > max_temp)
        {
            max_temp = veicoli[i]->getVelocita();
            ind_max = i; //linea 27
        }
    }
 // std::cout << "Il veicolo piu veloce e' " << *veicoli[ind_max] << " e ha velocita' " << max_temp << std::endl;
}

void Gara::partenza()
{
    srand(time(NULL));
    for(int i=0; i<durata; i++)
    {
        for(int j=0; j<n_iscritti; j++)
        {
            int scelta = rand()%10;
            if(scelta >=0)
                veicoli[j]->accelera();
            else
                veicoli[j]->decelera();
        }
       this->controlla(i);
    }
    this->stampa_classifica();
}

/*int ordinato(int* x){
    
}*/

void swap(string *aro,int*arr,int i,int j){



	
    string t = aro[i];
    aro[i] =aro[j];
    aro [j] = t;
     int tt=arr[i];
    arr[i] =arr[j];
    arr [j] = tt;
   
}

void insertionsort(int *arr,string *aro, int n_iscritti)  {
 /*   for(int i=1; i<n; i++) {
        // inseriamo l'elemento i-esimo
        int j = i;
        while(j>0 && v[j]<v[j-1]) {
            swap(v,j,j-1);
            j--;
        }
    }
 */
    if(n_iscritti<=1) return;
    insertionsort(arr,aro,n_iscritti-1);
    int j=n_iscritti-1;
    while(j>0 && arr[j]>arr[j-1]) {
        swap(aro,arr,j,j-1);
        j--;
    }
}

void Gara::stampa_classifica()
{
   
    int* arr=new int[n_iscritti];
    string *aro=new string[n_iscritti];
    for (int i=0;i<n_iscritti;i++){
        arr[i]=veicoli[i]->getVelocita();
        aro[i]=veicoli[i]->getMarca()+" "+veicoli[i]->getMotorizzazione()+" "+veicoli[i]->getCarburante();
       
    }
  /*for(int i=0;i<n_iscritti;i++){
     	std::cout<<arr[i]<<" "<<aro[i]<<endl;
     }  
    insertionsort(arr,aro,n_iscritti);*/
   
    for(int i=0;i<n_iscritti;i++){
    	std::cout<<i+1<<" POSIZIONE: "<<aro[i]<<std::endl;
	}
/*for(int i=0;i<n_iscritti;i++){
	 	std::cout<<arr[i]<<std::endl;
	 }*/
	
}
 

