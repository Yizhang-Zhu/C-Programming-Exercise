//

// C++程序设计基础 Project2

// ATM 模拟程序

// 2020.6.5

// 朱绎彰 20194113

// 测试账号



#include<iostream> 
#include<windows.h> 
#include<iomanip>  
#include<fstream>    
#include<cstring>  
#include<time.h>

using namespace std;


class account {
    /**************************    用户数据   **************************/
public:
    int use;  //用户卡号
    int pwd;  //password
    double rmb;  //余额(人民币)
public:
    /***********************   界面函数  ************************/
    void welcome();               //默认显示界面
    void login_show();            //登录成功界面
    void menu_show();             //默认主菜单
    void balance_show();          //余额查询界面
    void withdraw_show();         //ATM取款界面
    void deposit_show();          //ATM存款界面
    void pwdchange_show();        //密码修改界面
    void pwdchange_confirm();     //密码修改确认界面
    void exit();                  //退出系统界面

    /***********************   操作函数  ************************/
    void login();        //登录系统函数
    void menu();         //主菜单函数
    void withdraw();     //ATM取款函数
    void deposit();      //ATM存款函数 

    /***********************   测试函数  ************************/
    void test1();
    void test2();
    void test3();

    /***********************   故障函数  ************************/
    void system_broken();


}a, b;


/*************************  子函数     ***********************/

/*************************  界面显示函数  ***********************/

void account::welcome()     //欢迎界面 ：程序猿银行
{
    fflush(stdin);
    system("cls");
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                               请输入账号和密码登录本系统！                                            " << endl;
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;

    login();

}

void account::login_show()    //登录成功界面 
{
    system("cls");
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   您已成功登录本系统 ！                           " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;

    Sleep(2000);
    system("cls");
    menu_show();

}

void account::menu_show()        //默认主菜单界面
{

    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                            请输入相关数字选择对应功能                         " << endl;
    cout << "                                                                               " << endl;
    cout << "                                【1】   余额查询                               " << endl;
    cout << "                                【2】   实时取款                               " << endl;
    cout << "                                【3】   实时存款                               " << endl;
    cout << "                                【4】   密码修改                               " << endl;
    cout << "                                【5】   退出系统                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << endl;
    cout << "                           请输入【1—5】：";

    menu();

}

void account::balance_show()           //余额查询界面
{

    int m;
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  【余款查询】                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                         您当前卡上的余额为:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            请输入相关数字选择对应功能                         " << endl;
    cout << "                                【1】   查询刷新                               " << endl;
    cout << "                                【2】   返回菜单                               " << endl;
    cout << "                                【3】   退出系统                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << endl;
    cout << "                           请输入【1—3】：";
    cin >> m;


    switch (m)
    {
    case 1:
        system("cls");
        balance_show();
        break;
    case 2:
        system("cls");
        menu_show();
        break;
    case 3:
        system("cls");
        exit();
        break;
    default:
        cout << endl
            << "                           输入错误，请正确输入！";
        Sleep(1000);
        system("cls");
        balance_show();
    }

}

void account::withdraw_show()       //ATM取款界面
{
    system("cls");
    fflush(stdin);
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  【实时取款】                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                        您当前卡上的可用余额为:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            请输入相关数字选择对应功能                         " << endl;
    cout << "                              【取款数】实时提款                               " << endl;
    cout << "                                【1】   返回菜单                               " << endl;
    cout << "                                【2】   退出系统                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << endl;
    cout << "                           输入【1】【2】将不会进行提款                        " << endl;
    cout << "        每次输入【提款数】须为100的整数倍且须少于可用余额且少于5000元          " << endl;
    cout << "                           请输入【提款数】【1】【2】：";

    withdraw();
}

void account::deposit_show()     //ATM存款界面 
{

    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  【实时存款】                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                        您当前卡上的可用余额为:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            请输入相关数字选择对应功能                         " << endl;
    cout << "                              【存款数】实时存款                               " << endl;
    cout << "                                【1】   返回菜单                               " << endl;
    cout << "                                【2】   退出系统                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << endl;
    cout << "                           输入【1】【2】将不会进行存款                        " << endl;
    cout << "          每次放入【存款数】须为100的整数倍，且只能放入100元整的钞票           " << endl;
    cout << "                           请输入【存款数】【1】【2】：";
    deposit();

}

