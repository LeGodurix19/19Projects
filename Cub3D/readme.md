## 📌 **Cub3D - Implémentation d’un moteur Raycasting**  

### 📖 **Description**  
**Cub3D** est un projet inspiré du jeu **Wolfenstein 3D**, qui utilise la technique du **raycasting** pour simuler une vue en **pseudo-3D** dans un environnement labyrinthique. Ce projet permet d'explorer les concepts de **mathématiques appliquées, gestion graphique et interaction utilisateur** à l’aide de la bibliothèque **MiniLibX**.  

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Le programme `cub3D` doit :  
- **Générer une vue en pseudo-3D** à partir d’un fichier `.cub` décrivant un labyrinthe.  
- **Utiliser la technique du raycasting** pour calculer les collisions et les distances.  
- **Afficher des textures différentes** selon la direction des murs (**Nord, Sud, Est, Ouest**).  
- **Gérer les couleurs du sol et du plafond** séparément.  
- **Gérer les déplacements** :  
  - `W` / `A` / `S` / `D` → **Déplacement avant/arrière et latéral**.  
  - Flèches gauche/droite → **Rotation de la caméra**.  
- **Quitter proprement** via `ESC` ou en cliquant sur la croix de la fenêtre.  

##### 📌 **Format du fichier `.cub` (exemple) :**  
```txt
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```
- `NO`, `SO`, `WE`, `EA` → **Chemins des textures murales**.  
- `F` / `C` → **Couleurs du sol et du plafond (RGB 0-255)**.  
- `1` → Mur, `0` → Espace vide, `N/S/E/W` → Position et orientation du joueur.  
- **La carte doit être fermée par des murs.**  

⚠ **Restrictions :**  
- **La gestion des fenêtres doit être fluide** (minimisation, passage d’une autre fenêtre, etc.).  
- **Les textures doivent être correctement chargées et affichées.**  
- **Gestion correcte des erreurs** (`Error\n` si la carte est invalide).  

#### 2️⃣ **Bonus (optionnel)**  
- **Détection des collisions avec les murs**.  
- **Ajout d’une minimap dynamique** affichant le labyrinthe et la position du joueur.  
- **Ajout de portes ouvrables/fermables** dans la carte `.cub`.  
- **Animations des textures et sprites (effet de flamme, eau, etc.).**  
- **Gestion de la souris** pour tourner la caméra.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise **MiniLibX**, compilé avec `-lmlx -framework OpenGL -framework AppKit -lz`.  
```bash
make        # Compile le jeu
make bonus  # Compile la version bonus (si applicable)
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et l’exécutable
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Lancer le jeu avec une carte :  
```bash
./cub3D maps/map1.cub
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ **Utilisation correcte des maths et du raycasting**  
✅ **Gestion propre des erreurs et du fichier `.cub`**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` du moteur  
📂 **textures/** → Contient les textures murales  
📂 **maps/** → Contient des cartes `.cub` d’exemple  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** **Lisa Buccheri** - Projet réalisé dans le cadre de l’école **19**  