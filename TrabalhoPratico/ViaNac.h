#ifndef ViaNac_
#define ViaNac_
#include "ViaLig.h"

class ViaNac:ViaLig
{
private:
	string tpav;
public:
	ViaNac();
	ViaNac(const string preco, const int Cod, const int Km,const int MTemp);
	ViaNac(const ViaNac &p);
	~ViaNac();

	int getCod() const;
	int getKm() const;
	int getMTemp() const;
	string getTPav() const;
	
	void setTPav(const string TPav);
	void setCod(const int Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	virtual void listar()const;
	virtual ViaLig* clone() const;
	virtual ViaNac& operator=(const ViaNac& VN);
	virtual bool operator==(const ViaNac& VN)const;
	virtual bool operator<(const ViaNac& VN)const;
	virtual void escreve (ostream& out)const;
};
	ViaNac::ViaNac():ViaLig(){
		tpav="";
	}
	ViaNac::ViaNac(const string TPav, const int Cod,const int Km,const int MTemp):ViaLig(Cod,Km,MTemp){
		tpav=TPav;
	}
	ViaNac::ViaNac(const ViaNac &VN):ViaLig(VN){
		tpav=VN.tpav;
	}
	ViaNac::~ViaNac(){}

	int ViaNac::getCod() const{
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
	void ViaNac::setCod(const int Cod){
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
	ViaLig* ViaNac::clone() const{
			return new ViaNac(*this);
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