#ifndef LocNatural_
#define LocNatural_

#include <iostream>
using namespace std;
#include <string>

#include "LocTurist.h"
class LocNatural:public LocTurist{
	private:
		int area;
	public:
		LocNatural(void);
		LocNatural(const int Area,const string Desc);
		LocNatural(const LocNatural &LN);
		 ~LocNatural();

		void setArea(const int Area);
		void setDesc(const string Desc);
	
		int getArea() const;
		string getDesc() const;

		void listar()const;
		
		LocNatural& operator=(const LocNatural& LN);
		bool operator<(const LocNatural& LN);
		bool operator==(const LocNatural& LN);
		void escreve(ostream &out) const;
};
		LocNatural::LocNatural(void):LocTurist(){
			area=0;
		}
		LocNatural::LocNatural(const int Area,const string Desc):LocTurist(Desc){
			area=Area;
		}
		LocNatural::LocNatural(const LocNatural& LN){
			area=LN.area;
			setDesc(LN.getDesc());
		}
		LocNatural::~LocNatural(){}

		void LocNatural::setArea(const int Area){
			area=Area;
		}
		void LocNatural::setDesc(const string Desc){
			LocTurist::setDesc(Desc);
		}

	
		int LocNatural::getArea() const{
			return area;
		}
		string LocNatural::getDesc() const{
			return LocTurist::getDesc();
		}

		void LocNatural::listar()const{
			cout<<"---Local Natual---"<<endl;
			cout<<"Área: "<<area<<endl;
			LocTurist::listar();
		}
		LocNatural& LocNatural::operator=(const LocNatural& LN){
			if(this!=&LN){
				LocTurist::operator=(LN);
				area=LN.area;
			}
			return *this;
		}
		bool LocNatural::operator<(const LocNatural& LN){
			if(area<LN.area)
				return true;
			else
				return false;
		}
		bool LocNatural::operator==(const LocNatural& LN){
			if(area==LN.area && getDesc()==LN.getDesc())
				return true;
			else
				return false;
		}
		void LocNatural::escreve(ostream &out) const{
			out << "Local Natural com: " << area << "m2." <<endl;
			LocTurist::escreve(out);
		}

		ostream & operator << (ostream &out, const LocNatural &c){
			c.escreve(out);
			return out;
		}

#endif