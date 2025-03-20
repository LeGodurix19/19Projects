## 📌 **Minitalk - Communication entre processus via signaux UNIX**  

### 📖 **Description**  
**Minitalk** est un projet qui vise à implémenter un système de communication entre un **client** et un **serveur** en utilisant exclusivement les **signaux UNIX** (`SIGUSR1` et `SIGUSR2`).  

Le serveur écoute et affiche les messages envoyés par le client, qui transmet une chaîne de caractères en encodant les bits sous forme de signaux. Ce projet permet de mieux comprendre la gestion des signaux et la communication inter-processus en C.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Le projet est composé de **deux programmes exécutables** :  
- **Le serveur** → Attend des messages, affiche son **PID** au lancement et reçoit les données envoyées par le client.  
- **Le client** → Envoie une **chaîne de caractères** au serveur via des **signaux UNIX**.  

**Comportement attendu :**  
- Le **serveur** doit afficher son **PID** au démarrage.  
- Le **client** prend en argument :  
  - **Le PID du serveur**  
  - **Une chaîne de caractères à transmettre**  
- La communication **ne peut se faire que via `SIGUSR1` et `SIGUSR2`**.  
- Le **serveur doit afficher le message** une fois la transmission terminée.  
- **Plusieurs clients peuvent envoyer des messages à la suite sans relancer le serveur.**  

**Fonctions autorisées :**  
- `write`, `malloc`, `free`, `exit`  
- `ft_printf` ou un équivalent codé par toi-même  
- Gestion des signaux : `signal`, `sigemptyset`, `sigaddset`, `sigaction`, `kill`, `getpid`, `pause`, `sleep`, `usleep`  

---

#### 2️⃣ **Bonus (optionnel)**  
- **Le serveur envoie une confirmation** au client après réception de chaque message.  
- **Support des caractères Unicode** pour permettre l’envoi de caractères spéciaux.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** permettant de compiler le **serveur** et le **client**.  
```bash
make        # Compile les exécutables serveur et client
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et les exécutables
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Démarrer le serveur :  
```bash
./serveur
```
Cela affichera un **PID** (exemple : `12345`).

Envoyer un message avec le client :  
```bash
./client 12345 "Hello, Minitalk!"
```
Le serveur affichera alors :  
```bash
Hello, Minitalk!
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ **Gestion propre des signaux**  
✅ **Pas de boucles infinies** → Le serveur ne doit pas ralentir avec le temps  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` d’implémentation  
📂 **serveur** → Programme serveur  
📂 **client** → Programme client  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  