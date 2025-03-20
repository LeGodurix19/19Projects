## 📌 **Minishell - Un Shell Simplifié**  

### 📖 **Description**  
**Minishell** est une implémentation simplifiée de **Bash**, permettant d’exécuter des **commandes interactives**, de gérer des **redirections et des pipes**, et d’interpréter des **variables d’environnement**. Ce projet vise à approfondir la compréhension des **processus, des descripteurs de fichiers et de la gestion des signaux** en C.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Le programme `minishell` doit :  
- **Afficher un prompt** lorsqu’il attend une commande.  
- **Gérer un historique** des commandes.  
- **Exécuter des binaires** en cherchant dans `$PATH` ou via un chemin absolu/relatif.  
- **Utiliser au maximum une variable globale** pour les signaux.  
- **Gérer les redirections :**  
  - `<` → Redirige l’entrée standard depuis un fichier.  
  - `>` → Redirige la sortie standard vers un fichier.  
  - `<<` (Heredoc) → Lit l’entrée jusqu’à un **délimiteur donné**.  
  - `>>` → Append la sortie à un fichier existant.  
- **Gérer les pipes `|`** entre plusieurs commandes.  
- **Gérer les variables d’environnement (`$VAR`)**.  
- **Gérer `$?`** (statut de sortie de la dernière commande exécutée).  
- **Interpréter les signaux :**  
  - `Ctrl+C` → Affiche un nouveau prompt.  
  - `Ctrl+D` → Quitte le shell.  
  - `Ctrl+\` → Ne fait rien.  
- **Implémenter les commandes internes :**  
  - `echo` (supporte `-n`)  
  - `cd` (chemin absolu ou relatif)  
  - `pwd`  
  - `export`  
  - `unset`  
  - `env`  
  - `exit`  

⚠ **Restrictions :**  
- **Les citations (`'` et `"`)** doivent être correctement gérées.  
- **Aucune gestion de caractères spéciaux non demandés** (`\`, `;`, etc.).  
- **Aucune mémoire ne doit fuir** (sauf celles de `readline()`, qui est autorisée).  
- **Le comportement doit être proche de `bash`** lorsque ce n’est pas précisé.  

#### 2️⃣ **Bonus (optionnel)**  
- **Ajout des opérateurs logiques `&&` et `||`** (avec parenthèses pour la priorité).  
- **Gestion du wildcard `*`** pour lister les fichiers correspondants dans le dossier courant.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** permettant de compiler `minishell`.  
```bash
make        # Compile le programme minishell
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et l’exécutable
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Lancer le shell :  
```bash
./minishell
```
Exécuter une commande simple :  
```bash
minishell$ ls -la
```
Exécuter une commande avec pipe et redirection :  
```bash
minishell$ cat fichier.txt | grep "hello" > result.txt
```
Quitter `minishell` :  
```bash
minishell$ exit
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre, sauf `readline()`)  
✅ **Utilisation correcte des processus et des signaux**  
✅ **Comportement proche de `bash` lorsque nécessaire**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` du shell  
📂 **libs/** → Contient `libft` si utilisée  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** **Lisa Buccheri** **Mateo Buccheri** - Projet réalisé dans le cadre de l’école **19**  