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

/*	--TODO--
	1- Reformular os try/catch exeptions para que digam o numero da linha onde foi obtido o erro
	2- O "get" da ultima variavel de introduçao de dados nas vias n apanha erros
	3- N limpa espaços para os inteiros
//*/

class Teste
{
private:
	vector<LocTurist*> locais;
	vector<ViaLig*> vias;

public:

	Teste();

	bool LerLocais();
	bool LerViasLigacao();
	void Contabilizar();
};


Teste::Teste(){

}

bool Teste::LerViasLigacao(){
	LocTurist *lt1=new LocTurist(), *lt2=new LocTurist();
	int ind=0, inic,pos;
	string linha;
	ifstream fx;
	fx.open("Vias.txt");
	if(fx){
		while(!fx.eof()){
			getline(fx,linha,'\n');
			if(linha.size()>0){
				//Encontra e retira a primeira palavra até a virgula
				inic=0;
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
				string desc(linha.substr(inic,pos-inic));
				for (int i = 0; i < locais.size(); i++)
				{
					if (desc.compare(locais[i]->getDesc()))
					{

						lt1=locais[i];
					}//Excecção de referencia nao encontrada
				}
				pos++;

				//Encontra e retira a segunda palavra até a virgula
				inic=pos;
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
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
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
				string via(linha.substr(inic,pos-inic));
				pos++;

				//Encontra e retira a quarta palavra até a virgula
				inic=pos;
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
				string kmSTR(linha.substr(inic,pos-inic));
				int km=0;
				try{
					km= stoi(kmSTR);
				}catch(const invalid_argument& kmexeption){
					cout<<"Kilometragem inválida!!"<<endl;
					return false;
				}
				pos++;


				//Encontra e retira a quinta palavra até a virgula
				inic=pos;
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
				string tempomedioSTR(linha.substr(inic,pos-inic));
				int tempomedio=0;
				try{
					tempomedio= stoi(tempomedioSTR);
				}catch(const invalid_argument& tmedvia_exeption){
					cout<<"Tempo médio inválido!!"<<endl;
					return false;
				}
				pos++;


				//Encontra e retira a sexta palavra até a virgula
				inic=pos;
				if(pos= linha.find(',', inic)==-1){
					return false;
				}
				string ultimapoz(linha.substr(inic,pos-inic));
				stringstream ss5(ultimapoz);
				int preco = 0;
				ss5 >> preco;
				pos++;


				//Verificação de tipo de construtor
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
		fx.close();
	}else{
		cout << "Fx. nao existe!" << endl;
	}
	return true;
}

bool Teste::LerLocais(){
	int ind=0,inic,c=0,pos;
	string linha;
	ifstream fx;
	fx.open("Locais.txt");
	if(fx){
		while(!fx.eof()){
			getline(fx,linha,'\n');
			c=0;
			if(linha.size()>0){
				//Contabilização do numero de "," para decisão de tipo de construtor
				for (int i = 0; i < linha.size(); i++)
				{
					string aux=linha.substr(i,1);
					if(!aux.compare(",")){
						c++;
					}
				}
				//Fixeiro.LocNatural
				if(c==1){
					//Fixeiro.LocNatural.getDesc()
					inic=0;
					if(pos= linha.find(',', inic)==-1){
						return false;
					}
					string desc(linha.substr(inic,pos-inic));
					pos++;

					//Fixeiro.LocNatural.getArea()
					inic=pos;
					if(pos= linha.find(',', inic)==-1){
						return false;
					}
					string areaSTR(linha.substr(inic,pos-inic));
					int area=0;
					try{
						area= stoi(areaSTR);
					}catch(const invalid_argument& area_exeption){
						cout<<"Tempo médio inválido!!"<<endl;
						return false;
					}
					pos++;

					//construtor de locais naturais
					LocNatural ln(area, desc);
					locais.push_back(&ln);

				}else if(c==3){
					//Fixeiro.LocHistorico.getDesc()
					int inic=0;
					if(pos= linha.find(',', inic)==-1){
						return false;
					}
					string desc(linha.substr(inic,pos-inic));
					pos++;

					//Fixeiro.LocHistorico.getTempoMédio()
					inic=pos;
					if(pos= linha.find(',', inic)==-1){
						return false;
					}
					string tempomedioSTR(linha.substr(inic,pos-inic));
					int tempomedio=0;
					try{
						tempomedio= stoi(tempomedioSTR);
					}catch(const invalid_argument& tmedlocalhistorico_exeption){
						cout<<"Tempo médio inválido!!"<<endl;
						return false;
					}
					pos++;

					//Fixeiro.LocHistorico.getAbertura()
					if(pos= linha.find(',', inic)==-1){
						return false;
					}					
					string aberturaSTR(linha.substr(inic,pos-inic));
					int abertura=0;
					try{
						abertura= stoi(aberturaSTR);
					}catch(const invalid_argument& abertura_exeption){
						cout<<"Hora de abertura inválida!!"<<endl;
						return false;
					}
					pos++;
					//Fixeiro.LocHistorico.getFecho()
					inic=pos;
					if(pos= linha.find(',', inic)==-1){
						return false;
					}
					string fechoSTR(linha.substr(inic,pos-inic));
					int fecho=0;
					try{
						fecho= stoi(fechoSTR);
					}catch(const invalid_argument& fecho_exeption){
						cout<<"Hora de fecho inválida!!"<<endl;
						return false;
					}
					pos++;

					//construtor de locais historicos
					LocHistorico lh(tempomedio, abertura, fecho, desc);
					locais.push_back(&lh);
				}else{
					cout<<"Erro na identificação do tipo de construtor"<<endl;
					return false;
				}
			}
		}
		fx.close();
	}else{
		cout << "Fx. nao existe!" << endl;
	}
	return true;
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
}

