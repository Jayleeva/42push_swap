# 42push_swap
Projet du 3ème cercle du cursus 42

# Consignes:
**Créer un programme qui reçoit des int en arguments, les stock dans une stack A, et les trie par ordre croissant de façon optimisée à l'aide d'une stack B vide et avec un pannel d'actions limité.**
### Les actions possibles
- swap : échanger les deux premiers int d'une stack (si A: sa; si B: sb; si les deux: ss).
- push : déplacer le premier int d'une stack au sommet de l'autre (si déplace sur A: pa; si déplace sur B; pb).
- rotate : décaler tous les int d'une stack vers le haut, en passant alors le premier en dernier (si A: ra; si B: rb; si les deux: rr).
- reverse rotate : décaler tous les int d'une stack vers le bas, en passant alors le dernier en premier (si A: rra; si B: rrb; si les deux: rrr).

### Gestion des erreurs
Vous devez vérifier que les arguments reçus sont bien:
- des chiffres.
- plus précisement des int (rien en-dehors de int_min et int_max; les floats seront gérés comme des int de toute façon).
- uniques (pas de répétitions).

ATTENTION, les arguments doivent pouvoir être traités de la même façon, peu importe si:
- ils sont passés sans guillemets (ex.: 2 453 86 9).
- ils sont passés entre guillemets comme une seule string (ex.: "2 453 86 9").
- ils sont TOUS passés entre guillemets comme plusieurs string (ex.: "2" "453" "86" "9").
Liberté est donnée de traiter ou non le mélange de string entre guillemets et sans guillemets comme une erreur.

ATTENTION: les erreurs doivent être signalée par un write() dans la **sortie d'erreur**. En clair, écrivez bien ``write(2, "Error\n", 6);``. Remarquez le retour à la ligne.

ATTENTION: vérifiez bien de free() dans vos return là où cela a du sens. 
Pour vérifier les leaks sur linux: ``valgrind ./your_program arg0 arg1``

### Optimisation
Le nombre d'actions effectuées pour trier doit être minimal. On ne veut pas juste un programme qui trie, on en veut un qui trie vite et évite les calculs inutiles.

# Listes chaînées
Pour ce projet, vous pouvez tout à fait choisir d'utiliser des tableaux. Cependant, les listes chaînées offrent des avantages intéressants. 

## Qu'est-ce qu'une liste chaînée?
Pour comprendre les listes chaînées, comparons-les avec les tableaux.

Un tableau réserve un espace mémoire dans lequel il peut stocker des valeurs, les unes à la suite des autres au sein de l'espace réservé. Ces valeurs sont donc physiquement voisines les unes des autres. On accède à chacune facilement grâce à un index. Pour imager, on pourrait dire que les valeurs d'un tableau sont toutes dans un même immeuble, chacune dans leur propre appartement indiqué par l'index.

La liste chaînée en revanche met en lien des valeurs éparpillées dans la mémoire, en utilisant des pointeurs: la première pointe sur la deuxième, qui pointe sur la troisième, et ainsi de suite; la dernière pointe sur NULL. Pour imager, on pourrait dire que les valeurs d'une liste chaînée sont les postes d'un rallye, chacun menant au poste suivant. Pour en trouver un spécifique, il faut commencer par le début et parcourir le chemin jusqu'au poste recherché. Dit comme ca, les liste chaînées, ça a l'air très nul. Cependant, elles offrent un avantage non négligeable dans un programme de tri: là où un tableau devrait décaler toutes ses valeurs pour en ajouter ou en enlever une tout en gérant constamment l'espace mémoire, la liste chainée n'a qu'à modifier ses pointeurs.

## Comment écrire une liste chaînée?
Si vous n'êtes pas à l'aise avec les pointeurs, accrochez-vous (ça va aller).

### Structures
Tout d'abord, pour ce projet du moins, on a besoin d'une structure, dont voici disons l'architecture de base:
```
typedef struct your_struct_name
{
	int		  		value;
	struct	your_struct_name 	*next;
}			    		t_your_struct_name;
```
On peut aussi l'écrire ainsi:
```
typedef struct your_struct_name t_your_struct_name
{
	int		  		value;
	struct	your_struct_name	*next;
};
```
La reprise du nom de la structure précédée d'un ``t_`` semble être une convention de nommage qui permet de distinguer le "modèle" de la structure et son instance concrète (du moins c'est ainsi que je le comprends).

