# 42push_swap
Projet du 3ème cercle du cursus 42

# Consignes:
**Créer un programme qui recoit des int en arguments, les stock dans une stack A, et les trie par ordre croissant de facon optimisée a l'aide d'une stack B vide et avec un pannel d'actions limité.**
### Les actions possibles
- swap : échanger les deux premiers int d'une stack (si A: sa; si B: sb; si les deux: ss).
- push : déplacer le premier int d'une stack au sommet de l'autre (si déplace sur A: pa; si déplace sur B; pb).
- rotate : décaler tous les int d'une stack vers le haut, en passant alors le premier en dernier (si A: ra; si B: rb; si les deux: rr).
- reverse rotate : décaler tous les int d'une stack vers le bas, en passant alors le dernier en premier (si A: rra; si B: rrb; si les deux: rrr).

# Gestion des erreurs
Vous devez verifier que les arguments recus sont bien:
- des chiffres.
- plus precisement des int (pas de virgules, et rien en-dehors de int_min et int_max).
- uniques (pas de repetitions).

ATTENTION, les arguments doivent pouvoir etre traites de la meme facon, peu importe si:
- ils sont passes sans guillemets (ex.: 2 453 86 9).
- ils sont passes entre guillemets comme une seule string (ex.: "2 453 86 9").
- ils sont TOUS passes entre guillemets comme plusieurs string (ex.: "2" "453" "86" "9").

# Listes chainées
Pour ce projet, vous pouvez tout a fait choisir d'utiliser des tableaux. Cependant, les listes chainées offrent des avantages intéressants. 

## Qu'est-ce qu'une liste chainée?
Pour comprendre les listes chainées, comparons-les avec les tableaux.

Un tableau réserve un espace mémoire dans lequel il peut stocker des valeurs, les unes a la suite des autres au sein de l'espace réservé. Ces valeurs sont donc physiquement voisines les unes des autres. On accede a chacune facilement grace a un index. Pour imager, on pourrait dire que les valeurs d'un tableau sont toutes dans un meme immeuble, chacune dans leur propre appartement indiqué par l'index.

La liste chainée en revanche met en lien des valeurs éparpillées dans la mémoire, en utilisant des pointeurs: la premiere pointe sur la deuxieme, qui pointe sur la troisieme, et ainsi de suite; la derniere pointe sur NULL. Pour imager, on pourrait dire que les valeurs d'une liste chainée sont les postes d'un rallye, chacun menant au poste suivant. Pour en trouver un spécifique, il faut commencer par le début et parcourir le chemin jusqu'au poste recherché. Dit comme ca, les liste chainées, ca a l'air tres nul. Cependant, elles offrent un avantage non négligeable dans un programme de tri: la ou un tableau devrait decaler toutes ses valeurs pour en ajouter ou en enlever une tout en gérant l'espace mémoire, la liste chainée n'a qu'a modifier ses pointeurs.

## Comment écrire une liste chainée?
Si vous n'etes pas a l'aise avec les pointeurs, accrochez-vous.


```
```



# Algorithme de tri
## Algorithme turc
