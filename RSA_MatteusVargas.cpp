#include <iostream>
#include <cmath>
#include <map>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

//Variaveis globais
map<char,long long unsigned int> mymap;
map<char,long long unsigned int>::iterator it;
vector<long long unsigned int> mensagemcifrada;
string::iterator itstr;

//Escopo das funcoes
void criaMapa();
void encripta(string msg, long long unsigned int e, long long unsigned int n);
void desencripta(long long unsigned int d, long long unsigned int n);
long long unsigned int euclides(long long unsigned int fi, long long unsigned int i);
long long unsigned int fi(long long unsigned int p,long long unsigned int q);
long long unsigned int gerad(long long unsigned int e,long long unsigned int fi);
long int gerae(long long unsigned int fi);
long long unsigned int potencia(long long unsigned a, long long unsigned int b);
void relatorio(long long unsigned int p,long long unsigned int q,long long unsigned int n,long long unsigned int f, long long unsigned int e, long long unsigned int d);

int main(int argc, char **argv)
{
    criaMapa();
    long long unsigned int p=3,q=17;
    long long unsigned int n = p*q;
    long long unsigned int f = fi(p,q);
    long long unsigned int e = gerae(f);//7
    long long unsigned int d = gerad(e,f);
    string msg;
    cout<<"Entre com a mensagem: ";
    getline(cin,msg);
    cout<<endl;
    encripta(msg,e,n);
    desencripta(d,n);

    /*for(it = mymap.begin(); it != mymap.end(); ++it)
    {
    	std::cout << it->first << " " << it->second<< "\n";
    }*/
    //relatorio(p,q,n,f,e,d);
    return 0;
}
void criaMapa()
{
    mymap.insert ( std::pair<char,long long unsigned int>(' ',	40) );
    mymap.insert ( std::pair<char,long long unsigned int>('.',	37) );
    mymap.insert ( std::pair<char,long long unsigned int>('d',	14) );
    mymap.insert ( std::pair<char,long long unsigned int>('q',	27) );
    mymap.insert ( std::pair<char,long long unsigned int>('-',	38) );
    mymap.insert ( std::pair<char,long long unsigned int>(',',	39) );
    mymap.insert ( std::pair<char,long long unsigned int>('e',	15) );
    mymap.insert ( std::pair<char,long long unsigned int>('r',	28) );
    mymap.insert ( std::pair<char,long long unsigned int>('0',	1) );
    mymap.insert ( std::pair<char,long long unsigned int>('5',	6) );
    mymap.insert ( std::pair<char,long long unsigned int>('9',	10) );
    mymap.insert ( std::pair<char,long long unsigned int>('f',	16) );
    mymap.insert ( std::pair<char,long long unsigned int>('s',	29) );
    mymap.insert ( std::pair<char,long long unsigned int>('1',	2) );
    mymap.insert ( std::pair<char,long long unsigned int>('6',	7) );
    mymap.insert ( std::pair<char,long long unsigned int>('g',	17) );
    mymap.insert ( std::pair<char,long long unsigned int>('t',	30) );
    mymap.insert ( std::pair<char,long long unsigned int>('2',	3) );
    mymap.insert ( std::pair<char,long long unsigned int>('7',	8) );
    mymap.insert ( std::pair<char,long long unsigned int>('h',	18) );
    mymap.insert ( std::pair<char,long long unsigned int>('u',	31) );
    mymap.insert ( std::pair<char,long long unsigned int>('3',	4) );
    mymap.insert ( std::pair<char,long long unsigned int>('8',	9) );
    mymap.insert ( std::pair<char,long long unsigned int>('i',	19) );
    mymap.insert ( std::pair<char,long long unsigned int>('v',	32) );
    mymap.insert ( std::pair<char,long long unsigned int>('4',	9) );
    mymap.insert ( std::pair<char,long long unsigned int>('j',	20) );
    mymap.insert ( std::pair<char,long long unsigned int>('w',	33) );
    mymap.insert ( std::pair<char,long long unsigned int>('a',	11) );
    mymap.insert ( std::pair<char,long long unsigned int>('n',	24) );
    mymap.insert ( std::pair<char,long long unsigned int>('k',	21) );
    mymap.insert ( std::pair<char,long long unsigned int>('x',	34) );
    mymap.insert ( std::pair<char,long long unsigned int>('b',	12) );
    mymap.insert ( std::pair<char,long long unsigned int>('o',	25) );
    mymap.insert ( std::pair<char,long long unsigned int>('l',	22) );
    mymap.insert ( std::pair<char,long long unsigned int>('y',	35) );
    mymap.insert ( std::pair<char,long long unsigned int>('c',	13) );
    mymap.insert ( std::pair<char,long long unsigned int>('p',	26) );
    mymap.insert ( std::pair<char,long long unsigned int>('m',	23) );
    mymap.insert ( std::pair<char,long long unsigned int>('z',	36) );
}

void relatorio(long long unsigned int p,long long unsigned int q,long long unsigned int n,long long unsigned int f, long long unsigned int e, long long unsigned int d)
{
    cout<<"P: "<<p<<endl;
    cout<<"Q: "<<q<<endl;
    cout<<"N: "<<n<<endl;
    cout<<"Fi: "<<f<<endl;
    cout<<"E: "<<e<<endl;
    cout<<"D: "<<d<<endl;
}

void encripta(string msg, long long unsigned int e, long long unsigned int n)
{

    long long unsigned int c, m;
    cout<<endl;
    for(itstr = msg.begin(); itstr < msg.end(); itstr++)
    {
        *itstr = tolower(*itstr);
        c = potencia(mymap.find(*itstr)->second,e);
        m = (c%n);
        mensagemcifrada.push_back(m);
    }
    cout<<"Mensagem cifrada: ";
    for (unsigned i =0 ; i<mensagemcifrada.size(); i++)
    {
        cout<<(mensagemcifrada[i]);
    }
    cout<<endl;
    cout<<endl;
}
void desencripta(long long unsigned int d, long long unsigned int n)
{
    long long unsigned int c, m;
    for (unsigned i =0 ; i<mensagemcifrada.size(); i++)
    {
        c = potencia(mensagemcifrada[i],d);
        m = (c%n);
        mensagemcifrada[i] = m;
    }
    cout<<"Mensagem decifrada: ";
    for (unsigned i =0 ; i<mensagemcifrada.size(); i++)
    {
        for(it = mymap.begin(); it != mymap.end(); ++it)
        {
            if(it->second == mensagemcifrada[i])
            {
                cout<<it->first;
                break;
            }
        }
    }
    cout<<endl;
    cout<<endl;
}

long long unsigned int euclides(long long unsigned int fi, long long unsigned int i)
{
    if (i == 0)
    {
        return fi;
    }
    else
    {
        return euclides(i, fi % i);
    }
}

long long unsigned int gerad(long long unsigned int e,long long unsigned int fi)
{
    long long unsigned int d = 2;
    while((d < fi) && ((e*d) % fi)!= 1)
    {
        d++;
    }
    return d;
}
long long unsigned int potencia(long long unsigned a, long long unsigned int b)
{
    long long unsigned int soma = a;
    for (long long unsigned int i = 0; i < b - 1; i++)
        soma *= a;
    return soma;
}

long int gerae(long long unsigned int fi)
{
    long long unsigned int j=0;
    for(long long unsigned int i=3; i<fi; i++)
    {
        if((euclides(fi,i)==1))
        {
            j = i;
            break;
        }
    }
    return j;
}

long long unsigned int fi(long long unsigned int p,long long unsigned int q)
{
    return (p-1)*(q-1);
}
