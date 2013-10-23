#ifndef ViaLig_
#define ViaLig_


class ViaLig{
private:
	int cod;
	int km;
	int mtemp;
public:
	ViaLig();
	ViaLig(const int Cod, const int Km,const int MTemp);
	ViaLig(const ViaLig &p);
	~ViaLig();

	int getCod() const;
	int getKm() const;
	int getMTemp() const;

	void setCod(const int Cod);
	void setKm(const int Km);
	void setMTemp(const int MTemp);

	virtual void listar()const;
	virtual ViaLig* clone() const =0;
	virtual ViaLig& operator=(const ViaLig& VL);
	virtual bool operator==(const ViaLig& VL)const=0;
	virtual bool operator<(const ViaLig& VL)const;
	virtual void escreve (ostream& out)const;
};
	ViaLig::ViaLig(){
		cod=0;
		km=0;
		mtemp=0;
	}
	ViaLig::ViaLig(const int Cod,const int Km,const int MTemp){
		cod=Cod;
		km=Km;
		mtemp=MTemp;
	}
	ViaLig::ViaLig(const ViaLig &VL){
		cod=VL.cod;
		km=VL.km;
		mtemp=VL.mtemp;
	}
	ViaLig::~ViaLig(){}

	int ViaLig::getCod() const{
		return cod;
	}
	int ViaLig::getKm() const{
		return km;
	}
	int ViaLig::getMTemp() const{
		return mtemp;
	}
	void ViaLig::setCod(const int Cod){
		cod=Cod;
	}
	void ViaLig::setKm(const int Km){
		km=Km;
	}
	void ViaLig::setMTemp(const int MTemp){
		mtemp=MTemp;
	}

	void ViaLig::listar()const{
		cout<<"Código de via: "<<cod<<" Kilómetros: "<<km<<"km Tempo Médio de viagem: "<<mtemp<<"min "; 
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
		out<<"Código: "<<cod<<endl;
		out<<"Kilómetros: "<<km<<endl;
		out<<"Tempo Médio: "<<mtemp<<endl;
	}

	ostream & operator<<(ostream& out, const ViaLig& VL){
		VL.escreve(out);
		return out;
	}

#endif