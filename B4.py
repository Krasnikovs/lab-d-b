# Gustavs Krasnikovs, gk24018
# B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
# Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
# Skaitļa dalīšana ciparos jāveic skaitliski.
# Programma izveidota: 17.09.24

def nat_num_validate(num):
	if num <= 0:
		print('Skatlis nav naturals')
		return False
	else:
		return True
	
def endivitual_num(num):
	confirmed_num = []

	

	for i in range(10):
		confirmed_num.append([])
		confirmed_num[i].append(i)
		confirmed_num[i].append(0)
		
	biggest_dig = 0

	while num > 0:
		confirmed_num[num % 10][1] +=1
		num //=10
		
	for i in confirmed_num:
		if i[1] > biggest_dig:
			biggest_dig = i[1]


	return confirmed_num, biggest_dig

			
		

# def _main_():
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

#  64				 2 32					+
#    				 4 16
# 	    			 8	8
# 		    		16	4
# 			    	32	2

#  8		    	 2	4					+
# 				     4	2
