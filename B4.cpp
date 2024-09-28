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

int** endivitual_num(int num) {
	int** confirmed_num = new int*;
	int cycle = 0;


	while (num > 0) {
		confirmed_num[cycle] = new int[2];
		// confirmed_num[cycle][0] = num % 10;

		for (int i = 0; i <= cycle; i++) {
			if (confirmed_num[i][0] == num % 10) {
				confirmed_num[i][1]++;
				num = num / 10;
				cycle +=1;
				break;
			} else if (i == cycle && confirmed_num[i][0] != num % 10) {
				confirmed_num[cycle][0] = num % 10;
				confirmed_num[cycle][1]++;
				num = num / 10;
				cycle +=1;
				break;
				
			}
		}
		
		// num = num / 10;
		
		// if (num == 0) {
		// 	break;
		// }
		
	}

	// int** confirmed_same_num = new int*[2];

	// for (int i = 0; i <= cycle; i++) {
	// 	// confirmed_same_num[i] = new int[cycle];
	// 	for (int j = 0; j <= cycle; j++) {
	// 		if (confirmed_num[j] == confirmed_num[i]) {
	// 			// confirmed_num[i][0] = confirmed_num[i];
	// 			confirmed_num[i][1]++;
	// 		}
	// 	}

	// }

	return confirmed_num;

}

int* most_reacuring_diggit(int** confirmed_num) {
	int* biggest_diggit_code = new int;
	int biggest_diggit;
	int cycle = sizeof(confirmed_num)/sizeof(confirmed_num[0][0]);

	for (int i = 0; i < cycle; i++) {
		if (confirmed_num[i][1] > biggest_diggit) {
			biggest_diggit = confirmed_num[i][1];
			biggest_diggit_code[0] = i;
		}
	}

	int num = 0;

	for (int i = 0; i < cycle; i++) {
		if (confirmed_num[i][1] == biggest_diggit && biggest_diggit_code[0] != i) {
			num++;
			biggest_diggit_code[num] = i;
		}
	}

	return biggest_diggit_code;
}

int main() {
	bool continue_prog = true; // nosaka, lai programma izpildītos vismaz vienu reizi

	do {
		bool nat_num = false;
		int num, cycle;

		while (nat_num == false) {
			cout << "Ievadiet naturalu skaitli: ";
			cin >> num;

			nat_num = nat_num_validate(num);
		}

		// cout << 1;

		int** confirmed_num;
		confirmed_num = endivitual_num(num);

		int* reacuring_diggit_code = new int;
		reacuring_diggit_code = most_reacuring_diggit(confirmed_num);

		cycle = sizeof(reacuring_diggit_code)/sizeof(reacuring_diggit_code[0]);

		for (int i = 0; i < cycle; i++) {
			cout << "Cipars kas atkārtojās ir " << confirmed_num[reacuring_diggit_code[i]][0] << ", tas atkārtojās " << confirmed_num[reacuring_diggit_code[i]][1] << ".reizes" << endl;
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

 64					0					+
				 
 818				2					+
*/