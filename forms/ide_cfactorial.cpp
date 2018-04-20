#include "ide_cfactorial.h"
#include "ui_ide_cfactorial.h"

/*
 * Inicializa la interfaz
 */
IDE_CFactorial::IDE_CFactorial(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::IDE_CFactorial)
{

    ui->setupUi(this);
    ui->StepButton->setVisible(false);
    ui->StopButton->setVisible(false);

    ////////////////////////////////
    ui->RamLiveView->setRowCount(0);
    ui->RamLiveView->setColumnCount(4);
    m_TableHeader<<"Nombre"<<"Dirección"<<"Valor"<<"Referencias";
    ui->RamLiveView->setHorizontalHeaderLabels(m_TableHeader);
    ui->RamLiveView->verticalHeader()->setVisible(true);
    ui->RamLiveView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->RamLiveView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->RamLiveView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->RamLiveView->setShowGrid(true);
    ui->RamLiveView->setStyleSheet("QTableView {selection-background-color: red;}");





    /////////////////////////////////
}

IDE_CFactorial::~IDE_CFactorial()
{
    delete ui;
}

/*
 * Evento del botón correr
 * Separa lo escrito en el editor en una lista de expresiones
 * Asigna esta lista de expresiones a un atributo
 */
void IDE_CFactorial::on_RunButton_clicked() {
    ui->RamLiveView->clear();
    ui->RamLiveView->setRowCount(0);
    m_TableHeader<<"Nombre"<<"Dirección"<<"Valor"<<"Referencias";
    ui->RamLiveView->setHorizontalHeaderLabels(m_TableHeader);
    QString codeQT = ui->EditorC->toPlainText();
    string CodeString = codeQT.toStdString();
    if(CodeString != ""){
        ui->StepButton->setVisible(true);
        ui->StopButton->setVisible(true);
        listaExpresiones = new List<Expresion>();
        dividirEnExpresiones(CodeString);
    }
}


//Limpia la consola StdOut
void IDE_CFactorial::on_ClearStdOut_clicked()
{
    ui->StdOut->clear();
}

//Limpia el application log
void IDE_CFactorial::on_ClearAppLog_clicked()
{
    ui->ApplicationLog->clear();
}

void IDE_CFactorial::on_StopButton_clicked()
{
    contador = 0;
    ui->StopButton->setVisible(false);
    ui->StepButton->setVisible(false);
}

/*
 * Toma una expresión y la separa en partes
 * para luego ser validada
 */
void IDE_CFactorial::separarExpresion(string codigo, int nivel) {
    string temp, tipo = "", nombre = "", valor = "", tipoRef = "";

    //Saca el tipo de variable
    int x = 0;
    while (codigo[x] != ' ' && codigo[x] != '(' && codigo[x] != '<') {
        tipo = tipo + codigo[x];
        x++;
    }

    /*
     * Continua aumentando para validar los espacios vacíos
     */
    while (codigo[x] == ' ') {
        x++;
    }

    if (tipo == "show") {
        while (x < codigo.size()) {
            temp = temp + codigo[x];
            x++;
        }
        if(temp[0] == '(' && temp[temp.size()-1] == ')'){
            for(int i = 0; i<temp.size();i++){
                if(i != 0 && i != temp.size()-1){
                    valor = valor+temp[i];
                }
            }
        }
        Expresion nueva;
        nueva.setAtributos(nombre, tipo, valor, nivel);
        listaExpresiones->Insert(nueva);

    } else if(tipo == "reference"){
        if(codigo[x] == '<'){
            x++;
            while(codigo[x] != '>'){
                tipoRef = tipoRef+codigo[x];
                x++;
            }
            x++;
            while(codigo[x] == ' '){
                x++;
            }
            while(codigo[x] != '='){
                if(codigo[x] != ' '){
                    nombre = nombre + codigo[x];
                    x++;
                }else{
                    x++;
                }
            }
            x++;
            while (x < codigo.size()) {
                if(codigo[x] != ' '){
                    valor = valor + codigo[x];
                    x++;
                }else{
                    x++;
                }
            }
        }
        Expresion nueva;
        nueva.setAtributos(nombre, tipo, valor, nivel);
        nueva.setTipoRef(tipoRef);
        listaExpresiones->Insert(nueva);


    } else {

        //Saca la variable nombre de la expresion
        while (codigo[x] != '=') {
            if (codigo[x] != ' ') {
                nombre = nombre + codigo[x];
                x++;
            } else {
                x++;
            }

        }

        x++;
        //Se asegura de saltar los espacios en blanco
        while (codigo[x] == ' ') {
            x++;
        }


        //Saca el valor asignado de la expresión
        while (x < codigo.size()) {
            valor = valor + codigo[x];
            x++;
        }

        Expresion nueva;
        nueva.setAtributos(nombre, tipo, valor, nivel);
        listaExpresiones->Insert(nueva);

    }
}


