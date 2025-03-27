#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cctype>
#include <fstream>
#include <chrono>
#include <algorithm>


using namespace std;

// Código creado por Monjaraz Briseño Luis Fernando

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Función que valida que los datos ingresados por el usuario sean compatibles con un STRING
bool es_valido(string str) {
  if (str.length() == 0) {
    return false;
  }
  
  for (char c : str) {
    if (!isdigit(c) && !isalpha(c) && !isspace(c)) {
      return false;
    }
  }
  
  return true;
}

// Función que valida que los datos ingresados por el usuario sean Numeros en un string
bool ValidaNE(string str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función que valida que los datos ingresados por el usuario sean Letras en un string
bool ValidaNombre(string str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

// Función que valida que los datos ingresados por el usuario sean números enteros
bool ValidaNumerosEnteros(char *dato){
    bool ban = true;
    int i = 0;
    if (*dato == '-' || *dato == '+') {
        i++;
    }
    while (*(dato + i) != '\0') {
        if (*(dato + i) < '0' || *(dato + i) > '9') {
            ban = false;
            break;
        }
        i++;
    }
    return ban;
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

class Node {
    public:
        int number;
        int posicion;
        string nombre;
        string artista;
        int duracion;
        int duracions;
        string album;
        string genero;
        string ruta;
        Node *next;
        Node *back;
};

class CircularList{
    protected:
        Node *ptrHead;
    public:
        CircularList();
        void insert_Last(int number, string nombre, string artista, int duracion, int duracions, string ruta, string album, string genero);
        bool empty();
        void print();
        void moveTo(int);
        Node* searchByPosition(int);
        Node* searchByPosition2(int);
        Node* searchByname(string);
        Node* searchByArtist(string);
        void modifyNode(int, string, string, int, int, string, string, string);
        void sortId();
        void sortName();
        void sortArtist();
        void sortAscending();
        void sortDescending();
        void remover();
        void removeAll();
        void reproducir();
        void reproducirBusqueda();
        void detener();
        void writeToFileAll();
        void alterarFile();
        void readFromFile();
        void pantallazo();
        bool isEmpty();
        void detenerV2();
};

CircularList::CircularList(){
    ptrHead = NULL;
}

void CircularList::insert_Last(int number, string nombre, string artista, int duracion, int duracions, string ruta, string album, string genero){
    Node *new_node = new Node();
    if (empty()){
        new_node->number = number;
        new_node->posicion = 1; // Si es el primer elemento, la posición es 1.
    } else {
        Node* temp = ptrHead;
        do {
            if (temp->number == number) {
                number++;
                temp = ptrHead;
            } else {
                temp = temp->next;
            }
        } while (temp != ptrHead);
        new_node->number = number;
        new_node->posicion = ptrHead->back->posicion + 1; // La posición es una más que la del último elemento.
        new_node->number = new_node->posicion;
    }
    new_node->nombre = nombre;
    new_node->artista = artista;
    new_node->duracion = duracion;
    new_node->duracions = duracions;
    new_node->ruta = ruta;
    new_node->album = album;
    new_node->genero = genero;
    if (ptrHead == NULL){
        new_node->next = new_node;
        new_node->back = new_node;
        ptrHead = new_node;
    } else {
        Node *last_node = ptrHead->back;
        new_node->next = ptrHead;
        new_node->back = last_node;
        ptrHead->back = new_node;
        last_node->next = new_node;
    }
}

bool CircularList::empty() {
    if (ptrHead == NULL) return true;
    else return false; 
}
/* cout<<temp->number <<"-"<< temp->nombre <<"-"<< temp->artista <<"-"<< temp->duracion <<"-"<< temp->duracions <<"-"<< temp->ruta <<"-" << temp->album <<"-"<< temp->genero <<endl; */
void CircularList::print(){
    int y = 3;
    if (!empty()){
        Node *temp = ptrHead;
        do {
            gotoxy(1,y);
            cout << temp->number;
            gotoxy(8,y);
            cout << temp->nombre;
            gotoxy(45,y);
            cout << temp->artista;
            gotoxy(77,y);
            cout << temp->duracion <<":"<< temp->duracions;
            y = y + 2;
            temp = temp->next;
        }while(temp != ptrHead);
        cout << "\n";
    }
}

void CircularList::moveTo(int opc){
    int i=0;
    if (!empty()) {
        Node *temp = ptrHead;
        if(opc==1){
            temp = temp->next;
            ptrHead=temp;
        }else if(opc==2){
            temp = temp->back;
            ptrHead=temp;
        }
    }
}

Node* CircularList::searchByPosition(int pos){
    if (!empty()) {
        Node *temp = ptrHead;
        int i = 1;
        do {
            if (i == pos){
        gotoxy(86, 2);
        cout << "La ruta de la cancion actual es: ";
        gotoxy(86, 3); 
        cout << temp->ruta << endl;
        gotoxy(86, 4);
        cout << "8. Detener cancion" << endl;
        gotoxy(86, 5);
        cout << "Nodo encontrado";
        gotoxy(86, 6);
        cout << "Indice: " << temp -> number;
        gotoxy(86, 7);
        cout << "Cancion: " << temp -> nombre;
        gotoxy(86, 8);
        cout << "Artista: " << temp -> artista;
        gotoxy(86, 9);
        cout << "Duracion: " << temp -> duracion << ":" << temp -> duracions;
        gotoxy(86, 10);
        cout << "Ruta: " << temp -> ruta;
        gotoxy(86, 11);
        cout << "Album: " << temp -> album;
        gotoxy(86, 12);
        cout << "Genero: " << temp -> genero;
        gotoxy(1,30);
        cout << "Artista: " << temp->artista;
        gotoxy(40,30);
        cout << "Genero: " << temp->genero;
        gotoxy(1,28);
        cout << "Cancion: " << temp->nombre;
        gotoxy(40,28);
        cout << "Album: " << temp->album;
        gotoxy(1,26);
        cout << "Datos de la cancion" << endl;
        string ruta = temp->ruta;
        PlaySound(TEXT(ruta.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        // Progreso de la cancion
        int minutos = temp->duracion;
        int segundos = temp->duracions;
        minutos = minutos * 60;
        float total = minutos + segundos;
        int progreso = 1;
        float time = total/84;
        int x = 1;
        while (progreso <= 84){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            gotoxy(x, 24);
            printf("%c", 219); //█
            gotoxy(x, 23);
            printf("%c", 219); //█
            x++;
            progreso++;
            // Verificar si se ha presionado alguna tecla
            if (kbhit() && getch() == '8') {
                detener();
                break; // Salir del bucle si se ha presionado una tecla
            }
            Sleep(time*1000);
        }
                return temp;
            }
            temp = temp->next;
            i++;
        } while (temp != ptrHead);
    }
    return NULL;
}

Node* CircularList::searchByPosition2(int pos){
    if (!empty()) {
        Node *temp = ptrHead;
        int i = 1;
        do {
            if (i == pos){
                return temp;
            }
            temp = temp->next;
            i++;
        } while (temp != ptrHead);
    }
    return NULL;
}

Node* CircularList::searchByname(string name){
    if (!empty()) {
        Node *temp = ptrHead;
        do {
            if (temp->nombre == name){
                        gotoxy(86, 2);
        cout << "La ruta de la cancion actual es: ";
        gotoxy(86, 3); 
        cout << temp->ruta << endl;
        gotoxy(86, 4);
        cout << "8. Detener cancion" << endl;
        gotoxy(86, 5);
        cout << "Nodo encontrado";
        gotoxy(86, 6);
        cout << "Indice: " << temp -> number;
        gotoxy(86, 7);
        cout << "Cancion: " << temp -> nombre;
        gotoxy(86, 8);
        cout << "Artista: " << temp -> artista;
        gotoxy(86, 9);
        cout << "Duracion: " << temp -> duracion << ":" << temp -> duracions;
        gotoxy(86, 10);
        cout << "Ruta: " << temp -> ruta;
        gotoxy(86, 11);
        cout << "Album: " << temp -> album;
        gotoxy(86, 12);
        cout << "Genero: " << temp -> genero;
        gotoxy(1,30);
        cout << "Artista: " << temp->artista;
        gotoxy(40,30);
        cout << "Genero: " << temp->genero;
        gotoxy(1,28);
        cout << "Cancion: " << temp->nombre;
        gotoxy(40,28);
        cout << "Album: " << temp->album;
        gotoxy(1,26);
        cout << "Datos de la cancion" << endl;
        string ruta = temp->ruta;
        PlaySound(TEXT(ruta.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        // Progreso de la cancion
        int minutos = temp->duracion;
        int segundos = temp->duracions;
        minutos = minutos * 60;
        float total = minutos + segundos;
        int progreso = 1;
        float time = total/84;
        int x = 1;
        while (progreso <= 84){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            gotoxy(x, 24);
            printf("%c", 219); //█
            gotoxy(x, 23);
            printf("%c", 219); //█
            x++;
            progreso++;
            // Verificar si se ha presionado alguna tecla
            if (kbhit() && getch() == '8') {
                detener();
                break; // Salir del bucle si se ha presionado una tecla
            }
            Sleep(time*1000);
        }
                return temp;
            }
            temp = temp->next;
        } while (temp != ptrHead);
    }
    return NULL;
}

Node* CircularList::searchByArtist(string artist){
    if (!empty()) {
        Node *temp = ptrHead;
        do {
            if (temp->artista == artist){
        gotoxy(86, 2);
        cout << "La ruta de la cancion actual es: ";
        gotoxy(86, 3); 
        cout << temp->ruta << endl;
        gotoxy(86, 4);
        cout << "8. Detener cancion" << endl;
        gotoxy(86, 5);
        cout << "Nodo encontrado";
        gotoxy(86, 6);
        cout << "Indice: " << temp -> number;
        gotoxy(86, 7);
        cout << "Cancion: " << temp -> nombre;
        gotoxy(86, 8);
        cout << "Artista: " << temp -> artista;
        gotoxy(86, 9);
        cout << "Duracion: " << temp -> duracion << ":" << temp -> duracions;
        gotoxy(86, 10);
        cout << "Ruta: " << temp -> ruta;
        gotoxy(86, 11);
        cout << "Album: " << temp -> album;
        gotoxy(86, 12);
        cout << "Genero: " << temp -> genero;
        gotoxy(1,30);
        cout << "Artista: " << temp->artista;
        gotoxy(40,30);
        cout << "Genero: " << temp->genero;
        gotoxy(1,28);
        cout << "Cancion: " << temp->nombre;
        gotoxy(40,28);
        cout << "Album: " << temp->album;
        gotoxy(1,26);
        cout << "Datos de la cancion" << endl;
        string ruta = temp->ruta;
        PlaySound(TEXT(ruta.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        // Progreso de la cancion
        int minutos = temp->duracion;
        int segundos = temp->duracions;
        minutos = minutos * 60;
        float total = minutos + segundos;
        int progreso = 1;
        float time = total/84;
        int x = 1;
        while (progreso <= 84){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            gotoxy(x, 24);
            printf("%c", 219); //█
            gotoxy(x, 23);
            printf("%c", 219); //█
            x++;
            progreso++;
            // Verificar si se ha presionado alguna tecla
            if (kbhit() && getch() == '8') {
                detener();
                break; // Salir del bucle si se ha presionado una tecla
            }
            Sleep(time*1000);
        }
        return temp;
            }
            temp = temp->next;
        } while (temp != ptrHead);
    }
    return NULL;
}

void CircularList::modifyNode(int pos, string nombrem, string artistam, int duracionm, int duracionsm, string rutam, string albumm, string generom){
    Node *nodeToModify = searchByPosition2(pos);
    if (nodeToModify != NULL) {
        nodeToModify->nombre = nombrem;
        nodeToModify->artista = artistam;
        nodeToModify->duracion = duracionm;
        nodeToModify->duracions = duracionsm;
        nodeToModify->ruta = rutam;
        nodeToModify->album = albumm;
        nodeToModify->genero = generom;
    } else {
        cout << "La posicion " << pos << " no existe en la lista." << endl;
    }
}

void CircularList::sortId() {
    if (!empty()) {
        Node *current = ptrHead;
        do {
            Node *minNode = current;
            Node *index = current->next;
            while (index != ptrHead) {
                if (index->number < minNode->number) {
                    minNode = index;
                }
                index = index->next;
            }
            if (minNode != current) {
                string tempNombre = current->nombre;
                string tempArtista = current->artista;
                int tempDuracion = current->duracion;
                int tempDuracions = current->duracions;
                string tempRuta = current->ruta;
                string tempAlbum = current->album;
                string tempGenero = current->genero;
                int tempNumber = current->number;

                current->nombre = minNode->nombre;
                current->artista = minNode->artista;
                current->duracion = minNode->duracion;
                current->duracions = minNode->duracions;
                current->ruta = minNode->ruta;
                current->album = minNode->album;
                current->genero = minNode->genero;
                current->number = minNode->number;

                minNode->nombre = tempNombre;
                minNode->artista = tempArtista;
                minNode->duracion = tempDuracion;
                minNode->duracions = tempDuracions;
                minNode->ruta = tempRuta;
                minNode->album = tempAlbum;
                minNode->genero = tempGenero;
                minNode->number = tempNumber;
            }
            current = current->next;
        } while (current != ptrHead);
    }
}

void CircularList::sortName() {
    if (!empty()) {
        Node *current = ptrHead;
        do {
            Node *index = current->next;
            while (index != ptrHead) {
                if (current->nombre > index->nombre) {
                    string tempNombre = current->nombre;
                    string tempArtista = current->artista;
                    int tempDuracion = current->duracion;
                    int tempDuracions = current->duracions;
                    string tempRuta = current->ruta;
                    string tempAlbum = current->album;
                    string tempGenero = current->genero;

                    current->nombre = index->nombre;
                    current->artista = index->artista;
                    current->duracion = index->duracion;
                    current->duracions = index->duracions;
                    current->ruta = index->ruta;
                    current->album = index->album;
                    current->genero = index->genero;

                    index->nombre = tempNombre;
                    index->artista = tempArtista;
                    index->duracion = tempDuracion;
                    index->duracions = tempDuracions;
                    index->ruta = tempRuta;
                    index->album = tempAlbum;
                    index->genero = tempGenero;
                }
                index = index->next;
            }
            current = current->next;
        } while (current != ptrHead);
    }
}

void CircularList::sortArtist() {
    if (!empty()) {
        Node *current = ptrHead;
        do {
            Node *index = current->next;
            while (index != ptrHead) {
                if (current->artista > index->artista) {
                    string tempNombre = current->nombre;
                    string tempArtista = current->artista;
                    int tempDuracion = current->duracion;
                    int tempDuracions = current->duracions;
                    string tempRuta = current->ruta;
                    string tempAlbum = current->album;
                    string tempGenero = current->genero;

                    current->nombre = index->nombre;
                    current->artista = index->artista;
                    current->duracion = index->duracion;
                    current->duracions = index->duracions;
                    current->ruta = index->ruta;
                    current->album = index->album;
                    current->genero = index->genero;

                    index->nombre = tempNombre;
                    index->artista = tempArtista;
                    index->duracion = tempDuracion;
                    index->duracions = tempDuracions;
                    index->ruta = tempRuta;
                    index->album = tempAlbum;
                    index->genero = tempGenero;
                }
                index = index->next;
            }
            current = current->next;
        } while (current != ptrHead);
    }
}

void CircularList::sortAscending() {
    if (!empty()) {
        Node *i, *j, *minNode;
        for (i = ptrHead; i->back != ptrHead; i = i->next) {
            minNode = i;
            for (j = i->next; j != ptrHead; j = j->next) {
                if (j->number < minNode->number) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                string tempNombre = i->nombre;
                string tempArtista = i->artista;
                int tempDuracion = i->duracion;
                int tempDuracions = i->duracions;
                string tempRuta = i->ruta;
                string tempAlbum = i->album;
                string tempGenero = i->genero;
                int tempNumber = i->number;

                i->nombre = minNode->nombre;
                i->artista = minNode->artista;
                i->duracion = minNode->duracion;
                i->duracions = minNode->duracions;
                i->ruta = minNode->ruta;
                i->album = minNode->album;
                i->genero = minNode->genero;
                i->number = minNode->number;

                minNode->nombre = tempNombre;
                minNode->artista = tempArtista;
                minNode->duracion = tempDuracion;
                minNode->duracions = tempDuracions;
                minNode->ruta = tempRuta;
                minNode->album = tempAlbum;
                minNode->genero = tempGenero;
                minNode->number = tempNumber;
            }
        }
    }
}

void CircularList::sortDescending() {
    if (!empty()) {
        Node *i, *j, *maxNode;
        for (i = ptrHead; i->back != ptrHead; i = i->next) {
            maxNode = i;
            for (j = i->next; j != ptrHead; j = j->next) {
                if (j->number > maxNode->number) {
                    maxNode = j;
                }
            }
            if (maxNode != i) {
                string tempNombre = i->nombre;
                string tempArtista = i->artista;
                int tempDuracion = i->duracion;
                int tempDuracions = i->duracions;
                string tempRuta = i->ruta;
                string tempAlbum = i->album;
                string tempGenero = i->genero;
                int tempNumber = i->number;

                i->nombre = maxNode->nombre;
                i->artista = maxNode->artista;
                i->duracion = maxNode->duracion;
                i->duracions = maxNode->duracions;
                i->ruta = maxNode->ruta;
                i->album = maxNode->album;
                i->genero = maxNode->genero;
                i->number = maxNode->number;

                maxNode->nombre = tempNombre;
                maxNode->artista = tempArtista;
                maxNode->duracion = tempDuracion;
                maxNode->duracions = tempDuracions;
                maxNode->ruta = tempRuta;
                maxNode->album = tempAlbum;
                maxNode->genero = tempGenero;
                maxNode->number = tempNumber;
            }
        }
    }
}

void CircularList::remover(){
    if (!empty()) {
        Node *temp = ptrHead;
        if (temp->next == ptrHead) {
            ptrHead = NULL;
        } else {
            Node *last_node = ptrHead->back;
            ptrHead = ptrHead->next;
            ptrHead->back = last_node;
            last_node->next = ptrHead;
        }
        delete temp;
    }
}

void CircularList::removeAll(){
    if (!empty()) {
        Node *current = ptrHead;
        do {
            Node *temp = current;
            current = current->next;
            delete temp;
        } while (current != ptrHead);
        ptrHead = NULL;
    }
}

void CircularList::reproducir(){
    if(!empty()){
        Node *currentSong = ptrHead;
        gotoxy(86, 2);
        cout << "La ruta de la cancion actual es: ";
        gotoxy(86, 3); 
        cout << currentSong->ruta << endl;
        gotoxy(86, 4);
        cout << "8. Detener cancion" << endl;
        gotoxy(1,30);
        cout << "Artista: " << currentSong->artista;
        gotoxy(40,30);
        cout << "Genero: " << currentSong->genero;
        gotoxy(1,28);
        cout << "Cancion: " << currentSong->nombre;
        gotoxy(40,28);
        cout << "Album: " << currentSong->album;
        gotoxy(1,26);
        cout << "Datos de la cancion" << endl;
        string ruta = currentSong->ruta;
        PlaySound(TEXT(ruta.c_str()), NULL, SND_FILENAME | SND_ASYNC);
        // Progreso de la cancion
        int minutos = currentSong->duracion;
        int segundos = currentSong->duracions;
        minutos = minutos * 60;
        float total = minutos + segundos;
        int progreso = 1;
        float time = total/84;
        int x = 1;
        while (progreso <= 84){
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            gotoxy(x, 24);
            printf("%c", 219); //█
            gotoxy(x, 23);
            printf("%c", 219); //█
            x++;
            progreso++;
            // Verificar si se ha presionado alguna tecla
            if (kbhit() && getch() == '8') {
                detenerV2();
                break; // Salir del bucle si se ha presionado una tecla
            }
            Sleep(time*1000);
        }
    }
}

void CircularList::detener(){
    if(!empty()){
        PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
        gotoxy(86, 13);
        cout << "Se ha detenido la cancion" << endl;
        PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // restaurar color original
    }
}
void CircularList::detenerV2(){
    if(!empty()){
        gotoxy(86, 5);
        cout << "Se ha detenido la cancion" << endl;
        gotoxy(86, 6);
        system("pause");
        PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // restaurar color original
    }
}
void CircularList::writeToFileAll() {
    ofstream file("canciones.txt", ios::app);
    if (file.is_open()) {
        if (!isEmpty()) { // Verifica si la lista está vacía
            Node *current = ptrHead;
            do {
                file << current->number << " " << current->nombre << " " << current->artista << " " << current->duracion << " " << current->duracions << " " << current->ruta << " " << current->album << " " << current->genero << endl;
                current = current->next;
            } while (current != ptrHead);
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void CircularList::alterarFile() {
    ifstream file("canciones.txt");
    ofstream tempfile("tempcanciones.txt");
    if (file.is_open() && tempfile.is_open()) {
        file.close();
        tempfile.close();
        remove("canciones.txt");
        rename("tempcanciones.txt", "canciones.txt");
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    
}

void CircularList::readFromFile() {
    ifstream myfile("canciones.txt");
    if (myfile.is_open()) {
        // Verificar si el archivo está vacío
        if (myfile.peek() == std::ifstream::traits_type::eof()) {
            myfile.close();
            return; // No hay datos en el archivo, terminar la función sin leer
        }
        
        int number;
        string nombre;
        string artista;
        int duracion;
        int duracions;
        string ruta;
        string album;
        string genero;
        while (myfile >> number >> nombre >> artista >> duracion >> duracions >> ruta >> album >> genero){
            insert_Last(number, nombre, artista, duracion, duracions, ruta, album, genero);
        }
        myfile.close();
    }
}

void CircularList::pantallazo() {
      int x = 1, y = 1;
  gotoxy(0,0);
  printf("%c", 201); //╔
  gotoxy(132,0);
  printf("%c", 187); //╗
  gotoxy(0,31);
  printf("%c", 200); //╚
  gotoxy(132,31);
  printf("%c", 188); //╝
  while (y<=30)
  {
    gotoxy(0,y);
    printf("%c", 186); //║
    gotoxy(132,y);
    printf("%c", 186); //║
    y++;
  }
  while (x<=131)
  {
    gotoxy(x,0);
    printf("%c", 205); //═
    gotoxy(x,31);
    printf("%c", 205); //═
    x++;
  }
  gotoxy(85, 0);
  printf("%c", 203); //╦
  gotoxy(85, 31);
  printf("%c", 202); //╩
  x = 1;
  y = 1;

  while (y<=30)
  {
    gotoxy(85,y);
    printf("%c", 186); //║
    y++;
  }
  x = 1;
  y = 1;
  gotoxy(0, 29);
  printf("%c", 204); //╠
  gotoxy(85,29);
  printf("%c", 185); //╣
  while (x<=84){
    gotoxy(x,29);
    printf("%c", 205); //═
    x++;
  }
  gotoxy(0, 27);
  printf("%c", 204); //╠
  gotoxy(85,27);
  printf("%c", 185); //╣
  x = 1;
  while (x<=84){
    gotoxy(x,27);
    printf("%c", 205); //═
    x++;
  }
  gotoxy(0, 25);
  printf("%c", 204); //╠
  gotoxy(85,25);
  printf("%c", 185); //╣
  x = 1;
  while (x<=84){
    gotoxy(x,25);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,2);
    printf("%c", 205); //═
    x++;
  }
  gotoxy(1,26);
  cout << "Datos de la cancion" << endl;
  gotoxy(1,1);
  printf("Indice");
  gotoxy(7,1);
  printf("%c", 186); //║
  gotoxy(7,0);
  printf("%c", 203); //╦
  gotoxy(7,2);
  printf("%c", 202); //╩
  gotoxy(0,2);
  printf("%c", 204); //╠
  gotoxy(85,2);
  printf("%c", 185); //╣
  gotoxy(8,1);
  printf("Nombre Cancion");
  gotoxy(44,1);
  printf("%c", 186); //║
  gotoxy(44,0);
  printf("%c", 203); //╦
  gotoxy(44,2);
  printf("%c", 202); //╩
  gotoxy(45,1);
  printf("Artista");
  gotoxy(76,1);
  printf("%c", 186); //║
  gotoxy(76,0);
  printf("%c", 203); //╦
  gotoxy(76,2);
  printf("%c", 202); //╩
  gotoxy(77,1);
  printf("Duracion");
  x = 7;
  y = 3;
  while (y<=22)
  {
    gotoxy(7,y);
    printf("%c", 186); //║
    y++;
  }
  x = 44;
  y = 3;
  while (y<=22)
  {
    gotoxy(44,y);
    printf("%c", 186); //║
    y++;
  }
  x = 76;
  y = 3;
  while (y<=22)
  {
    gotoxy(76,y);
    printf("%c", 186); //║
    y++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,4);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,6);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,8);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,10);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,12);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,14);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,16);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,18);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,20);
    printf("%c", 205); //═
    x++;
  }
  x = 1;
  while (x<=84){
    gotoxy(x,22);
    printf("%c", 205); //═
    x++;
  }
  y = 2;
  x = 1;
  while (y<=22)
  {
    gotoxy(0,y);
    printf("%c", 204); //╠
    y = y+2;
  }
  y = 2;
  while (y<=22)
  {
    gotoxy(85,y);
    printf("%c", 185); //╣
    y = y+2;
  }
  y = 2;
  while (y<=20)
  {
    gotoxy(7,y);
    printf("%c", 206); //╬
    y = y+2;
  }
  gotoxy(7,22);
  printf("%c", 202); //╩
  y = 2;
  gotoxy(44,2);
  printf("%c", 206); //╬
  while (y<=20)
  {
    gotoxy(44,y);
    printf("%c", 206); //╬
    y = y+2;
  }
  gotoxy(44,22);
  printf("%c", 202); //╩
  y = 2;
  gotoxy(76,2);
  printf("%c", 206); //╬
  while (y<=20)
  {
    gotoxy(76,y);
    printf("%c", 206); //╬
    y = y+2;
  }
  gotoxy(76,22);
  printf("%c", 202); //╩
}
bool CircularList::isEmpty() {
    return ptrHead == nullptr;
}



int main(int argc, char** argv) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    system("pause");
    int opc=0,opc2=0;
    int contador = 1;
    char opcc[100];
    CircularList *obj = new CircularList();
    obj->readFromFile();
    cout<<endl;
    do{ system("cls");
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // restaurar color original
        obj->alterarFile();
        obj->writeToFileAll();
        obj->print();
        obj->pantallazo();
        gotoxy(86, 2);
        cout<<"Menu"<<endl;
        gotoxy(86, 3);
        cout << "1. Agregar cancion" << endl; // Listo
        gotoxy(86, 4);
        cout << "2. Buscar por: " << endl; // Listo
        gotoxy(86, 5);
        cout << "3. Ordenar por: " << endl; // Listo
        gotoxy(86, 6);
        cout << "4. Editar Registro" << endl; // Listo
        gotoxy(86, 7);
        cout << "5. Eliminar Registro" << endl; // Listo
        gotoxy(86, 8);
        cout << "6. Vaciar lista" << endl; // Listo
        gotoxy(86, 9);
        cout << "7. Reproducir (La que este mas arriba)" << endl; // Listo
        gotoxy(86, 10);
        cout << "8. Detener cancion" << endl; // Listo
        gotoxy(86, 11);
        cout << "9. Mover" << endl; // Listo
        gotoxy(86, 12);
        cout << "10. Salir" << endl; // Listo
        gotoxy(86, 13);
        cout << "Opcion: ";
        gotoxy(86, 14);
        cin>>opcc;
        if(ValidaNumerosEnteros(opcc)==true){
            opc=atoi(opcc);
        }else{
            cout<<"Ingrese un numero entero"<<endl;
            system("pause");
            main(argc,argv);
        }
        switch(opc){
            case 1:{
                system("cls");
                obj->print();
                obj->pantallazo();
                int duracion, duracions;
                char duracionc[100], duracionsc[100];
                string nombre,artista,ruta,album,genero;
                gotoxy(86, 2);
                cout << "Ingrese el nombre de la cancion: ";
                gotoxy(86, 3);
                cin >> nombre;
                if(!ValidaNombre(nombre)){
                    gotoxy(86, 4);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 5);
                    system("pause");
                    break;
                }
                gotoxy(86, 4);
                cout << "Ingrese el nombre del artista: ";
                gotoxy(86, 5);
                cin >> artista;
                if(!ValidaNombre(artista)){
                    gotoxy(86, 6);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 7);
                    system("pause");
                    break;
                }
                gotoxy(86, 6);
                cout << "Ingrese la duracion de la cancion (minutos): ";
                gotoxy(86, 7);
                cin >> duracionc;
                if(ValidaNumerosEnteros(duracionc)==true){
                    duracion=atoi(duracionc);
                }else{
                    gotoxy(86, 8);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 9);
                    system("pause");
                    break;
                }
                gotoxy(86, 8);
                cout << "Ingrese la duracion de la cancion (segundos): ";
                gotoxy(86, 9);
                cin >> duracionsc;
                if(ValidaNumerosEnteros(duracionsc)==true){
                    duracions=atoi(duracionsc);
                }else{
                    gotoxy(86, 10);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 11);
                    system("pause");
                    break;
                }
                gotoxy(86, 10);
                cout << "Ingrese la ruta de la cancion: ";
                gotoxy(86, 11);
                cin >> ruta;
                if(!ValidaNombre(ruta)){
                    gotoxy(86, 12);
                    cout<<"Ingrese una ruta valida"<<endl;
                    gotoxy(86, 13);
                    system("pause");
                    break;
                }
                gotoxy(86, 12);
                cout << "Ingrese el album de la cancion: ";
                gotoxy(86, 13);
                cin >> album;
                if(!ValidaNombre(album)){
                    gotoxy(86, 14);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 15);
                    system("pause");
                    break;
                }
                gotoxy(86, 14);
                cout << "Ingrese el genero de la cancion: ";
                gotoxy(86, 15);
                cin >> genero;
                if(!ValidaNombre(genero)){
                    gotoxy(86, 16);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 17);
                    system("pause");
                    break;
                }
                obj->insert_Last(contador, nombre, artista, duracion, duracions, ruta, album, genero);
                obj->alterarFile();
                obj->writeToFileAll();
                contador++;
                obj->print();
            }break;
            case 2:{
                int opcion;
                char opcionc[100];
                system("cls");
                obj->print();
                obj->pantallazo();
                gotoxy(86, 2);
                cout << "Buscar por: " << endl;
                gotoxy(86, 3);
                cout << "1. Indice" << endl;
                gotoxy(86, 4);
                cout << "2. Nombre de cancion" << endl;
                gotoxy(86, 5);
                cout << "3. Nombre de artista" << endl;
                gotoxy(86, 6);
                cin >> opcionc;
                if(ValidaNumerosEnteros(opcionc)==true){
                    opcion=atoi(opcionc);
                }else{
                    gotoxy(86, 7);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 8);
                    system("pause");
                    break;
                }
                switch (opcion){
                    case 1: {
                        system("cls");
                        obj->print();
                        obj->pantallazo();
                        gotoxy(86, 2);
                        cout << "Que posicion desea buscar?" << endl;
                        gotoxy(86, 3);
                        cout << "Posicion: ";
                        gotoxy(86, 4);
                        int pos;
                        char posc[100];
                        cin>>posc;
                        if(ValidaNumerosEnteros(posc)==true){
                            pos=atoi(posc);
                        }else{
                            gotoxy(86, 5);
                            cout<<"Ingrese un numero entero"<<endl;
                            gotoxy(86, 6);
                            system("pause");
                            break;
                        }
                        Node* node = obj->searchByPosition(pos);
                        if (node != NULL) {
                            gotoxy(86, 14);
                            system("pause");

                        } else {
                            gotoxy(86, 5);
                            cout << "No hay nada en: " << pos << endl;
                        }
                    }break;
                    case 2:{
                        string nameb;
                        system("cls");
                        obj->print();
                        obj->pantallazo();
                        gotoxy(86, 2);
                        cout << "Que nombre desea buscar?" << endl;
                        gotoxy(86, 3);
                        cout << "Nombre: ";
                        gotoxy(86, 4);
                        cin >> nameb;
                        if(!ValidaNombre(nameb)){
                            gotoxy(86, 5);
                            cout<<"Ingrese un nombre valido"<<endl;
                            gotoxy(86, 6);
                            system("pause");
                            break;
                        }
                        Node* node = obj->searchByname(nameb);
                        if (node != NULL) {
                            gotoxy(86, 14);
                            system("pause");
                        } else {
                            gotoxy(86, 5);
                            cout << "No existe: " << nameb << endl;
                        }
                    }break;
                    case 3:{
                        string artistab;
                        system("cls");
                        obj->print();
                        obj->pantallazo();
                        gotoxy(86, 2);
                        cout << "Que artista desea buscar?" << endl;
                        gotoxy(86, 3);
                        cout << "Artista: ";
                        gotoxy(86, 4);
                        cin >> artistab;
                        if(!ValidaNombre(artistab)){
                            gotoxy(86, 5);
                            cout<<"Ingrese un nombre valido"<<endl;
                            gotoxy(86, 6);
                            system("pause");
                            break;
                        }
                        Node* node = obj->searchByArtist(artistab);
                        if (node != NULL) {
                            gotoxy(86, 14);
                            system("pause");
                        } else {
                            gotoxy(86, 5);
                            cout << "No existe: " << artistab << endl;
                        }
                    }break;
                    default:{
                        gotoxy(86, 6);
                        cout<<"Opcion no valida"<<endl;
                        gotoxy(86, 7);
                        system("pause");
                        break;
                    }
                }
            }break;
            case 3: {
                int opcion;
                char opcionc[100];
                system("cls");
                obj->print();
                obj->pantallazo();
                gotoxy(86, 2);
                cout << "Ordenar por: " << endl;
                gotoxy(86, 3);
                cout << "1. Indice" << endl;
                gotoxy(86, 4);
                cout << "2. Nombre de cancion" << endl;
                gotoxy(86, 5);
                cout << "3. Nombre de artista" << endl;
                gotoxy(86, 6);
                cout << "4. Ascendente" << endl;
                gotoxy(86, 7);
                cout << "5. Descendente" << endl;
                gotoxy(86, 8);
                cin >> opcionc;
                if(ValidaNumerosEnteros(opcionc)==true){
                    opcion=atoi(opcionc);
                }else{
                    gotoxy(86, 9);
                    cout<<"Ingrese una opcion valida"<<endl;
                    gotoxy(86, 10);
                    system("pause");
                    break;
                }
                switch (opcion){
                    case 1: {
                        obj->sortId();
                    }break;
                    case 2:{
                        obj->sortName();
                    }break;
                    case 3:{
                        obj->sortArtist();
                    }break;
                    case 4:{
                        obj->sortAscending();
                    }break;
                    case 5:{
                        obj->sortDescending();
                    }break;
                    default:{
                        gotoxy(86, 9);
                        cout<<"Ingrese una opcion valida"<<endl;
                        gotoxy(86, 10);
                        system("pause");
                        break;
                    }
                }
            }break;
            case 4:{
                system("cls");
                obj->print();
                obj->pantallazo();
                int pos, newValue;
                char posc[100],newvaluec[100];
                int duracionm, duracionsm;
                char duracionmc[100], duracionsmc[100];
                string nombrem,artistam,rutam,albumm,generom;
                gotoxy(86, 2);
                cout << "Posicion a modificar: ";
                cin >> posc;
                if(ValidaNumerosEnteros(posc)==true){
                    pos=atoi(posc);
                }else{
                    gotoxy(86, 3);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 4);
                    system("pause");
                    break;
                }
                gotoxy(86, 3);
                cout << "Nuevo nombre de la cancion: ";
                gotoxy(86, 4);
                cin >> nombrem;
                if(!ValidaNombre(nombrem)){
                    gotoxy(86, 5);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 6);
                    system("pause");
                    break;
                }
                gotoxy(86, 5);
                cout << "Nuevo nombre del artista: ";
                gotoxy(86, 6);
                cin >> artistam;
                if(!ValidaNombre(artistam)){
                    gotoxy(86, 7);
                    cout<<"Ingrese un nombre valido"<<endl;
                    gotoxy(86, 8);
                    system("pause");
                    break;
                }
                gotoxy(86, 7);
                cout << "Nueva duracion de la cancion (minutos): ";
                gotoxy(86, 8);
                cin >> duracionmc;
                if(ValidaNumerosEnteros(duracionmc)==true){
                    duracionm=atoi(duracionmc);
                }else{
                    gotoxy(86, 9);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 10);
                    system("pause");
                    break;
                }
                gotoxy(86, 9);
                cout << "Nueva duracion de la cancion (segundos): ";
                cin >> duracionsmc;
                if(ValidaNumerosEnteros(duracionsmc)==true){
                    duracionsm=atoi(duracionsmc);
                }else{
                    gotoxy(86, 10);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 11);
                    system("pause");
                    break;
                }
                gotoxy(86, 10);
                cout << "Nueva ruta de la cancion: ";
                gotoxy(86, 11);
                cin >> rutam;
                if(!ValidaNombre(rutam)){
                    gotoxy(86, 12);
                    cout<<"Ingrese una ruta valida"<<endl;
                    gotoxy(86, 13);
                    system("pause");
                    break;
                }
                gotoxy(86, 12);
                cout << "Nuevo album de la cancion: ";
                gotoxy(86, 13);
                cin >> albumm;
                if(!ValidaNombre(albumm)){
                    gotoxy(86, 14);
                    cout<<"Ingrese un album valido"<<endl;
                    gotoxy(86, 15);
                    system("pause");
                    break;
                }
                gotoxy(86, 14);
                cout << "Nuevo genero de la cancion: ";
                gotoxy(86, 15);
                cin >> generom;
                if(!ValidaNombre(generom)){
                    gotoxy(86, 16);
                    cout<<"Ingrese un genero valido"<<endl;
                    gotoxy(86, 17);
                    system("pause");
                    break;
                }
                obj->modifyNode(pos, nombrem, artistam, duracionm, duracionsm, rutam, albumm, generom);
            }break;
            case 5:{
                system("cls");
                obj->print();
                obj->pantallazo();
                obj->remover();
                gotoxy(86, 2);
                cout << "Nodo eliminado" << endl;
            }break;
            case 6: {
                obj->removeAll();
            }break;
            case 7: {
                system("cls");
                obj->print();
                obj->pantallazo();
                obj->reproducir();
            }break;
            case 8: {
                system("cls");
                obj->print();
                obj->pantallazo();
                obj->detener();
            }break;
            case 9: {
                int move;
                char movec[100];
                system("cls");
                obj->print();
                obj->pantallazo();
                gotoxy(86, 2);
                cout << "Mover hacia:" << endl;
                gotoxy(86, 3);
                cout << "1. Izquierda" << endl;
                gotoxy(86, 4);
                cout << "2. Derecha" << endl;
                gotoxy(86, 5);
                cin >> movec;
                if(ValidaNumerosEnteros(movec)==true){
                    move=atoi(movec);
                }else{
                    gotoxy(86, 6);
                    cout<<"Ingrese un numero entero"<<endl;
                    gotoxy(86, 7);
                    system("pause");
                    break;
                }
                switch (move){
                    case 1: {
                        obj->moveTo(1);
                    }break;
                    case 2: {
                        obj->moveTo(2);
                    }break;
                    case 3: {
                        gotoxy(86, 6);
                        cout << "Pruebas/EasterEgg" << endl;
                        obj->alterarFile();
                    }break;
                    default: {
                        gotoxy(86, 6);
                        cout << "Opcion no valida" << endl;
                        gotoxy(86, 7);
                        system("pause");
                    }break;
                }
            }break;
            case 10: {
                system("cls");
                obj->print();
                obj->pantallazo();
                gotoxy(86, 2);
                cout << "Saliendo..." << endl;
                gotoxy(86, 3);
                system("pause");
                return 0;
            }break;
            default: {
                gotoxy(86, 2);
                cout << "Opcion no valida" << endl;
                gotoxy(86, 3);
                system("pause");
            }break;
        }
    system("cls");
    obj->print();
    obj->pantallazo();
    gotoxy(86, 2);
    cout<<"Continuar 2 no, Cualquier otra tecla si: ";
    gotoxy(86, 3);
    cin>>opc2;
    }while(opc2!=2);
return 0;
}