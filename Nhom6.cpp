#include <iostream>
#include <string>
using namespace std;
//struct
struct Node // node kieu char
{
	char data;
	Node* Next;
};

struct Stack // stack kieu char
{
	Node* top;
};
//struct
struct Node1 // node kieu float
{
	float data;
	Node1* Next;
};

struct Stack1 // stack kieu float
{
	Node1* top;
};
// khai bao prototye
Node1* createStackNode1(float d);
void createStack1(Stack1& s);
int IsEmty1(Stack1 s);
int push1(Stack1& s, float d);
int pop1(Stack1& s);
float top1(Stack1 s);
Node* createStackNode(char d);
void createStack(Stack& s);
int IsEmty(Stack s);
int push(Stack& s, char d);
int pop(Stack& s);
int top(Stack s);
bool LaSo(char c);
bool LaTT(char c);
int UT(char c);
string ChuyenTrungToSangHauTo(string TT);
float TinhHauTo(string HT);

int main()
{
	string b = ("(4*5-(1+9)/2)");
	char A, B, C, D;
	string a = "(A+B)*(C-(D+A))";
	int chon, thoat = 0;
	do
	{
		cout << "========================================================================\n\n";
		cout << "\t\t\tMENU\n";
		cout << "\n\n0.Thoat ";
		cout << "\n\n1.Chuyen bieu thuc (4*5-(1+9)/2 sang hau to va tinh ket qua ";
		cout << "\n\n2.Chuyen bieu thuc (A+B)*(C-(D+A)) sang hau to va tinh ket qua ";
		cout << "\n\nVui long nhap lua chon: "; cin >> chon;
		switch (chon)
		{
		case 0: {
			thoat = 1;
			break;
		}
		case 1: {
			

			cout << "Trung to : " << b;
			string a = ChuyenTrungToSangHauTo(b);
			cout << "\n\nHau to: " << a;
			cout << "\n\nKet qua: ";
			cout << TinhHauTo(a);
			cout << "\n";

			break;
		}
		case 2: {
			cout << "\n\nTrung To: " <<a ;
			string k = ChuyenTrungToSangHauTo(a);
			cout << "\n\nHau To: "<<k;
			cout << "\n";
			cout << "\nVui long nhap tu 0-9\n";
			
				fflush(stdin);
				cout << "\nNhap A:";
				cin >> A;
				cout << "\nNhap B:";
				cin >> B;
				cout << "\nNhap C:";
				cin >> C;
				cout << "\nNhap D:";
				cin >> D;
			
				a[1] = A;
				a[3] = B;
				a[7] = C;
				a[10] = D;
				a[12] = A;
			
			cout <<"\n\n=====> " << a;

			
			string c = ChuyenTrungToSangHauTo(a);
			cout << "\n\nHau To: " << c;
			cout << "\n\nKet qua: " << TinhHauTo(c);
			cout << "\n";
			break;
		}
		
		default:("\n\nKhong co lua chon nay!");
			break;
		}

	} while (thoat==0);
	return 0;
}
//prototye
Node1* createStackNode1(float d) //tao node co kieu du lieu float
{
	Node1* p = new Node1;
	if (p == NULL)
		cout << endl << "Khong du bo nho de khoi tao";
	else
	{
		p->data = d;
		p->Next = NULL;
	}
	return p;
}
void createStack1(Stack1& s) //tao stack float de tinh ket qua
{ 
	s.top = NULL;
}
int IsEmty1(Stack1 s)  // kiem tra stack float rong
{
	if (s.top == NULL)
		return 1; // stack rong
	return 0;
}
int push1(Stack1& s, float d) // them vao dinh cua stack float
{
	Node1* p = createStackNode1(d);
	if (p == NULL)
		return 0;
	if (IsEmty1(s) == 1)
		s.top = p;
	else
	{
		p->Next = s.top;
		s.top = p;
	}
	return 1;
}
int pop1(Stack1& s) // lay phan tu o dinh cua stack float
{
	if (IsEmty1(s) == 1)
		return 0;
	Node1* p = s.top;
	s.top = s.top->Next;
	delete p;
	return 1;

}
float top1(Stack1 s) // lay gia tri phan tu o dinh cua stack float
{
	if (IsEmty1(s) == 1)
		return NULL;
	float d = s.top->data;
	return d;
}
Node* createStackNode(char d) // tao node kieu du lieu char
{
	Node* p = new Node;
	if (p == NULL)
		cout << endl << "Khong du bo nho de khoi tao";
	else
	{
		p->data = d;
		p->Next = NULL;
	}
	return p;
}
void createStack(Stack& s) // tao stack de chuyen doi hau to
{
	s.top = NULL;
}
int IsEmty(Stack s) //kiem tra stack char rong
{
	if (s.top == NULL)
		return 1; // stack rong
	return 0;
}
int push(Stack& s, char d) //them phan tu vao dinh cua stack char
{
	Node* p = createStackNode(d);
	if (p == NULL)
		return 0;
	if (IsEmty(s) == 1)
		s.top = p;
	else
	{
		p->Next = s.top;
		s.top = p;
	}
	return 1;
}
int pop(Stack& s) //lay phan tu o dinh cua stack char
{
	if (IsEmty(s) == 1)
		return 0;
	Node* p = s.top;
	s.top = s.top->Next;
	
	delete p;
	return 1;

}
int top(Stack s) //lay gia tri phan tu cua dinh stack char
{
	if (IsEmty(s) == 1)
		return NULL;
	char d = s.top->data;
	return d;
}
bool LaSo(char c) // kiem tra ki tu "c" la so
{		
	return (c >= '0' && c <= '9');
}
bool LaTT(char c)//kiem tra ki tu "c" co la toan tu khong
{
	return (c == '+' || c == '-' || c == '*' || c == '/' );
}
int UT(char c)// xet do uu tien
{

	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/' ) return 2;
	
	return 0;
}


