#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;

	getline(cin, word);
	int flag = 0;
	while(true){
		flag = 0;
		for(int i =0; i < word.length(); i = i + 1) {
			if(int(word[i]) < 48) {
				cout << "Simbolo nao pertence ao alfabeto" << endl;
				cout << "Digite outra palavra valida: ";
				getline(cin, word);
				flag = 1;
				break;
			}
			else if(int(word[i]) > 57 && int(word[i]) < 65) {
				cout << "Simbolo nao pertence ao alfabeto" << endl;
				cout << "Digite outra palavra valida: ";
				getline(cin, word);
				flag = 1;
				break;
			}
			else if(int(word[i]) > 90 && int(word[i] < 97)) {
				cout << "Simbolo nao pertence ao alfabeto" << endl;
				cout << "Digite outra palavra valida: ";
				getline(cin, word);
				flag = 1;
				break;
			}
			else if(int(word[i]) > 122) {
				cout << "Simbolo nao pertence ao alfabeto" << endl;
				cout << "Digite outra palavra valida: ";
				getline(cin, word);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			break;
	}

	if(int(word[0]) >= 97 && int(word[0]) <= 122)
		cout << "Linguagem Aceita" << endl;
	else if(int(word[0]) >= 65 && int(word[0]) <= 90)
		cout << "Linguagem Aceita" << endl;
	else
		cout << "Linguage Recusada" << endl;
	return 0;
}