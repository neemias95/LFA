#include<iostream>
#include <stdio.h>
#include<vector>
#include<string>
#include <cmath>
#include <stdlib.h>
#include <map>
using namespace std;


// class Edge
// {
// public:
// 	string endVertex;
// 	string weight;
// 	string startVertex;
// 	Edge(string startVertex, string endVertex, string weight)
// 	{
// 		this->startVertex = startVertex;
// 		this->endVertex = endVertex;
// 		this->weight = weight;
// 	}
// };

// void printGraph(vector<vector<Edge> > graph, int nV)
// {
//  	for(int v = 0; v < graph.size(); v++)
//  	{
//  		cout << "\n ∂("; 
//  		for(auto x : graph[v])
//  		{	
//  			cout << x.startVertex << ", " << x.weight << ") : {";
//  			cout << x.endVertex << "}";
//  		}
//  		cout << endl;
//  	}
//  }

bool compare(string a, string b)
{
  if(a.length() < b.length()) return true;
  else return false;
}

int main()
{
	int nS, nA, nE;
	cout << "Digite a qtd de estados: ";
	cin >> nS;


	vector<string> states (nS);

	cout << "Digite os nomes dos estados: ";
	for(int i = 0; i < nS; i++)
		cin >> states[i];

	cout << "Digite a qtd de alfabetos: ";
	cin >> nA;
	vector<string> alphabet (nA);
	cout << "Digite os respectivos simbolos do alfabeto: ";
	for(int i = 0; i < nA; i++)
		cin >> alphabet[i];

	cout << "Digite o estado inicial: ";
	string beginState;
	cin >> beginState;
	
	cout << "Digite a qtd de estados finais: ";
	cin >> nE;
	cout << "Digite o nome dos estados finais: ";
	vector<string> endstate (nE);
	for(int i = 0; i < nE; i++)
		cin >> endstate[i];



	cout << "Digite a quantidade de ligaçoes de estado para estado: ";
	int qtdLigations;
	cin >> qtdLigations;
	//vector<vector<Edge> > graphTransiction (qtdLigations);
	vector<pair<string, string> > mR; 
  vector<pair<string, string> > mA;
  cout << "Digite todas as ligaçoes de estado para estado:" << endl;
  cout << "Insere todos com o alfabeto 0 todos com o 1 e assim por diante. " << endl;
	for(int i = 0; i < qtdLigations; i++)
	{
		string startVertex, endVertex, weight;
		cin >> startVertex >> weight >> endVertex;
    mR.push_back(make_pair(startVertex,endVertex));
    mA.push_back(make_pair(startVertex,weight));
    //graphTransiction[i].push_back(Edge(startVertex, endVertex, weight));
		// if undirected
		//graphTransiction[y].push_back(Edge(x,wheight));
	}
	//printGraph(graphTransiction, qtdLigations);

	//calcular a qtd de estados possíveis;
	int statesPossible = pow(2, nS);
	vector<string> afd (statesPossible);
  for(int i = 0; i < statesPossible-1; i++)
    afd[i] = 'q';
  afd[statesPossible-1] = "INF";
  char T[nS];
  char A[statesPossible][nS];
  char indexs[nS];
  //frequencia de numeros.
  for(int i = 0; i < nS; i++)
  { 
    string aux = states[i]; 
    indexs[i]= aux[1];
  }

  for(int i= 0; i < statesPossible; i++)
  {
    int index = 0;
    for(int j=0; j< nS+1; j++)
    {
      if((i & (int)pow(2, j)) != 0){
        T[index++] = indexs[j];
      }
    }
    T[index] = '\0';
    for(int a = 0; a<index; a++){
      A[i][a] = T[a];
      A[i][a+1] = '\0';
    }
  }
  int j = 0;
  for(int i =1; i < statesPossible; i++)
  {  
      //printf("%s ", A[i]);
    string aux = afd[j];
    string aux1 = A[i];
    for(int k =0; k < aux1.length(); k++)
    {
      aux += aux1[k];
      if(k < aux1.length()-1)
        aux+= afd[j];
    }
    afd[j] = aux; 
    j++;
  }
  stable_sort(afd.begin(), afd.end(), compare);
  // for(int i =0; i < statesPossible; i++)
  // {  
  //     cout << afd[i] << " ";
  //     //printf("%s ", A[i]);
  // // }
  // cout << endl;
  // cout << "==== FUNCAO DE TRANSICAO AFN==== ";
  // cout << endl;
  // cout << endl;
  // for(vector< pair<string, string> >::iterator it = mR.begin(); it != mR.end(); ++it)
  // {
  //   cout << it->first <<" = {" << it->second << "}\n";
  // }
  // cout << endl;
  // for(vector< pair<string, string> >::iterator it = mA.begin(); it != mA.end(); ++it)
  //   cout << it->first << " -> " << it->second << endl;
  // cout << endl;
  // cout << "==== FUNCAO DE TRANSICAO ==== ";
  // cout << endl;

  vector<pair<string, string> > afdAnswerR, afdAnswerA;
  for(int i = 0; i < nS; i++)
  {
    for(j = 0; j < qtdLigations; j++)
    {
      if(mR[j].first == afd[i] && mR[j].second != "INF")
      {
        string aux = mR[j].second;
        if(aux.length() > 2)
        {
          int k = 3, length = aux.length();
          string aux1;
          for(k = 3; k < length; k = k+2)
          {
            aux1 += aux[k-1];
            aux1 += aux[k];
            // if(k < aux.length() && aux[k] == 'q')
            //   aux1 += aux[k+1];
            int x = 0;
            cout << "AUX1" << aux1 <<endl;
            
            while(aux1 != mR[x].first && x < qtdLigations) x++;
            while( mA[x].second != "E" && x < qtdLigations) x++;

            if(mA[x].second == "E" && mR[x].second != "INF")
            {
              //aux += ",";
              aux += mR[x].second;
              mR[x].second = "INF";
              afdAnswerR.push_back(make_pair(afd[i], aux));
              afdAnswerA.push_back(make_pair(afd[i], mA[j].second));
            }
            else
            { 
              afdAnswerR.push_back(make_pair(afd[i], aux));
              afdAnswerA.push_back(make_pair(afd[i], mA[j].second));
            }
          }
        }
        else
        {
          afdAnswerR.push_back(make_pair(afd[i], aux));
          afdAnswerA.push_back(make_pair(afd[i], mA[j].second));
        }
      }
      else if(mR[j].first == afd[i] && mA[j].second != "E" && mR[j].second =="INF")
      {
        afdAnswerR.push_back(make_pair(afd[i], mR[j].second));
        afdAnswerA.push_back(make_pair(afd[i], mA[j].second));
      }
    }
  }


  for(int i = nS+1; i < statesPossible; i++)
  {
    string aux = afd[i];
    vector<string> v;

    for(int x=0; x< aux.length(); x= x+2)
    {
      string aux1 = "ab";
      aux1[0] = aux[x];
      if(x+1 < aux.length())
        aux1[1] = aux[x+1];
      v.push_back(aux1);
    }
    int x = 0;
    vector<pair<string,string> > v10, v20, v11, v21;
    for(x = 0; x < v.size(); x++)  
    {  
      for(j = 0; j < nS*nA; j++)
      {
        if(afdAnswerR[j].first == v[x] && afdAnswerA[j].second == "0")
        {
          
          v10.push_back(make_pair(afd[i], afdAnswerR[j].second));
          v20.push_back(make_pair(afd[i], afdAnswerA[j].second));
        }
        if(afdAnswerR[j].first == v[x] && afdAnswerA[j].second == "1")
        {
          v11.push_back(make_pair(afd[i], afdAnswerR[j].second));
          v21.push_back(make_pair(afd[i], afdAnswerA[j].second));
        }  
      }
    }
    string flag1="", flag2="";
    for(int y = 0; y < v10.size(); y++)
    {
      if(v10[y].second != "INF" && v20[y].second == "0")
      {
        flag1 += v10[y].second;
        flag2 += v20[y].second;
      }
    }
    afdAnswerR.push_back(make_pair(afd[i], flag1));
    afdAnswerA.push_back(make_pair(afd[i], flag2));
    flag1 = "";
    flag2 = "";
    for(int y = 0; y < v11.size(); y++)
    {
      if(v11[y].second != "INF" && v21[y].second == "1")
      {
        flag1 += v11[y].second;
        flag2 += v21[y].second;
      }
    }
    afdAnswerR.push_back(make_pair(afd[i], flag1));
    afdAnswerA.push_back(make_pair(afd[i], flag2));
    
    // for(vector<pair<string, string> >::iterator it = v10.begin(); it != v2.end(); ++it)
    //   cout << it->first << " -> " << it->second << endl;
    // cout << endl;
    // for(vector<pair<string, string> >::iterator it = v11.begin(); it != v11.end(); ++it)
    //   cout << it->first << " -> " << it->second << endl;
    // cout << endl;
  }



  int opcao;
  while(true)
  {
    cout << "\t\t====DIGITE UMA DAS SEGUINTES OPCOES====" << endl;
    cout << "\t1- MOSTRAR OS ESTADOS FINAIS DO AFD E SUAS RESPECTIVAS LIGACOES" << endl;
    cout << "\t2- MOSTRAR O ESTADO INICIAL" << endl;
    cout << "\t3- MOSTRAR TODOS OS ESTADOS DO AFD" << endl;
    cout << "\t4- FUNCAO DE TRANSICAO DO AFD EQUIVALENTE" << endl;
    cout << "\t5- Sair da simulação" << endl;
    cin >> opcao;
    if(opcao == 5) break;
    else if(opcao == 1)
    {
      cout << endl << "====ETADOS FINAIS E SUAS LIGACOES====" << endl;
      for(vector<pair<string, string> >::iterator it = afdAnswerR.begin(); it != afdAnswerR.end(); ++it)
      {
        string aux = it->first;
        bool flag = false;
        for(int i = 0; i < aux.length(); i++)
          if(aux[i] == '4')
            flag = true;
        if(flag == true)
          cout << it->first << " -> " << it->second << endl;
      }
      cout << endl;
    }
    else if(opcao == 2)
    {
      cout << "====ESTADO INICIAL====" << endl;
      cout << beginState << endl;
    }
    else if(opcao == 3)
    {
      cout << "====TODOS OS ESTADOS DO AFD===" << endl;
      for(int i =0; i < statesPossible; i++)
      {  
        cout << afd[i] << " ";
        //printf("%s ", A[i]);
      }
    }
    else if(opcao == 4)
    {
      cout << endl << "====FUNCAO DE TRANSICAO DO AFD RESULTADO====" << endl;
      for(vector<pair<string, string> >::iterator it = afdAnswerR.begin(); it != afdAnswerR.end(); ++it)
        cout << it->first << " -> " << it->second << endl;
      cout << endl << "===FUNCAO DE TRANSICAO DO AFD ALFABETO===" << endl;
      for(vector<pair<string, string> >::iterator it = afdAnswerA.begin(); it != afdAnswerA.end(); ++it)
        cout << it->first << " -> " << it->second << endl;
      cout << endl;
      
    }
  }



	return 0;
}