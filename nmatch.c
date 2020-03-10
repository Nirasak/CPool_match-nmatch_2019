/*
** EPITECH PROJECT, 2019
** nmatch.c
** File description:
** nmatch
*/

int my_add(int x, int y)
{
    return (x + y);
}

int my_rec_nmatch(char const *s1, char const *s2, int i, int j)
{
    if (s1[i] == '\0' && s2[j] == '\0')
        return (1);
    if (s1[i] != '\0' && s2[j] == '*')
        return (my_add(my_rec_nmatch(s1, s2, i + 1, j),
                    my_rec_nmatch(s1, s2, i, j + 1)));
    if (s1[i] == '\0' && s2[j] == '*')
        return (my_rec_nmatch(s1, s2, i, j + 1));
    if (s1[i] == s2[j])
        return (my_rec_nmatch(s1, s2, i + 1, j + 1));
    return (0);
}

int nmatch(char const *s1, char const *s2)
{
    return (my_rec_nmatch(s1, s2, 0, 0));
}