``typedef`` permet de definir un nouveau type de variable.

``struct`` précise que ce type sera une structure.

``your_struct_name`` donne un nom personnalisé à votre structure.

Comme vous le voyez, cet exemple de structure contient un int appelé "value": il servira à stocker la valeur du chaînon de la chaîne; par exemple, si c'est le premier chaînon et qu'on a reçu les arguments ``2 453 86 9``, il stockera ``2``. 
L'exemple contient également quelque chose appelé "*next". Mais pourquoi diable son type est-il le même que celui qu'on définit avec ``typedef``, comme une sorte de structureception ? Et pourquoi y a-t-il une étoile devant? Il y a une étoile parce que c'est un pointeur, et il est du type même qu'on définit dans notre structure parce qu'on veut qu'il puisse pointer sur un autre chaînon, lui-même de ce type-la.

Pas clair? Peut-être faut-il nous pencher sur ce à quoi servent les structures.

Basiquement, une structure permet de créer des "sous-variables" à un endroit pour toutes les variables du type de la structure. Ici, au lieu de créer manuellement un int à chaque fois que je crée un nouveau chaînon, je dis que chaque chaînon, déjà créé ou futur, a le potentiel d'avoir un int où stocker sa valeur. Chaque chaînon peut y accéder simplement à l'aide de l'écriture suivante: ``your_node_name->value``. La flèche ``->`` indique "cette variable a une "sous-variable" définie dans sa structure, et je veux y accéder". Ainsi, nous pouvons aussi accéder au "*next", avec la même methode: ``your_node_name->next``. Ce qui nous donne l'adresse du prochain chaînon. Et voilà notre liste chaînée: chaque chaînon peut contenir sa propre valeur, ET l'adresse du chaînon suivant! 

Mais ce n'est pas tout... On peut cumuler les flèches! Par exemple, si je veux accéder à la valeur du 2ème chaînon, je n'ai qu'à écrire: ``your_node_name->next->value``. Et si je veux l'adresse du 3ème? ``your_node_name->next->next``. Etc. 

Bon, c'est bien beau, mais si ma chaîne fait plus de 20, 500, 1000000000 chaînons, et que je veux accéder au 42ème, je ne vais quand même pas écrire plus de 40 flèches, non? Non.

### Naviguer dans une liste chaînee
*ATTENTION: comme on utilise des pointeurs, il faut faire bien attention à ce qu'on modifie! Si vous recevez un pointeur, vous recevez en réalité une adresse mémoire, sur laquelle s'effectueront tous les changements que vous appliquez au pointeur. C'est justement ce qu'on veut dans certains cas, et c'est précisement ce qu'on ne veut pas dans d'autres. Prenez l'habitude de conscientiser la nature de ce que vous recevez en arguments!*

Pour passer d'un chaînon à l'autre, il vous suffit de mettre à jour l'adresse du chaînon actuel, en lui assignant celle du suivant:
```
your_node_name = your_node_name->next;
```
Cependant, si vous le faites directement sur le pointeur, vous perdez le lien avec le chaînon précédent (à moins d'utiliser une liste doublement chaînée, mais nous n'en traiterons pas ici). Si vous devez accéder à un chaînon en particulier sans perdre aucune adresse, faites-en une copie, par exemple:
```
t_your_struct_name	*copy;

copy = *your_list;
```
Puis, vous pouvez utiliser des boucles while pour avancer jusqu'au chaînon désiré. 

