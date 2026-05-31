# 2526_Projet1A_Cansat

## A Propos de la CanSat
Le concours CanSat, organisé chaque année dans le cadre du C’Space par le CNES et Planète Sciences, propose aux étudiants de concevoir, construire et faire voler un véritable mini-satellite de la taille d’une canette.
Lancé depuis un drone à environ 150 mètres d’altitude, le CanSat doit réaliser une mission scientifique ou technique en chute contrôlée, tout en respectant des contraintes strictes de taille, de masse et d’autonomie et en réalisant les missions imposées.
Ce concours permet aux étudiants d’aborder concrètement l’ensemble des étapes d’un projet spatial : conception système, intégration électronique, programmation embarquée, gestion de l’énergie et tests.

# L'équipe
- Marin.P
- Pierre-Antoine.R
- Lucas.G
- Arnaud.M
- Mathis.B.

## Liste des fonctionnalités
- Mesure de la pression grâce au baromètre
- Mesure de la distance grâce au TOF
- Utilisation d'un moteur pour actionner un mécanisme
- Prise de vidéo à l'aide de la caméra
- Interrupteur général permettant d'allumer et éteindre la canette

## Choix des composants
- Microcontroleur (stm32g431kbt)
- Baromètre (bnp581)
- Moteur brushless (GA12-N20)
- Centrale inertielle (abandonné) 
- Time of Lights (abandonné)
- Caméra (VC0706)
- Interrupteur

## PCB
<img width="767" height="712" alt="image" src="https://github.com/user-attachments/assets/fc9043c4-c62f-4b40-8fdd-d5d9bdf81f5b" />


PCB à quatre couches constitué de
- STM32G431KBT
- Régulateur 6.5-36V vers 5V
- Régulateur 5V vers 3.3V
- Driver Moteur
- Baromètre
- Interface Jack
- Interface Moteur
- Interface Bouton
- Interface Camera
- Connecteur ST


## Difficultés

Approvisionnement en composants
Nous n'avons pas reçu exactement les composants que l'on souhaitait au départ notamment la caméra qui devait enregistrer les images pendant la chute. Celle à laquelle nous avons eu accès transmet les images par onde radio, permettant de voir directement les images sur un écran extérieur à la canette.

Forme restrictive
La forme particulière du PCB imposée par le volume restreint de la canette et le système d'ouverture du parachute a constitué un frein considérable à la conception du PCB.

Code
Une étude détaillée du fonctionnement du baromètre a été nécessaire afin de coder les différentes fonctions permettant d'aboutir au calcul de l'altitude, ce qui a été très chronophage 

Conception de la canette
Le système d'ouverture du parachute a été le principal défi de conception nous forçant à modifier l'architecture de notre canette.


## Solutions trouvées

Les composants 
Pour la caméra nous avons trouvé une caméra avec un fonctionnement différent de celle initialement prévue.
Nous avons reçu le baromètre déjà soudé sur un PCB alors que nous avions demandé le baromètre seul, nous l'avons donc désoudé pour le resouder sur notre PCB.
En attendant la livraison du connecteur pour la batterie (JST-SH) nous avons soudé directement la batterie à l'interface prévue initialement pour le connecteur.

Conception de la canette 
Nous avons séparé notre canette en 2 espaces : une partie acceuillant le PCB et ses différents composants dont le moteur et une partie dans laquelle se trouve le parachute.
Le système d'ouverture fonctionne gràce à 2 goupilles qui maintiennent la partie contenant le parachute et la patie contenant le PCB ensemble. Ces 2 goupilles sont reliées par des fils au moteur qui en tournant va enrouler ces fils autour de son axe et les libérer. Le capuchon dans lequel se trouve le parachute va donc se détacher pour laisser le parachute sortir et se déployer. Le capuchon une fois détaché du reste de la canette reste relié à celle-ci via un autre fil nous permettant de respecter une exigeance imposée par le concours: aucune partie de la canette ne doit tomber au sol sans être ralentie.

## Partie Méca

Partie contenant le PCB et tout les éléments qui y sont reliés :
<img width="902" height="511" alt="image" src="https://github.com/user-attachments/assets/38d895d1-ad01-4584-8a0e-90aecc5c6918" />

Opercule fermant la partie PCB qui maintient la partie parachute :
<img width="898" height="510" alt="image" src="https://github.com/user-attachments/assets/543768c2-f79f-4a44-81d8-2554685a19ac" />

Corps du capuchon contenant le parachute : 
<img width="904" height="507" alt="image" src="https://github.com/user-attachments/assets/d3025e49-6c13-4ef4-8b9e-eeaec2ea7e83" />

Opercule fermant le capuchon du parachute :
<img width="900" height="509" alt="image" src="https://github.com/user-attachments/assets/e0bd637e-639f-47a3-a1f0-ecc056483ceb" />

## Bilan des fonctionnalités


Test du bouton permettant d'allumer la LED

https://github.com/user-attachments/assets/89bd5818-fe06-4b41-a8be-61a60c13a220



Test du moteur

https://github.com/user-attachments/assets/85a999e9-10d9-4074-9609-f378fe4b467d







## Reflexion responsable 
Dans quelle mesure votre projet peut-il être intégré à des mesures d’adaptaton ou d’aténuaton du changement
climatque ?

Notre Cansat pourrait filmer un territoire pendant le largage et nous y montrer une évolution. Par exemple, face à une forêt, voir l'effet d'une déforestation ou d'une dégradation du territoire. 
