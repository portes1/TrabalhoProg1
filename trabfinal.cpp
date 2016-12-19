#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <vector>
#include "split.hpp"
#include "calculaDistancia.hpp"
#include <iomanip>

using namespace std;

struct Cidade{
    double lat1, lon1;
    double lat2, lon2;
    double lat3, lon3;
    double lat4, lon4;
};

void abreArqCep(int cep1, int cep2, int cep3, int cep4){
    Cidade cidade;
    bool achou1 = false;
    bool achou2 = false;
    bool achou3 = false;
    bool achou4 = false;
    string nomeCidade1,nomeCidade2,nomeCidade3,nomeCidade4;
    fstream arq;
    string linha;
    arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto= split(linha, ';');
        int cepInicial = atoi(texto[1].c_str());
        int cepFinal = atoi(texto[2].c_str());
        if(cep1 >= cepInicial && cep1 <= cepFinal){
            achou1 = true;
            cout << texto[0] << "-" << texto[3] << endl;
            if (achou1 == true){
                nomeCidade1 = texto[0];
            }
            break;
        }

    }
    arq.close();

    arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto2= split(linha, ';');
        int cepInicial = atoi(texto2[1].c_str());
        int cepFinal = atoi(texto2[2].c_str());
        if(cep2 >= cepInicial && cep2 <= cepFinal){
        achou2 = true;
        cout << texto2[0] << "-" << texto2[3] << endl;
        if (achou2 == true){
                nomeCidade2 = texto2[0];
        }
        break;
        }

    }
    arq.close();
    
     arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto2= split(linha, ';');
        int cepInicial = atoi(texto2[1].c_str());
        int cepFinal = atoi(texto2[2].c_str());
        if(cep3 >= cepInicial && cep3 <= cepFinal){
        achou3 = true;
        cout << texto2[0] << "-" << texto2[3] << endl;
        if (achou3 == true){
                nomeCidade3 = texto2[0];
        }
        break;
        }

    }
    arq.close();
    
    arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto2= split(linha, ';');
        int cepInicial = atoi(texto2[1].c_str());
        int cepFinal = atoi(texto2[2].c_str());
        if(cep4 >= cepInicial && cep4 <= cepFinal){
        achou4 = true;
        cout << texto2[0] << "-" << texto2[3] << endl;
        if (achou4 == true){
                nomeCidade4 = texto2[0];
        }
        break;
        }

    }
    arq.close();

    dbggg:
    if (!achou2) cout << "CEP nao encontrado!!" << endl;
    cout << nomeCidade1 << " - " << nomeCidade2<< " - " << nomeCidade3 << endl;

    double lat1, lon1, lat2, lon2, lat3, lon3, lat4, lon4;
    
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');

        if(!nomeCidade1.compare(v[3]) ){
            lat1 = atof(v[1].c_str());
            lon1 = atof(v[2].c_str());
        }
    }
    arq.close();
      
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');


        if(!nomeCidade2.compare(v[3]) ){
            lat2 = atof(v[1].c_str());
            lon2 = atof(v[2].c_str());
        }
    }
    arq.close();
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');


        if(!nomeCidade3.compare(v[3]) ){
            lat3 = atof(v[1].c_str());
            lon3 = atof(v[2].c_str());
        }
    }
    arq.close();
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');

        if(!nomeCidade4.compare(v[3]) ){
            lat4 = atof(v[1].c_str());
            lon4 = atof(v[2].c_str());
        }
    }
    arq.close();
    double pi = 3.1415926536;
    cidade.lat1 = lat1 * pi/180;
    cidade.lon1 = lon1 * pi/180;
    cidade.lat2 = lat2 * pi/180;
    cidade.lon2 = lon2 * pi/180;
    cidade.lat3 = lat3 * pi/180;
    cidade.lon3 = lon3 * pi/180;
    cidade.lat4 = lat4 * pi/180;
    cidade.lon4 = lon4 * pi/180;
    cout << "A distancia entre, " <<nomeCidade1 << " e " <<nomeCidade2 <<" é: " << calculaDistancia(cidade.lat1, cidade.lon1, cidade.lat2, cidade.lon2) << " KM"<< endl;
    cout << "A distancia entre, " <<nomeCidade1 << " e " <<nomeCidade3 <<" é: " << calculaDistancia(cidade.lat1, cidade.lon1, cidade.lat3, cidade.lon3) << " KM"<< endl;
    cout << "A distancia entre, " <<nomeCidade1 << " e " <<nomeCidade4 <<" é: " << calculaDistancia(cidade.lat1, cidade.lon1, cidade.lat4, cidade.lon4) << " KM"<< endl;
    cout << "A distancia entre, " <<nomeCidade2 << " e " <<nomeCidade3 <<" é: " << calculaDistancia(cidade.lat2, cidade.lon2, cidade.lat3, cidade.lon3) << " KM"<< endl;
    cout << "A distancia entre, " <<nomeCidade2 << " e " <<nomeCidade4 <<" é: " << calculaDistancia(cidade.lat2, cidade.lon2, cidade.lat4, cidade.lon4) << " KM"<< endl;
    cout << "A distancia entre, " <<nomeCidade3 << " e " <<nomeCidade4 <<" é: " << calculaDistancia(cidade.lat3, cidade.lon3, cidade.lat4, cidade.lon4) << " KM"<< endl;
}

