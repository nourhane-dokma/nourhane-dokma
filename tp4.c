#include <stdio.h>
#include <stdlib.h>

// تعريف العنصر في القائمة
typedef struct element {
    int val;
    struct element *suivant;
} element;

// إنشاء قائمة فارغة
element* creerListe() {
    return NULL;
}

// تحميل القائمة من المصفوفة
element* chargerListe(int Tab[], int taille, element *liste) {
    for (int i = 0; i < taille; i++) {
        element *nouveau = (element*)malloc(sizeof(element));
        nouveau->val = Tab[i];
        nouveau->suivant = liste;
        liste = nouveau;
    }
    return liste;
}

// عرض القائمة
void afficherListe(element *L) {
    element *temp = L;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// حذف العنصر الأخير
element* supprimerEnFin(element *L) {
    if (L == NULL) return NULL; // إذا كانت القائمة فارغة
    if (L->suivant == NULL) { // إذا كان هناك عنصر واحد فقط
        free(L);
        return NULL;
    }
    element *temp = L;
    while (temp->suivant->suivant != NULL) {
        temp = temp->suivant;
    }
    free(temp->suivant);
    temp->suivant = NULL;
    return L;
}

// إضافة عنصر في البداية
element* ajouterEnDebut(element *L, int val) {
    element *nouveau = (element*)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = L;
    return nouveau;
}

// تفريغ القائمة
void viderListe(element **L) {
    element *temp;
    while (*L != NULL) {
        temp = *L;
        *L = (*L)->suivant;
        free(temp);
    }
    printf("la liste est vide\n");
}

// البرنامج الرئيسي
int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element *liste = creerListe();

    liste = chargerListe(Tab, 10, liste);
    afficherListe(liste);

    liste = supprimerEnFin(liste);
    afficherListe(liste);

    liste = ajouterEnDebut(liste, 40);
    afficherListe(liste);

    viderListe(&liste);
    return 0;
> }