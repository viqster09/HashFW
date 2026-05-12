HashFW

Framework minimaliste de cracking de hash développé en C.

Supporte :

attaques par dictionnaire MD5

attaques par dictionnaire SHA256

mode dictionnaire brut

interface CLI interactive

Fonctionnalités

Interface en ligne de commande interactive

Support MD5

Support SHA256

Support des wordlists

Compatible Linux

Architecture légère et simple

Implémentation dans un seul fichier

Prérequis

GCC

Bibliothèques de développement OpenSSL

Installation

Debian / Ubuntu / Kali Linux

Installer les dépendances :

sudo apt install gcc libssl-dev

Compiler le programme :

gcc hashcat.c -o hashcat -lcrypto -lssl

Lancer le framework :
```bash
./hashcat
```
Utilisation

Démarrer le framework
```bash
./hashcat
```
Commandes

Commande	Description

-u <module>	Sélectionner un module

--use <module>	Sélectionner un module

-sh <hash>	Définir le hash cible

--hash <hash>	Définir le hash cible

-sw <fichier>	Définir la wordlist

--wordlist <fichier>	Définir la wordlist

-r	Lancer l’attaque

--run	Lancer l’attaque

-h	Afficher l’aide

--help	Afficher l’aide

exit	Quitter le framework

Modules Disponibles

MD5

Effectue une attaque par dictionnaire sur un hash MD5.

Exemple :
```bash
-u md5
```

SHA256

Effectue une attaque par dictionnaire sur un hash SHA256.

Exemple :
```bash
-u sha256
```

DICT

Mode dictionnaire brut (comparaison directe de texte).

Exemple :
```bash
-u dict
```

Exemple Complet

Crack d’un hash MD5

Hash cible :
```bash
5d41402abc4b2a76b9719d911017c592
```

Texte correspondant :
```bash
hello
```
Contenu de test.txt :
```bash
hello

admin

password

test
```
Commandes :
```bash
-u md5

-sh 5d41402abc4b2a76b9719d911017c592

-sw test.txt

-r
```

Résultat :
```bash
[+] FOUND: hello
Wordlists sur Kali Linux
RockYou
```

Emplacement par défaut :

/usr/share/wordlists/rockyou.txt

Si le fichier est compressé :
```bash
gunzip /usr/share/wordlists/rockyou.txt.gz
```

Utilisation :
```bash
-sw /usr/share/wordlists/rockyou.txt
```
Algorithmes Supportés

Algorithme	Support

MD5	Oui

SHA256	Oui

Structure du Projet

Implémentation en un seul fichier :

hashcat.c

Fonctionnement Interne

Sélection du module

Chargement du hash cible

Chargement de la wordlist

Lecture ligne par ligne

Génération du hash

Comparaison avec le hash cible

Affichage du résultat si correspondance

Warnings OpenSSL

Avec OpenSSL 3.x, il est possible d’obtenir :

MD5 is deprecated

Ce warning est normal et n’empêche pas l’exécution du programme.

Sécurité & Avertissement

Ce projet est destiné :

à l’apprentissage

à l’étude des algorithmes de hash

aux audits locaux autorisés

aux laboratoires et environnements de test


Utilisez uniquement ce programme sur :

vos propres systèmes

ou des systèmes pour lesquels vous avez une autorisation explicite

Toute utilisation non autorisée peut être illégale.

Améliorations Futures

Fonctionnalités prévues :

multi-threading

détection automatique du type de hash

système de plugins/modules

statistiques de performance

mode brute-force

support NTLM

support bcrypt
