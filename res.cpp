#include <iostream>
#include <vector>

using namespace std;

struct Dis{
	vector<int> elem;//Элементы
	int len;//Количество элементов
};

Dis* contrar(Dis &a, Dis &b)
{
	Dis *c=new Dis;
	c->elem.reserve(2);
	c->elem.push_back(0);
	c->elem.push_back(0);
	c->len=0;
	int save;
	int countsave=0;
	for(int i=0;i<a.len;i++)
	{
		int k=0;
		for(int j=0;j<b.len;j++)
		{
			if(a.elem[i]!=(-1)*b.elem[j])
			{
				k++;
			}
			else{
				save=a.elem[i];
			}
		}
		if(k==2){
			c->elem[c->len]=a.elem[i];
			c->len++;
		}else if(k==1){

			for(int t=0;t<b.len;t++)
			{
				if((-1)*save!=b.elem[t])
				{
					c->elem[c->len]=b.elem[t];
					c->len++;
				}
			}
		}
	}
	if(c->elem[0]==a.elem[0] && c->elem[1]==a.elem[1])
	{
		c->elem[0]=0;
		c->elem[1]=0;
		c->len=0;
	}
	if(c->elem[0]==b.elem[1] && c->elem[1]==b.elem[0])
	{
		c->elem[0]=0;
		c->elem[1]=0;
		c->len=2;
	}
	return c;
}

void main(){
	Dis a,b;
	a.elem.reserve(2);
	a.elem.push_back(10);
	a.elem.push_back(9);
	a.len=2;
	cout<<a.elem[0]<<endl;
	cout<<a.elem[1]<<endl;
	cout<<a.len<<endl;
	b.elem.reserve(2);
	b.elem.push_back(-11);
	b.elem.push_back(-9);
	b.len=2;
	cout<<b.elem[0]<<endl;
	cout<<b.elem[1]<<endl;
	cout<<b.len<<endl;
	Dis *c=contrar(a,b);
	cout<<c->elem[0]<<endl;
	cout<<c->elem[1]<<endl;
	cout<<c->len<<endl;
	system("pause");
}
