#ifndef ViaAut_
#define ViaAut_
#include "ViaLig.h"
class ViaAut:ViaLig{
private:
	double preco;
public:
	ViaAut();
	ViaAut(const double preco, const int Cod, const int Km,const int MTemp);
	ViaAut(const ViaAut &p);
	~ViaAut();

	int getCod() const;
	int getKm() const;
	int getMTemp() const;
	double getPreco() const;
	
	void setPreco(const double Preco);
	void setCod(const int Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	virtual void listar()const;
	virtual ViaLig* clone()const;
	virtual ViaAut& operator=(const ViaAut& VA);
	virtual bool operator==(const ViaAut& VA)const;
	virtual bool operator<(const ViaAut& VA)const;
	virtual void escreve (ostream& out)const;
};
	ViaAut::ViaAut():ViaLig(){
		preco=0;
	}
	ViaAut::ViaAut(const double Preco, const int Cod,const int Km,const int MTemp):ViaLig(Cod,Km,MTemp){
		preco=Preco;
	}
	ViaAut::ViaAut(const ViaAut &VA):ViaLig(VA){
		preco=VA.preco;
	}
	ViaAut::~ViaAut(){}

	int ViaAut::getCod() const{
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
	void ViaAut::setCod(const int Cod){
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
	ViaLig* ViaAut::clone() const{
		return new ViaAut(*this);
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