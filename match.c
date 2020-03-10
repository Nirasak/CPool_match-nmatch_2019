/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** match
*/

int my_intcmp(int x, int y)
{
    if (x >= y)
        return (x);
    return (y);
}

int my_rec_match(char const *s1, char const *s2, int i, int j)
{
    if (s1[i] == '\0' && s2[j] == '\0')
        return (1);
    if (s1[i] != '\0' && s2[j] == '*')
        return (my_intcmp(my_rec_match(s1, s2, i + 1, j),
                    my_rec_match(s1, s2, i, j + 1)));
    if (s1[i] == '\0' && s2[j] == '*') {
        for (; s2[j] == '*'; j++);
        return (my_rec_match(s1, s2, i, j));
    }
    if (s1[i] == s2[j])
        return (my_rec_match(s1, s2, i + 1, j + 1));
    return (0);
}

int match(char const *s1, char const *s2)
{
    return (my_rec_match(s1, s2, 0, 0));
}