void abreArqCep1(int cep1, int cep2){
    Cidade cidade;
    bool achou1 = false;
    bool achou2 = false;
   
    string nomeCidade1,nomeCidade2,nomeCidade3,nomeCidade4;
    fstream arq;
    string linha;
    arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto= split(linha, ';');
        int cepInicial = atoi(texto[1].c_str());
        int cepFinal = atoi(texto[2].c_str());
        if(cep1 >= cepInicial && cep1 <= cepFinal){
            achou1 = true;
            cout << texto[0] << "-" << texto[3] << endl;
            if (achou1 == true){
                nomeCidade1 = texto[0];
            }
            break;
        }

    }
    arq.close();

    arq.open("cep.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> texto2= split(linha, ';');
        int cepInicial = atoi(texto2[1].c_str());
        int cepFinal = atoi(texto2[2].c_str());
        if(cep2 >= cepInicial && cep2 <= cepFinal){
        achou2 = true;
        cout << texto2[0] << "-" << texto2[3] << endl;
        if (achou2 == true){
                nomeCidade2 = texto2[0];
        }
        break;
        }

    }
    arq.close();
    
     

    dbggg:
    if (!achou2) cout << "CEP nao encontrado!!" << endl;
    cout << nomeCidade1 << " - " << nomeCidade2<< " - " << nomeCidade3 << endl;

    double lat1, lon1, lat2, lon2, lat3, lon3, lat4, lon4;
    
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');

        if(!nomeCidade1.compare(v[3]) ){
            lat1 = atof(v[1].c_str());
            lon1 = atof(v[2].c_str());
        }
    }
    arq.close();
      
    arq.open("municipios_br.csv", ios::in| ios::out| ios::app);
    while(arq.good()){
        getline(arq, linha);
        vector<string> v= split(linha, ';');

        if(!nomeCidade2.compare(v[3]) ){
            lat2 = atof(v[1].c_str());
            lon2 = atof(v[2].c_str());
        }
    }
    arq.close();
   
    double pi = 3.1415926536;
    cidade.lat1 = lat1 * pi/180;
    cidade.lon1 = lon1 * pi/180;
    cidade.lat2 = lat2 * pi/180;
    cidade.lon2 = lon2 * pi/180;
    
    cout << "A distancia entre, " <<nomeCidade1 << " e " <<nomeCidade2 <<" é: " << calculaDistancia(cidade.lat1, cidade.lon1, cidade.lat2, cidade.lon2) << " KM"<< endl;
    
}

bool valida(int n){
    int contaDigitos = 0;
    if (n == 0) contaDigitos = 1;
        else {
            while (n != 0)
           {
               contaDigitos++;
               n /= 10;
           }
        }
    if (contaDigitos == 8 ||contaDigitos == 7 ) return true;
    else false;
}

int main () {
	
    int cep1 = 0;
    int cep2 = 0;
    int cep3 = 0;
    int cep4 = 0;
    bool ok = false;
    int x;
    inicio:
	cout << "Insira uma das opções: \n" << "[1] Para calcular apenas 2 CEPs \n" << "[2] Para Calcular 4 CEPs \n";
	cin >> x;
	switch (x) {
  case 1:
    while(!ok){
        cout << "Informe cep da cidade 1 (com 8 digitos): " << endl;
        cin >> cep1;

        ok = valida(cep1);
    }
    ok = false;
    while(!ok){
        cout << "Informe cep da cidade 2 (com 8 digitos): " << endl;
        cin >> cep2;

        ok = valida(cep2);
    }
    abreArqCep1(cep1, cep2);
    break;
  case 2:
        while(!ok){
        cout << "Informe cep da cidade 1 (com 8 digitos): " << endl;
        cin >> cep1;

        ok = valida(cep1);
    }
    ok = false;
    while(!ok){
        cout << "Informe cep da cidade 2 (com 8 digitos): " << endl;
        cin >> cep2;

        ok = valida(cep2);
    }
    ok = false;
    while(!ok){
        cout << "Informe cep da cidade 3 (com 8 digitos): " << endl;
        cin >> cep3;

        ok = valida(cep3);
    }
    ok = false;
    while(!ok){
        cout << "Informe cep da cidade 4 (com 8 digitos): " << endl;
        cin >> cep4;

        ok = valida(cep3);
    }

    abreArqCep(cep1, cep2, cep3, cep4);
    break;
  default:
    cout << "insira uma opcao valida \n";
    goto inicio;
  }

    return 0;
}