Si vous connaissez sa place exacte en int (par ex., pour le 3ème chaînon: sa place = 2):
```
while (place > 0)
{
	copy = copy->next;
	place --;
}
```
Si vous voulez aller jusqu'à la fin de la chaîne, servez-vous du fait que le dernier chaînon est identifiable parce qu'il pointe sur NULL:
```
while (copy->next != NULL)
	copy = copy->next;
```
## Créer une liste chaînée
Tout d'abord, il faut allouer de l'espace à un premier chaînon: ``your_node_name = (t_your_struct_name *)malloc(sizeof(t_your_struct_name))``. Une fois cela fait, vous pouvez assigner la valeur du premier argument: ``your_node_name->value = arg_value``, et faire pointer votre chaînon sur NULL (dans le cas d'une liste chaînée, cela revient à dire: le chaînon suivant sera NULL, soit: le chaînon actuel est le dernier de la liste): ``your_node_name->next = NULL``. Faites une copie de ce premier chaînon: elle vous servira à parcourir la chaîne.

Pour la suite, vous avez besoin d'une boucle dans une boucle: une englobante qui s'assure de parcourir tous les arguments reçus, et une interne qui s'assure qu'on est bien au dernier chaînon avant d'en créer un nouveau. Tant qu'il vous reste des arguments à assigner, à chaque fois que vous arrivez au dernier chaînon (soit si le prochain est NULL), allouez à nouveau de l'espace pour un nouveau chaînon et assignez-lui sa valeur et un suivant: 
```
if (copy->next == NULL)
{
	copy->next = (t_your_struct_name *)malloc(sizeof(t_your_struct_name));
	copy->next->value = arg_value;
	copy->next->next = NULL;
}
```
Attention, prenez en compte deux choses: le nom du programme est compris comme l'argument 0, et vous avez déjà assigné l'argument 1 dans votre premier chaînon.

Une fois tous vos arguments assignés dans des chaînons, retournez le premier dont vous aviez fait une copie: ``return(your_node_name)``. Et voilà! Votre premier chaînon a une valeur et pointe sur le suivant, qui a sa propre valeur et pointe sur le suivant, etc.

## Passer une liste chaînée en argument
Les listes chaînées passées par le main sont des pointeurs sur pointeur! En conséquence, quand vous déclarez des fonctions qui en reçoivent, il faut vous inspirer de cette écriture: ``void your_function(**list)``. Oui, vous avez bien vu, ce n'est pas une faute de frappe: il y a bien DEUX étoiles.

Je ne maîtrise pas complètement ces histoires de pointeurs, mais voilà ce que j'ai retenu:
- quand vous créez vos listes, il faut les déclarer comme des simples pointeurs du type de votre structure ``t_your_struct_name	*list;``, MAIS
- quand vous passez votre liste la première fois (soit depuis le main a priori), il faut utiliser l'éperluette. ``your_function(&list)`` (ce que je crois avoir compris: cela permet de passer non pas la valeur de la liste mais bien son adresse; puisque c'est déjà un pointeur, cela en fait donc... un pointeur sur pointeur)
- ensuite, vous pouvez vous en passer. ``your_function(list)``
- dans vos fonctions, quand vous voulez accéder à votre liste directement, il faut le signifier avec un astérisque; les copies que vous voudrez en faire devront également être des pointeurs. En revanche, pour accéder à vos copies, plus besoin d'astérisque une fois la déclaration passée (voir "naviguer dans une liste chaînée" ci-dessus).

## Modifier les listes chaînées
Les différentes actions autorisées (swap, push, rotate, reverse rotate) vont directement modifier nos listes chaînées. Puisqu'on travaille avec des pointeurs, pas besoin pour nos fonctions "actions" de retourner quoi que ce soit.

Petite précision: il est possible de faire une liste chaînée circulaire, qui facilite notamment le rotate et reverse rotate. Personnellement, j'ai opté pour ce que je comprenais le mieux sur le moment, en laissant le dernier élément pointer sur NULL.

### swap
1. Stocker le pointeur reçu en argument (sommet actuel de la pile) ainsi que le chaînon suivant dans des copies séparées. ``top_cpy = *top; second = *top;``
2. Faire pointer la copie du 1er chaînon sur le 3ème chaînon. ``top_cpy->next = (*top)->next->next;``
3. Faire pointer la copie du 2ème chainon sur la copie du 1er. ``second->next = top_cpy;``
4. Déplacer le sommet en lui assignant la copie du 2ème chaînon. ``*top = second;``

