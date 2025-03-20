## 📌 **Webserv - Implémentation d'un Serveur HTTP en C++**  

### 📖 **Description**  
**Webserv** est un projet qui consiste à développer un **serveur HTTP** en **C++ 98**. L'objectif est de comprendre le fonctionnement des **requêtes et réponses HTTP**, la gestion des **sockets**, ainsi que l'implémentation des **routes et méthodes HTTP**.  

Ce projet permet d’approfondir les **systèmes UNIX**, les **protocoles réseau**, et la **gestion des processus**.  

---

### 📂 **Contenu du projet**  

#### 1️⃣ **Partie Obligatoire**  
Le programme `webserv` doit :  
- **Gérer plusieurs clients simultanément** à l’aide de **poll()** ou un équivalent (`select()`, `kqueue()`, `epoll()`).  
- **Écouter sur plusieurs ports et hôtes simultanément**.  
- **Gérer un fichier de configuration** (exemple : `config.conf`).  
- **Prendre en charge les méthodes HTTP :**  
  - `GET` → Récupérer un fichier ou une page statique.  
  - `POST` → Envoyer des données au serveur (ex : formulaire, fichier).  
  - `DELETE` → Supprimer une ressource sur le serveur.  
- **Gérer les erreurs HTTP et afficher des pages d’erreur personnalisées**.  
- **Gérer les requêtes non bloquantes** (aucune opération de lecture/écriture ne doit bloquer le serveur).  
- **Servir des fichiers statiques** (ex : `.html`, `.css`, `.js`).  
- **Gérer les limites de taille des requêtes (`client_max_body_size`)**.  
- **Gérer les en-têtes HTTP** correctement.  

##### 📌 **Exemple de fichier de configuration `config.conf` :**  
```conf
server {
    listen 8080;
    server_name myserver.com;

    error_page 404 /404.html;

    location / {
        root /var/www/html;
        index index.html;
    }

    location /upload {
        method POST;
        upload_store /var/www/uploads;
    }

    location /cgi-bin/ {
        cgi_pass /usr/bin/php-cgi;
    }
}
```
- **Définit les ports d'écoute et le nom du serveur**.  
- **Gère les pages d’erreur personnalisées**.  
- **Spécifie des routes (`location`) avec des règles spécifiques**.  
- **Active le support CGI pour certains fichiers (`/cgi-bin/`)**.  

⚠ **Restrictions :**  
- **Le serveur ne doit jamais bloquer** (utilisation de `poll()`, `select()`, `epoll()`, ou `kqueue()`).  
- **Le client doit toujours recevoir une réponse** (même en cas d’erreur).  
- **Pas d’utilisation de bibliothèques externes (sauf celles autorisées)**.  
- **Les erreurs HTTP doivent être correctes et conformes à la RFC 2616**.  
- **Le serveur doit fonctionner avec un navigateur web standard (ex : Chrome, Firefox, Curl)**.  

#### 2️⃣ **Bonus (optionnel)**  
- **Support des sessions et cookies**.  
- **Prise en charge de plusieurs scripts CGI** (PHP, Python, etc.).  
- **Gestion du WebSocket** pour des connexions en temps réel.  
- **Gestion avancée du `multipart/form-data` pour l’upload de fichiers**.  

⚠ **Les bonus ne seront évalués que si la partie obligatoire est parfaitement fonctionnelle !**  

---

### ⚙️ **Compilation et Utilisation**  

#### 🏗 **Compilation**  
Le projet utilise un **Makefile** pour compiler `webserv`.  
```bash
make        # Compile le serveur
make clean  # Supprime les fichiers objets (.o)
make fclean # Supprime les fichiers objets et l’exécutable
make re     # Nettoie et recompile tout
```

#### 🛠 **Utilisation**  
Lancer le serveur avec un fichier de configuration :  
```bash
./webserv config.conf
```
Tester avec `curl` :  
```bash
curl -X GET http://localhost:8080/
```
Envoyer un fichier avec `POST` :  
```bash
curl -X POST -F "file=@test.txt" http://localhost:8080/upload
```
Supprimer un fichier avec `DELETE` :  
```bash
curl -X DELETE http://localhost:8080/file.txt
```
---

### 📜 **Règles et Contraintes**  
✅ Respect de la **Norme C++ 98**  
✅ Pas de **fuites mémoire** (valgrind doit être propre)  
✅ **Gestion correcte des sockets et du réseau**  
✅ **Utilisation exclusive des fonctions système UNIX autorisées**  
✅ **Compatibilité avec un navigateur web**  

---

### 📄 **Fichiers Importants**  
📂 **Makefile** → Gestion de la compilation  
📂 **includes/** → Contient les fichiers `.hpp` nécessaires  
📂 **src/** → Contient les fichiers `.cpp` du serveur  
📂 **config/** → Contient des fichiers `.conf` de test  
📂 **www/** → Contient des fichiers statiques `.html`, `.css`, `.js`  

---

### 🚀 **Auteur**  
👤 **Hugo Goorickx** **Lisa Buccheri** - Projet réalisé dans le cadre de l’école **19**  