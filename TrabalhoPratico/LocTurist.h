#ifndef LocTurist_
#define LocTurist_

#include <iostream>
using namespace std;
#include <string>

class LocTurist{
private:
	string desc;
public:
	LocTurist(void);
	LocTurist(const string Desc);
	LocTurist(const LocTurist &p);
	~LocTurist();

	string getDesc() const;

	void setDesc(const string Desc);
	
	 virtual void listar()const;
	 virtual LocTurist& operator=(const LocTurist& LT);
	 virtual void escreve (ostream& out)const;

};

LocTurist::LocTurist(void){
	desc=" ";
}

LocTurist::LocTurist(const string Desc){
	desc=Desc;
}
LocTurist::LocTurist(const LocTurist &LT){
	desc=LT.desc;
}
LocTurist::~LocTurist()
{
}

void LocTurist::setDesc(const string Desc){
	desc=Desc;
}

string LocTurist::getDesc() const{
	return desc;
}

void LocTurist::listar()const{
	cout<<"Desrição: "<<desc<<endl;
}

LocTurist& LocTurist::operator=(const LocTurist& LT){
	setDesc(LT.desc);
	return *this;
}

void LocTurist::escreve(ostream& out) const{
	out<<"Descrição: "<<desc<<endl;
}

ostream & operator<<(ostream& out, const LocTurist& LT){
	LT.escreve(out);
	return out;
}
#endif