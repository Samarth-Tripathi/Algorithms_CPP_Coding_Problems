#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class card
{
    private:
        int c;
        char s;

    public:
        friend class deck;
        friend class user;
        friend class dealer;
        card(int ,char );
        void p_card();
};

card:: card(int a, char ch)
{
    this->c=a;
    this->s=ch;
}

void card:: p_card()
{
    cout<<this->s<<" "<<this->c<<" ";
}

class deck
{
    private:
        vector<card> v;
        vector<card> d;

    public:
        card top_card();
        void shuffle();
        void add_deck(card& );
        void add_discard(card );
        void p_deck();
        friend class dealer;

};

card deck:: top_card()
{
    card c=v.back();
    v.pop_back();
    return c;
}

void deck:: shuffle()
{
    random_shuffle(v.begin(),v.end());
}

void deck:: add_deck(card &c)
{
    v.push_back(c);
}

void deck:: add_discard(card c)
{
    d.push_back(c);
}

void deck:: p_deck()
{
    for(int a=0;a<v.size();a++)
        v[a].p_card();
}

class user
{
    private:
        vector<card > v;

    public:
        int score();
        void add(card);
        friend class dealer;

};

void user:: add(card c)
{
    v.push_back(c);
}

int user:: score()
{
    int sum=0;
    for(int a=0;a<v.size();a++)
    {
        if(v[a].c>10)
            sum+=10;
        else
            sum+=v[a].c;
    }
    return sum;
}

class dealer
{
    public:
        void give_card(deck& , user& );
        void shuffle(deck& );
        void check(user ,user );
};

void dealer:: give_card(deck &d1, user &u1)
{
    u1.add(d1.top_card());
}

void dealer:: shuffle(deck &d1)
{
    d1.shuffle();
}

void dealer:: check(user u1,user u2)
{
    if(u1.score() > u2.score())
        cout<<"P1 "<<u1.score()<<endl;
    else
        cout<<"P2 "<<u2.score()<<endl;
}

int main()
{
    card* p;
    deck d;
    for(int a=1;a<=13;a++)
    {
        p=new card(a,'h');
        d.add_deck(*p);
        p=new card(a,'c');
        d.add_deck(*p);
        p=new card(a,'s');
        d.add_deck(*p);
        p=new card(a,'d');
        d.add_deck(*p);
    }
    user u1,u2;
    dealer d1;
    d1.shuffle(d);
    d1.give_card(d,u1);
    d1.give_card(d,u1);
    d1.give_card(d,u2);
    d1.give_card(d,u2);
    d1.check(u1,u2);

}
