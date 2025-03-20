
## 📌 **Libft - Une bibliothèque C personnalisée**  

### 📖 **Description**  
**Libft** est un projet visant à recréer certaines fonctions standard de la bibliothèque C, ainsi que des fonctions supplémentaires et des utilitaires pour la gestion de listes chaînées. Ce projet permet de mieux comprendre le fonctionnement interne des bibliothèques en C et de constituer une base de code réutilisable pour des projets futurs.  

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Cette partie contient des fonctions usuelles de la **libc** recodées en respectant leurs prototypes et comportements d’origine.  
**Liste des fonctions implémentées :**  
- Fonctions de vérification : `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`  
- Fonctions de manipulation de chaînes : `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`  
- Fonctions de manipulation de mémoire : `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`  
- Fonctions de conversion : `ft_toupper`, `ft_tolower`, `ft_atoi`  
- Fonctions auxiliaires : `ft_strlcpy`, `ft_strlcat`, `ft_bzero`  

#### 2️⃣ **Partie Supplémentaire**  
Cette partie ajoute des fonctions absentes de la **libc** mais utiles pour le développement en C :  
- Fonctions de manipulation de chaînes : `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`  
- Fonctions d'affichage : `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`  

#### 3️⃣ **Bonus - Listes Chaînées**  
Le projet inclut des fonctions permettant de manipuler des **listes chaînées** via une structure `t_list` :  
- Création et gestion de listes : `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`  
- Suppression et nettoyage : `ft_lstdelone`, `ft_lstclear`  
- Itération et transformation : `ft_lstiter`, `ft_lstmap`  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet est accompagné d’un **Makefile** permettant de compiler la bibliothèque.  
Commandes disponibles :  
```bash
make        # Compile libft.a (partie obligatoire)
make bonus  # Compile libft.a avec les bonus
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et la bibliothèque (libft.a)
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Inclure **libft** dans un projet se fait en ajoutant la bibliothèque et l’en-tête dans le code :  
```c
#include "libft.h"

// Exemple d'utilisation
int main() {
    char *str = ft_strdup("Hello, Libft!");
    printf("%s\n", str);
    free(str);
    return 0;
}
```
Compiler avec :  
```bash
gcc main.c -L. -lft -o my_program
```

---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme 42**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ Respect des **prototypes et comportements originaux** des fonctions standard  
✅ Interdiction d’utiliser **libtool**  
✅ Pas de **variables globales**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **libft.h** → Fichier d’en-tête contenant les prototypes et la structure `t_list`  
📂 **ft_*.c** → Implémentations des fonctions  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  