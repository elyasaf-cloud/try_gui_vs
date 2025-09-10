#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Queen
{
    char *name;
    int loc_x;
    int loc_y;
} queen;


queen *ptr_clone(const queen *original)
{
    if(!original)
        return NULL;
    
    queen *copy = malloc(sizeof(queen));
    if(!copy)
        return NULL;
    copy->name = malloc(strlen(original->name) + 1);
    if(!copy->name)
    {
        free(copy);
        return NULL;
    }
    strcpy(copy->name, original->name);
    copy->loc_x = original->loc_x;
    copy->loc_y = original->loc_y;
    return copy;
    
}

queen std_clone(const queen original)
{
    queen copy;
    copy.name = malloc(strlen(original.name) + 1);
    if(!copy.name)
    {
        exit(0);
    }
    strcpy(copy.name, original.name);
    copy.loc_x = original.loc_x;
    copy.loc_y = original.loc_y;
    return copy;
}

void free_queen(queen *tofree)
{
    if(!tofree)
        return;
    if(tofree->name)
        free(tofree->name);
    free(tofree);
}

int main()
{
    queen white;
    white.name = malloc(strlen("white") + 1);
    strcpy(white.name, "white");
    white.loc_x = 3;
    white.loc_y = 4;
    printf("first, before: her name is %s, and she stand in %d,%d\n", white.name, white.loc_x, white.loc_y);

    queen *black = ptr_clone(&white);
    black->loc_x -= 2;
    black->loc_y -= 2;
    strcpy(black->name, "bkack");
    black->name[1] = 'l';
    printf("first, after: her name is %s, and she stand in %d,%d\n", white.name, white.loc_x, white.loc_y);
    printf("second: her name is %s, and she stand in %d,%d\n", black->name, black->loc_x, black->loc_y);

    queen green = std_clone(white);
    strcpy(green.name, "green");
    green.loc_x += 1;
    green.loc_y += 1;
    printf("first, after: her name is %s, and she stand in %d,%d\n", white.name, white.loc_x, white.loc_y);
    printf("third: her name is %s, and she stand in %d,%d\n", green.name, green.loc_x, green.loc_y);

    free(white.name);
    free(green.name);
    free_queen(black);

    return 0;
}
