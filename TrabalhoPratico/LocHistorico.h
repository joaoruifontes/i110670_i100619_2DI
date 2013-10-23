#ifndef LocHistorico_
#define LocHistorico_

#include "LocTurist.h"

class LocHistorico:public LocTurist
{
private:
	int tmed;
	int abert;
	int encerr;
public:
	LocHistorico();
	LocHistorico(const int Tmed,const int Abert,const int Encerr, string desc);
	LocHistorico(const int Tmed,const int Abert,const int Encerr);
	LocHistorico(const LocHistorico &c);
	virtual ~LocHistorico();

	void setTMed(const int Tmed);
	void setAbert(const int Abert);
	void setEncerr(const int Encerr);
	void setDesc(const string Desc);
	
	int getTMEd() const;
	int getAbert() const;
	int getEncerr() const;
	string getDesc() const;

	virtual void listar()const;
	virtual LocTurist* clone() const;
	LocHistorico& operator=(const LocHistorico& LH);
	bool operator<(const LocHistorico& LH);
	bool operator==(const LocHistorico& LH);
	void escreve(ostream &out) const;

};

LocHistorico::LocHistorico():LocTurist(){
	tmed=0;
	abert=1200;
	encerr=1800;
}

LocHistorico::LocHistorico(const int Tmed,const int Abert,const int Encerr, string Desc):LocTurist(Desc){
	tmed=Tmed;
	abert=Abert;
	encerr=Encerr;
}
LocHistorico::LocHistorico(const int Tmed,const int Abert,const int Encerr):LocTurist(){
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

LocTurist* LocHistorico::clone() const{
	return new LocHistorico(*this);
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
	if(tmed==LH.tmed && abert==LH.abert && encerr=LH.encerr && getDesc()==LH.getDesc()){
		return true;
	else
		return false;
	}
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