# Automate Formal Language AFL Readme
<b><p align="justify">This repository have three implementation of the assignment for the course AFL. The course was ministered for the teacher PhD Elisângela Silva da Cunha Rodrigues.

</p></b>
For the implementation 3 follow one instance (or one automate for minimize):
<p align="justify">
Begin states: A
Bength of the final states: 3
Final states respectively: C D E
Length of the Aphabets symbols: 2
Respectively for the Aphabets symbols: 0 1
Trasiction Function:
	A 0 B
	A 1 C
	B 0 A
	B 1 D
	C 0 E
	C 1 F
	D 0 E
	D 1 F
	E 0 E
	E 1 F
	F 0 F
	F 1 F
	z -1 z // stop condition for the transiction function
1
2
0

// Program Menu:
1 - transiction function of the AFD
2 - transiction function of the AFDM
0 - program output
</p>