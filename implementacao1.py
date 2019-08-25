word = raw_input()

while True:
	flag = 0
	for i in word:
		if(ord(i) < 48):
			print("Simbolo nao pertence ao alfabeto")
			word = raw_input("Digite novamente a palavra: ")
			flag =1
			break
		elif(ord(i) > 57 and ord(i) < 65):
			print("Simbolo nao pertence ao alfabeto")
			word = raw_input("Digite novamente a palavra: ")
			flag =1
			break
		elif(ord(i) > 90 and ord(i) < 97):
			print("Simbolo nao pertence ao alfabeto")
			word = raw_input("Digite novamente a palavra: ")
			flag =1
			break
		elif(ord(i) > 122):
			print("Simbolo nao pertence ao alfabeto")
			word = raw_input("Digite novamente a palavra: ")
			flag =1
			break
	if flag == 0:
		break


if ord(word[0]) >= 97 and ord(word[0]) <= 122:
	print("Palavra Aceita") 
elif ord(word[0]) >= 65 and ord(word[0]) <= 90:
	print("Palavra Aceita")
else:
	print("Palavra Recusada")