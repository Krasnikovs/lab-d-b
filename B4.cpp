/*
Gustavs Krasnikovs, gk24018
B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
Skaitļa dalīšana ciparos jāveic skaitliski.
*/

#include<iostream>
using namespace std;

bool nat_num_validate(int num) {
	if (num <= 0) {
		cout << "Skaitlis nav naturals" << endl;

		return false;
	} else {
		return true;
	}
}

int* endivitual_num(int num) {
	static int confirmed_num[10] = {};
	int cycle = 0;

	while (true) {
		confirmed_num[cycle] = num % 10;
		
		num = num / 10;

		// cout << cycle << endl;
		// cout << num << endl;
		
		if (num == 0) {
			break;
		}
		cycle +=1;
	}

	static int confirmed_same_num[10] = {};

	for (int i = 0; i <= cycle; i++) {
		for (int j = 0; j <= cycle; j++) {
			if (confirmed_num[j] == confirmed_num[i]) {
				confirmed_same_num[i]++;
			}
		}

	}

	return [confirmed_num, confirmed_same_num];
}

int* posible_len() {
	
	return confirmed_num;
}

int main() {
	bool continue_prog = true; // nosaka, lai programma izpildītos vismaz vienu reizi

	do {
		bool nat_num = false;
		int num;

		while (nat_num == false) {
			cout << "Ievadiet naturalu skaitli: ";
			cin >> num;

			nat_num = nat_num_validate(num);
		}

		// cout << 1;

		int* confirmed_num, confirmed_same_num;
		confirmed_num = posible_len(num);
		
		// int confirmed_times[x] = {};

		// for (int devider = 1; devider < num; devider++) {
		// 	if (num % devider == 0 && devider != 1) {
		// 		cout << "Atrasts vienāds cipars " << devider << " un cipars ir satopams " << num / devider << ". reizes" << endl;
		// 		// confirmed_times[devider - 1] = x / devider;
		// 		// confirmed_deviders[devider - 1] = devider;
		// 	}
		// }

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

 64					0					+
				 
 818				2					+
*/