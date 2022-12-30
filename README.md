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
| ✅ | ✅ | ✅ | ✅ |

## Fonctionnalités actuelles
- Interface avec QT
- Threads.
- Socket (client et serveur asynchrone).
- "Bases de données" en json.
- Il est possible de déposer et d'envoyer de l'argent pour deux comptes de la même agence.
- On peut créer et supprimer des comptes et des utilisateurs.
- Les comptes ont un taux d'intérêt.
- Toutes les 10 secondes (court pour pouvoir déboguer) chaque agence envoie sa base de données à l'agence centrale.
- Avec la requête "get {acountId}", l'agence centrale va chercher un compte donné dans ses bases de données et renvoyer le json correspondant.
- Commandes "send" et "deposit" pour envoyer 100$ et déposer 1000$ vers des comptes aléatoires (pour debug car nous n'avons pas d'interface).
- La commande "update {agencyId} {timestamp}" permet de mettre à jour la base de données d'une agence, l'agence centrale va renvoyer sa base donnée si elle a été modifié plus récemment que celle de locale de l'agence en question en comparant les deux timestamp d'écriture.

## Schéma explicatif (backend)
## Aperçu de l'interface
![image](https://user-images.githubusercontent.com/52755677/209443922-85e1b8f9-366c-4e63-a9ce-40fe61a302af.png)
![image](https://user-images.githubusercontent.com/52755677/209443934-3319f12c-d50c-474a-b15f-0cbb8f2b2b05.png)
![image](https://user-images.githubusercontent.com/52755677/209443959-e35ad5ce-d3a6-404a-883f-7850c806680b.png)
![image](https://user-images.githubusercontent.com/52755677/209443976-1d2a5b22-fb2d-430d-8c8d-4151a820322a.png)



