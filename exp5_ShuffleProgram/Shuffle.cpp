//设计类，并编写程序模拟扑克牌洗牌。一副扑克牌共有52张牌（不含大小王），
//其中有4种花色：Hearts（红桃）、Spades（黑桃）、Diamonds（方块）和Clubs（梅花），
//每种花色各有13种不同的牌面值：
//Ace（A）、Two（2）、Three（3）、Four（4）、Five（5）、Six（6）、Seven（7）、Eight（8）、Nine（9）、Ten（10）、Jack（J）、Queen（Q）、King（K）。
//用牌面值加花色的方式表示具体的一张扑克牌，比如：“Eight of Hearts”。
//请设计类来表示一张扑克牌和一副扑克牌，并实现洗牌功能，打印输出洗牌的结果。
//模拟洗牌程序

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>

using namespace std;

//储存一张牌的数据：花色color、点数point
class Card{
	public:
		string color;  //花色
		string point;  //点数
		Card(string color, string point);
		Card(string point);
		void index(Card card1);

};

//储存一副牌，之后洗牌打乱
class Cards{
    public:
        vector<Card> card;  //一副牌中用vector容器储存每一张牌
        Cards();
		void show();
        void shufflePoker();
};

Card::Card(string color, string point){
    this->color = color;
    this->point = point;
}

Card::Card(string point){
    this->color = "";
    this->point = point;
}

//利用map建立扑克牌点数、花色（string类型）关于数字的索引（int类型）
void Card::index(Card card1){
	map<string, int> color;  //color花色：Hearts（红桃）、Spades（黑桃）、Diamonds（方块）和Clubs（梅花）
	map<string, int> point;  //point点数：1-13，无大小王
	point["A"] = 1;
	point["2"] = 2;
	point["3"] = 3;
	point["4"] = 4;
	point["5"] = 5;
	point["6"] = 6;
	point["7"] = 7;
	point["8"] = 8;
	point["9"] = 9;
	point["10"] = 10;
	point["J"] = 11;
	point["Q"] = 12;
	point["K"] = 13;
	color["Diamonds"] = 1;
	color["Clubs"] = 2;
	color["Hearts"] = 3;
	color["Spades"] = 4;
}

//嵌套循环按顺序依次输出初始扑克牌
Cards::Cards(){
    string colors[]={"Spades","Hearts","Clubs","Diamonds"};
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            this->card.push_back(Card(colors[i], numbers[j]));
        }
    }
}

//shufflePoker:随机打乱扑克牌（洗牌）的函数
void Cards::shufflePoker(){
    srand((unsigned int)time(0));
	random_shuffle(this->card.begin(), this->card.end());
}

//show:把扑克牌呈现出来的函数
void Cards::show(){
	for(int i=0;i<card.size();i++){
        cout<<this->card[i].color;
		cout<<this->card[i].point + "\t";
    }
    cout<<endl;
}


int main()
{
    cout<<"初始化扑克牌序列："<<endl;
    Cards cards;
	cards.show();
	cout<<"开始洗牌："<<endl;
	cards.shufflePoker();
	cards.show();
    return 0;
}