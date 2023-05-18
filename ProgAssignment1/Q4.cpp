#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;
int total = 0;
bool r = true;
int blackjack(int x ,int y);
int blackjack(int x ,char y);
int blackjack(char x ,int y);
int blackjack(char x ,char y);
int blackjack(int x);
int blackjack(char y);
int check();
int convertb(char x);
char convert(int x);


int main (){
    srand(time(NULL));
    cout <<"Welcome to EC327 Black Jack" << endl;
    int c1;
    int c2;
    char f1;
    char f2;
    bool t1 = false;
    bool t2 = false;

    c1 = rand() % 13 + 2;
    c2 = rand() % 13 + 2;
    if(c1 > 10)
    {
      f1 = convert(c1);
      t1 = true;
    }
    if(c2>10)
    {
      f2 = convert(c2);
      t2= false;
    }
    if(t1 && t2)
    {
      total = blackjack(f1,f2);
    }
    else if (t1 && !t2)
    {
      total = blackjack(f1,c2);
    }
    else if (!t1 && t2)
    {
      total = blackjack(c1,f2);
    }
    else{
      total = blackjack(c1,c2);
    }
    return 0;
}

char convert (int x)
{
    if (x == 11){
        return 'J';
    }
    else if (x == 12){
        return 'Q';
    }
    else if (x == 13){
        return 'K';
    }
    else if (x == 14){
        return 'A';
    }
    else{
        return ' ';
    }

}

int convertb (char x)
{
    if (x == 'A'){
        return 11;
    }
    else{
        return 10;
    }
}
int check (){
    if(total > 21)
  {
    total = -1;
    cout<<"FAILED BLACKJACK";
    r=false;
    return -1;
  }
  else if(total == 21){
    cout<< "YOU WON BLACKJACK";
    return 21;
    r = false;
  }
  else
  {
    cout<< "Total: " << total << endl;
    char ans = ' ';
    cout << "Draw Again (y/n): ";
    cin >> ans;
    if(ans == 'y' || ans == 'Y')
    {
      int c3;
      char f3;
      bool t3 = false;
      c3 = rand() % 13 + 2;
      if(c3>10)
      {
        f3 = convert(c3);
        t3 = true;
      }
      if(t3)
      {
        total = blackjack(f3);
      }
      else{
        total = blackjack(c3);
      }

    }
    else{
      cout<<"YOU QUIT WITH " << total;
      return total;
    }
  }
}
int blackjack(int x ,int y)
{
  total += x + y;
  total = check();
}
int blackjack(int x ,char y)
{
  total += x + convertb(y);
  total = check();

}
int blackjack(char x ,int y)
{
  total += y + convertb(x);
  total = check();
}
int blackjack(char x ,char y)
{
  total += convertb(x) + convertb(y);
  total = check();
}
int blackjack(int x)
{
  total += x;
  total = check();
}
int blackjack(char y)
{
  total += convertb(y);
  total = check();
}