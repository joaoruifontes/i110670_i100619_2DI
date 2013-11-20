#include "LocHistorico.h"
#include "LocNatural.h"
#include "LocTurist.h"
#include "ViaAut.h"
#include "ViaLig.h"
#include "ViaNac.h"
#include "Teste.h"
#include <vector>

void carregamentos(bool ranflag){
		if(ranflag){
			cout<<"Carregamento feito com sucesso!!"<<endl;
		}else{
			cout<<"Erro no carregamento do fixeiro"<<endl;
		}
}

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
	bool exit=false,ranflag;
	char op;
	while(!exit){
		cout<<"Opção 1 - Ler Locais"<<endl;
		cout<<"Opção 2 - Ler Vias de Ligação"<<endl;
		cout<<"Opção 3 - Contabilizar"<<endl;
		cout<<"Opção 4 - Sair"<<endl;
		cin>>op;
		switch (op){
		case '1':
			ranflag=x.LerLocais();
			carregamentos(ranflag);
			break;
		case '2':
			ranflag=x.LerViasLigacao();
			carregamentos(ranflag);
			break;
		case '3':
			x.Contabilizar();
			break;
		case '4':
			exit=true;
			break;
		default:
			cout<<"Comando não reconhecido"<<endl;
		}
	}
};