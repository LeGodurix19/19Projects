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
👤 **hgoorick** - Projet réalisé dans le cadre de l’école **42**  

---

Ce **README** peut être **personnalisé** en fonction de ton besoin ! 😊

Voici un **README** pour ton projet **Inception**, basé sur ton Makefile et le document PDF que tu as fourni.  

---

## 📌 **Inception - Infrastructure Dockerisée**  

### 📖 **Description**  
**Inception** est un projet qui vise à approfondir l'utilisation de **Docker** et de **Docker Compose** en mettant en place une infrastructure complète composée de plusieurs services virtualisés dans des conteneurs distincts. L'objectif est de configurer et d'orchestrer plusieurs conteneurs de manière efficace et sécurisée.  

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
L’infrastructure Docker doit inclure les services suivants :  
- **NGINX** → Serveur web avec **TLSv1.2 ou TLSv1.3 uniquement**.  
- **WordPress + PHP-FPM** → Système de gestion de contenu sans serveur web intégré.  
- **MariaDB** → Base de données relationnelle pour WordPress.  
- **Volumes** pour :  
  - **Stocker les fichiers WordPress**  
  - **Stocker la base de données**  
- **Un réseau Docker dédié** permettant aux conteneurs de communiquer.  
- **Re-démarrage automatique** des conteneurs en cas de crash.  

##### 📌 **Contraintes**  
- **Chaque service doit avoir son propre Dockerfile**, écrit manuellement.  
- **Utilisation d’Alpine ou Debian (avant-dernière version stable)** pour les conteneurs.  
- **Le conteneur NGINX doit être le seul point d’entrée** via le port **443 (HTTPS)**.  
- **Configuration via un fichier `.env`** pour stocker les variables sensibles.  
- **Le tag `latest` est interdit** (chaque image doit avoir une version spécifique).  
- **Les mots de passe ne doivent pas être présents en dur dans les fichiers** (utilisation de `Docker secrets` recommandée).  
- **Utilisation obligatoire de `docker-compose.yml`** pour orchestrer les services.  

##### 📌 **Exemple de structure de fichiers :**  
```bash
.
├── Makefile
├── .env
├── srcs/
│   ├── docker-compose.yml
│   ├── requirements/
│   │   ├── mariadb/
│   │   │   ├── Dockerfile
│   │   │   ├── conf/
│   │   ├── nginx/
│   │   │   ├── Dockerfile
│   │   │   ├── conf/
│   │   ├── wordpress/
│   │   │   ├── Dockerfile
│   │   │   ├── conf/
│   │   ├── bonus/ (si bonus réalisé)
│   ├── secrets/
│   │   ├── db_password.txt
│   │   ├── db_root_password.txt
└── data/ (volumes Docker)
    ├── wordpress/
    ├── database/
```

#### 2️⃣ **Bonus (optionnel)**  
- **Ajout de Redis** pour gérer le cache de WordPress.  
- **Ajout d’un serveur FTP** pour gérer les fichiers WordPress.  
- **Ajout d’un site statique (HTML/CSS/JS, sans PHP)**.  
- **Ajout d’Adminer** (interface web pour gérer la base de données).  
- **Ajout d’un service supplémentaire pertinent (à justifier en soutenance)**.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Utilisation et Commandes**  

#### 🏗 **Compilation et déploiement**  
Le projet utilise un **Makefile** pour automatiser la gestion des conteneurs.  

```bash
make        # Construit et démarre les conteneurs
make build  # Construit ou reconstruit les images Docker
make up     # Démarre les conteneurs
make down   # Arrête et supprime les conteneurs
make clean  # Supprime les conteneurs, images et volumes
make fclean # Nettoie totalement le projet (conteneurs, volumes, images, réseaux)
make re     # Nettoie et relance tout
make show_me # Affiche les logs détaillés des conteneurs
```

#### 🛠 **Accéder aux services**  
- **WordPress** sera accessible via `https://hgoorick.42.fr`.  
- **MariaDB** est un service interne, utilisé uniquement par WordPress.  
- **Les logs des conteneurs** peuvent être consultés via :  
  ```bash
  docker logs <nom_du_conteneur>
  ```

---

### 📜 **Règles et Contraintes**  
✅ **Respect des bonnes pratiques Docker** (pas de `while true`, `tail -f`, etc.).  
✅ **Utilisation des variables d’environnement** pour les informations sensibles.  
✅ **Interdiction d’utiliser des images Docker toutes faites (sauf Alpine/Debian)**.  
✅ **Gestion correcte des volumes et des secrets Docker**.  
✅ **Infrastructure stable et sécurisée** (HTTPS, redémarrage automatique des services).  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Automatisation de la gestion des conteneurs  
📂 **.env** → Contient les variables d’environnement  
📂 **srcs/** → Contient les configurations des services  
📂 **data/** → Contient les volumes persistant les données  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  