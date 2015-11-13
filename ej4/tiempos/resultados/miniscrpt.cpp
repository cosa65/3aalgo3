#include <iostream>
#include <fstream>
#include <sstream>

int main(){
	
	std::ifstream fileread("time.out");
	std::ofstream filewrite("time.proms",std::ofstream::app);

	std::string line;

	std::string indiv;

	double Nodos[3],Colores[3],Tiempo[3],Conflictos[3],ConflictosAntes[3];
	std::string devnull;

	for(int j=0;j<16;j++) {

		for(int i=0;i<3;i++){
			getline(fileread,line);
			std::istringstream sline(line);
			sline >> indiv;
			sline >> devnull;
			sline >> Nodos[i];
			sline >> devnull;
			sline >> Colores[i];
			sline >> devnull;
			sline >> Tiempo[i];
			sline >> devnull;
			sline >> Conflictos[i];
			sline >> devnull;
			sline >> ConflictosAntes[i];
		}
		for(int i=1;i<3;i++){
			Nodos[0]+=Nodos[i];
			Colores[0]+=Colores[i];
			Tiempo[0]+=Tiempo[i];
			Conflictos[0]+=Conflictos[i];
			ConflictosAntes[0]+=ConflictosAntes[i];
		}
		Nodos[0]=Nodos[0]/3.0;
		Colores[0]=Colores[0]/3.0;
		Tiempo[0]=Tiempo[0]/3.0;
		Conflictos[0]=Conflictos[0]/3.0;
		ConflictosAntes[0]=ConflictosAntes[0]/3.0;
		
		filewrite << std::fixed << indiv << " Nodos : " << Nodos[0] << " Colores: " << Colores[0] << " Tiempo " << Tiempo[0] << " Conflictos " << Conflictos[0] << " ConflictosAntes " << ConflictosAntes[0] << std::endl;

	}


	return 0;
}