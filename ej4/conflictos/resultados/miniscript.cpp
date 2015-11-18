#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char **argv){

        std::ifstream fileread("resultados/confs.out");
        std::ofstream filewrite("resultados/confs.proms");

        std::string line;

        std::string indiv;
        std::string indiv1;
        int how_many = atoi(argv[1]);
        double Nodos[100],Colores[100],Tiempo[100],Conflictos[100],ConflictosAntes[100];
        double Nodos1[100],Colores1[100],Tiempo1[100],Conflictos1[100],ConflictosAntes1[100];
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
                        sline >> devnull;
                        sline >> ConflictosAntes[i];

                        getline(fileread,line);
                        std::istringstream sline1(line);
                        sline1 >> indiv1;
                        sline1 >> devnull;
                        sline1 >> Nodos1[i];
                        sline1 >> devnull;
                        sline1 >> Colores1[i];
                        sline1 >> devnull;
                        sline1 >> Tiempo1[i];
                        sline1 >> devnull;
                        sline1 >> Conflictos1[i];
                        sline1 >> devnull;
                        sline1 >> ConflictosAntes1[i];
                }
                for(int i=1;i<100;i++){
                        Nodos[0]+=Nodos[i];
                        Colores[0]+=Colores[i];
                        Tiempo[0]+=Tiempo[i];
                        Conflictos[0]+=Conflictos[i];
                        ConflictosAntes[0]+=ConflictosAntes[i];
                        Nodos1[0]+=Nodos1[i];
                        Colores1[0]+=Colores1[i];
                        Tiempo1[0]+=Tiempo1[i];
                        Conflictos1[0]+=Conflictos1[i];
                        ConflictosAntes1[0]+=ConflictosAntes1[i];
                }
                Nodos[0]=Nodos[0]/100.0;
                Colores[0]=Colores[0]/100.0;
                Tiempo[0]=Tiempo[0]/100.0;
                Conflictos[0]=Conflictos[0]/100.0;
                ConflictosAntes[0]=ConflictosAntes[0]/100.0;
                Nodos1[0]=Nodos1[0]/100.0;
                Colores1[0]=Colores1[0]/100.0;
                Tiempo1[0]=Tiempo1[0]/100.0;
                Conflictos1[0]=Conflictos1[0]/100.0;
                ConflictosAntes1[0]=ConflictosAntes1[0]/100.0;

                filewrite << std::fixed << indiv << " Nodos : " << Nodos[0] << " Colores: " << Colores[0] << " Tiempo: " << Tiempo[0] << " Conflictos: " << Conflictos[0] << " ConflictosAntes: " << ConflictosAntes[0] << std::endl;
        		filewrite << std::fixed << indiv1 << " Nodos : " << Nodos1[0] << " Colores: " << Colores1[0] << " Tiempo: " << Tiempo1[0] << " Conflictos: " << Conflictos1[0] << " ConflictosAntes: " << ConflictosAntes1[0] << std::endl;
        }


        return 0;
}