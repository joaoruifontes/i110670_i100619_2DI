#ifndef ViaNac_
#define ViaNac_
#include "ViaLig.h"
#include "LocTurist.h"
#include <iostream>
using namespace std;
#include <string>

class ViaNac:ViaLig
{
private:
	string tpav;
public:
	ViaNac(void);
	ViaNac(LocTurist* Loc1, LocTurist* Loc2, const string Cod, const int Km,const int MTemp,const string preco);
	ViaNac(const ViaNac &p);
	~ViaNac();

	LocTurist* getLoc1();
	LocTurist* getLoc2();
	string getCod() const;
	int getKm() const;
	int getMTemp() const;
	string getTPav() const;
	
	void setLoc(LocTurist* Loc1,LocTurist* Loc2);
	void setLoc1(LocTurist* Loc);
	void setLoc2(LocTurist* Loc);
	void setTPav(const string TPav);
	void setCod(const string Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	 void listar()const;
	 ViaNac& operator=(const ViaNac& VN);
	 bool operator==(const ViaNac& VN)const;
	 bool operator<(const ViaNac& VN)const;
	 void escreve (ostream& out)const;
};
	ViaNac::ViaNac(void):ViaLig(){
		tpav="";
	}
	ViaNac::ViaNac(LocTurist* Loc1,LocTurist* Loc2, const string Cod,const int Km,const int MTemp, const string TPav):ViaLig(Loc1,Loc2,Cod,Km,MTemp){
		tpav=TPav;
	}
	ViaNac::ViaNac(const ViaNac &VN):ViaLig(VN){
		tpav=VN.tpav;
	}
	ViaNac::~ViaNac(){}



	LocTurist* ViaNac::getLoc1(){
		return ViaLig::getLoc1();
	}
	LocTurist* ViaNac::getLoc2(){
		return ViaLig::getLoc2();
	}
	string ViaNac::getCod() const{
		return ViaLig::getCod();
	}
	int ViaNac::getKm() const{
		return ViaLig::getKm();
	}
	int ViaNac::getMTemp() const{
		return ViaLig::getMTemp();
	}
	string ViaNac::getTPav() const{
		return tpav;
	}


	void ViaNac::setLoc(LocTurist* Loc1, LocTurist* Loc2){
		ViaLig::setLoc1(Loc1);
		ViaLig::setLoc2(Loc2);
	}
	void ViaNac::setLoc1(LocTurist* Loc){
		ViaLig::setLoc1(Loc);
	}
	void ViaNac::setLoc2(LocTurist* Loc){
		ViaLig::setLoc2(Loc);
	}
	void ViaNac::setCod(const string Cod){
		ViaLig::setCod(Cod);
	}
	void ViaNac::setKm(const int Km){
		ViaLig::setKm(Km);
	}
	void ViaNac::setMTemp(const int MTemp){
		ViaLig::setMTemp(MTemp);
	}
	void ViaNac::setTPav(const string TPav){
		tpav=TPav;
	}
	void ViaNac::listar()const{
		ViaLig::listar();
		cout<<"Tipo de Pavimento: "<<tpav<<"."<<endl;
	}
	ViaNac& ViaNac::operator=(const ViaNac& VN){
		if(this!=&VN){
			ViaLig::operator=(VN);
			tpav=VN.tpav;
		}
		return *this;
	}
	bool ViaNac::operator<(const ViaNac& VN)const{
		return ViaLig::operator<(VN);
	}
	bool ViaNac::operator==(const ViaNac& VN) const{
		if(tpav==VN.tpav && getKm()==VN.getKm() && getCod()==VN.getCod())
			return true;
		else
			return false;
	}
	void ViaNac::escreve(ostream &out) const{
		out << "Tipo de Pavimento: " << tpav << ". " <<endl;
		ViaLig::escreve(out);
	}

	ostream & operator << (ostream &out, const ViaNac &c){
		c.escreve(out);
		return out;
	}
#endif