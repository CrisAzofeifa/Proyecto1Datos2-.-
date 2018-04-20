#include <QApplication>
#include "forms/ide_cfactorial.h"
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]) {


    QApplication a(argc,argv);
    IDE_CFactorial w;
    w.show();
    Json::Value event;
    event["tipo"] = "int";
    string x = event.toStyledString();
    Json::Reader reader;
    Json::Value obj;
    reader.parse(x, obj);
    cout<<obj["tipo"];

    return a.exec();

}