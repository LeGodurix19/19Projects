# 🚀 **19 Projects - Récapitulatif Général**  

Ce dépôt contient une collection de **projets développés à l’école 42**, chacun mettant en œuvre différentes compétences en **C, C++, programmation système, développement web, infrastructure et cybersécurité**.  

Chaque projet suit les **normes 42**, est **optimisé pour éviter les fuites mémoire** et respecte les **bonnes pratiques de développement**.  

---

## 📂 **Table des Projets**  

| Projet | Description | Langage | Sujet |
|--------|------------|---------|-------|
| **Libft** | Implémentation de la bibliothèque C standard | C | Développement |
| **Get Next Line** | Lecture de fichiers ligne par ligne | C | Gestion mémoire |
| **Ft_printf** | Reproduction de la fonction `printf()` | C | Variadic functions |
| **Push_swap** | Algorithme d’optimisation de tri | C | Algorithmes |
| **Minitalk** | Communication entre processus via signaux UNIX | C | Signaux |
| **So_long** | Mini-jeu 2D en utilisant MiniLibX | C | Graphisme |
| **Philosophers** | Synchronisation multi-threading avec mutex | C | Threads |
| **Minishell** | Implémentation simplifiée de `bash` | C | Systèmes UNIX |
| **Cub3D** | Moteur de jeu 3D basé sur `Wolfenstein 3D` | C | Raycasting |
| **Inception** | Infrastructure Dockerisée avec services multiples | Docker | DevOps |
| **Webserv** | Serveur HTTP en C++ | C++ | Réseau |
| **Ft_transcendence** | Développement full-stack d’un site web | TypeScript / React | Web |

---

## 🏗 **Installation et Utilisation Générale**  

### 📌 **Cloner le dépôt**  
```bash
git clone https://github.com/LeGodurix19/19Projects.git/42-projects.git
cd 42-projects
```

### 📌 **Compiler tous les projets**  
Un **Makefile global** permet de compiler, nettoyer et reconstruire tous les projets en une seule commande.  

```bash
make        # Compile tous les projets
make clean  # Supprime les fichiers objets
make fclean # Supprime les objets et exécutables
make re     # Recompile tout proprement
```

### 📌 **Démarrer les projets Dockerisés**  
Certains projets comme **Inception** et **Ft_transcendence** nécessitent **Docker** pour fonctionner.  

```bash
make docker-up    # Démarrer les services Docker
make docker-down  # Arrêter les services
```

---

## 🔍 **Détail des Projets**  

### **1️⃣ Libft - Bibliothèque C Personnalisée**  
📌 **Description** : Implémentation des fonctions standard de la **libc**.  
📌 **Objectifs** : Maîtriser la gestion de la mémoire et optimiser les performances.  

📂 **Compilation et utilisation** :  
```bash
make -C libft
gcc main.c -Llibft -lft -o test
```

---

### **2️⃣ Get Next Line - Lecture de fichiers**  
📌 **Description** : Fonction permettant de **lire un fichier ligne par ligne**.  
📌 **Objectifs** : Gérer la mémoire dynamiquement et optimiser l’allocation.  

📂 **Exécution** :  
```bash
make -C get_next_line
./get_next_line fichier.txt
```

---

### **3️⃣ Ft_printf - Reproduction de `printf()`**  
📌 **Description** : Fonction permettant **d’afficher des variables formatées** comme `printf()`.  
📌 **Objectifs** : Gestion des **fonctions variadiques** et de la conversion de types.  

📂 **Exemple d’utilisation** :  
```bash
ft_printf("Hello %s, the number is %d\n", "World", 42);
```

---

### **4️⃣ Push_swap - Algorithme de tri**  
📌 **Description** : Tri d’une pile en un **nombre minimal d’opérations**.  
📌 **Objectifs** : Optimisation des algorithmes de tri et gestion de la mémoire.  

📂 **Lancer le programme** :  
```bash
./push_swap "3 2 1 5 4"
```

---

### **5️⃣ Minitalk - Communication entre processus**  
📌 **Description** : Transmission de **messages entre processus** via `SIGUSR1` et `SIGUSR2`.  
📌 **Objectifs** : Comprendre la gestion des **signaux UNIX**.  

📂 **Exemple d’exécution** :  
```bash
./server
./client <PID_SERVER> "Hello"
```

---

### **6️⃣ So_long - Mini-jeu 2D**  
📌 **Description** : Déplacement d’un personnage sur une **carte générée** en `.ber`.  
📌 **Objectifs** : Apprentissage de **MiniLibX** et de la gestion des événements.  

📂 **Lancer le jeu** :  
```bash
./so_long maps/map.ber
```

---

### **7️⃣ Philosophers - Gestion de threads**  
📌 **Description** : Synchronisation de **philosophes mangeant à une table**.  
📌 **Objectifs** : Gestion de **threads et mutex** en programmation concurrente.  

📂 **Exécution** :  
```bash
./philo 5 800 200 200
```

---

### **8️⃣ Minishell - Implémentation d’un Shell**  
📌 **Description** : Reproduction simplifiée de **bash**.  
📌 **Objectifs** : Manipulation des processus, des **pipes**, et gestion des **signaux**.  

📂 **Lancer le shell** :  
```bash
./minishell
```

---

### **9️⃣ Cub3D - Moteur de Raycasting**  
📌 **Description** : Implémentation d’un **moteur 3D** basé sur **Wolfenstein 3D**.  
📌 **Objectifs** : Maîtriser le **raycasting** et la gestion graphique en C.  

📂 **Lancer le jeu** :  
```bash
./cub3D maps/map1.cub
```

---

### **🔟 Inception - Infrastructure Dockerisée**  
📌 **Description** : Mise en place de **plusieurs services Dockerisés** (**Nginx, WordPress, MariaDB**).  
📌 **Objectifs** : Maîtriser Docker et l’**orchestration avec Docker Compose**.  

📂 **Démarrer l’infrastructure** :  
```bash
make -C inception up
```

---

### **1️⃣1️⃣ Webserv - Serveur HTTP en C++**  
📌 **Description** : Implémentation d’un **serveur HTTP** supportant `GET`, `POST`, `DELETE`.  
📌 **Objectifs** : Apprentissage du **réseau et des sockets en C++**.  

📂 **Lancer le serveur** :  
```bash
./webserv config.conf
```

---

### **1️⃣2️⃣ Ft_transcendence - Application Web Full-Stack**  
📌 **Description** : Un **site web interactif** permettant de jouer à **Pong en ligne**.  
📌 **Objectifs** : Développement **full-stack** avec **React, NestJS, PostgreSQL**.  

📂 **Démarrer le projet** :  
```bash
make up -C ft_transcendence
```

---

## 🚀 **Auteur**  
👤 **hgoorick** - Projets réalisés dans le cadre de **l’école 19**.  # 19Projects
