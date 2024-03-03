# Automate d'Analyse Ascendante

Ce programme implémente un automate d'analyse ascendante en C++.
Il est conçu pour analyser et évaluer des expressions arithmétiques simples.

## Description

L'automate prend en entrée une chaîne de caractères représentant une expression arithmétique et l'évalue afin d'en déterminer le résultat.

**Les symboles acceptés sont les suivants :**
- symbole d'addition : +
- symbole de multiplication : *
- symbole de parenthèse ouvrante : (
- symbole de parenthèse fermante : )

Des [exemples](#exemples) sont donnés plus bas.

## Fonctionnalités

- Analyse et interprétation d'expressions arithmétiques
- Gestion des opérations arithmétiques d'addition et de multiplication
- Prise en charge des parenthèses pour la priorité des opérations
- Gestion des erreurs de syntaxe

## Utilisation

Pour utiliser l'automate d'analyse ascendante, vous pouvez suivre les étapes suivantes :

1. Placez-vous dans le dossier `src` et ouvrez une fenêtre du terminal ici.
2. Compilez le programme dans votre terminal en utilisant la commande `make`.
3. Lancez l'exécutable avec la commande `./automate`.
4. Entrez une expression arithmétique valide lorsque vous y êtes invité(e). Des [exemples](#exemples) sont donnés plus bas.
5. L'automate d'analyse ascendante affichera le résultat si la syntaxe est correcte, un message d'erreur sinon.
6. Vous pouvez relancer le programme, ou bien effacer les fichiers compilés et l'exécutable avec la commande `make clean`.

Si vous souhaitez afficher plus d'informations concernant l'analyse, vous pouvez mettre la constante `DEBUG` à `true` dans le fichier `automate.cpp`, ligne 9.
Cela vous permettra notamment d'afficher les piles d'états et de symboles.

## Exemples

Voici quelques exemples d'expressions arithmétiques valides :

- 2+3*4 *qui donnera 14*
- (5+2)*(3+1) *qui donnera 28*
- 10*(2+3) *qui donnera 50*

### Auteurs
Tim Morel et Marie Roulier, 4IF4
