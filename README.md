# N27
>Développeurs : Hage Rémi, Deparis Hippolyte, Merlaud Thomas, Chiadmi Yassine

## Présentation
### Qu'est-ce que N27 ?

N27 est un projet de deuxième année de cycle préparatoire CIR à l'ISEN Lille.

### En quoi consiste ce projet ?

L'objet de ce projet est de modéliser la gestion de comptes bancaires en ligne.
Le modèle de gestion adopté repose sur une agence considérée comme centrale et plusieurs agences décentralisées. A intervalle régulier, l’agence centrale interroge et rassemble l’ensemble des modifications sur les transactions, situations financières, création de comptes... effectuées dans les agences décentralisées, et met à jour sa base de données.

Les transactions, paiements, dépôts, transferts... sont réalisés dans les agences décentralisées. Elles sont suivies par des enregistrements locaux en mémoire et/ou sur disque.

### En quel langage est développé ce projet ?

Ce projet est développé entièrement en C++.

## Suivi de développement

| structures du backend | mise en place des sockets | mise en place du système de données | interface graphique |
| :------- | :------- | :-------- | :------ |
| ✅ | ✅ | ✅ | 🚫 |

## Fonctionnalités actuelles
- Threads
- Socket (client et serveur asynchrone)
- Il est possible de déposer et d'envoyer de l'argent pour deux comptes de la même agence.
- Toutes les 10 secondes (court pour pouvoir déboguer) chaque agence envoie sa base de données à l'agence centrale.
- Avec la requete "get" il l'agence centrale va chercher un compte donné dans ses bases de données et renvoyer le json correspondant

## Schéma explicatif (backend)
## Aperçu
