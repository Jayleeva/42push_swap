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

La liste chainée en revanche met en lien des valeurs éparpillées dans la mémoire, en utilisant des pointeurs: la premiere pointe sur la deuxieme, qui pointe sur la troisieme, et ainsi de suite; la derniere pointe sur NULL. Pour imager, on pourrait dire que les valeurs d'une liste chainée sont les postes d'un rallye, chacun menant au poste suivant. Pour en trouver un spécifique, il faut commencer par le début et parcourir le chemin jusqu'au poste recherché. Dit comme ca, les liste chainées, ca a l'air tres nul. Cependant, elles offrent un avantage non négligeable dans un programme de tri: la ou un tableau devrait decaler toutes ses valeurs pour en ajouter ou en enlever une tout en gérant constamment l'espace mémoire, la liste chainée n'a qu'a modifier ses pointeurs.

## Comment écrire une liste chainée?
Si vous n'etes pas a l'aise avec les pointeurs, accrochez-vous (ca va aller).

### Structures
Tout d'abord, pour ce projet du moins, on a besoin d'une structure, dont voici l'architecture de base:
```
typedef struct your_struct_name
{
	int		  		value;
	struct	your_struct_name 	*next;
}			    		your_struct_name_t;
```
On peut aussi l'ecrire ainsi:
```
typedef struct your_struct_name your_struct_name_t
{
	int		  		value;
	struct	your_struct_name	*next;
};
```
La reprise du nom de la structure suivie d'un _t semble etre une convention de nommage qui permet de distinguer le "modele" de la structure et son instance concrete (du moins c'est ainsi que je le comprends).

``typedef`` permet de definir un nouveau type d'element.

``struct`` precise que ce type sera une structure.

``your_struct_name`` donne un nom personnalise a votre structure.

Comme vous le voyez, cet exemple de structure contient un int appele "value": il servira a stocker la valeur du chainon de la chaine; par exemple, si c'est le premier chainon et qu'on a recu les arguments ``2 453 86 9``, il stockera ``2``. 
L'exemple contient egalement quelque chose appele "*next". Mais pourquoi diable son type est-il le meme que celui qu'on definit avec ``typedef``, comme une sorte de structureception ? Et pourquoi y a-t-il une etoile devant? Il y a une etoile parce que c'est un pointeur, et il est du type meme qu'on definit dans notre structure parce qu'on veut qu'il puisse pointer sur un autre chainon, lui-meme de ce type-la.

Pas clair? Peut-etre faut-il nous pencher sur ce a quoi servent les structures.

Basiquement, une structure permet de creer des "sous-variables" a un endroit pour toutes les variables du type de la structure. Ici, au lieu de creer manuellement un int a chaque fois que je cree un nouveau chainon, je dis que chaque chainon, deja cree ou futur, a le potentiel d'avoir un int ou stocker sa valeur. Chaque chainon peut y acceder simplement a l'aide de l'ecriture suivante: ``your_node_name->value``. La fleche ``->`` indique "cette variable a une "sous-variable" definie dans sa structure, et je veux y acceder". Ainsi, nous pouvons aussi acceder au "*next", avec la meme methode: ``your_node_name->next``. Ce qui nous donne l'adresse du prochain chainon. Et voila notre liste chainee: chaque chainon peut contenir sa propre valeur, ET l'adresse du chainon suivant! 

Mais ce n'est pas tout... On peut cumuler les fleches! Par exemple, si je veux acceder a la valeur du 2eme chainon, je n'ai qu'a ecrire: ``your_node_name->next->value``. Et si je veux l'adresse du 3eme? ``your_node_name->next->next``. Etc. 

Bon, c'est bien beau, mais si ma chaine fait plus de 20, 500, 1000000000 chainons, et que je veux acceder au 42eme, je ne vais quand meme pas ecrire plus de 40 fleches, non? Non.

### Naviguer dans une liste chainee
*ATTENTION: comme on utilise des pointeurs, il faut faire bien attention a ce qu'on modifie! Si vous recevez un pointeur, vous recevez en realite une adresse memoire, sur laquelle s'effectueront tous les changements que vous appliquez au pointeur. C'est justement ce qu'on veut dans certains cas, et c'est precisement ce qu'on ne veut pas dans d'autres. Prenez l'habitude de conscientiser la nature de ce que vous recevez en arguments!*

Pour passer d'un chainon a l'autre, il vous suffit d'actualiser l'adresse du chainon actuel, en lui assignant celle du suivant:
```
your_node_name = your_node_name->next;
```
Cependant, si vous le faites directement sur le pointeur, vous perdez le lien avec le chainon precedent (a moins d'utiliser une liste doublement chainee, mais nous n'en traiterons pas ici). Si vous devez acceder a un chainon en particulier sans perdre aucune adresse, faites-en une copie, par exemple:
```
your_struct_name_t	*copy;

copy = *your_list;
```
Puis, vous pouvez utiliser des boucles while pour avancer jusqu'au chainon desire. 

Si vous connaissez sa place exacte en int (par ex., le 3eme chainon: sa place = 2):
```
while (place > 0)
{
	copy = copy->next;
	place --;
}
```
Si vous voulez aller jusqu'a la fin de la chaine, servez-vous du fait que le dernier chainon est identifiable parce qu'il pointe sur NULL:
```
while (copy->next != NULL)
	copy = copy->next;
```
## Modifier les listes chainees
Les differentes actions autorisees (swap, push, rotate, reverse rotate) vont directement modifier nos listes chainees. Puisqu'on travaille avec des pointeurs, pas besoin pour nos fonctions "actions" de retourner quoi que ce soit.

### swap
1. Stocker le pointeur recu en argument (sommet actuel de la pile) ainsi que le chainon suivant dans des copies separees.
2. Faire pointer la copie du 1er chainon sur le 3eme chainon.
3. Faire pointer la copie du 2eme chainon sur la copie du 1er.
4. Assigner la copie du 2eme chainon au pointeur recu en argument pour le mettre a jour.

### push
*!! Identifiez quelle pile doit transmettre un chainon a l'autre.*
1. Verifier si la pile qui doit transmettre un chainon est vide: si c'est le cas, return. Sinon, on continue.
2. Stocker le sommet actuel de la pile qui doit transmettre un chainon dans une copie. ``giving_top_cpy = *giving_top;``
3. Deplacer le sommet de la pile qui transmet en lui assignant son suivant: ``*giving_top = (*giving_top)->next;``
4. Stocker le sommet actuel de la pile qui recoit un chainon dans une copie. ``receiving_top_cpy = *receiving_top;``
5. Assigner la copie du sommet de la pile qui transmet au sommet de la pile qui recoit. ``*receiving_top = giving_top_cpy;``
6. Faire pointer le nouveau sommet de la pile qui a recu un chainon sur la copie de son ancien sommet. ``(*receiving_top)->next = receiving_top_cpy;``

### rotate
1. Stocker le pointeur recu en argument dans deux copies separees: une qui servira de "curseur" pour parcourir la liste, et une autre qui stock. ``current = *top; top_cpy = *top;``
2. Faire une boucle while qui deplace la copie "curseur" tant qu'elle ne pointe pas sur NULL. ``while (current->next != NULL){current = current->next;}``
3. Deplacer le sommmet en lui assignant son suivant. ``top = top->next;``
4. Faire pointer la copie "curseur" sur la 2eme copie. ``current->next = top_copy;``
5. Faire pointer la 2eme copie sur NULL. ``top_cpy->next = NULL;``

# Algorithme de tri
## Algorithme turc
