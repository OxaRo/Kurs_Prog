//22. Написать программу для перевода цен хранящихся в файле из цифр в слова.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;
struct Num {float c; string data;} t;
int j = 0;
void Input(FILE *);
void Translate(FILE *);
void AddToFile(FILE *);
void PrintFile(FILE *);

int main(){
  setlocale(LC_ALL, "Rus");
  char ch;
  FILE *tf;
  while(1){
    puts("\n1 - Новый файл \n2 - Добавить \n3 - Преобразовать и вывести на экран \n0 - Выход");
	ch = getch();
    switch(ch){
      case '1': {
		Input(tf); break;
	  }
      case '2': {
		AddToFile(tf); break;
	  }
	  case '3':{
		Translate(tf); break;
	  }
      case '0': return 0;
      default: puts("\nОшибка");
    }
  }
}

void Input(FILE *tf){
  setlocale(LC_ALL, "Rus");
  char ch;
  remove ("file1.dat");
  tf = fopen("file1.dat","wb");
  printf("\n  Ввод данных:");
  do{
    printf("\nЦена: "); cin >> t.c;
    fwrite(&t, sizeof(t), 1, tf);
    printf("\nЗакончить?  д/н  ");
    j++;
    ch = getch();
  } while (ch == -83 || ch == 121);
  fclose(tf);
}

