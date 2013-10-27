#ifndef ViaLig_
#define ViaLig_
#include <iostream>
using namespace std;
#include <string>
#include "LocTurist.h"
class ViaLig{
private:

	LocTurist* loc1;
	LocTurist* loc2;
	string cod;
	int km;
	int mtemp;
public:
	ViaLig(void);
	ViaLig(LocTurist* Loc1, LocTurist* Loc2, const string Cod, const int Km,const int MTemp);
	ViaLig(const ViaLig &p);
	~ViaLig();

	LocTurist* getLoc1();
	LocTurist* getLoc2();
	string getCod() const;
	int getKm() const;
	int getMTemp() const;

	void setLoc(LocTurist* Loc1,LocTurist* Loc2);
	void setLoc1(LocTurist* Loc);
	void setLoc2(LocTurist* Loc);
	void setCod(const string Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	void listar()const;
	virtual ViaLig& operator=(const ViaLig& VL);
	virtual bool operator<(const ViaLig& VL)const;
	void escreve (ostream& out)const;
};
	ViaLig::ViaLig(void){
		loc1=NULL;
		loc2=NULL;
		cod="";
		km=0;
		mtemp=0;
	}
	ViaLig::ViaLig( LocTurist* Loc1,LocTurist* Loc2, const string  Cod ,const int Km, const int MTemp){
		loc1=Loc1;
		loc2=Loc2;
		cod=Cod;
		km=Km;
		mtemp=MTemp;
	}
	ViaLig::ViaLig(const ViaLig &VL){
		loc1=VL.loc1;
		loc2=VL.loc2;
		cod=VL.cod;
		km=VL.km;
		mtemp=VL.mtemp;
	}
	ViaLig::~ViaLig(){}

	LocTurist* ViaLig::getLoc1(){
		return loc1;
	}
	
	LocTurist* ViaLig::getLoc2(){
		return loc2;
	}
	string ViaLig::getCod() const{
		return cod;
	}
	int ViaLig::getKm() const{
		return km;
	}
	int ViaLig::getMTemp() const{
		return mtemp;
	}

	void ViaLig::setLoc(LocTurist* Loc1, LocTurist* Loc2){
 		setLoc1(Loc1);
		setLoc2(Loc2);
	}
	void ViaLig::setLoc1(LocTurist* Loc){
		loc1=Loc;
	}
	void ViaLig::setLoc2(LocTurist* Loc){
		loc2=Loc;
	}
	void ViaLig::setCod(const string Cod){
		cod=Cod;
	}
	void ViaLig::setKm(const int Km){
		km=Km;
	}
	void ViaLig::setMTemp(const int MTemp){
		mtemp=MTemp;
	}


	void ViaLig::listar()const{
		cout<<loc1->getDesc()<<" / "<<loc2->getDesc()<<" | Código de via: "<<cod<<" Kilómetros: "<<km<<"km Tempo Médio de viagem: "<<mtemp<<"min "; 
	}
	
	ViaLig& ViaLig::operator=(const ViaLig& VL){
		cod=VL.cod;
		km=VL.km;
		mtemp=VL.mtemp;
		return *this;
	}
	bool ViaLig::operator<(const ViaLig& VL)const{
			if(km<VL.km)
				return true;
			else 
				return false;
	}
	void ViaLig::escreve(ostream& out) const{
		out<<loc1->getDesc()<<" / "<<loc2->getDesc()<<endl;
		out<<"Código: "<<cod<<endl;
		out<<"Kilómetros: "<<km<<endl;
		out<<"Tempo Médio: "<<mtemp<<endl;
	}

	ostream & operator<<(ostream& out, const ViaLig& VL){
		VL.escreve(out);
		return out;
	}

#endif