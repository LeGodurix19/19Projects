# 🚀 **ft_transcendence - Développement Full-Stack d'un Site Web de Pong**  

## 📖 **Description**  
**ft_transcendence** est un projet complet où l'objectif est de concevoir une **application web interactive** permettant aux utilisateurs de jouer à **Pong en ligne**, en intégrant un **backend sécurisé**, un **frontend réactif**, et une **gestion avancée des utilisateurs**.  

Le projet couvre plusieurs domaines techniques :  
- Développement **web full-stack**  
- **Gestion des utilisateurs et authentification**  
- **Infrastructure Dockerisée et DevOps**  
- **Sécurité et cybersécurité**  
- **Intégration d’une intelligence artificielle** pour un adversaire Pong  

Le projet est développé sous **Docker** et s’exécute avec une seule commande.  

---

## 📂 **Contenu du projet**  

### 🏗 **Partie Obligatoire**  

- **Interface Web** : Un site web permettant de jouer à **Pong multijoueur**.  
- **Serveur et API** : Backend gérant la logique du jeu et la base de données.  
- **Gestion des utilisateurs** : Authentification (OAuth 42), profils, avatars.  
- **Matchmaking** : Organisation de **tournois** et de **matchs en ligne**.  
- **Hébergement sécurisé** : Serveur HTTPS avec protection contre XSS/SQLi.  
- **Infrastructure Dockerisée** : Déploiement via `docker-compose up --build`.  

Le projet repose sur une **architecture modulaire** et suit des **standards de sécurité** élevés.  

---

### 🎮 **Fonctionnalités principales**  

#### **1️⃣ Jeu Pong Multijoueur**  
- Jeu de **Pong en ligne** jouable directement sur le navigateur.  
- **Mode local** et **mode multijoueur** (matchmaking, tournois).  
- **Physique réaliste** et **animation fluide**.  
- **Support du clavier et de la souris**.  

#### **2️⃣ Authentification et Gestion des Utilisateurs**  
- **Connexion via OAuth 42**.  
- **Système de profil** (pseudo, avatar, historique des matchs).  
- **Amis et statut en ligne**.  

#### **3️⃣ Chat et Messagerie**  
- **Messages privés** entre joueurs.  
- **Blocage d’utilisateurs** et gestion des contacts.  
- **Invitations aux matchs via le chat**.  

#### **4️⃣ Mode Tournoi**  
- **Tournois en ligne** organisés automatiquement.  
- **Affichage des scores et classement**.  
- **Gestion des rounds et des matchs en direct**.  

#### **5️⃣ Sécurité et Gestion des Données**  
- **Base de données PostgreSQL** avec données sécurisées.  
- **Mots de passe hashés** et authentification sécurisée.  
- **Protection contre les attaques SQLi et XSS**.  
- **Connexion HTTPS** obligatoire.  

#### **6️⃣ Infrastructure Docker et DevOps**  
- **Déploiement via Docker Compose**.  
- **Système de logs** avec gestion des erreurs.  
- **Monitoring avec Prometheus et Grafana**.  

---

## ⚙️ **Technologies utilisées**  

| Domaine | Technologie |
|---------|------------|
| **Backend** | NestJS (Node.js) |
| **Base de données** | PostgreSQL |
| **Frontend** | React / Vanilla JS |
| **Sécurité** | JWT, OAuth 42, HTTPS |
| **Infra & DevOps** | Docker, Docker Compose |
| **Logs & Monitoring** | Prometheus, Grafana |
| **Stockage** | Minio (Stockage objet) |
| **Blockchain (Bonus)** | Ethereum (Solidity) |

---

## 🛠 **Installation et Exécution**  

### 2️⃣ **Lancer les conteneurs Docker**  
```bash
make up
```
📌 **Accéder à l'application :**  
- **Frontend** : [http://127.0.0.1:3000](http://127.0.0.1:3000)  
- **API Docs** : [http://127.0.0.1:4000/api-docs](http://127.0.0.1:4000/api-docs)  
- **Base de données** : [http://127.0.0.1:8081](http://127.0.0.1:8081)  

### 3️⃣ **Gestion des conteneurs**  
| Commande | Action |
|----------|--------|
| `make up` | Démarrer tous les services |
| `make down` | Stopper tous les services |
| `make clean` | Supprimer les conteneurs |
| `make fclean` | Supprimer les volumes & images Docker |
| `make re` | Nettoyer et relancer les services |

⚠ **Le Makefile utilise `sudo`, il peut nécessiter votre mot de passe.**  

---

## 🔥 **Bonus et Modules Avancés**  

**✅ Modules optionnels implémentés :**  
- **Mode IA** : Jouer contre un **adversaire IA intelligent**.  
- **Pong en CLI** : Affronter des joueurs web depuis un terminal.  
- **Personnalisation du jeu** : Skins, modes spéciaux, power-ups.  
- **Stockage sur la blockchain** : Scores des tournois stockés sur Ethereum.  
- **API REST complète** : Permet l’intégration avec d'autres applications.  

**🚀 Modules potentiels à implémenter :**  
- **Support WebRTC** pour du jeu en **temps réel sans latence**.  
- **Mode Spectateur** pour observer les matchs en direct.  
- **Compatibilité mobile** pour jouer sur smartphones et tablettes.  

---

## 📜 **Règles et Contraintes**  
✅ Respect des **standards de sécurité**.  
✅ **Code propre et modulaire** (pas de solutions toutes faites).  
✅ **Utilisation exclusive des technologies imposées**.  
✅ **Aucune fuite mémoire** (vérification avec Valgrind).  
✅ **Respect du format SPA (Single Page Application)**.  

---

## 📄 **Structure du Projet**  

📂 **Makefile** → Gestion de la compilation et des conteneurs  
📂 **srcs/** → Contient le code source  
📂 **srcs/front/** → Frontend React / JS  
📂 **srcs/api/** → Backend NestJS  
📂 **srcs/db/** → Configuration de la base PostgreSQL  
📂 **config/** → Fichiers de configuration  
📂 **docs/** → Documentation et API  

---

## 🚀 **Auteur**  
👤 **Hugo Goorickx** - Projet réalisé dans le cadre de l’école **19**  