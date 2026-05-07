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
- Time of Lights 
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

## Reflexion responsable 
Dans quelle mesure votre projet peut-il être intégré à des mesures d’adaptaton ou d’aténuaton du changement
climatque ?

Notre Cansat pourrait filmer un territoire pendant le largage et nous y montrer une évolution. Par exemple, face à une forêt, voir l'effet d'une déforestation ou d'une dégradation du territoire. 
