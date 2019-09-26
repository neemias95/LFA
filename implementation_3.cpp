#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

#define MAX 100

typedef char c;
typedef int i;
typedef vector<i> vi;
typedef vector<c> vc;
typedef pair<c,c> pc;
typedef vector<pc> vpc;
typedef string s;
typedef vector<s> vs;
vc states;
char beginState;
vc stateFinal;
vi alphabet;
vc statesDiferent;
vc t;
vi l;
vc h;
vs t1, h1;
vi l1;
bitset<MAX> bs;
int len;
void printAFD() {
    cout << "\t======";
    for(int i = 0; i < alphabet.size(); i++) cout << "=====";
    cout << "=" << endl;
    cout << "\t=| Q | ";
    for(int i = 0; i < alphabet.size(); i++)
        cout << alphabet[i] << " | ";
    cout <<"=" << endl;
    cout << "\t------";
    for(int i = 0; i < alphabet.size(); i++) cout << "-----";
    cout << "-" << endl;
    for(int i = 0; i < t.size(); i++){
        cout << "\t=| " << t[i] << " | " << l[i] << " | " << h[i] << " | =" << endl;
        cout << "\t------";
        for(int i = 0; i < alphabet.size(); i++) cout << "-----";
        cout << "-" << endl;
    }
    cout << "\t======";
    for(int i = 0; i < alphabet.size(); i++) cout << "=====";
    cout << "=" << endl;
}

void printAFDMinimize() {
    cout << "\t======";
    for(int i = 0; i < alphabet.size(); i++) cout << "=====";
    cout << "=" << endl;
    cout << "\t=| Q | ";
    for(int i = 0; i < alphabet.size(); i++)
        cout << alphabet[i] << " | ";
    cout <<"=" << endl;
    cout << "\t------";
    for(int i = 0; i < alphabet.size(); i++) cout << "-----";
    cout << "-" << endl;
    for(int i = 0; i < t1.size(); i++){
        cout << "\t=| " << t1[i].c_str() << " | " << l1[i] << " | " << h1[i].c_str() << " | =" << endl;
        cout << "\t------";
        for(int i = 0; i < alphabet.size(); i++) cout << "-----";
        cout << "-" << endl;
    }
    cout << "\t======";
    for(int i = 0; i < alphabet.size(); i++) cout << "=====";
    cout << "=" << endl;
}

void init(){
    int qtd, symbol;
    char input;
    bs.set();
    cout << "\t\t============================================" << endl;
    cout << "\t\t==         MINIMIZACAO DE UM AFD          ==" << endl;
    cout << "\t\t============================================" << endl;
    cout << "I = "; cin >> beginState; states.push_back(beginState);
    cout << "QTD de estados finais = ";
    cout << "Digite os estado (s) final (ais) ";
    cout << "(Obs.: com espaco se for mais de um) = "; cin >> qtd;
    for(int i = 0; i < qtd; i++) {
        cin >> input; stateFinal.push_back(input); states.push_back(input);
    }

    cout << "Digite a qtd de simbolos para o alfabeto = "; cin >> qtd;
    for(int i = 0; i < qtd; i++) {
        cin >> symbol; alphabet.push_back(symbol);
    }

    cout << "(estado caracter) (simbolo numero) (estado caracter)" << endl;
    cout << "ex.: A 1 B" << endl;
    cout << "Finalizar transicao: z -1 z" << endl;
    char stateA , stateB;
    for(int i = 0; i < MAX; i++) {
        cin >> stateA >> symbol >> stateB;
        if(stateA == 'z' && stateB == 'z' && symbol == -1) break;
        t.push_back(stateA); l.push_back(symbol); h.push_back(stateB);
    }

    for(int i = 0; i < t.size(); i++){
        bool flag = true;
        for(int j = 0; j < states.size(); j++)
            if(t[i] == states[j]) {
                flag = false;
            }
        if(flag == true){
            states.push_back(t[i]);
        }
    }
}

