#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char **argv){

        std::ifstream fileread("resultados/confs.out");
        std::ofstream filewrite("resultados/confs.proms");

        std::string line;

        std::string indiv;
        int how_many = atoi(argv[1]);
        double Nodos[100],Colores[100],Tiempo[100],Conflictos[100],ConflictosAntes[100];
        std::string devnull;

        for(int j=0;j<how_many;j++) {

                for(int i=0;i<100;i++){
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
                }
                for(int i=1;i<100;i++){
                        Nodos[0]+=Nodos[i];
                        Colores[0]+=Colores[i];
                        Tiempo[0]+=Tiempo[i];
                        Conflictos[0]+=Conflictos[i];
                }
                Nodos[0]=Nodos[0]/100.0;
                Colores[0]=Colores[0]/100.0;
                Tiempo[0]=Tiempo[0]/100.0;
                Conflictos[0]=Conflictos[0]/100.0;

                filewrite << std::fixed << indiv << " Nodos : " << Nodos[0] << " Colores: " << Colores[0] << " Tiempo: " << Tiempo[0] << " Conflictos: " << Conflictos[0] << std::endl;
        }


        return 0;
}