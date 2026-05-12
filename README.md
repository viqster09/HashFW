# 🔐 HashFW

> Mini framework de cracking de hash développé en C ⚡

HashFW est un outil CLI léger permettant d’effectuer des attaques par dictionnaire sur différents types de hash comme :

- 🔓 MD5

- 🔐 SHA256

- 📚 Dictionary Mode


Le projet a été conçu dans un objectif :

- d’apprentissage

- de compréhension des fonctions de hash

- d’expérimentation locale en environnement contrôlé

---

# ✨ Fonctionnalités

✅ Interface CLI interactive  

✅ Support MD5  

✅ Support SHA256  

✅ Support des wordlists  

✅ Architecture simple et modulaire  

✅ Compatible Linux / Kali Linux  

✅ Implémentation dans un seul fichier  

✅ Framework extensible  

---

# 📦 Prérequis

Avant compilation, installer :

- 🛠 GCC

- 🔑 OpenSSL Dev Libraries

---

# ⚙️ Installation

## 🐧 Debian / Ubuntu / Kali Linux

### Installer les dépendances
```bash
sudo apt install gcc libssl-dev
```

---

### Compiler le framework
```bash
gcc hashcat.c -o hashcat -lcrypto -lssl
```

---

### Lancer HashFW
```bash
./hashcat
```

---

# 🖥️ Interface CLI

Une fois lancé :
```bash
HashFW CLI v1.0

hashfw >
```

---

# 📚 Commandes Disponibles

| Commande | Description |
```bash
|---|---|
| -u <module> | 🔧 Sélectionner un module |
| --use <module> | 🔧 Sélectionner un module |
| -sh <hash> | 🎯 Définir le hash cible |
| --hash <hash> | 🎯 Définir le hash cible |
| -sw <fichier> | 📂 Charger une wordlist |
| --wordlist <fichier> | 📂 Charger une wordlist |
| -r | 🚀 Lancer l’attaque |
| --run | 🚀 Lancer l’attaque |
| -h | ❓ Afficher l’aide |
| --help | ❓ Afficher l’aide |
| exit | 🚪 Quitter le framework |
```

---

# 🧩 Modules Disponibles

## 🔓 MD5

Effectue une attaque par dictionnaire sur un hash MD5.

Exemple :
```bash
-u md5
```

---

## 🔐 SHA256

Effectue une attaque par dictionnaire sur un hash SHA256.

Exemple :
```bash
-u sha256
```

---

## 📚 DICT

Mode dictionnaire brut :

compare directement le texte avec l’entrée cible.

Exemple :
```bash
-u dict
```

---

# 🚀 Exemple Complet

## 🔓 Crack d’un hash MD5

### Hash cible
```bash
5d41402abc4b2a76b9719d911017c592
```

---

### Mot correspondant
```bash
hello
```

---

### Contenu du fichier test.txt

hello

admin

password

test

---

## ⚡ Commandes
```bash
-u md5
-sh 5d41402abc4b2a76b9719d911017c592
-sw test.txt
-r
```

---

## ✅ Résultat

[+] FOUND: hello

---

# 📂 Wordlists sur Kali Linux

## 🔥 RockYou

Wordlist très connue en cybersécurité.

### Emplacement

/usr/share/wordlists/rockyou.txt

---

## 📦 Si compressée
```bash
gunzip /usr/share/wordlists/rockyou.txt.gz
```

---

## 📌 Utilisation dans HashFW
```bash
-sw /usr/share/wordlists/rockyou.txt
```

---

# 🔐 Algorithmes Supportés

| Algorithme | Statut |

|---|---|

| 🔓 MD5 | ✅ Supporté |

| 🔐 SHA256 | ✅ Supporté |

---

# 🧠 Fonctionnement Interne

HashFW fonctionne de cette manière :

1️⃣ Sélection du module  

2️⃣ Chargement du hash cible  

3️⃣ Chargement de la wordlist  

4️⃣ Lecture ligne par ligne  

5️⃣ Génération du hash correspondant  

6️⃣ Comparaison avec le hash cible  

7️⃣ Affichage du résultat si correspondance  

---

# ⚠️ Warning OpenSSL

Avec OpenSSL 3.x, ce warning peut apparaître :

MD5 is deprecated

👉 Cela est normal et n’empêche pas l’exécution du programme.

---

# 🛡️ Sécurité & Avertissement

⚠️ Ce projet est destiné uniquement :

- à l’apprentissage

- aux laboratoires de test

- à l’étude des algorithmes de hash

- aux audits autorisés

❌ Toute utilisation non autorisée sur des systèmes tiers peut être illégale.

---

# 🚧 Améliorations Futures

Fonctionnalités prévues :

- ⚡ Multi-threading

- 🔍 Détection automatique des hash

- 🧩 Plugins dynamiques

- 📊 Statistiques de performance

- 💥 Mode brute-force

- 🔐 Support NTLM

- 🔒 Support bcrypt

---

# 📁 Structure du Projet

hashcat.c

README.md
