## 📌 **So_long - Un jeu 2D simple avec MiniLibX**  

### 📖 **Description**  
**So_long** est un jeu **2D** développé avec la bibliothèque **MiniLibX**. Le but du jeu est de contrôler un personnage qui doit **collecter tous les objets** d’une carte avant d’atteindre la sortie.  

Ce projet met en avant les bases du **développement graphique**, la gestion des **événements clavier** et la **manipulation d’images et de sprites**.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire - Le jeu**  
- Le joueur doit récupérer **tous les objets (`C`)** et atteindre **la sortie (`E`)**.  
- Déplacement avec les **touches `W, A, S, D`**.  
- Le personnage **ne peut pas traverser les murs (`1`)**.  
- **Affichage des mouvements dans le terminal**.  
- La carte est lue depuis un fichier `.ber`.  

**Exemple de carte `.ber` :**  
```
1111111
1P000E1
1C00111
1111111
```
Légende :  
- `1` → Mur  
- `0` → Espace vide  
- `C` → Objet à récupérer  
- `E` → Sortie  
- `P` → Position de départ  

⚠ **Contraintes :**  
- La carte doit être **rectangulaire** et entourée de **murs**.  
- Il doit **exister un chemin valide** vers la sortie.  
- **Gestion des erreurs** (`Error\n` en cas de carte invalide).  

#### 2️⃣ **Gestion Graphique**  
- Le jeu doit s’afficher **dans une fenêtre** via **MiniLibX**.  
- Fermeture propre en appuyant sur **ESC** ou en cliquant sur la croix de la fenêtre.  
- Les mouvements doivent être **fluides et réactifs**.  

#### 3️⃣ **Bonus (optionnel)**  
- **Ajout d’ennemis** : Si le joueur touche un ennemi, il **perd** la partie.  
- **Animations des sprites** pour plus de fluidité.  
- **Affichage des mouvements sur l’écran** plutôt que dans le terminal.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise **MiniLibX**, compilé avec `-lmlx -framework OpenGL -framework AppKit -lz`.  
```bash
make        # Compile le jeu
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et l’exécutable
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Lancer le jeu avec une carte :  
```bash
./so_long maps/map1.ber
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ **Gestion propre des erreurs et de la carte**  
✅ **Utilisation de MiniLibX pour l’affichage**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` du jeu  
📂 **textures/** → Contient les sprites et assets visuels  
📂 **maps/** → Contient des cartes `.ber` d’exemple  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  