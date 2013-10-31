#pragma once
#include<fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "ViaAut.h"
#include "ViaLig.h"
#include "ViaNac.h"
#include "LocNatural.h"
#include "LocHistorico.h"
#include "LocTurist.h"


using namespace std;

int countH=0,countN=0;

class Teste
{
private:
	vector<LocTurist*> locais;
	vector<ViaLig*> vias;

public:

	Teste();

	void LerLocais();
	void LerViasLigacao();
	void Contabilizar();
};


Teste::Teste(){

}

void Teste::LerViasLigacao(){
	LocTurist *lt1=new LocTurist(), *lt2=new LocTurist();
	int ind=0, inic;
	string linha;
	ifstream fx;
	fx.open("Vias.txt");
	if(fx){
		int c=0;
		while(!fx.eof()){
			getline(fx,linha,'\n');
			if(c!=0){
				if(linha.size()>0){
					//Encontra e retira a primeira palavra até a virgula
					inic=0;
					int pos= linha.find(',', inic);
					string loc1(linha.substr(inic,pos-inic));
					for (int i = 0; i < locais.size(); i++)
					{
						if (loc1.compare(locais[i]->getDesc()))
						{

							lt1=locais[i];
						}
					}
					pos++;

					//Encontra e retira a segunda palavra até a virgula
					inic=pos;
					pos= linha.find(',', inic);
					string loc2(linha.substr(inic,pos-inic));
					for (int i = 0; i < locais.size(); i++)
					{
						if (loc2.compare(locais[i]->getDesc()))
						{
							lt2=locais[i];
						}
					}
					pos++;


					//Encontra e retira a terceira palavra até a virgula
					inic=pos;
					pos= linha.find(',', inic);
					string via(linha.substr(inic,pos-inic));
					pos++;

					//Encontra e retira a quarta palavra até a virgula
					inic=pos;
					pos= linha.find(',', inic);
					string kmSTR(linha.substr(inic,pos-inic));
					stringstream ss3(kmSTR);
					int km = 0;
					ss3 >> km;
					pos++;


					//Encontra e retira a quinta palavra até a virgula
					inic=pos;
					pos= linha.find(',', inic);
					string tempomedioSTR(linha.substr(inic,pos-inic));
					stringstream ss4(tempomedioSTR);
					int tempomedio = 0;
					ss4 >> tempomedio;
					pos++;


					//Encontra e retira a sexta palavra até a virgula
					inic=pos;
					pos= linha.find(',', inic);
					string ultimapoz(linha.substr(inic,pos-inic));
					stringstream ss5(ultimapoz);
					int preco = 0;
					ss5 >> preco;
					pos++;



					int tamanho=ultimapoz.size();
					char aux[50];
					int i;
					for(i=0;i<tamanho;i++){
						aux[i]='a';
					}
					//Passar string para char
					for(i = 0; i < tamanho; i++){
						ultimapoz[i]=aux[i];
					}

					//ver se é inteiro ou string
					if(isalpha(aux[0])){
						//invocar coinstrutor estradas nacionais
						ViaNac vn(lt1,lt2,via, km, tempomedio ,ultimapoz);
						vias.push_back(&vn);
					}else{
						ViaAut va(lt1,lt2,via,km,tempomedio,preco);
						vias.push_back(&va);
					}
				}
			}
			c++;
		}
		fx.close();
	}else{
		cout << "Fx. nao existe!" << endl;
	}
}

void Teste::LerLocais(){
	int ind=0,inic,c=0;
	string linha;
	ifstream fx;
	fx.open("Locais.txt");
	if(fx){
		while(!fx.eof()){
			getline(fx,linha,'\n');
			c=0;
			if(linha.size()>0){
				for (int i = 0; i < linha.size(); i++)
				{
					string aux=linha.substr(i,1);
					if(!aux.compare(",")){
						c++;
					}
				}
				if(c==1){
					inic=0;
					int pos= linha.find(',', inic);
					string loc1(linha.substr(inic,pos-inic));
					pos++;

					//
					inic=pos;
					pos= linha.find(',', inic);
					string areaSTR(linha.substr(inic,pos-inic));
					stringstream ss1(areaSTR);
					int area = 0;
					ss1 >> area;
					pos++;

					//construtor de locais naturais
					LocNatural ln(area, loc1);
					locais.push_back(&ln);

				}else{
					int inic=0;
					int pos= linha.find(',', inic);
					string loc1(linha.substr(inic,pos-inic));
					pos++;

					inic=pos;

					pos= linha.find(',', inic);
					string tempomedioSTR(linha.substr(inic,pos-inic));
					stringstream ss1(tempomedioSTR);
					int tempomedio = 0;
					ss1 >> tempomedio;
					pos++;

					pos= linha.find(',', inic);
					string aberturaSTR(linha.substr(inic,pos-inic));
					stringstream ss(aberturaSTR);
					int abertura = 0;
					ss >> abertura;

					pos++;

					inic=pos;

					pos= linha.find(',', inic);
					string fechoSTR(linha.substr(inic,pos-inic));
					stringstream ss2(fechoSTR);
					int fecho = 0;
					ss2 >> fecho;
					pos++;

					//construtor de locais historicos
					LocHistorico lh(tempomedio, abertura, fecho, loc1);
					locais.push_back(&lh);
				}
			}
		}
		fx.close();
	}else{
		cout << "Fx. nao existe!" << endl;
	}
}

void Teste::Contabilizar(){
	
	for(vector<LocTurist*>::iterator it = locais.begin(); it != locais.end(); ++it){
		if(LocHistorico* H = dynamic_cast<LocHistorico*>(*it))
			countH++;
		else if(LocNatural* N = dynamic_cast<LocNatural*>(*it))
			countN++;
	}//*/
	cout<<"No. Locais Naturais: "<<countN<<endl;
	cout<<"No. Locais Historicos: "<<countH<<endl;
	bool exit=false;
	do{
		exit=true;
		for(int i=0; i<locais.size()-1;i++){
			if ((locais[i]->getDesc()) > (locais[i+1]->getDesc())){
                exit = false;
				LocTurist* temp=locais[i];
				locais[i]=locais[i+1];
				locais[i+1]=temp;
			}
		}
	}while(!exit);
	for(int i=0;i<locais.size();i++){
		cout<<locais[i]->getDesc()<<endl;
	}
	cin.get();
}
