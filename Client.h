//
// Created by kimberlyc on 25/03/18.
//
#include <iostream>
#ifndef C_CLIENT_H
#define C_CLIENT_H

using namespace std;
class Client {
public:
    string mensajeActual;

    int crear();
    int conectar();
    int enviar(char json[]);
    int recibir();

    string getMensajeActual(){
        return mensajeActual;
    }


};


#endif //C_CLIENT_H
