## 📌 **Get Next Line - Lecture optimisée ligne par ligne**  

### 📖 **Description**  
**Get Next Line** est une fonction permettant de lire un fichier ligne par ligne à partir d'un **descripteur de fichier (fd)**. Ce projet met en avant la gestion efficace de la mémoire et l'utilisation des **variables statiques** en C.  

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
L'implémentation de `get_next_line()` permet de lire un fichier texte ligne par ligne.  

**Prototype :**  
```c
char *get_next_line(int fd);
```
**Comportement attendu :**  
- À chaque appel, retourne la **ligne suivante** du fichier, y compris le `\n` si présent.  
- Renvoie `NULL` si la fin du fichier est atteinte ou en cas d'erreur.  
- Compatible avec l'entrée standard (`fd = 0`).  
- Fonctionne avec un **buffer de taille variable**, défini à la compilation avec `-D BUFFER_SIZE=<valeur>`.  

**Fonctions externes autorisées :**  
- `read`, `malloc`, `free`  

**Fichiers à rendre :**  
- `get_next_line.h` → Contient le prototype de la fonction  
- `get_next_line.c` → Contient l'implémentation principale  
- `get_next_line_utils.c` → Contient les fonctions auxiliaires  

⚠ **Restrictions :**  
- **Pas de libft autorisée.**  
- **Pas de `lseek()`.**  
- **Aucune variable globale autorisée.**  

#### 2️⃣ **Bonus (optionnel)**  
Quelques améliorations peuvent être ajoutées :  
- **Gestion de plusieurs `fd` en parallèle** → Permet de lire plusieurs fichiers sans perdre la progression de chacun.  
- **Utilisation d’une seule variable statique** pour améliorer l’efficacité.  

**Fichiers bonus à rendre :**  
- `get_next_line_bonus.c`  
- `get_next_line_bonus.h`  
- `get_next_line_utils_bonus.c`  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet doit être compilé avec une définition de `BUFFER_SIZE` :  
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```
#### 🛠 **Utilisation**  
Voici un exemple d’utilisation pour lire un fichier ligne par ligne :  
```c
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd))) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ Compatible avec **BUFFER_SIZE dynamique**  
✅ **Gestion efficace de la mémoire** (lecture progressive, pas de surcharge inutile)  

---

### 📄 **Fichiers Importants**  
📂 **get_next_line.h** → Contient le prototype de la fonction  
📂 **get_next_line.c** → Implémentation principale  
📂 **get_next_line_utils.c** → Fonctions utilitaires  

📂 **Fichiers bonus** (si implémentés) :  
📂 `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`  

---

### 🚀 **Auteur**  
👤 **hgoorick** - Projet réalisé dans le cadre de l’école **19**