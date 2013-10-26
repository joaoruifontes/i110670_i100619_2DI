#ifndef ViaAut_
#define ViaAut_
#include "ViaLig.h"
#include "LocTurist.h"
#include <iostream>
using namespace std;
#include <string>

class ViaAut:ViaLig{
private:
	double preco;
public:
	ViaAut(void);
	ViaAut(LocTurist* Loc1,LocTurist* Loc2, const string Cod, const int Km,const int MTemp, const double Preco);
	ViaAut(const ViaAut &p);
	~ViaAut();

	LocTurist* getLoc1();
	LocTurist* getLoc2();
	string getCod() const;
	int getKm() const;
	int getMTemp() const;
	double getPreco() const;
	

	void setLoc(LocTurist* Loc1, LocTurist* Loc2);
	void setLoc1(LocTurist* Loc);
	void setLoc2(LocTurist* Loc);
	void setPreco(const double Preco);
	void setCod(const string Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	 void listar()const;
	 ViaAut& operator=(const ViaAut& VA);
	 bool operator==(const ViaAut& VA)const;
	 bool operator<(const ViaAut& VA)const;
	 void escreve (ostream& out)const;
};
	ViaAut::ViaAut(void):ViaLig(){
		preco=0;
	}
	ViaAut::ViaAut(LocTurist* Loc1,LocTurist* Loc2, const string Cod, const int Km,const int MTemp, const double Preco):ViaLig(Loc1,Loc2,Cod,Km,MTemp){
		preco=Preco;
	}
	ViaAut::ViaAut(const ViaAut &VA):ViaLig(VA){
		preco=VA.preco;
	}
	ViaAut::~ViaAut(){}



	LocTurist* ViaAut::getLoc1(){
		return ViaLig::getLoc1();
	}
	LocTurist* ViaAut::getLoc2(){
		return ViaLig::getLoc2();
	}
	string ViaAut::getCod() const{
		return ViaLig::getCod();
	}
	int ViaAut::getKm() const{
		return ViaLig::getKm();
	}
	int ViaAut::getMTemp() const{
		return ViaLig::getMTemp();
	}
	double ViaAut::getPreco() const{
		return preco;
	}


	void ViaAut::setLoc(LocTurist* Loc1, LocTurist* Loc2){
		ViaLig::setLoc(Loc1,Loc2);
	}
	void ViaAut::setLoc1(LocTurist* Loc){
		ViaLig::setLoc1(Loc);
	}
	void ViaAut::setLoc2(LocTurist* Loc){
		ViaLig::setLoc2(Loc);
	}
	void ViaAut::setCod(const string Cod){
		ViaLig::setCod(Cod);
	}
	void ViaAut::setKm(const int Km){
		ViaLig::setKm(Km);
	}
	void ViaAut::setMTemp(const int MTemp){
		ViaLig::setMTemp(MTemp);
	}
	void ViaAut::setPreco(const double Preco){
		preco=Preco;
	}
	void ViaAut::listar()const{
		ViaLig::listar();
		cout<<"Preço: "<<preco<<"€."<<endl;
	}
	ViaAut& ViaAut::operator=(const ViaAut& VA){
		if(this!=&VA){
			ViaLig::operator=(VA);
			preco=VA.preco;
		}
		return *this;
	}
	bool ViaAut::operator<(const ViaAut& VA)const{
			if(preco<VA.preco)
				return true;
			else
				return false;
	}
	bool ViaAut::operator==(const ViaAut& VA) const{
		if(preco==VA.preco && getKm()==VA.getKm() && getCod()==VA.getCod())
			return true;
		else
			return false;
	}
	void ViaAut::escreve(ostream &out) const{
		out << "Preço: " << preco << "€." <<endl;
		ViaLig::escreve(out);
	}

	ostream & operator << (ostream &out, const ViaAut &c){
		c.escreve(out);
		return out;
	}

#endif