string ChuyenTrungToSangHauTo(string TT)
{
	
	
	string HT = ""; //chuoi dung de xuat hau to
	Stack S;
	createStack(S);
	int len = TT.size();//do dai chuoi
	for (int i = 0; i < len; i++)
	{
		if (LaSo(TT[i])||isalpha(TT[i]))//kiem tra co phai la so khong
		{
			while (LaSo(TT[i])||isalpha(TT[i])) // neu la so thi them vao chuoi HT 
				HT += TT[i++];
			HT += ' ';
		}
		if (TT[i] == '(') 
			push(S,TT[i]); // bo vao stack
		if (TT[i] == ')') // neu gap dau ) thi lay het trong stack ra cho vao chuoi 
		{
			while (top(S) != '(')
			{
				HT += top(S);
				pop(S);
			}
			pop(S);
		}
		if (LaTT(TT[i])) // neu la toan tu thi xet do uu tien 
		{
			while (IsEmty(S)!=1 && UT(top(S)) >= UT(TT[i]))// neu trong stack dang co toan tu khac thi xet do uu tien roi moi dua vao
			{
				HT += top(S); // cho toan tu duoc uu tien vao chuoi
				pop(S);// dem toan tu duoc uu tien ra khoi stack
			}
			push(S, TT[i]);// bo toan tu khong duoc uu tien vao stack
		}
	}
	while (IsEmty(S)!=1)
	{
		HT+=top(S); // bo het tat ca cac phan tu con lai vao chuoi
		pop(S);
	}
	return HT;
}
float TinhHauTo(string HT)
{
	
	Stack1 S;
	createStack1(S);
	float x = 0;
	float a, b, c;
	int len = HT.size();// do dai chuoi
	for (int i = 0; i < len; i++)
	{
		if (LaSo(HT[i]))
		{
			while (LaSo(HT[i]))
			{
				x = x * 10 + HT[i++] - 48; //chuyen ki tu thanh so de tinh va tra ket qua ve x
				push1(S, x); // dua ket qua x vao stack
				x = 0;
			}
		}
		if (LaTT(HT[i]))
		{
		
			a = top1(S);
			pop1(S);
			b = top1(S);
			pop1(S);
			if (HT[i] == '-') c = b - a;
			if (HT[i] == '*') c = b * a;
			if (HT[i] == '/') c = b / a;
			if (HT[i] == '+') c = b + a;
			push1(S, c);
		}
	}
	return top1(S);
}