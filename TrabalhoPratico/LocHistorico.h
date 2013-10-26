#ifndef LocHistorico_
#define LocHistorico_

#include "LocTurist.h"

#include <iostream>
using namespace std;
#include <string>

class LocHistorico: public LocTurist
{
private:
	int tmed;
	int abert;
	int encerr;
public:
	LocHistorico(void);
	LocHistorico(const int Tmed,const int Abert,const int Encerr, const string Desc);
	LocHistorico(const LocHistorico &c);
	 ~LocHistorico();

	void setTMed(const int Tmed);
	void setAbert(const int Abert);
	void setEncerr(const int Encerr);
	void setDesc(const string Desc);
	
	int getTMed() const;
	int getAbert() const;
	int getEncerr() const;
	string getDesc() const;

	 void listar()const;
	 LocHistorico& operator=(const LocHistorico& LH);
	 virtual bool operator<(const LocHistorico& LH);
	 bool operator==(const LocHistorico& LH);
	 void escreve(ostream &out) const;

};

LocHistorico::LocHistorico(void):LocTurist(){
	tmed=0;
	abert=1200;
	encerr=1800;
}

LocHistorico::LocHistorico(const int Tmed,const int Abert,const int Encerr, const string Desc):LocTurist(Desc){
	tmed=Tmed;
	abert=Abert;
	encerr=Encerr;
}

LocHistorico::LocHistorico(const LocHistorico& LH){
	tmed=LH.tmed;
	abert=LH.abert;
	encerr=LH.encerr;
	setDesc(LH.getDesc());
}
LocHistorico::~LocHistorico()
{
}

void LocHistorico::setTMed(const int Tmed){
	tmed=Tmed;
}
void LocHistorico::setAbert(const int Abert){
	abert=Abert;
}
void LocHistorico::setEncerr(const int Encerr){
	encerr=Encerr;
}
void LocHistorico::setDesc(string Desc){
	LocTurist::setDesc(Desc);
}

int LocHistorico::getTMed() const{
	return tmed;
}
int LocHistorico::getAbert() const{
	return abert;
}
int LocHistorico::getEncerr() const{
	return encerr;
}
string LocHistorico::getDesc() const{
	return LocTurist::getDesc();
}

void LocHistorico::listar()const{
	cout<<"---Local Historico---"<<endl;
	cout<<"Tempo Médio: "<<tmed<<endl;
	cout<<"Hora de Abertura: "<<abert<<endl;
	cout<<"Hora de Encerramento: "<<encerr<<endl;
	LocTurist::listar();
}

LocHistorico& LocHistorico::operator=(const LocHistorico& LH){
	if(this!=&LH){
		LocTurist::operator=(LH);
		tmed=LH.tmed;
		abert=LH.abert;
		encerr=LH.encerr;
	}
	return *this;
}
bool LocHistorico::operator<(const LocHistorico& LH){
	if(tmed<LH.tmed)
		return true;
	else
		return false;
}
bool LocHistorico::operator==(const LocHistorico& LH){
	if(LH.abert==abert && LH.getDesc()==getDesc() && LH.encerr==encerr && LH.tmed==tmed){
		return true;
	}else{
		return false;
	}//*/
}
void LocHistorico::escreve(ostream &out) const{
	out << "Local Historico aberto das: " << abert << "hrs as " << encerr <<"hrs."<<"Tempo médio de visita: "<<tmed<<endl;
	LocTurist::escreve(out);
}

ostream & operator << (ostream &out, const LocHistorico &c){
	c.escreve(out);
	return out;
}

#endif