void minAFD(){
    len = states.size();
    char table [len][len];
    int i, j; 
    for (i = 0; i < len; i++) 
    { 
        for (j = 0; j < len; j++) 
        { 
            if (i > j) 
            { 
                table[i][j] = '0'; 
            } 
            else table[i][j] = '-';
        } 
    }
    /*Print table to veriefed
    cout << endl;
    for(i = 0; i < len; i++){
        cout << "\t";
        for(j = 0; j < len; j++) 
            cout << table[i][j] << " ";
        cout << endl;
    }*/
    sort(stateFinal.begin(), stateFinal.end());
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++)
        {
            if(i > j){
                int k;
                bool flag1 = false, flag2 = false;
                for(k = 0; k < stateFinal.size(); k++)
                    if(states[i] == stateFinal[k]){
                        flag1 = true; break;
                    }
                
                int x;
                for(x = 0; x < stateFinal.size(); x++){
                    if(states[j] == stateFinal[x]){
                        flag2 = true;
                        break;
                    }
                }
                if(flag1 != flag2){
                    table[i][j] = 'X';
                }
            }
        }
    }

    cout << endl;
    for(i = 0; i < len; i++){
        cout << "\t";
        for(j = 0; j < len; j++) 
            cout << table[i][j] << " ";
        cout << endl;
    } 
    vpc vp;              
    for(i = 0; i < len; i++){
        for(j = 0; j < len; j++) {
            if(table[i][j] == 'X') {
                vc seta, setb;
                for(int k = 0; k < t.size(); k++)
                {
                    if(l[k] == 1 && h[k] == states[i]) {
                        seta.push_back(t[k]);
                    }
                }
                for(int k = 0; k < t.size(); k++){
                    if(l[k] == 1 && h[k] == states[j])
                        setb.push_back(t[k]);
                }
                if(seta.size()>0 && setb.size()>0)
                    for(int x = 0; x < seta.size(); x++){
                        for(int y = 0; y < setb.size(); y++){
                            vp.push_back(std::make_pair(seta[x], setb[y]));
                        }
                    }
                cout << states[i] << "1: " << endl << "\t{";
                for(int k = 0; k < seta.size(); k++) cout << seta[k] << " ";
                cout << "}" << endl;

                cout << states[j] << "1: " << endl << "\t{";
                for(int k = 0; k < setb.size(); k++) cout << setb[k] << " ";
                cout << "}" <<endl;
                seta.clear(); setb.clear();
                for(int k = 0; k < t.size(); k++)
                {
                     if(l[k] == 0 && h[k] == states[i]) {
                         seta.push_back(t[k]);
                     }
                }
                for(int k = 0; k < t.size(); k++){
                    if(l[k] == 0 && h[k] == states[j]){
                        setb.push_back(t[k]);
                    }
                }
                if(seta.size()>0 && setb.size()>0)
                    for(int x = 0; x < seta.size(); x++){
                        for(int y = 0; y < setb.size(); y++){
                            vp.push_back(std::make_pair(seta[x], setb[y]));
                        }
                    }

                cout << states[i] << "0: " << endl << "\t{";
                for(int k = 0; k < seta.size(); k++) cout << seta[k] << " ";
                cout << "}" << endl;

                cout << states[j] << "0: " << endl << "\t{";
                for(int k = 0; k < setb.size(); k++) cout << setb[k] << " ";
                cout << "}" <<endl;

            }
        }
    }
    for(int i = 0; i < vp.size(); i++)
        cout << "(" << vp[i].first << ", " << vp[i].second << ")" << endl;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < vp.size(); k++){
                if(states[i] == vp[k].first && states[j] == vp[k].second)
                    table[i][j] = 'X';
            }
        }
    }

    cout << endl;
    for(i = 0; i < len; i++){
        cout << "\t";
        for(j = 0; j < len; j++) 
            cout << table[i][j] << " ";
        cout << endl;
    }
    vp.clear();
    for(i = 0; i < len; i++)
        for(j = 0; j < len; j++){
            if(table[i][j] == '0'){
                vp.push_back(std::make_pair(states[i], states[j]));
            }
        }
    for(i = 0; i < vp.size(); i++){
        cout << "{" << vp[i].first << ", " << vp[i].second << "}";
        if(i < vp.size()) cout << ", ";
    }
    cout << endl;
    vi positions;
    vs svector; s temp="";
    for(i = 1; i < vp.size(); i++){
        if(vp[i].first == vp[i-1].first){
            temp += vp[i].first;
            temp+= vp[i].second;
            temp+= vp[i-1].second;
            svector.push_back(temp);
            temp="";
            positions.push_back(i-1);
            positions.push_back(i);
        }
        else if(vp[i].second == vp[i-1].first){
            temp += vp[i].second;
            temp+= vp[i].first;
            temp+= vp[i-1].second;
            svector.push_back(temp);
            temp="";
            positions.push_back(i);
        }
        else if(vp[i].first == vp[i-1].second){
            temp += vp[i].first;
            temp+= vp[i].second;
            temp+= vp[i-1].first;
            svector.push_back(temp);
            temp="";
            positions.push_back(i);
        }
        else if(vp[i].second == vp[i-1].second){
            temp += vp[i].second;
            temp+= vp[i].first;
            temp+= vp[i-1].first;
            svector.push_back(temp);
            temp="";
            positions.push_back(i);
        }
        else {
            // temp += vp[i].first;
            // temp+= vp[i].second;
            // svector.push_back(temp);
            // temp="";
            temp += vp[i-1].first;
            temp += vp[i-1].second;
            svector.push_back(temp);
            temp="";
            
        }
    }
    for(i = 0; i < svector.size(); i++){
        printf("{%s}, ", svector[i].c_str());
    }
    cout << endl;

    for(i = 0; i < svector.size(); i++){
        s temp = svector[i];
        sort(temp.begin(), temp.end());
        svector[i] = temp;
    }

    for(i = 0; i < svector.size(); i++){
        printf("{%s}, ", svector[i].c_str());
    }
    cout << endl;
    int aux = -1;
    for(i = 0; i < svector.size(); i++){
        s temp1 = svector[i];
        for(j = i+1; j < svector.size(); j++){
            s temp2 = svector[j];
            if(temp1 == temp2)
                aux = j;
        }
    }
    svector.erase (svector.begin()+aux);
    for(i = 0; i < svector.size(); i++){
        printf("{%s}, ", svector[i].c_str());
    }
    cout << endl;
    for(i = 0; i < states.size(); i++){
        bool flag = true;
        for(j = 0; j < svector.size(); j++){
            s temp = svector[j];
            for(int k = 0; k < temp.length(); k++){
                if(states[i] == temp[k]) flag = false;
            }
        }
        if(flag) statesDiferent.push_back(states[i]);
    }
    cout << statesDiferent.size() << endl;
    for(i = 0; i < statesDiferent.size(); i++)
        printf(" {%c}", statesDiferent[i]);
    cout << endl;
    for(i = 0; i < statesDiferent.size(); i++){
        s temp = ""; temp += statesDiferent[i];
        svector.push_back(temp);
    }
    for(i = 0; i < svector.size(); i++){
        printf("{%s}, ", svector[i].c_str());
    }
    cout << endl;
    for(i = 0; i < svector.size(); i++){
        s temp = svector[i];
        for(j = 0; j < t.size(); j++){
            if(l[j]== 0 && t[j] == temp[0]){
                t1.push_back(svector[i]);
                l1.push_back(0);
                for(int k = 0; k < svector.size(); k++){
                    s temp1 = svector[k];
                    for(int x = 0; x < temp1.length(); x++)
                        if(temp1[x] == h[j]){
                            h1.push_back(svector[k]);
                            break;
                        }
                }
            }
            if(l[j]== 1 && t[j] == temp[0]){
                t1.push_back(svector[i]);
                l1.push_back(1);

                for(int k = 0; k < svector.size(); k++){
                    s temp1 = svector[k];
                    for(int x = 0; x < temp1.length(); x++)
                        if(temp1[x] == h[j]){
                            h1.push_back(svector[k]);
                            break;
                        }
                }
            }
        }
    }
    // for(i = 0; i < svector.size()-1; i++){
    //     s temp = svector[i];
    //     s aux1 = "", aux2="";
    //     for(j = 0; j < temp.length(); j++){
    //         for(int k = 0; k < t.size(); k++){
    //             if(l[k] == 1 && t[k] == temp[j]) aux1 += h[k];
    //             if(l[k] == 0 && t[k] == temp[j]) aux2 += h[k];
            
    //         }
    //     }
    //     t1.push_back(svector[i]);
    //     l1.push_back(0);

    //     bool flag = true;
    //     for(int k = 0; k < aux1.length(); k++){
    //         s temp = svector[i];
    //         for(int y = 0; y < temp.length(); y++){
    //             if(flag && aux1[k] == temp[y]){
    //                 h1.push_back(svector[i]);
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag == false) break;
    //     }
    //     if(flag){
    //         s temp = svector[i];
    //         for(j = 0; j < t.size(); j++){
    //             for(int k = 0; k < temp.length(); k++)
    //             {
    //                 if(t[j] == temp[k]) {
    //                     flag = false;
    //                 }
    //             }
    //             if(flag == false){
    //                 for(int k = 0; k < statesDiferent.size(); k++){
    //                     temp = "";
    //                     if(h[k] == statesDiferent[k]) {
    //                         temp += statesDiferent[k];
    //                         h1.push_back(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     t1.push_back(svector[i]);
    //     l1.push_back(1);

    //     flag = true;
    //     for(int k = 0; k < aux2.length(); k++){
    //         s temp = svector[i];
    //         for(int y = 0; y < temp.length(); y++){
    //             if(flag && aux2[k] == temp[y]){
    //                 h1.push_back(svector[i]);
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag == false) break;
    //     }
    //     if(flag){
    //         s temp = svector[i];
    //         for(j = 0; j < t.size(); j++){
    //             bool flag1 = false;
    //             for(int k = 0; k < temp.length(); k++)
    //             {
    //                 if(t[j] == temp[k]) {
    //                     for(int k = 0; k < statesDiferent.size(); k++){
    //                     temp = "";
    //                     if(h[k] == statesDiferent[k]) {
    //                         temp += statesDiferent[k];
    //                         h1.push_back(temp);
    //                     }
    //                 }
    //                 }
    //             }
    //             if(flag1){
                    
    //             }
    //         }
    //     }
    //     //cout << aux1 << " --- ";
    //     //cout << aux2 << endl;
    //     cout << svector.size() << endl;
    //     printf("Ola%d", i);
    //     //cout << i << endl;
    //     //cout << t1.size() << " " << h1.size() << " " << l1.size() << endl;
    // }
    cout << endl;
    printAFDMinimize();
}

int main() {
    init();
    while(true) {
        int input;
        cout << "\t\t============================================" << endl;
        cout << "\t\t==                 MENU                   ==" << endl;
        cout << "\t\t============================================" << endl;
        cout << "\t\t1 - funcao de transicao do AFD" << endl;
        cout << "\t\t2 - funcao de transicao do AFDM" << endl;
        cout << "\t\t0 - sair" << endl;
        cin >> input;
        if(input == 1) printAFD();
        else if(input == 2) minAFD();
        else break;
        sort(states.begin(), states.end());
        for(int i = 0; i < states.size(); i++) cout << states[i];
        cout << endl;
    }
    return 0;
}
