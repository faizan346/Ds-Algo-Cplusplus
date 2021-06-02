#include<bits/stdc++.h>
using namespace std;
int out(char, int n, char[]);
static char p[10][20];
char c[10];
int k = 0;
char final[10][20];
int main()
{
     int n, i, j, flag, u, t = 4, d = 0, l, v;
     char a[10], first[10][20];
     cout << "\nEnter the no of productions: ";
     cin >> n;
     for (i = 0; i < n; i++)
     {
          cin >> p[i];
     }
     for (j = 0; j < n; j++)
     {
          k = 0;
          u = 0;
          if (p[j][3] >= 'A' && p[j][3] <= 'Z')
          {
               for (i = 3; i < strlen(p[j]); i++)
               {
                    flag = 0;
                    k = 0;
                    k = out(p[j][i], n, a);
                    for (int l = 0; l < k; l++)
                    {
                         if (a[l] == '^')
                              flag = 1;
                         else
                              first[j][u++] = a[l];
                    }
                    if (flag == 1)
                    {
                         if (i != strlen(p[j]) - 1)
                         {
                              if (p[j][t] >= 'A' && p[j][t] <= 'Z')
                              {
                                   t++;
                                   continue;
                              }
                              else
                              {
                                   first[j][u++] = p[j][t];
                                   break;
                              }
                         }
                         else
                         {
                              first[j][u++] = '^';
                         }
                    }
                    else
                    {
                         break;
                    }
               }
          }
          else
          {
               first[j][0] = p[j][3];
               first[j][1] = '\0';
          }
     }
     t = 0;
     for (int e = 0; e < n; e++)
     {
          int flag = 1;
          for (int i = 0; i < t; i++)
          {
               if (c[i] == p[e][0])
               {
                    flag = 0;
                    break;
               }
               else
               {
                    flag = 1;
               }
          }
          if (flag == 1)
          {
               c[t] = p[e][0];
               d = 0;
               for (int f = 0; f < n; f++)
               {
                    if (p[e][0] == p[f][0])
                    {
                         for (int o = 0; o < strlen(first[f]); o++)
                         {
                              final[t][d++] = first[f][o];
                         }
                         final[t][d] = '\0';
                    }
               }
               t++;
          }
     }
     for (i = 0; i < t; i++)
          cout << "First of " << c[i] << "is : " << final[i] << "\n";
     //Code to find follow
     cout << "\n\nFOLLOW\n";
     for (i = 0; i < strlen(c); i++)
     {
          cout << "\nFollow of " << c[i] << "is :";
          if (i == 0)
               cout << '$' << " ";
          for (j = 0; j < n; j++)
          {
               for (k = 3; k < strlen(p[j]); k++)
               {
                    if (c[i] == p[j][k])
                    {
                         if (k != strlen(p[j]) - 1)
                         {
                              for (l = k + 1; l < strlen(p[j]); l++)
                              {
                                   flag = 0;
                                   if (p[j][l] >= 'A' && p[j][l] <= 'Z')
                                   {
                                        for (u = 0; u < strlen(c); u++)
                                        {
                                             if (c[u] == p[j][l])
                                                  break;
                                        }
                                        for (v = 0; v < strlen(c); v++)
                                        {
                                             if (final[u][v] == '^')
                                                  flag = 1;
                                             else
                                                  cout << final[u][v] << " ";
                                        }
                                        if (flag == 1)
                                        {
                                             if (l == strlen(p[j]) - 1)
                                                  cout << "Follow of " << p[j][0] << " ";
                                             else
                                                  continue;
                                        }
                                        else
                                        {
                                             break;
                                        }
                                   }
                                   else
                                   {
                                        cout << p[j][l];
                                        break;
                                   }
                              }
                         }
                         else
                         {
                              cout << "Follow of " << p[j][0] << " ";
                         }
                    }
               }
          }
     }
     cout << endl;
}
int out(char c, int n, char a[])
{
     for (int i = 0; i < n; i++)
     {
          if (p[i][0] == c)
          {
               if (p[i][3] >= 'A' && p[i][3] <= 'Z')
               {
                    out(p[i][3], n, a);
               }
               else
                    a[k++] = p[i][3];
          }
     }
     return k;
}

// 9
// S->aBDh
// B->cC
// C->bC
// C->^
// D->EF
// E->g
// E->^
// F->f
// F->^