#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

int main(int argc, char **argv){

        std::ifstream fileread("test.out");
        std::ofstream filewrite("test.proms");

        std::string line;

        std::string indiv;
        int how_many = 10;//atoi(argv[1]);
        double Nodos[11],Colores[11],TiempoAntes[11],TiempoDespues[11],ConflictosDespues[11],ConflictosAntes[11];
        std::string devnull;

        for(int j=0;j<how_many;j++) {

                for(int i=0;i<11;i++){
                        getline(fileread,line);
                        std::istringstream sline(line);
                        sline >> indiv;
                        sline >> devnull;
                        sline >> Nodos[i];
                        sline >> devnull;
                        sline >> Colores[i];
                        sline >> devnull;
                        sline >> TiempoAntes[i];
                        sline >> devnull;
                        sline >> TiempoDespues[i];
                        sline >> devnull;
                        sline >> ConflictosDespues[i];
                        sline >> devnull;
                        sline >> ConflictosAntes[i];
                }
                for(int i=1;i<11;i++){
                        Nodos[0]+=Nodos[i];
                        Colores[0]+=Colores[i];
                        TiempoAntes[0]+=TiempoAntes[i];
                        TiempoDespues[0]+=TiempoDespues[i];
                        ConflictosDespues[0]+=ConflictosDespues[i];
                        ConflictosAntes[0]+=ConflictosAntes[i];
                }
                Nodos[0]=Nodos[0]/11.0;
                Colores[0]=Colores[0]/11.0;
                TiempoAntes[0]=TiempoAntes[0]/11.0;
                TiempoDespues[0]=TiempoDespues[0]/11.0;
                ConflictosDespues[0]=ConflictosDespues[0]/11.0;
                ConflictosAntes[0]=ConflictosAntes[0]/11.0;

                filewrite << indiv << " " << "Nodos: " << std::fixed << Nodos[0] << " Colores: " << Colores[0] << " TiempoGoloso: " << TiempoAntes[0] << " TiempoBusq: " << TiempoDespues[0] << " ConflictosDespues: " << ConflictosDespues[0] << " ConflictosAntes: " << ConflictosAntes[0] << std::endl;
        }

        return 0;
}