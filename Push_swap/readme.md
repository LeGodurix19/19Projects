## 📌 **Push_swap - Algorithme de tri avec un ensemble limité d'opérations**  

### 📖 **Description**  
**Push_swap** est un projet d’algorithmie consistant à trier une liste d'entiers en utilisant deux piles (`a` et `b`) et un ensemble d'opérations spécifiques. L'objectif est d'optimiser le nombre de coups nécessaires pour obtenir un tri efficace.

Le projet inclut également un programme `checker`, qui permet de vérifier si la séquence d'instructions produite par `push_swap` est correcte.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire - Programme `push_swap`**  
Le programme `push_swap` prend en argument une liste d'entiers et doit produire une **suite minimale d’instructions** permettant de **trier la pile `a`** en ordre croissant.  

**Opérations disponibles :**  
- **Échanges :**  
  - `sa` : Échange les deux premiers éléments de `a`.  
  - `sb` : Échange les deux premiers éléments de `b`.  
  - `ss` : Effectue `sa` et `sb` en même temps.  

- **Push (transfert d'élément) :**  
  - `pa` : Déplace le premier élément de `b` vers `a`.  
  - `pb` : Déplace le premier élément de `a` vers `b`.  

- **Rotations :**  
  - `ra` : Décale `a` vers le haut.  
  - `rb` : Décale `b` vers le haut.  
  - `rr` : Effectue `ra` et `rb` simultanément.  

- **Rotations inversées :**  
  - `rra` : Décale `a` vers le bas.  
  - `rrb` : Décale `b` vers le bas.  
  - `rrr` : Effectue `rra` et `rrb` en même temps.  

**Exemple d'exécution :**  
```bash
$> ./push_swap 3 2 1 5 4
sa
ra
ra
```

**Contraintes :**  
- Le programme **ne doit pas afficher autre chose** que les instructions de tri.  
- En cas d’erreur (entrée invalide, doublons, non-entier), afficher `"Error"` suivi d'un `\n` sur la sortie d’erreur.  
- La **complexité des opérations doit être optimisée** :
  - **100 nombres** triés en **< 700 opérations**  
  - **500 nombres** triés en **< 5500 opérations**  

#### 2️⃣ **Bonus - Programme `checker`**  
Le programme **`checker`** prend en argument une liste d’entiers et attend une **séquence d’instructions** en entrée standard. Il exécute ces instructions et affiche **"OK"** si la pile `a` est triée et `b` vide, sinon **"KO"**.  

**Exemple d'exécution :**  
```bash
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** permettant de compiler `push_swap` et `checker`.  
```bash
make        # Compile push_swap
make bonus  # Compile checker
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et les exécutables
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Exécuter `push_swap` :  
```bash
./push_swap 3 2 1 6 5
```
Exécuter `push_swap` avec `checker` :  
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ **Optimisation du nombre d’opérations**  
✅ Gestion des **erreurs** (`Error\n` en cas de doublons ou entrée invalide)  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` d’implémentation  
📂 **push_swap** → Exécutable principal  
📂 **checker** (bonus) → Exécutable de vérification  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  