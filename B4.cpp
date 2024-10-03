/*
Gustavs Krasnikovs, gk24018
B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
Skaitļa dalīšana ciparos jāveic skaitliski.
Programma izveidota: 30.09.24
*/

#include<iostream>
using namespace std;

/*
bool nat_num_validate(int num);
Funkcija nat_num_validate(num) -
nosaka vai lietotaja ievadita skaitlis ir naturals skaitlis.
Atgriez ka rezultatu true vai false
*/

bool nat_num_validate(int num) { 
	if (num <= 0) {
		cout << "Skaitlis nav naturals" << endl;

		return false;
	} else {
		return true;
	}
}

/*
int** endivitual_num(int num)
Funkcija endivitual_num(num) - 
nosaka visus ciparus ievaditaja skaitli num un cik reizu katrs atkartojas.
Atgriez virkni ar cipariem un cik katrs cipars ir paradijies.
*/

int** endivitual_num(int num) { 
	int** confirmed_num = new int*[10]; // Izmanto divdimensionalu, lai noteiktu gan skaitli gan cikreizes tas ir paradijies 
	int cycle = 0;

	for (int i = 0; i < 10; i++) {
		confirmed_num[i] = new int[2];
		confirmed_num[i][0] = i;
		confirmed_num[i][1] = 0;
	}


	while (num > 0) {
		
		confirmed_num[num % 10][1]++;
		num = num / 10;

	}

	return confirmed_num;

}

/*
int most_reacuring_diggit_count(int** confirmed_num) 
Funkcija most_reacuring_diggit_count(confirmed_num) -
nosaka
*/

int most_reacuring_diggit_count(int** confirmed_num) { // Funkcija sanem, skaitlu virkni, kas tika atgriezta no citas funkcijas 
	int* biggest_diggit_count = new int;
	int biggest_diggit = 0;

	for (int i = 0; i < 10; i++) {
		if (confirmed_num[i][1] > biggest_diggit) {
			biggest_diggit = confirmed_num[i][1];
		}
	}

	return biggest_diggit; // Funkcija atgriez, skaitu kas bija lielakais reizu skaits cik reizes paradijas
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

		int** confirmed_num;
		confirmed_num = endivitual_num(num);

		int biggest_diggit = most_reacuring_diggit_count(confirmed_num);


		for (int i = 0; i < 10; i++) {
			if (confirmed_num[i][1] == biggest_diggit) {
				cout << "Cipars kas atkārtojās ir " << confirmed_num[i][0] << ", tas atkārtojās " << confirmed_num[i][1] << ".reizes" << endl;
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

		delete[] confirmed_num;

	} while (continue_prog == true);
    
	return 0;
}

/*
Testa plāns
Ievads		Programma vēlamā		Rezultāts C++
				reakcija

 64					1 1					+
				 
 8188				3					+

 43034				2 2					+
*/