### push
*!! Identifiez quelle pile doit transmettre un chaînon à l'autre.*
1. Verifier si la pile qui doit transmettre un chaînon ests vide: si c'est le cas, return. Sinon, on continue.
2. Stocker le sommet actuel de la pile qui doit transmettre un chaînon dans une copie. ``giving_top_cpy = *giving_top;``
3. Déplacer le sommet de la pile qui transmet en lui assignant son suivant: ``*giving_top = (*giving_top)->next;``
4. Stocker le sommet actuel de la pile qui reçoit un chaînon dans une copie. ``receiving_top_cpy = *receiving_top;``
5. Assigner la copie du sommet de la pile qui transmet au sommet de la pile qui reçoit. ``*receiving_top = giving_top_cpy;``
6. Faire pointer le nouveau sommet de la pile qui a reçu un chaînon sur la copie de son ancien sommet. ``(*receiving_top)->next = receiving_top_cpy;``

### rotate
1. Stocker le pointeur reçu en argument dans deux copies séparées: une qui servira de "curseur" pour parcourir la liste, et une autre qui stock. ``current = *top; top_cpy = *top;``
2. Faire une boucle while qui déplace la copie "curseur" tant qu'elle ne pointe pas sur NULL (pour trouver le *dernier* chaînon). ``while (current->next != NULL){current = current->next;}``
3. Déplacer le sommmet en lui assignant son suivant. ``*top = top->next;``
4. Faire pointer la copie "curseur" sur la 2ème copie, pour qu'elle devienne le premier chaînon. ``current->next = top_cpy;``
5. Faire pointer la 2ème copie sur NULL, pour qu'elle devienne le dernier chaînon. ``top_cpy->next = NULL;``

