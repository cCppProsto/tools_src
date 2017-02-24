#ifndef STRING_TYPE_H
#define STRING_TYPE_H

// https://wiki.qt.io/Doxygen_Plugin_for_QtCreator

typedef struct
{
    char     *p_str;
    unsigned  length;
}sString;

void st_init(sString *);
void st_free(sString *);
void st_add(sString *, const char *);
char st_at(sString *, int);
void st_set_at(sString *, int, char);

unsigned st_length(sString *);

#endif // STRING_TYPE_H
