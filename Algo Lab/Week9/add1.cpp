# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <bits/stdc++.h>
 
using namespace std;
 

void Generate( char *str, int size, int badchar[])
{
    int i;
 
   
    for (i = 0; i < 126; i++)
         badchar[i] = -1;
 
    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}
 

void search( char *txt,  char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
 
    int badchar[126];
 
   
  Generate(pat,m,badchar);
    int s = 0; 
    while(s <= (n - m))
    {
        int j = m-1;
           while(j >= 0 && pat[j] == txt[s+j])
            j--;
 
        
        if (j < 0)
        {
            printf("\n pattern occurs at shift = %d", s);
 
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
 
        }
 
        else
            s += max(1, j - badchar[txt[s+j]]);
    }
}
 

int main()
{
    char txt[10000];
    char pat[10000];
    cout<<"Enter Pattern:";
    cin>>pat;
    cout<<"Enter Text:";
    cin>>txt;
    search(txt, pat);
    return 0;
}