void account::pwdchange_show()            //密码修改界面 
{

    fflush(stdin);
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  【密码修改】                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                            请输入相关数字选择对应功能                         " << endl;
    cout << "                                【1】   密码修改                              " << endl;
    cout << "                                【2】   返回菜单                               " << endl;
    cout << "                                【3】   退出系统                               " << endl;
    cout << "                                                                               " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << endl;
    cout << "                           输入【2】【3】将不会进行密码修改                    " << endl;
    cout << "                           输入【1】将会进行旧密码确认于修改                   " << endl;
    cout << "                              请输入【1-3】：";
    int q;
    cin >> q;

    switch (q)
    {
    case 1:
        system("cls");
        pwdchange_confirm();
        break;
    case 2:
        system("cls");
        menu_show();
        break;
    case 3:
        system("cls");
        exit();
        break;
    default:
        cout << endl
            << "                           输入错误，请正确输入！";
        Sleep(1000);
        system("cls");
        pwdchange_show();

    }
}

void account::pwdchange_confirm()
{
    int pwd0, newpwd1, newpwd2;
    fflush(stdin);


    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                新密码须为六位不能完全相同数字，需要输入两次确认！             " << endl;
    cout << "                                                                               " << endl;
    cout << "                          请输入旧密码:";
    cin >> pwd0;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // 检查文件是否成功打开  
        cout << "          系统故障，无法使用！请联系客服！" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    if (pwd0 != a.pwd)
    {
        cout << "                             密码输入有错！无法修改密码！               ";
        Sleep(3000);
        system("cls");
        pwdchange_show();
    }
    else
    {
        cout << "                          请输入新密码:";
        cin >> newpwd1;
        cout << endl
            << "                          请确认新密码:";
        cin >> newpwd2;
        if (newpwd1 == newpwd2)
        {
            a.pwd = newpwd2;
            acc.open("ac.txt", ios::out);
            acc << a.use << "  " << a.pwd << "   " << a.rmb;
            acc.close();


            cout << "☆    ===================================================================    ☆" << endl;
            cout << "                            密码修改完成，请牢记新密码！                       " << endl;
            Sleep(3000);
            system("cls");
            fflush(stdin);
            pwdchange_show();
        }
        else
        {
            cout << "                          两次密码不一致，无法修改密码！";
            Sleep(3000);
            system("cls");
            pwdchange_show();
        }
    }
}

void account::exit()      //退出系统界面 
{
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   欢迎使用程序猿银行                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM服务系统                             " << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "                                                                               " << endl;
    cout << "                是否退出系统？                                                 " << endl;
    cout << "                                                                              " << endl;
    cout << "               请输入【1】确认                                                  " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << endl;
    cout << "☆    ===================================================================    ☆" << endl;
    cout << "               请输入【1】确认退出，其他键则返回菜单：";

    int w;
    cin >> w;

    if (w == 1)
    {
        system("cls");
        cout << endl;
        cout << "☆    ===================================================================    ☆" << endl;
        cout << "                                                                               " << endl;
        cout << "                                   欢迎使用程序猿银行                        " << endl;
        cout << "                                                                               " << endl;
        cout << "                                      ATM服务系统                             " << endl;
        cout << "☆    ===================================================================    ☆" << endl;
        cout << "                                                                               " << endl;
        cout << "                      您已成功退出系统，欢迎您的再次使用                       " << endl;
        cout << endl;
        cout << "☆    ===================================================================    ☆" << endl;

        Sleep(4000);
        system("cls");
        welcome();
    }
    else
    {
        system("cls");
        menu_show();
    }
}

/*************************  操作函数  ***********************/
void account::menu()
{
    fflush(stdin);
    int v;
    cin >> v;

    switch (v)
    {
    case 1:
        system("cls");
        balance_show();
        break;
    case 2:
        system("cls");
        withdraw_show();
        break;
    case 3:
        system("cls");
        deposit_show();
        break;
    case 4:
        system("cls");
        pwdchange_show();
        break;
    case 5:
        system("cls");
        exit();
        break;
    default:
        cout << "                           输入错误，请正确输入！";
        Sleep(2000);
        system("cls");
        menu_show();
    }
}

