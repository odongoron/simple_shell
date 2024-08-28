#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
* _strchr - Locates a character in a string.
* @s: The string to be searched.
* @c: The character to be located.
*
* Return: If c is found - a pointer to the first occurrence.
*         If c is not found - NULL.
*/
char *_strchr(char *s, char c)
{
if (!s)
return (NULL);

while (*s)
{
if (*s == c)
return (s);
s++;
}

return (NULL);
}

/**
* _strspn - Gets the length of a prefix substring.
* @s: The string to be searched.
* @accept: The prefix to be measured.
*
* Return: The number of bytes in s which consist only of bytes from accept.
*/
int _strspn(char *s, char *accept)
{
int bytes = 0;
int index;
int found;

if (!s || !accept)
return (0);

while (*s)
{
found = 0;
for (index = 0; accept[index]; index++)
{
if (*s == accept[index])
{
bytes++;
found = 1;
break;
}
}
if (!found)
break;
s++;
}
return (bytes);
}

/**
* _strcmp - Compares two strings.
* @s1: The first string to be compared.
* @s2: The second string to be compared.
*
* Return: Positive byte difference if s1 > s2,
*         0 if s1 = s2,
*         Negative byte difference if s1 < s2.
*/
int _strcmp(char *s1, char *s2)
{
if (!s1 || !s2)
return (0);

while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}

return ((unsigned char)*s1 - (unsigned char)*s2);
}

/**
* _strncmp - Compares two strings up to n bytes.
* @s1: Pointer to the first string.
* @s2: Pointer to the second string.
* @n: The number of bytes to compare.
*
* Return: Less than 0 if s1 is shorter than s2,
*         0 if s1 and s2 match up to n bytes,
*         Greater than 0 if s1 is longer than s2.
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

if (!s1 || !s2)
return (0);

for (i = 0; i < n && s1[i] && s2[i]; i++)
{
if (s1[i] != s2[i])
return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
if (i < n && (s1[i] || s2[i]))
return ((unsigned char)s1[i] - (unsigned char)s2[i]);

return (0);
}
