Je crois que la structure la plus optimisée pour le travail sera la liste d'adjacence. 

En terme de mémoire, elle ne représente que les nœuds (pixels blancs/chemins) donc en consomme moins. Puisque une liste d'adjacence va utiliser les pixels blancs et non tout les pixels comme une matrice d'adjacence, elle va nécessairement utiliser moins de mémoire.

En terme de performance, elle est aussi la meilleure car elle peut accéder à ses voisins plus rapidement. En effet, lors de cette opération, avec une liste d'adjacence on aura qu'à regarder les voisins des pixels visés, mais avec une matrice d'adjacence on aurait à parcourir toute une ligne de la matrice pour trouver des connexions.