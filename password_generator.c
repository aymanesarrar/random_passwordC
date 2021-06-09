#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void ft_putchar(char c)
{
  write(1, &c, 1);
}
void ft_putstr(char *str)
{
  while (*str)
    ft_putchar(*str++);
}
int ft_strlen(char *str)
{
  char *ptr;
  ptr = str;
  while (*ptr)
    ptr++;
  return (ptr - str);
}
char *password_generator(int length)
{
  srand(time(0));
  char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOQRSTUVWXYZ_~!#$%%^&*()-+|\\`={}[]:\";<>?,./";
  int i;
  int random_number;
  char *password;
  if (length >= 16 && length <= 64)
  {
    password = (char *)malloc(length + 1);
    i = 0;
    while (i < length)
    {
      random_number = rand() % 91;
      password[i] = characters[random_number];
      i++;
    }
    password[i] = '\0';
    return password;
  }
  return NULL;
}
int main(void)
{
  char *password = password_generator(32);
  ft_putstr(password);
  free(password);
  return (0);
}