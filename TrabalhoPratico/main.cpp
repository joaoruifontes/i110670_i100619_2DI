#include "LocHistorico.h"
#include "LocNatural.h"
#include "LocTurist.h"
#include "ViaAut.h"
#include "ViaLig.h"
#include "ViaNac.h"
#include "Teste.h"
#include <vector>


void main(){
	LocHistorico lochist1();
	LocHistorico lochist2(20,20,20,"LocalH2");
	LocHistorico lochist4(lochist2);
	
	LocNatural locnat1();
	LocNatural locnat2(20,"LocalN2");
	LocNatural locnat4(locnat2);

	ViaNac vianac1();
	ViaNac vianac2(&locnat2,&lochist4,"EN2",20,20,"asfalto");
	ViaNac vianac3(vianac2);

	ViaAut viaaut1();
	ViaAut viaaut2(&lochist2,&lochist2,"A3",20,20,20);
	//*/
	
	Teste x;
	x.LerLocais();
	x.LerViasLigacao();
	x.Contabilizar();
};
