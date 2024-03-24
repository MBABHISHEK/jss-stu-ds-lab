#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *LL, *RL;
};
typedef struct node *NODE;
NODE construct(NODE r)
{
    int ch;
    for (;;)
    {
        printf("Enter 1 for Insertion and 0 to STOP :");
        scanf("%d", &ch);
        if (ch == 0)
            break;
        NODE nn = ((NODE)malloc(sizeof(struct node)));
        nn->RL = nn->LL = NULL;
        printf("Enter Info : ");
        scanf("%d", &nn->info);
        if (r == NULL)
            return nn;
        NODE tp = r, pn = NULL;
        while (tp != NULL)
        {
            pn = tp;
            if (nn->info < tp->info)
                tp = tp->LL;
            else
                tp = tp->RL;
        }
        if (nn->info < pn->info)
            pn->LL = nn;
        else
            pn->RL = nn;
    }
    return r;
}
void inorder(NODE r)
{
    if (r == NULL)
        return;
    inorder(r->LL);
    printf("%d ", r->info);
    inorder(r->RL);
}
void postorder(NODE r)
{
    if (r == NULL)

        return;
    postorder(r->LL);
    postorder(r->RL);
    printf("%d ", r->info);
}
void preorder(NODE r)
{
    if (r == NULL)
        return;
    printf("%d ", r->info);
    preorder(r->LL);
    preorder(r->RL);
}
void searchbykey(NODE r)
{
    if (r == NULL)
    {
        printf("Tree Empty\n");
        return;
    }
    printf("Enter The Key : ");
    int key;
    scanf("%d", &key);
    if (r->info == key)
    {
        printf("Element Found and its the Root of The Tree\n");
        return;
    }
    NODE tp = r, pn = NULL;
    while (tp != NULL)
    {
        pn = tp;
        if (key < tp->info)
            tp = tp->LL;

        else
            tp = tp->RL;
        if (tp == NULL) // if not found tp will be NULL
        {
            printf("Element not Found\n");
            return;
        }
        if (tp->info == key)
        {
            printf("Element Found and Parent is %d\n", pn->info);
            return;
        }
    }
}
NODE inordersuccessor(NODE r)
{
    NODE current = r;
    while (current && current->RL != NULL)
        current = current->RL;
    return current;
}
NODE deletebykey(NODE r, int key)
{
    if (r == NULL)
        return NULL;
    if (key < r->info)
        r->LL = deletebykey(r->LL, key);
    else if (key > r->info)
        r->RL = deletebykey(r->RL, key);
    else
    {
        if (r->LL == NULL)
        {
            NODE temp = r->RL;
            free(r);
            return temp;
        }
        else if (r->RL == NULL)
        {
            NODE temp = r->LL;
            free(r);
            return temp;
        }
        NODE temp = inordersuccessor(r->RL);
        r->info = temp->info;
        r->RL = deletebykey(r->RL, temp->info);
    }
    return r;
}
void main()
{
    NODE root = NULL;
    int ch;
    for (;;)

    {
        printf("1.Tree Construction\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Search by Key\n6.Delete By Key\nEnter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = construct(root);
            break;
        case 2:
            printf("Inorder Traversal is : ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal is : ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal is : ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            searchbykey(root);
            break;
        case 6:
            printf("Enter The Key : ");
            int key;
            scanf("%d", &key);
            root = deletebykey(root, key);
            break;
        }
    }
}
