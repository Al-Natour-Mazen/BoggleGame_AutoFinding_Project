Vous trouverez 1 dossier et un fichier dans ce répertoire :
-------------------------------------------------------------
		
	* Dossier src : Ce dossier contient les fichiers sources du Boggle.
	
	* Makefile : un makefile permettant de compiler le projet plus facilement.
	
		--> la commande "make" permet de compiler les fichiers sources 
		--> la commande "make clean" permet de nettoyer les fichiers générés

Comment utiliser le Boggle ? 
----------------------------

	Tout d'abord, Boggle est un jeu où les joueurs essaient de trouver autant de mots que possible dans une grille de lettres disposées aléatoirement. 
	Cette grille est de taille 4*4 par défaut, mais il est possible de modifier cette valeur dans le fichier BoggleMain.cpp, ligne 19 par : BoggleGame game(dictionaryFileName, X); où X est la taille que vous désirez.
	
	Dans ma conception, il y a plusieurs manières de lancer le Boggle et des comportements qui peuvent surgir :
	
		* ./boggle
		 	
		 	>> Dans ce cas, le programme va générer une grille de manière aléatoire.
		 
		* ./boggle a a
		
			>> Dans ce cas, le programme va récupérer l'entrée de l'utilisateur, dans notre cas 'a', puis 'a' et les placer dans la grille en partant du haut et de la gauche pour remplir chaque ligne et passer à la ligne suivante, et le reste des lettres sera généré aléatoirement.
		
		* ./boggle a b c d a b c d a b c d a b c d 
		
			>> Dans ce cas, il y a exactement la taille de la grille (par défaut) en entrée, à savoir 16 lettres, et donc toutes les lettres seront prises en compte dans la grille.
			
		* ./boggle a b c d a b c d a b c d a b c d a b c d
		
			>> Dans ce cas, il y a plus de lettres en entrée que la taille de la grille (par défaut), donc seulement les 16 premières lettres seront prises en compte.
			
		* ./boggle a 5 gg azertoipp 4687684 / ^ 
			
			>> Dans ce cas, il y aura des caractères qui vont être ignorés de l'entrée, à savoir '5', 'gg', 'azertoipp', '4687684', '/', '^', 'qd', et seulement le caractère 'a' sera pris en compte dans la grille, et le reste des lettres sera généré aléatoirement.


	Le résultat de tous les mots possibles, "possibleWords.txt", se générera au même niveau que ce readme et le Makefile. Lorsque vous lancerez la commande "make clean", il sera supprimé.
	
	Si vous voulez afficher la grille, vous pourrez décommenter la ligne 22 dans le fichier BoggleMain.cpp.
	Le programme a été testé plusieurs fois et il fonctionne sans problème. Il a également été vérifié avec Valgrind.




