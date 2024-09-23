# Gustavs Krasnikovs, gk24018
# B4. Noskaidrot, vai dotajā naturālajā skaitlī ir atrodami vienādi cipari. 
# Ja ir, izdrukāt tos un skaitu, cik reižu dotais cipars ir sastopams. 
# Skaitļa dalīšana ciparos jāveic skaitliski.
# Programma izveidota: 17.09.24

x = int(input('Ievadiet naturalu skaitli: '))

confirmed_deviders = []
confirmed_times = []

for devider in range(1, x):
    if x % devider == 0 and devider != 1:
        confirmed_times.append(int(x / devider))
        confirmed_deviders.append(devider)


for i in range(len(confirmed_times)):
    print(f'Atrasts vienāds cipars {confirmed_deviders[i]} un cipars ir satopams {confirmed_times[i]}. reizes')

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