/*
 * Llama al método encargado de separar la expresion en partes
 * y luego aumenta el contador global
 */
void IDE_CFactorial::on_StepButton_clicked()
{
    if(validarExpresion(listaExpresiones->Get(contador))){
        cout<<"Se cumplió"<<endl;

    }else{
        cout<<"No se cumplió"<<endl;
        string x = "Error en la línea: "+convertirInt(contador);
        QString p = QString::fromStdString(x);
        ui->StdOut->append(p);
    }

    contador++;

    if(contador == listaExpresiones->length()){
        ui->StepButton->setVisible(false);
        ui->StopButton->setVisible(false);
        contador = 0;
    }
}

/*
 * Valida si una cadena de caracteres es un número
 */
bool IDE_CFactorial::esNumero(string valor) {
    {
        for(int x = 0; x<valor.size(); x++ )
        {
            if(valor[x]='.'){}
            // En cuanto un caracter no sea numérico
            else if( '0' > valor[x] || '9' < valor[x] ) {
                return false;
            }
        }

        return true;
    }

}

/*
 * Valida la que la expresión esté correcta con sus
 * partes
 */
bool IDE_CFactorial::validarExpresion(Expresion expresion) {
    //Validación básica de la estructura de una variable entera
    if (expresion.getTipo() == "int") {
        cout << "Tipo entero detectado." << endl;
        if (expresion.getNombre() == "") {
            cout << "El nombre no es válido" << endl;
            return false;
        } else {
            cout << "El nombre es válido." << endl;
            if (expresion.getValor() == "") {
                cout << "Hace falta el valor" << endl;
                return false;
            } else {
                if (esNumero(expresion.getValor())) {
                    //cout<<"Se generará el JSON"<<endl;
                    generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(), expresion.getTipoRef());
                    return true;
                } else {
                    for (int x = 0; x < contador; x++) {
                        if (expresion.getValor() == listaExpresiones->Get(x).getNombre() &&
                            expresion.getTipo() == listaExpresiones->Get(x).getTipo() &&
                            expresion.getNivel() >= listaExpresiones->Get(x).getNivel()) {
                            generarJson(expresion.getTipo(), expresion.getNombre(),
                            listaExpresiones->Get(x).getValor(), expresion.getTipoRef());
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
    } else if (expresion.getTipo() == "char") {
        cout << "Tipo char detectado." << endl;
        if (expresion.getNombre() == "") {
            cout << "El nombre no es válido" << endl;
            return false;
        } else {
            cout << "El nombre es válido." << endl;
            if (expresion.getValor() == "") {
                cout << "Hace falta el valor" << endl;
                return false;
            } else {
                string validacion = "";
                validacion =
                        validacion + expresion.getValor()[0] + expresion.getValor()[expresion.getValor().length() - 1];
                if (validacion == "''" && expresion.getValor().length() == 3) {
                    generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(), expresion.getTipoRef());
                    return true;
                } else {
                    for (int x = 0; x < contador; x++) {
                        if (expresion.getValor() == listaExpresiones->Get(x).getNombre() &&
                            expresion.getTipo() == listaExpresiones->Get(x).getTipo() &&
                            expresion.getNivel() >= listaExpresiones->Get(x).getNivel()) {

                            generarJson(expresion.getTipo(), expresion.getNombre(),
                                        listaExpresiones->Get(x).getValor(), expresion.getTipoRef());
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
    } else if (expresion.getTipo() == "double") {
        cout << "Tipo double detectado." << endl;
        if (expresion.getNombre() == "") {
            cout << "El nombre no es válido" << endl;
            return false;
        } else {
            cout << "El nombre es válido." << endl;
            if (expresion.getValor() == "") {
                cout << "Hace falta el valor" << endl;
                return false;
            } else {
                int cont = 0;
                for(int i = 0; i<expresion.getValor().length(); i++){
                    if(expresion.getValor()[i] == '.'){
                        cont++;
                    }
                }
                if(cont>1){
                    return false;
                }else{
                    if (esNumero(expresion.getValor())) {
                        //cout<<"Se generará el JSON"<<endl;
                        generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(), expresion.getTipoRef());
                        return true;
                    } else {
                        cout << "No es numero" << endl;
                        return false;
                    }
                }
            }
        }

    }else if(expresion.getTipo() == "float"){
            cout << "Tipo float detectado." << endl;
            if (expresion.getNombre() == "") {
                cout << "El nombre no es válido" << endl;
                return false;
            } else {
                cout << "El nombre es válido." << endl;
                if (expresion.getValor() == "") {
                    cout << "Hace falta el valor" << endl;
                    return false;
                } else {
                    int cont = 0;
                    for(int i = 0; i<expresion.getValor().length(); i++){
                        if(expresion.getValor()[i] == '.'){
                            cont++;
                        }
                    }
                    if(cont>1){
                        return false;
                    }else{
                        if (esNumero(expresion.getValor())) {
                            //cout<<"Se generará el JSON"<<endl;
                            generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(), expresion.getTipoRef());
                            return true;
                        } else {
                            cout << "No es numero" << endl;
                            return false;
                        }
                    }
                }
            }

    } else if (expresion.getTipo() == "long") {
        cout << "Tipo long detectado." << endl;
        if (expresion.getNombre() == "") {
            cout << "El nombre no es válido" << endl;
            return false;
        } else {
            cout << "El nombre es válido." << endl;
            if (expresion.getValor() == "") {
                cout << "Hace falta el valor" << endl;
                return false;
            } else {
                if (esNumero(expresion.getValor())) {
                    //cout<<"Se generará el JSON"<<endl;
                    generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(),expresion.getTipoRef());
                    return true;
                } else {
                    for (int x = 0; x < contador; x++) {
                        if (expresion.getValor() == listaExpresiones->Get(x).getNombre() &&
                            expresion.getTipo() == listaExpresiones->Get(x).getTipo() &&
                            expresion.getNivel() >= listaExpresiones->Get(x).getNivel()) {
                            generarJson(expresion.getTipo(), expresion.getNombre(),
                                        listaExpresiones->Get(x).getValor(), expresion.getTipoRef());
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
    }else if(expresion.getTipo() == "show"){
        for (int x = 0; x < contador; x++) {
            if (expresion.getValor()[0] == '"' && expresion.getValor()[expresion.getValor().length() - 1] == '"') {
                string print1 = "";
                for (int x = 0; x < expresion.getValor().length() - 1; x++) {
                    if (expresion.getValor()[x] != '"') {
                        print1 = print1 + expresion.getValor()[x];
                    }
                }
                QString print = QString::fromStdString(print1);
                ui->StdOut->append(print);
                return true;
            } else {
                if (expresion.getValor() == listaExpresiones->Get(x).getNombre() &&
                    expresion.getNivel() >= listaExpresiones->Get(x).getNivel()) {
                    QString print = QString::fromStdString(listaExpresiones->Get(x).getValor());
                    ui->StdOut->append(print);
                    return true;
                }
            }
        }

    }else if(expresion.getTipo() == "reference"){
        if(expresion.getTipoRef() == "int"||"char"||"long"||"float"||"double"){
            if(expresion.getNombre() != ""){
                for(int i = 0; i<listaExpresiones->length();i++){
                    if(listaExpresiones->Get(i).getNombre() == expresion.getValor() &&
                       listaExpresiones->Get(i).getTipo() == expresion.getTipoRef() &&
                       expresion.getNivel() >= listaExpresiones->Get(i).getNivel()){

                        generarJson(expresion.getTipo(), expresion.getNombre(), expresion.getValor(), expresion.getTipoRef());
                        return true;

                    }
                }
            }
        }
    }
}


//Genera el JSON que se le va a pasar al servidor
void IDE_CFactorial::generarJson(string tipo, string nombre, string valor, string tipoRef) {
    Json::Value event;
    event["tipo"] = tipo;
    event["nombre"] = nombre;
    event["valor"] = valor;

    if (tipo == "char") {
        event["tamanio"] = "1";
    } else if (tipo == "int" or tipo == "float") {
        event["tamanio"] = "4";
    } else if (tipo == "double" or tipo == "long") {
        event["tamanio"] = "8";
    } else if (tipo == "reference") {
        event["tamanio"] = "4";
        event["tipoReferencia"] = tipoRef;
    }

    ui->RamLiveView->setRowCount(contador+1);

    string mensaje = event.toStyledString();



    char json[mensaje.size()];
    for (int i = 0; i < mensaje.size(); i++) {
        json[i] = mensaje[i];
    }

    Client *cliente = new Client;
    cliente->crear();
    cliente->enviar(json);
    string JSON = cliente->getMensajeActual();

    Json::Reader reader;
    Json::Value obj;
    reader.parse(JSON, obj);
    cout<<obj["nombre"];

    QString x = QString::fromStdString(obj["nombre"].asString());
    ui->RamLiveView->setItem(contador, 0, new QTableWidgetItem(x));

    x = QString::fromStdString(obj["posmemoria"].asString());
    ui->RamLiveView->setItem(contador, 1, new QTableWidgetItem(x));

    x = QString::fromStdString(obj["valor"].asString());
    ui->RamLiveView->setItem(contador, 2, new QTableWidgetItem(x));

    x = QString::fromStdString(obj["referencias"].asString());
    ui->RamLiveView->setItem(contador, 3, new QTableWidgetItem(x));
}

void IDE_CFactorial::dividirEnExpresiones(string Texto) {
    string actual = "";
    int nivel = 0;

    for(int x = 0; x<Texto.size(); x++){
        if(Texto[x] == ';') {
            x++;
            while(Texto[x]== ' '){
                x++;
            }
            separarExpresion(actual, nivel);
            actual = "";
        }else if(Texto[x] == '{'){
            x++;
            while(Texto[x]== ' '){
                x++;
            }
            nivel++;
            actual = "";
        }else if(Texto[x] == '}'){
            x++;
            while(Texto[x]== ' '){
                x++;
            }
            nivel--;
            actual = "";
        }else{
            actual = actual+Texto[x];
        }
    }

    cout<<endl;
    for(int x = 0; x<listaExpresiones->length(); x++){
        Expresion t = listaExpresiones->Get(x);
        cout<<"Tipo: "<<t.getTipo()<<" Nombre: "<<t.getNombre()<< " Valor: "<<t.getValor()<<" Nivel: "<<t.getNivel()<<endl;
    }
}

string IDE_CFactorial::convertirInt(int i) {
    {
        //   int to string en c++
        string num;
        int temp;
        while(i / 10!=0){
            temp=i%10;
            i= i/10;
            temp =temp + 48;
            num = (char)temp + num;

        }
        i=i+48;
        num = (char)i + num ;
        return num;
    }
}

