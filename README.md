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
- La commande "update {agencyId} {timestamp}" permet de mettre à jour la base de données d'une agence, l'agence centrale va renvoyer sa base donnée si elle a été modifié plus récemment que celle de locale de l'agence en question en comparant les deux timestamp d'écriture.

## Informations importantes
Pour faire fonctionner le projet, ouvrez N27UI dans QT creator, vérifiez bien que le chemin de build correspond au dossier N27UI/build.
- Lancez le serveur asychrone (l'agence centrale)
- Lancez l'interface qui fait office de client et d'agence décentralisée
- Ce projet a été développé et compilé sur Fedora37
## Aperçu de l'interface
![image](https://user-images.githubusercontent.com/52755677/210112491-b7a3fec2-fde3-4d4a-9d2f-d299d5c9728f.png)
![image](https://user-images.githubusercontent.com/52755677/210112471-f144f40b-8c7c-4248-b67a-89fd59277561.png)
![image](https://user-images.githubusercontent.com/52755677/210112554-98034477-097a-4e14-a6bb-ef751591d9e3.png)
![image](https://user-images.githubusercontent.com/52755677/210112560-2e54f5b6-abd8-47f8-a2a5-aa9b82b303da.png)
![image](https://user-images.githubusercontent.com/52755677/210112580-95587d4a-fece-4817-b15e-68283af76df4.png)
![image](https://user-images.githubusercontent.com/52755677/210112589-12f20db5-78b5-49c1-a2a4-04e2532986fc.png)
![image](https://user-images.githubusercontent.com/52755677/210112613-4add1671-e720-4565-aea7-c52d55af9527.png)
![image](https://user-images.githubusercontent.com/52755677/210112625-0aa7b2c2-afaf-4b88-9078-3f687e488a79.png)
![image](https://user-images.githubusercontent.com/52755677/210112642-413c440b-b5d8-41bc-9096-9cf007cd9faa.png)
![image](https://user-images.githubusercontent.com/52755677/210112650-a203240b-9c2c-4705-a212-7b49dd57f0e4.png)













