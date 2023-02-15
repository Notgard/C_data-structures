#include "tree.h"

/**
 * @brief Allocates memory and returns a binary search tree
 * 
 * @return BST the binary search tree
 */
BST bst_init()
{
    BST tree = (BST)malloc(sizeof(Bst));
    tree->root = NULL;
    return tree;
}

/**
 * @brief Frees memory of a binary search tree
 * 
 * @param tree the BST
 */
void bst_free(BST tree)
{
    if (tree != (BST)NULL)
    {
        node_free(tree->root);
        free(tree);
    }
}

/**
 * @brief Inserts a word into a binary search tree using strcmp compare. Cf https://linux.die.net/man/3/strcmp
 * 
 * @param node the node to insert
 * @param tree the BST
 */
void bst_insert(struct node_t *node, BST tree)
{
    if (tree->root == NULL)
    {
        tree->root = node;
    }

    if (strcmp(tree->root->word, node->word) > 0)
    {
        // insert left
        node->father = tree;
        if (tree->root->left == NULL)
        {
            tree->root->left = bst_init();
        }
        bst_insert(node, tree->root->left);
    }
    else
    {
        if (strcmp(tree->root->word, node->word) < 0)
        {
            // insert right
            node->father = tree;
            if (tree->root->right == NULL)
            {
                tree->root->right = bst_init();
            }
            bst_insert(node, tree->root->right);
        }
    }
}

/**
 * @brief Prints recursively a BST
 * 
 * @param tree root node
 * @param indent starts at 0
 */
void bst_print(BST tree, int indent)
{
    if (tree != NULL)
    {
        char ind[20];
        size_t max_len = sizeof(ind);
        if (tree->root->left)
            bst_print(tree->root->left, indent + 4);
        if (tree->root->right)
            bst_print(tree->root->right, indent + 4);
        if (indent)
        {
            snprintf(ind, max_len, "%s%d%s", "%", indent, "s");
            printf(ind, ' ');
        }
        printf("%s\n ", tree->root->word);
    }
}

/**
 * @brief Searchs a word in a BST
 * 
 * @param tree the BST
 * @param word the word to search for
 * @return struct node_t* 
 */
struct node_t * bst_search(BST tree, char word[MAX_SIZE])
{
    if (tree == (BST)NULL)
    {
        return NULL;
    }
    else
    {
        if (tree->root == NULL)
        {
            return NULL;
        }
    }

    if (strcmp(tree->root->word, word) < 0)
    {
        // search right
        bst_search(tree->root->right, word);
    }
    else
    {
        if (strcmp(tree->root->word, word) > 0)
        {
            // search left
            bst_search(tree->root->left, word);
        } // else found
        // word found
        return tree->root;
    }
    return NULL;
}

/**
 * @brief Counts the number of nodes present in a binary search tree
 * 
 * @param tree the BST
 * @return int the amount of nodes
 */
int bst_count_nodes(BST tree)
{
    if (tree == (BST)NULL)
    {
        return 0;
    }
    return 1 + bst_count_nodes(tree->root->left) + bst_count_nodes(tree->root->right);
}