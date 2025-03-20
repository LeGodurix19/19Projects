## 📌 **Philosophers - Gestion des Threads et Mutex**  

### 📖 **Description**  
**Philosophers** est un projet permettant d’explorer les **threads**, les **mutex**, et la gestion de la **concurrence** en C. L'objectif est de modéliser le **problème des philosophes mangeurs**, un concept classique en **programmation concurrente**.

Chaque philosophe alterne entre **manger**, **penser**, et **dormir**, tout en partageant des **fourchettes** avec ses voisins. Le programme doit assurer que **chaque philosophe mange avant de mourir de faim**, tout en évitant les **situations de deadlock**.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Le programme **philo** doit :  
- Lancer **un thread par philosophe**.  
- Gérer **un nombre défini de philosophes** et autant de fourchettes.  
- **Un philosophe doit prendre deux fourchettes** (gauche et droite) pour manger.  
- Il alterne entre **manger**, **dormir**, et **penser**.  
- Il **meurt** s'il ne mange pas avant `time_to_die` (en ms).  
- Si tous les philosophes ont mangé `number_of_times_each_philosopher_must_eat` fois, la simulation s'arrête.  

**Syntaxe d’exécution :**  
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Exemple :  
```bash
./philo 5 800 200 200
```
Avec `number_of_philosophers = 5`, `time_to_die = 800ms`, `time_to_eat = 200ms`, `time_to_sleep = 200ms`.

**Affichage attendu :**  
```bash
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
⚠ **Règles supplémentaires :**  
- **Pas de variables globales.**  
- **Protection des fourchettes via des mutex.**  
- **Les messages ne doivent pas se chevaucher (éviter les races conditions).**  
- **L'annonce d’un philosophe mort doit apparaître en moins de 10 ms après sa mort.**  

**Fonctions autorisées :**  
- `pthread_create`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_lock`, `pthread_mutex_unlock`, `pthread_mutex_destroy`  
- `usleep`, `gettimeofday`, `malloc`, `free`, `write`, `printf`  

---

#### 2️⃣ **Bonus (optionnel) - `philo_bonus`**  
Le programme bonus utilise **des processus et des sémaphores** au lieu des threads et mutex.  
- **Chaque philosophe est un processus.**  
- **Les fourchettes sont remplacées par un sémaphore global.**  
- **Le processus parent ne joue pas le rôle de philosophe.**  

**Fonctions supplémentaires autorisées :**  
- `fork`, `kill`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** permettant de compiler `philo` et `philo_bonus` (si bonus réalisé).  
```bash
make        # Compile le programme philo
make bonus  # Compile le programme philo_bonus (si applicable)
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et l’exécutable
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Exécuter `philo` :  
```bash
./philo 5 800 200 200
```
Exécuter `philo_bonus` :  
```bash
./philo_bonus 5 800 200 200
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ **Pas de fuites mémoire** (valgrind doit être propre)  
✅ **Gestion correcte des threads et mutex**  
✅ **Pas de deadlocks ni starvation**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **philo/** → Contient les fichiers `.c` pour la version thread/mutex  
📂 **philo_bonus/** → Contient les fichiers `.c` pour la version process/sémaphore  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  