# Gustavs Krasnikovs, gk24018
# B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
# Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
# Skaitļa dalīšana ciparos jāveic skaitliski.
# Programma izveidota: 30.09.24

def nat_num_validate(num): # Funkcija sanem, naturalo skatli ko lietotajs ievadija
	if num <= 0: #Parbauda, jo ja mazaks par nulle tad nebus naturals
		print('Skatlis nav naturals')
		return False # Funkcija atgriez, rezultatu par ievadito skaitli, tas ir naturals tad true, ja nav naturals tad false
	else:
		return True
	
def endivitual_num(num): # Funkcija sanem, naturalo skaitli, kas tika parbaudits vai ir naturals
	confirmed_num = [] #Izmanto masivu, jo ir neierobezots vietu daudzums prieks ievaditajiem skaitliem

	

	for i in range(10):
		confirmed_num.append([]) # Izmanto divdimensionalu, lai noteiktu gan skaitli gan cikreizes tas ir paradijies 
		confirmed_num[i].append(i)
		confirmed_num[i].append(0)
		
	biggest_dig = 0

	while num > 0:
		confirmed_num[num % 10][1] +=1
		num //=10
		
	for i in confirmed_num:
		if i[1] > biggest_dig:
			biggest_dig = i[1]


	return confirmed_num, biggest_dig # Funkcijas atgriez skaitlu virkni, kura ir ierakstits cik reizes katrs skaitlis atkartojas un skaitu kas bija lielakais reizu skaits cik reizes paradijas

			

nat_num = False
while nat_num == False:
	num = int(input('Ievadiet naturalu skaitli: '))

	nat_num = nat_num_validate(num)

confirmed_numbers, most_reacuring_dig = endivitual_num(num)

for confirmed_num in confirmed_numbers:
	if confirmed_num[1] == most_reacuring_dig:
		print(f'Cipars kas atkartojas ir {confirmed_num[0]}, tas atkartojas {confirmed_num[1]}. reizes')


# Testa plāns
# Ievads		Programma vēlamā		Rezultāts Python
# 				   reakcija

#  64				 1 1					+
#

#  8898		    	 3					+
# 
#  43034
#
#