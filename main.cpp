#include<iostream>
#include<string>
#include <unordered_map>
#include<vector>
using namespace std;

class Player{

private:
    string nume;
    int suma;
public:
    Player(string nnume, int nsuma)
    {
        nume=nnume;
        suma=nsuma;
    }

    Player()
    {

    }
    string getName()
    {
        return nume;
    }
    int getSuma()
    {
        return suma;
    }

    void jocpierdut()
    {
        suma=suma-10;
    }
    void joccastigat()
    {
        suma=suma+10;
    }

    void print()
    {
        cout<<nume<<": "<<suma<<"\n";
    }
};

int Stema(string x)
{
    int k=0;
    if(x=="trefla")
    {
        k=0;
    }
    else if(x=="romb")
    {
        k=0;
    }
    else if(x=="rosu")
    {
        k=0;
    }
    else if(x=="negru")
    {
        k=0;
    }
    else k=1;

    return k;
}

int main()
{
    string command;
    cin>>command;
    if(command=="check_cards")
    {
        int nr_carte;
        int k=0;
        int s=0;
        char c;
        string stema_carte;
        while(cin>>nr_carte>>c>>stema_carte)
        {
            if(Stema(stema_carte)==1)
            {
                k++;
            }
            s=s+nr_carte;
        }
        if(k!=0)
        {
            cout<<"Pachet masluit"<<"\n";
        }
        else if(s!=416)
        {
            cout<<"Pregatit pentru Blackjack"<<"\n";
        }
        else cout<<"Pachet OK"<<"\n";
    }


    if(command=="shuffle_cards")
    {
        int x1, a1, c1, x2, a2 ,c2;
        cin>>a1>>c1>>x1>>a2>>c2>>x2;
        int nr_carte;
        int k=0;
        char c;
        int numere[1000];
        string steme[1000];
        string stema_carte;
        int i=0;
        while(cin>>nr_carte>>c>>stema_carte)
        {
            numere[i]=nr_carte;
            steme[i]=stema_carte;
            i++;
            if(Stema(stema_carte)==1)
            {
                k++;
            }

        }
        int n=50;
        if(k==0)
        {
            int i1=(a1*x1+c1)%i;
            int i2=(a2*x2+c2)%i;
            while(n!=0)
            {
                int aux1;
                string aux2;
                aux1=numere[i1];
                numere[i1]=numere[i2];
                numere[i2]=aux1;
                aux2=steme[i1];
                steme[i1]=steme[i2];
                steme[i2]=aux2;
                i1=(a1*i1+c1)%i;
                i2=(a2*i2+c2)%i;
                n--;
            }
            for(int j=0;j<i;j++)
            {
                cout<<numere[j]<<","<<steme[j]<<"\n";
            }
        }

    }

    if(command=="play_game")
    {
        //unordered_map<string,int>jucatori;
        vector<Player>jucatori;
        int nr_jucatori;
        cin>>nr_jucatori;
        int numar=nr_jucatori+1;
        string nume;
        int suma;
        //string v2[100];
        //int num=0;
        for(int j=0;j<nr_jucatori;j++)
        {
            cin>>nume>>suma;
           //jucatori.insert({nume,suma});

            Player jucator(nume,suma);
            jucatori.push_back(jucator);

            //v2[num]=nume;
            //num++;
           // cout<<nume<<" "<<suma<<endl;
        }

        int x1, a1, c1, x2, a2 ,c2;
        int n=0;
        int i=2;
        int numere[48];
        while(n<48)
        {
            if(i==12 || i==13 || i==14)
            {
                numere[n]=10;
            }
            else
            {
                numere[n]=i;
            }
            n++;
            i++;
            if(i==11)
            {
                i=12;
            }
            if(i==15)
            {
                i=2;
            }
        }
      //  for(int j=0;j<48;j++){ cout<<numere[j]<<" ";}
        while(cin>>a1>>c1>>x1>>a2>>c2>>x2)
        {
            // cout<<a1<<c1<<x1<<a2<<c2<<x2;
            int v[100];
            int x=50;
            int i1=(a1*x1+c1)%48;
           // cout<<i1;
            int i2=(a2*x2+c2)%48;
            //cout<<i2<<endl;
            while(x!=0)
            {
                int aux1;
                aux1=numere[i1];
                numere[i1]=numere[i2];
                numere[i2]=aux1;
                i1=(a1*i1+c1)%48;
                i2=(a2*i2+c2)%48;
                x--;
            }
            for(int j=0;j<nr_jucatori+1;j++)
            {
                v[j]=numere[2*j]+numere[2*j+1];
              //  cout<<j<<":"<<v[j]<<"\n";

            }

            int contor=0;
            for(int j=0;j<numar;j++)
            {
                if(v[j]<17)
                {
                    while(v[j]<17){

                        v[j]=v[j]+numere[2*numar+contor];
                    //   cout<<numere[2*numar+contor]<<" ";
                        contor++;

                    }
                }
                //cout<<j<<":"<<v[j]<<endl;

            }

            for(int j=0;j<nr_jucatori;j++)
            {
                if(v[j]>21)
                {
                    jucatori[j].jocpierdut();

                }
                if(v[nr_jucatori]<=21 && v[j]<v[nr_jucatori])
                {
                    jucatori[j].jocpierdut();
                }
                if(v[j]<=21  && v[j]>v[nr_jucatori])
                {
                    jucatori[j].joccastigat();
                }
                if(v[j]<=21 && v[nr_jucatori]>21)
                {
                    jucatori[j].joccastigat();
                }
                if(jucatori[j].getSuma()<=0)
                {
                    jucatori.erase(jucatori.begin()+j);
                    for(int k=j;k<nr_jucatori;k++)
                    {
                    v[k]=v[k+1];
                    }
                    j=j-1;
                    nr_jucatori=nr_jucatori-1;
                    numar--;

                }
              //  cout<<endl<<jucatori[j].getSuma()<<endl<<endl;
            }
            //cout<<endl<<nr_jucatori<<endl;

            for(int j=0;j<48;j++)
            {
               // cout<<numere[j]<<"\n";
            }
        }
       // for (auto j = jucatori.begin(); j!= jucatori.end(); j++) {
         //   cout << j->first << ": " << j->second << endl;}
        for(int j=0;j<jucatori.size();j++)
        {
            jucatori[j].print();
        }

    }
}

