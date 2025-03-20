## 📌 **ft_printf - Implémentation personnalisée de printf**  

### 📖 **Description**  
**ft_printf** est une réécriture de la fonction standard `printf()` en C. Ce projet vise à approfondir la gestion des **fonctions variadiques** et l'affichage formaté en C. L'objectif est de comprendre les mécanismes internes de `printf()` tout en créant une version optimisée et réutilisable pour des projets futurs.

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
L'implémentation de `ft_printf` doit supporter les conversions suivantes :  
- `%c` → Affichage d’un **caractère**  
- `%s` → Affichage d’une **chaîne de caractères**  
- `%p` → Affichage d’un **pointeur** en **hexadécimal**  
- `%d` / `%i` → Affichage d’un **nombre entier** en base 10  
- `%u` → Affichage d’un **entier non signé** en base 10  
- `%x` / `%X` → Affichage d’un **nombre hexadécimal** en minuscule/majuscule  
- `%%` → Affichage d’un **pourcentage**  

**Fonctions externes autorisées :**  
- `malloc`, `free`, `write`  
- `va_start`, `va_arg`, `va_copy`, `va_end` (gestion des arguments variadiques)  

#### 2️⃣ **Bonus (optionnel)**  
L'implémentation peut être enrichie avec des fonctionnalités supplémentaires :  
- **Gestion des flags `-`, `0`, `.` et de la largeur minimale**  
- **Prise en charge des flags `#`, `+`, et ` `(espace)**  
- **Amélioration de la gestion des formats complexes**  

⚠ **Le bonus ne sera évalué que si la partie obligatoire est parfaite !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** pour la compilation. Commandes disponibles :  
```bash
make        # Compile la bibliothèque libftprintf.a
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et la bibliothèque (libftprintf.a)
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Une fois `libftprintf.a` compilée, elle peut être utilisée comme une bibliothèque standard dans un projet C :  
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello %s! The number is %d\n", "world", 42);
    return 0;
}
```
Compilation avec `libftprintf.a` :  
```bash
gcc main.c -L. -lftprintf -o my_program
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ Utilisation de **va_list** pour gérer les arguments variables  
✅ Interdiction d’utiliser **libtool**  
✅ Compilation avec les flags `-Wall -Wextra -Werror`  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.h` nécessaires  
📂 **srcs/** → Contient les fichiers `.c` d’implémentation  
📂 **libftprintf.a** → Bibliothèque générée après compilation  

---

### 🚀 **Auteur**  
👤 **Hugo Goorick** - Projet réalisé dans le cadre de l’école **19**  