void account::login()    //登录系统函数
{
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())
    {
        acc.open("ac.txt", ios::out);
        acc << 1234567890 << "  " << 123456 << "  " << 100000<<endl;
        //acc >> a.use >> a.pwd >> a.rmb;
        acc << 1234567891 << "  " << 123457 << "  " << 800000<<endl;
        acc >> a.use >> a.pwd >> a.rmb;
        acc.close();
    }
    else
    {
        acc >> a.use >> a.pwd >> a.rmb;
    }
    acc.close();

    cout << "                            请输入账号：";
    cin >> setw(7) >> b.use;

    while (b.use <= 100000 && b.use >= 999999)
    {
        cout << "                         账号错误，请重新输入！";
        Sleep(2000);
        welcome();

    }
    cout << "                            请输入密码：";
    cin >> setw(7) >> b.pwd;
    while ((b.use <= 100000 && b.use >= 999999))
    {
        cout << "                            密码错误，请重新输入！";
        Sleep(2000);
        welcome();
    }

    if (b.use == a.use && b.pwd == a.pwd)
    {
        login_show();
    }
    else
    {
        cout << "                       该用户不存在或者密码错误，请重新输入！";
        Sleep(2000);
        welcome();
    }

}

void account::withdraw()    //ATM取款函数
{
    int g = 0;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // 检查文件是否成功打开  
        cout << "          系统故障，无法使用！请联系客服！" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    cin >> g;


    while (g != 1 && g != 2 && g % 100 != 0 && g > 5000 && g > a.rmb)
    {
        cout << "                          输入错误，请重新检查后输入！                         " << endl;
        Sleep(2000);
        system("cls");
        withdraw();
    }

    if (g == 1 || g == 2)
    {
        if (g == 1)
        {
            system("cls");
            menu_show();
        }
        else
        {
            system("cls");
            exit();
        }
    }
    else
    {
        cout << "                              你已成功取款共计" << setw(15) << g << "元            " << endl;
        a.rmb -= g;
        acc.open("ac.txt", ios::out);
        acc << a.use << "   " << a.pwd << "   " << a.rmb;
        acc.close();

        Sleep(2000);
        system("cls");
        menu_show();

    }


}

void account::deposit()   //ATM存款函数
{
    int h;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // 检查文件是否成功打开  
        cout << "          系统故障，无法使用！请联系客服！" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    cin >> h;
    while (h != 1 && h != 2 && h % 100 != 0)
    {
        cout << "                          输入有错，请重新检查后输入！                         " << endl;
        Sleep(2000);
        system("cls");
        withdraw();
    }

    if (h == 1 || h == 2)
    {
        if (h == 1)
        {
            system("cls");
            menu_show();
        }
        else
        {
            system("cls");
            exit();
        }
    }
    else
    {


        cout << "                        请稍后，你已成功存款共计" << setw(15) << h << "元            " << endl;
        a.rmb += h;
        acc.open("ac.txt", ios::out);
        acc << a.use << "   " << a.pwd << "   " << a.rmb;
        acc.close();

        Sleep(2000);
        system("cls");
        menu_show();


    }


}

void test1()
{
    cout << "welcome" << endl;
}

void test2()
{

}

void test3()
{

}

void system_broken()
{
    cout << "system broken" << endl;
}



/*************************    main函数     ************************/

int main()
{
    fstream acc; //the account book
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // 检查文件是否成功打开  
    {//cout << "          该系统已经出现错误！无法使用！请联系官方客服！" << endl;
        acc.open("ac.txt", ios::out);
        acc << 1234567890 << "  " << 123456 << "  " << 100000<<endl;
        //acc >> a.use >> a.pwd >> a.rmb;
        acc << 1234567891 << "  " << 123457 << "  " << 800000<<endl;
        acc >> a.use >> a.pwd >> a.rmb;
        acc.close();
    }
    else
    {
        acc >> a.use >> a.pwd >> a.rmb;
    }
    acc.close();

    system("cls");

    account atm;  //creat a object named atm
    atm.welcome();

    return 0;
}