//22. �������� ��������� ��� �������� ��� ���������� � ����� �� ���� � �����.

#include <cstdio>
#include <stdlib.h>
//#include <string.h>
#include <iostream>
#include <iomanip>
using namespace std;
struct Num {float c; string data;} t;
int j = 0;
void Input();
void Translate();
void AddToFile();
void PrintFile();

int main(){
  setlocale(LC_ALL, "Rus");
  char ch;
 // FILE *tf;
  while(1){
    cout << "\n1 - ����� ���� \n2 - �������� \n3 - ������������� � ������� �� ����� \n0 - �����";
	cin >> ch;
    switch(ch){
      case '1': {
		Input(); break;
	  }
      case '2': {
		AddToFile(); break;
	  }
	  case '3':{
		Translate(); break;
	  }
      case '0': return 0;
      default: cout << "\n������";
    }
  }
}

void Input(){
  setlocale(LC_ALL, "Rus");
  char ch;
FILE *tf;
  remove ("file1.dat");
  tf = fopen("file1.dat","wb");
  cout << "\n  ���� ������:";
  do{
    cout << "\n����: "; cin >> t.c;
    fwrite(&t, sizeof(t), 1, tf);
    cout << "\n���������?  �/�  ";
    j++;
    cin >> ch;
  } while (ch == -83 || ch == 121);
  fclose(tf);
}

void Translate(){
  setlocale(LC_ALL, "Rus");
FILE *tf;
  int r, l, ts, h, u, ten, d_t, d_u, f_t = 0, f_d = 0;
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
  	case 1:{ p += "���� ������ "; break;}
  	case 2:{ p += "��� ������ "; break;}
  	case 3:{ p += "��� ������ "; break;}
  	case 4:{ p += "������ ������ "; break;}
  	case 5:{ p += "���� ����� "; break;}
  	case 6:{ p += "����� ����� "; break;}
  	case 7:{ p += "���� ����� "; break;}
  	case 8:{ p += "������ ����� "; break;}
  	case 9:{ p += "������ ����� "; break;}
  	case 0:{ if (h == 0) if (ten == 0)  if (u == 0) p += "���� "; break;}
  	default: break;
  }
  
  switch(h){
  	case 1:{ p += "��� "; break;}
  	case 2:{ p += "������ "; break;}
  	case 3:{ p += "������ "; break;}
  	case 4:{ p += "��������� "; break;}
  	case 5:{ p += "������� "; break;}
  	case 6:{ p += "�������� "; break;}
  	case 7:{ p += "������� "; break;}
  	case 8:{ p += "��������� "; break;}
  	case 9:{ p += "��������� "; break;}
  	default: break;
  }
  
  switch(ten){
  	case 1:{
	  switch(u){
  		case 1:{ p += "����������� ������, "; f_t = 1; break;}
  		case 2:{ p += "���������� ������, "; f_t = 1; break;}
  		case 3:{ p += "���������� ������, "; f_t = 1; break;}
  		case 4:{ p += "������������ ������, "; f_t = 1; break;}
  		case 5:{ p += "���������� ������, "; f_t = 1; break;}
  		case 6:{ p += "����������� ������, "; f_t = 1; break;}
  		case 7:{ p += "���������� ������, "; f_t = 1; break;}
  		case 8:{ p += "������������ ������, "; f_t = 1; break;}
  		case 9:{ p += "������������ ������, "; f_t = 1; break;}
  		case 0:{ p += "��c��� ������, "; f_t = 1; break;}
  		default: break;
  	  }
  	  break;
    }
  	case 2:{ p += "�������� "; break;}
  	case 3:{ p += "�������� "; break;}
  	case 4:{ p += "����� "; break;}
  	case 5:{ p += "��������� "; break;}
  	case 6:{ p += "���������� "; break;}
  	case 7:{ p += "��������� "; break;}
  	case 8:{ p += "����������� "; break;}
  	case 9:{ p += "��������� "; break;}
  	default: break;
  }
  
  if (f_t != 1){
  switch(u){
  	case 1:{ p += "���� �����, "; break;}
  	case 2:{ p += "��� �����, "; break;}
  	case 3:{ p += "��� �����, "; break;}
  	case 4:{ p += "������ �����, "; break;}
  	case 5:{ p += "���� ������, "; break;}
  	case 6:{ p += "����� ������, "; break;}
  	case 7:{ p += "���� ������, "; break;}
  	case 8:{ p += "������ ������, "; break;}
  	case 9:{ p += "������ ������, "; break;}
  	case 0:{ p += "������, "; break;}
  	default: break;
  }
  }
  
  switch(d_t){
  	case 1:{
	  switch(d_u){
  		case 1:{ p += "����������� ������ "; f_d = 1; break;}
  		case 2:{ p += "���������� ������ "; f_d = 1; break;}
  		case 3:{ p += "���������� ������ "; f_d = 1; break;}
  		case 4:{ p += "������������ ������ "; f_d = 1; break;}
  		case 5:{ p += "���������� ������ "; f_d = 1; break;}
  		case 6:{ p += "����������� ������ "; f_d = 1; break;}
  		case 7:{ p += "���������� ������ "; f_d = 1; break;}
  		case 8:{ p += "������������ ������ "; f_d = 1; break;}
  		case 9:{ p += "������������ ������ "; f_d = 1; break;}
  		case 0:{ p += "������ ������ "; f_d = 1; break;}
  		default: break;
  	  }
  	  break;
    }
  	case 2:{ p += "�������� "; break;}
  	case 3:{ p += "�������� "; break;}
  	case 4:{ p += "����� "; break;}
  	case 5:{ p += "��������� "; break;}
  	case 6:{ p += "���������� "; break;}
  	case 7:{ p += "��������� "; break;}
  	case 8:{ p += "����������� "; break;}
  	case 9:{ p += "��������� "; break;}
  	case 0:{ if (d_u == 0) p += "���� ���� "; break;}
  	default: break;
  }
  
  if (f_d != 1){
  switch(d_u){
  	case 1:{ p += "���� ������� "; break;}
  	case 2:{ p += "��� ������� "; break;}
  	case 3:{ p += "��� ������� "; break;}
  	case 4:{ p += "������ ������� "; break;}
  	case 5:{ p += "���� ������ "; break;}
  	case 6:{ p += "����� ������ "; break;}
  	case 7:{ p += "���� ������ "; break;}
  	case 8:{ p += "������ ������ "; break;}
  	case 9:{ p += "������ ������ "; break;}
  	case 0:{ p += "������ "; break;}
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

void AddToFile(){
  setlocale(LC_ALL, "Rus");
FILE *tf;
  char ch;
  tf = fopen("file1.dat","ab");
  cout << "\n  ���� ������:";
  do{
    cout << "\n����: "; cin >> t.c;
    fwrite(&t, sizeof(t), 1, tf);
    j++;
    cout << "\n���������?  �/�  ";
    cin >> ch;
  } while (ch == -83 || ch == 121);
  fclose(tf);
}