void Translate(FILE *tf){
  setlocale(LC_ALL, "Rus");
  int r, l, ts, h, t_u, u, ten, d_t, d_u, f_t = 0, f_d = 0;
  string p;
  FILE *kf;
  remove ("file2.dat");
  tf = fopen("file1.dat","rb");
  kf = fopen("file2.dat","wb");
  rewind(tf);
  int e = j;
  while (e){
  fread(&t, sizeof(t), 1, tf);
  f_t = 0, f_d = 0;
  r = t.c/1;
  l = t.c*100;
  ts = r/1000; h = (r/100) % 10; u = r % 10; ten = (r%100)/10; d_u = l % 10; d_t = (l%100)/10;
  p = " ";
  switch(ts){
  	case 1:{ p += "одна тысяча "; break;}
  	case 2:{ p += "две тысячи "; break;}
  	case 3:{ p += "три тысячи "; break;}
  	case 4:{ p += "четыре тысячи "; break;}
  	case 5:{ p += "пять тысяч "; break;}
  	case 6:{ p += "шесть тысяч "; break;}
  	case 7:{ p += "семь тысяч "; break;}
  	case 8:{ p += "восемь тысяч "; break;}
  	case 9:{ p += "девять тысяч "; break;}
  	case 0:{ if (h == 0) if (ten == 0)  if (u == 0) p += "ноль "; break;}
  	default: break;
  }
  
  switch(h){
  	case 1:{ p += "сто "; break;}
  	case 2:{ p += "двести "; break;}
  	case 3:{ p += "триста "; break;}
  	case 4:{ p += "четыреста "; break;}
  	case 5:{ p += "пятьсот "; break;}
  	case 6:{ p += "шестьсот "; break;}
  	case 7:{ p += "семьсот "; break;}
  	case 8:{ p += "восемьсот "; break;}
  	case 9:{ p += "девятьсот "; break;}
  	default: break;
  }
  
  switch(ten){
  	case 1:{
	  switch(u){
  		case 1:{ p += "одиннадцать рублей, "; f_t = 1; break;}
  		case 2:{ p += "двенадцать рублей, "; f_t = 1; break;}
  		case 3:{ p += "тринадцать рублей, "; f_t = 1; break;}
  		case 4:{ p += "четырнадцать рублей, "; f_t = 1; break;}
  		case 5:{ p += "пятнадцать рублей, "; f_t = 1; break;}
  		case 6:{ p += "шестнадцать рублей, "; f_t = 1; break;}
  		case 7:{ p += "семнадцать рублей, "; f_t = 1; break;}
  		case 8:{ p += "восемнадцать рублей, "; f_t = 1; break;}
  		case 9:{ p += "девятнадцать рублей, "; f_t = 1; break;}
  		case 0:{ p += "деcять рублей, "; f_t = 1; break;}
  		default: break;
  	  }
  	  break;
    }
  	case 2:{ p += "двадцать "; break;}
  	case 3:{ p += "тридцать "; break;}
  	case 4:{ p += "сорок "; break;}
  	case 5:{ p += "пятьдесят "; break;}
  	case 6:{ p += "шестьдесят "; break;}
  	case 7:{ p += "семьдесят "; break;}
  	case 8:{ p += "восемьдесят "; break;}
  	case 9:{ p += "девяносто "; break;}
  	default: break;
  }
  
  if (f_t != 1){
  switch(u){
  	case 1:{ p += "один рубль, "; break;}
  	case 2:{ p += "два рубля, "; break;}
  	case 3:{ p += "три рубля, "; break;}
  	case 4:{ p += "четыре рубля, "; break;}
  	case 5:{ p += "пять рублей, "; break;}
  	case 6:{ p += "шесть рублей, "; break;}
  	case 7:{ p += "семь рублей, "; break;}
  	case 8:{ p += "восемь рублей, "; break;}
  	case 9:{ p += "девять рублей, "; break;}
  	case 0:{ p += "рублей, "; break;}
  	default: break;
  }
  }
  
  switch(d_t){
  	case 1:{
	  switch(d_u){
  		case 1:{ p += "одиннадцать копеек "; f_d = 1; break;}
  		case 2:{ p += "двенадцать копеек "; f_d = 1; break;}
  		case 3:{ p += "тринадцать копеек "; f_d = 1; break;}
  		case 4:{ p += "четырнадцать копеек "; f_d = 1; break;}
  		case 5:{ p += "пятнадцать копеек "; f_d = 1; break;}
  		case 6:{ p += "шестнадцать копеек "; f_d = 1; break;}
  		case 7:{ p += "семнадцать копеек "; f_d = 1; break;}
  		case 8:{ p += "восемнадцать копеек "; f_d = 1; break;}
  		case 9:{ p += "девятнадцать копеек "; f_d = 1; break;}
  		case 0:{ p += "десять копеек "; f_d = 1; break;}
  		default: break;
  	  }
  	  break;
    }
  	case 2:{ p += "двадцать "; break;}
  	case 3:{ p += "тридцать "; break;}
  	case 4:{ p += "сорок "; break;}
  	case 5:{ p += "пятьдесят "; break;}
  	case 6:{ p += "шестьдесят "; break;}
  	case 7:{ p += "семьдесят "; break;}
  	case 8:{ p += "восемьдесят "; break;}
  	case 9:{ p += "девяносто "; break;}
  	case 0:{ if (d_u == 0) p += "ноль ноль "; break;}
  	default: break;
  }
  
  if (f_d != 1){
  switch(d_u){
  	case 1:{ p += "одна копейка "; break;}
  	case 2:{ p += "две копейки "; break;}
  	case 3:{ p += "три копейки "; break;}
  	case 4:{ p += "четыре копейки "; break;}
  	case 5:{ p += "пять копеек "; break;}
  	case 6:{ p += "шесть копеек "; break;}
  	case 7:{ p += "семь копеек "; break;}
  	case 8:{ p += "восемь копеек "; break;}
  	case 9:{ p += "девять копеек "; break;}
  	case 0:{ p += "копеек "; break;}
  	default: break;
  }
  }
  t.data = p;
  t.data += '\0';
  fwrite(&t, sizeof(t), 1, kf);
    cout << j-e+1 << "  " << t.c << ": " << "  " << t.data << endl;
  e--;
}
  fclose(tf);
  fclose(kf);
}

void AddToFile(FILE *tf){
  setlocale(LC_ALL, "Rus");
  char ch;
  tf = fopen("file1.dat","ab");
  printf("\n  Ввод данных:");
  do{
    printf("\nЦена: "); cin >> t.c;
    fwrite(&t, sizeof(t), 1, tf);
    j++;
    printf("\nЗакончить?  д/н  ");
    ch = getch();
  } while (ch == -83 || ch == 121);
  fclose(tf);
}
