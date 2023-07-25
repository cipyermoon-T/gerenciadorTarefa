// Desenvolva um programa que permita ao usuário adicionar, remover e exibir tarefas a serem feitas.
// Cada tarefa deve ter um título e uma descrição. 
// O programa deve fornecer um menu interativo para que o usuário possa executar essas ações.

#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

void addTask(string title,  string desc);
void del_Task(int num);
void view_Task();
void action();

list<string> title_list;
list<string> desc_list;


int main(){
  
  int opc,num;
  string title, desc;


  while(1){
    action();
    cin >> opc;
    getchar();
    
    switch (opc){
      case 1:
        system("clear");
        cout << "Titulo pra tarefa: ";
        getline(cin, title);
        system("clear");
        cout << "Descriçao da tarefa: " << endl;
        getline(cin, desc);
        system("clear");
        addTask(title, desc);
        system("clear");
        break;
      case 2:
        system("clear");
        cout << "Digite o umero de qual lembrete voce quer apagar: (digite -1 para sair) ";
        cin >> num;
        if(num == -1){
          break;
        }
        del_Task(num);
        break;
      case 3:
        view_Task();
        break;
      case 4:
        return 0;
    }
  } 
  return 0;
}
// que ngc dificil vsf
void action(){
  cout << "Acoes: " << endl;
  cout << "1. Add_task " << endl << "2. Del_task " << endl << "3. View_task" << endl <<"4. Exit" << endl << endl;
  cout << "Command >> ";
}

void addTask(string title, string desc){
  title_list.push_back(title);
  desc_list.push_back(desc);
}

void view_Task(){
  system("clear");

  auto it_desc = desc_list.begin();

  for(auto it_title = title_list.begin(); it_title != title_list.end(); it_title++, it_desc++){
    cout << "Titulo: " << *it_title << endl << "Descrição: " << *it_desc << endl << endl;
  }
}

void del_Task(int num){
  auto it_desc = desc_list.begin();
  auto it_title = title_list.begin();

  int i = 1;
  for(auto it_title = title_list.begin(); it_title != title_list.end(); it_title++, it_desc++, i++){
    // title_list.pop_front();
    if (title_list.empty()){
      system("clear");
      cout << "Lista vazia!" << endl;
    }
    else if((i == num) && (!title_list.empty())){
      //it_title->pop_back();
      //it_desc->pop_back();
      title_list.erase(it_title);
      desc_list.erase(it_desc);
      it_title = title_list.begin();
      it_desc = desc_list.begin();
      cout << "Lista apagada com sucesso!! " << endl;
      break;
    }    
  }
  if(title_list.empty()){
    system("clear");
    cout << "Lista vazia!! " << endl;
  }
}
