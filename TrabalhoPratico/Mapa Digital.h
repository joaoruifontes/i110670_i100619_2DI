#ifndef _MapaDigital
#define _MapaDigital

#include "LocTurist.h"
#include "ViaLig.h"
#include "graphStlPath.h"

class MapaDigital:graphStlPath <LocTurist*,ViaLig*>{
private:
public:
	MapaDigital();
	MapaDigital(const MapaDigital& md);
	
	
	void construirGrafo(const vector<LocTurist*>& lt,const vector<ViaLig*>& vl);
	//determinar a complexidade temporal
	void percursosPossiveis(const string orig,const string dest);
	void percursosPossiveis(const LocTurist& orig,const LocTurist& dest);
	void percursosPossiveis(const string orig,const LocTurist
};

#endif // !