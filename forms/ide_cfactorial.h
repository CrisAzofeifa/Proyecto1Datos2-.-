#ifndef IDE_CFACTORIAL_H
#define IDE_CFACTORIAL_H

#include <QMainWindow>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <Client.h>
#include <List.h>
#include "Expresion.h"
#include <QDesktopWidget>
#include <string>


using namespace std;

namespace Ui {
    class IDE_CFactorial;
}

class IDE_CFactorial : public QMainWindow
{
Q_OBJECT

public:
    explicit IDE_CFactorial(QWidget *parent = 0);
    ~IDE_CFactorial();

private slots:
    void on_RunButton_clicked();

    void on_ClearStdOut_clicked();

    void on_ClearAppLog_clicked();

    void on_StopButton_clicked();

    void separarExpresion(string code, int nivel);

    void on_StepButton_clicked();

    bool esNumero(string valor);

    bool validarExpresion(Expresion expresion);

    void generarJson(string tipo, string nombre, string valor, string tipoRef);

    void dividirEnExpresiones(string Texto);

    string convertirInt(int xi);

private:
    Ui::IDE_CFactorial *ui;
    List<Expresion> *listaExpresiones;
    QStringList m_TableHeader;
    int contador = 0;
};



#endif // IDE_CFACTORIAL_H
