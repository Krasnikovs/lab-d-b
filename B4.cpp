/*
Gustavs Krasnikovs, gk24018
B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
Skaitļa dalīšana ciparos jāveic skaitliski.
*/

#include<iostream>
using namespace std;

int main() {
	bool continue_prog = true; // nosaka, lai programma izpildītos vismaz vienu reizi

	do {
		int x;

		cout << "Ievadiet naturalu skaitli: ";
		cin >> x;

		int confirmed_deviders[x] = {};
		int confirmed_times[x] = {};

		for (int devider = 1; devider < x; devider++) {
			if (x% devider == 0 && devider != 1) {
				cout << "Atrasts vienāds cipars " << devider << " un cipars ir satopams " << x / devider << ". reizes" << endl;
				// confirmed_times[devider - 1] = x / devider;
				// confirmed_deviders[devider - 1] = devider;
			}
		}

		char user_choise;
        std::cout << "Vēlaties turpināt? (Y/n):"; 
        cin >> user_choise;

		if (user_choise == 'n') { // tiek izvēlēts n un N, jo tas tiek izmantos kā standartilizētas opcijas, kas nozīmē nē
            continue_prog = false;
        } else if (user_choise == 'N') {
            continue_prog = false;
        } 

	} while (continue_prog == true);
    
	return 0;
}

/*
Testa plāns
Ievads		Programma vēlamā		Rezultāts C++
				reakcija

 64				 2 32					+
				 4 16
				 8	8
				16	4
				32	2

 8				 2	4					+
				 4	2
*/