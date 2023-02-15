#include "node.h"
#include "tree.h"

NODE node_init(char * word)
{
    NODE node = (NODE)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->father = NULL;
    strcpy(node->word, word);
    return node;
}

void node_free(NODE node)
{
    if (node != NULL)
    {
        if (node->left != NULL)
        {
            free(node->left);
        }
        else
        {
            if (node->right != NULL)
            {
                free(node->right);
            }
            else
            {
                if (node->father != NULL)
                {
                    free(node->father);
                }
            }
        }
        free(node);
    }
}