#include <iostream>
#include <string.h>
#include <deque>
#include <cmath>
using namespace std;

int main() {
  char n[] = "(5-3)*(7+4)";
  
  float longitud_n = strlen(n);
  deque<char> pila;
  char despliegue[100];
  int a = 0;
  for(int i = 0; i < longitud_n; i++){
    if(isdigit(n[i]) == 0 && n[i] != ')'){
      pila.push_front(n[i]);
    }
    else if(isdigit(n[i]) != 0){
      despliegue[a] = n[i];
      a++;
    }
    else if(n[i] == ')'){
      for(int j = 0; j < pila.size(); j++){
        if(pila[j] == '+' or pila[j] == '-' or pila[j] == '*' or pila[j] == '/'){
          despliegue[a] = pila[j];
          a++;
          pila.pop_front();
        }
        else if(pila[j] == '.'){
          despliegue[a] = pila[j];
          a++;
          pila.pop_front();
        }
        else{
          pila.pop_back();
        }
      }
    }
  }

  for(int i = 0; i <= pila.size(); i++){
    pila.pop_back();
  }

  char ch;
  float num = 0;
  char ing;
  float num_dec;
  float num_total;
  float num_exp;

  int cont_1 = 0;

  for(int i = 0; i < strlen(despliegue); i++){
    if(isdigit(despliegue[i]) != 0){
      pila.push_back(despliegue[i]);
      cont_1++;
    }
    if(despliegue[i] == '.'){
      ch = pila[cont_1 - 2];
      num = ch - '0';
      ch = pila[cont_1 - 1];
      num = num + (ch - '0');
      //cout << num << endl;
      pila.pop_back();
      pila.pop_back();
      ing = num + '0';
      pila.push_back(ing);
      cont_1--;
    }
    if(despliegue[i] == '+'){
      ch = pila[cont_1 - 2];
      num = ch - '0';
      ch = pila[cont_1 - 1];
      num = num + (ch - '0');
      //cout << num << endl;
      pila.pop_back();
      pila.pop_back();
      ing = num + '0';
      pila.push_back(ing);
      cont_1--;
    }
    if(despliegue[i] == '-'){
      ch = pila[cont_1 - 2];
      num = ch - '0';
      ch = pila[cont_1 - 1];
      num = num - (ch - '0');
      //cout << num << endl;
      pila.pop_back();
      pila.pop_back();
      ing = num + '0';
      pila.push_back(ing);
      cont_1--;
    }
    if(despliegue[i] == '*'){
      ch = pila[cont_1 - 2];
      num = ch - '0';
      ch = pila[cont_1 - 1];
      num = num * (ch - '0');
      //cout << num << endl;
      pila.pop_back();
      pila.pop_back();
      ing = num + '0';
      pila.push_back(ing);
      cont_1--;
    }
    if(despliegue[i] == '/'){
      ch = pila[cont_1 - 2];
      num = ch - '0';
      ch = pila[cont_1 - 1];
      num = num / (ch - '0');
      //cout << num << endl;
      pila.pop_back();
      pila.pop_back();
      ing = num + '0';
      pila.push_back(ing);
      cont_1--;
    }
  }
  cont_1 = 0;
  pila.pop_back();

  cout << "Resultado: " << num << endl;
  return 0;
}