### reverse rotate
1. Stocker le pointeur reçu en argument dans deux copies séparées: une qui servira de "curseur" pour parcourir la liste, et une autre qui stock. ``current = *top; top_cpy = *top;``
2. Faire une boucle while qui déplace la copie "curseur" tant que *le chaînon suivant* ne pointe pas sur NULL (pour trouver *l'avant-dernier* chaînon). ``while (current->next->next != NULL){current = current->next;}``
3. Stocker le chaînon suivant le "curseur" dans une copie (dernier chaînon actuellement). ``bottom = current->next;``
4. Faire pointer cette copie sur celle du sommet, pour qu'elle devienne le premier chaînon. ``bottom->next = top_cpy;``
5. Faire pointer l'avant-dernier chaînon sur NULL, pour qu'il devienne le dernier. ``current->next = NULL;``
6. Déplacer le sommet en lui assignant le nouveau premier chaînon. ``*top = bottom;``

# Algorithme de tri
A vous de choisir un algorithme qui vous parle (ou d'en créer un vous-mêmes?). Personnellement j'ai choisi celui dit "le turc".
## Algorithme turc
Tout d'abord, il faut gérer les cas où on reçoit 5 ou moins arguments. On le fait à part parce qu'ils sont "trop faciles" à résoudre et qu'on perdrait finalement du temps de calcul si on les traitait comme des cas plus durs. Au-delà de 5, ça se corse, et un algo est nécessaire. J'ai donc commencé par des conditions qui vérifient si le nombre d'arguments reçus est inférieur ou égal à 5 ou supérieur à 5: en fonction de la réponse, c'est une ou l'autre fonction qui est appelée.
### five_or_less()
- Si 0 OU 1 argument, return. On s'arrête, rien n'est changé, rien n'est imprimé. *ATTENTION: si le seul argument passé n'est pas valide (pas un nombre ou pas un int), il faut imprimer "Error".*
- Si 2 arguments: on vérifie si les deux sont déjà dans le bon ordre. Si c'est le cas, return: rien n'est changé, rien n'est imprimé. Sinon, on les échange, soit par swap, rotate ou reverse rotate. 
- Si 3 arguments: on vérifie si les 3 sont déjà dans le bon ordre. Si c'est le cas, return: rien n'est changé, rien n'est imprimé. Sinon, on les échange: selon l'ordre, soit par swap puis reverse rotate, juste swap, juste rotate, reverse rotate puis swap, ... 
- Si 4 arguments: on cherche le plus petit argument de a, on le met au sommet de a, et on le push sur b. On relance la fonction qui trie 3 arguments. Une fois les 3 de a restants triés, on push sur a celui précédemment déplacé sur b.
- Si 5 arguments: on cherche le plus petit argument de a, on le met au sommet de a, et on le push sur b; on fait exactement la même chose une 2ème fois. On relance la fonction qui trie 3 arguments. Une fois les 3 de a restants triés, on push sur a ceux précédemment déplacés sur b.
### more_than_five()
**Les grandes étapes**
- On commence par faire deux *pb* pour avoir une base sur laquelle travailler.
- Tant qu'il nous reste plus que 3 arguments sur la pile A, on va compter le coût de déplacement pour chacun et *pb* le moins cher.
- Quand il ne reste plus que 3 arguments sur la pile A, on les trie avec notre fonction déjà créée précédemment pour les piles de 3 arguments, puis on vérifie où *pa* chaque argument de la pile B, dans l'ordre de cette dernière, en en identifiant la cible dans A, et on rotate A autant que nécessaire avant de *pa*.

**Calcul du coût**

Le calcul du coût doit prendre en compte:
- Combien de mouvements sont nécessaires pour amener l'argument actuellement traité au sommet de la pile A. Pour cela, il faut identifier son index actuel dans la pile A ainsi que la taille actuelle de la pile A; si l'index est plus petit ou égal à la moitié de la taille, il faut rotate autant que l'index; sinon, il faut reverse rotate autant que la taille moins l'index. En français, si votre argument est dans la partie supérieure de la pile ou pile à la moitié, on fait monter les arguments avec des rotates, jusqu'à ce que le concerné soit au sommet (donc autant de fois que son index); s'il est dans la partie inférieure de la pile, on fait descendre les arguments avec des reverse rotate, jusqu'à ce que le concerné soit propulsé du dernier rang au premier (donc autant de fois que la taille moins l'index).
- Combien de mouvements sont nécessaires pour amener la cible de l'argument actuellement traité au sommet de la pile B. Tout d'abord, il faut donc identifier la cible en question et son index dans la pile B; une fois cela fait, on applique la même logique que dans le point précédent.
- Combien de mouvements peuvent être faits simultanément dans A et B. Repassez en revue vos premiers calculs: l'argument A et sa cible dans B doivent-ils se déplacer dans la même direction? Si oui, ajustez le coût en calculant combien de rotate / reverse rotate ils peuvent faire ensemble, et combien il reste à faire seul pour celui qui est le plus loin de son propre sommet.

**Identifier la cible**

Quand on veut placer un argument de la pile A sur la pile B (la cible est dans B, et la pile B doit être triée du plus grand au plus petit):
- Si comme moi vous n'avez pas fait de liste chaînée circulaire, vérifiez tout d'abord si votre argument est plus petit que le dernier argument de la pile B ET plus grand que le premier argument de la pile A. Si c'est le cas, vous avez trouvé la cible: votre argument doit pointer sur le premier de B.
- Ensuite, parcourez la pile B jusqu'à ce que votre argument soit plus petit que celui actuel de B ET plus grand que le suivant de B. Quand cette condition est remplie, vous avez trouvé la cible: votre argument doit être placé entre l'actuel et le suivant de B, et donc pointer sur le suivant de B.

Quand on veut placer un argument de la pile B sur la pile A (la cible est dans A, et la pile A doit être triée du plus petit au plus grand):
- Si comme moi vous n'avez pas fait de liste chaînée circulaire, vérifiez tout d'abord si votre argument est plus grand que le dernier argument de la pile B ET plus petit que le premier argument de la pile A. Si c'est le cas, vous avez trouvé la cible: votre argument doit pointer sur le premier de A.
- Ensuite, parcourez la pile A jusqu'à ce que votre argument soit grand petit que celui actuel de A ET plus petit que le suivant de A. Quand cette condition est remplie, vous avez trouvé la cible: votre argument doit être placé entre l'actuel et le suivant de A, et donc pointer sur le suivant de A.


