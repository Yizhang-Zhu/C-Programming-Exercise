//

// C++������ƻ��� Project2

// ATM ģ�����

// 2020.6.5

// ������ 20194113

// �����˺�



#include<iostream> 
#include<windows.h> 
#include<iomanip>  
#include<fstream>    
#include<cstring>  
#include<time.h>

using namespace std;


class account {
    /**************************    �û�����   **************************/
public:
    int use;  //�û�����
    int pwd;  //password
    double rmb;  //���(�����)
public:
    /***********************   ���溯��  ************************/
    void welcome();               //Ĭ����ʾ����
    void login_show();            //��¼�ɹ�����
    void menu_show();             //Ĭ�����˵�
    void balance_show();          //����ѯ����
    void withdraw_show();         //ATMȡ�����
    void deposit_show();          //ATM������
    void pwdchange_show();        //�����޸Ľ���
    void pwdchange_confirm();     //�����޸�ȷ�Ͻ���
    void exit();                  //�˳�ϵͳ����

    /***********************   ��������  ************************/
    void login();        //��¼ϵͳ����
    void menu();         //���˵�����
    void withdraw();     //ATMȡ���
    void deposit();      //ATM���� 

    /***********************   ���Ժ���  ************************/
    void test1();
    void test2();
    void test3();

    /***********************   ���Ϻ���  ************************/
    void system_broken();


}a, b;


/*************************  �Ӻ���     ***********************/

/*************************  ������ʾ����  ***********************/

void account::welcome()     //��ӭ���� ������Գ����
{
    fflush(stdin);
    system("cls");
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                               �������˺ź������¼��ϵͳ��                                            " << endl;
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;

    login();

}

void account::login_show()    //��¼�ɹ����� 
{
    system("cls");
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ���ѳɹ���¼��ϵͳ ��                           " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;

    Sleep(2000);
    system("cls");
    menu_show();

}

void account::menu_show()        //Ĭ�����˵�����
{

    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                            �������������ѡ���Ӧ����                         " << endl;
    cout << "                                                                               " << endl;
    cout << "                                ��1��   ����ѯ                               " << endl;
    cout << "                                ��2��   ʵʱȡ��                               " << endl;
    cout << "                                ��3��   ʵʱ���                               " << endl;
    cout << "                                ��4��   �����޸�                               " << endl;
    cout << "                                ��5��   �˳�ϵͳ                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << endl;
    cout << "                           �����롾1��5����";

    menu();

}

void account::balance_show()           //����ѯ����
{

    int m;
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  ������ѯ��                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                         ����ǰ���ϵ����Ϊ:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            �������������ѡ���Ӧ����                         " << endl;
    cout << "                                ��1��   ��ѯˢ��                               " << endl;
    cout << "                                ��2��   ���ز˵�                               " << endl;
    cout << "                                ��3��   �˳�ϵͳ                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << endl;
    cout << "                           �����롾1��3����";
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
            << "                           �����������ȷ���룡";
        Sleep(1000);
        system("cls");
        balance_show();
    }

}

void account::withdraw_show()       //ATMȡ�����
{
    system("cls");
    fflush(stdin);
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  ��ʵʱȡ�                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                        ����ǰ���ϵĿ������Ϊ:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            �������������ѡ���Ӧ����                         " << endl;
    cout << "                              ��ȡ������ʵʱ���                               " << endl;
    cout << "                                ��1��   ���ز˵�                               " << endl;
    cout << "                                ��2��   �˳�ϵͳ                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << endl;
    cout << "                           ���롾1����2��������������                        " << endl;
    cout << "        ÿ�����롾���������Ϊ100���������������ڿ������������5000Ԫ          " << endl;
    cout << "                           �����롾���������1����2����";

    withdraw();
}

void account::deposit_show()     //ATM������ 
{

    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  ��ʵʱ��                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                        ����ǰ���ϵĿ������Ϊ:"
        << setw(15) << showpoint << fixed << setprecision(2) << a.rmb << endl;
    cout << "                                                                               " << endl;
    cout << "                            �������������ѡ���Ӧ����                         " << endl;
    cout << "                              ���������ʵʱ���                               " << endl;
    cout << "                                ��1��   ���ز˵�                               " << endl;
    cout << "                                ��2��   �˳�ϵͳ                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << endl;
    cout << "                           ���롾1����2����������д��                        " << endl;
    cout << "          ÿ�η��롾���������Ϊ100������������ֻ�ܷ���100Ԫ���ĳ�Ʊ           " << endl;
    cout << "                           �����롾���������1����2����";
    deposit();

}

void account::pwdchange_show()            //�����޸Ľ��� 
{

    fflush(stdin);
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                  �������޸ġ�                                 " << endl;
    cout << "                                                                               " << endl;
    cout << "                            �������������ѡ���Ӧ����                         " << endl;
    cout << "                                ��1��   �����޸�                              " << endl;
    cout << "                                ��2��   ���ز˵�                               " << endl;
    cout << "                                ��3��   �˳�ϵͳ                               " << endl;
    cout << "                                                                               " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << endl;
    cout << "                           ���롾2����3����������������޸�                    " << endl;
    cout << "                           ���롾1��������о�����ȷ�����޸�                   " << endl;
    cout << "                              �����롾1-3����";
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
            << "                           �����������ȷ���룡";
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
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                ��������Ϊ��λ������ȫ��ͬ���֣���Ҫ��������ȷ�ϣ�             " << endl;
    cout << "                                                                               " << endl;
    cout << "                          �����������:";
    cin >> pwd0;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // ����ļ��Ƿ�ɹ���  
        cout << "          ϵͳ���ϣ��޷�ʹ�ã�����ϵ�ͷ���" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    if (pwd0 != a.pwd)
    {
        cout << "                             ���������д��޷��޸����룡               ";
        Sleep(3000);
        system("cls");
        pwdchange_show();
    }
    else
    {
        cout << "                          ������������:";
        cin >> newpwd1;
        cout << endl
            << "                          ��ȷ��������:";
        cin >> newpwd2;
        if (newpwd1 == newpwd2)
        {
            a.pwd = newpwd2;
            acc.open("ac.txt", ios::out);
            acc << a.use << "  " << a.pwd << "   " << a.rmb;
            acc.close();


            cout << "��    ===================================================================    ��" << endl;
            cout << "                            �����޸���ɣ����μ������룡                       " << endl;
            Sleep(3000);
            system("cls");
            fflush(stdin);
            pwdchange_show();
        }
        else
        {
            cout << "                          �������벻һ�£��޷��޸����룡";
            Sleep(3000);
            system("cls");
            pwdchange_show();
        }
    }
}

void account::exit()      //�˳�ϵͳ���� 
{
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
    cout << "                                                                               " << endl;
    cout << "                                      ATM����ϵͳ                             " << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "                                                                               " << endl;
    cout << "                �Ƿ��˳�ϵͳ��                                                 " << endl;
    cout << "                                                                              " << endl;
    cout << "               �����롾1��ȷ��                                                  " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << "                                                                               " << endl;
    cout << endl;
    cout << "��    ===================================================================    ��" << endl;
    cout << "               �����롾1��ȷ���˳����������򷵻ز˵���";

    int w;
    cin >> w;

    if (w == 1)
    {
        system("cls");
        cout << endl;
        cout << "��    ===================================================================    ��" << endl;
        cout << "                                                                               " << endl;
        cout << "                                   ��ӭʹ�ó���Գ����                        " << endl;
        cout << "                                                                               " << endl;
        cout << "                                      ATM����ϵͳ                             " << endl;
        cout << "��    ===================================================================    ��" << endl;
        cout << "                                                                               " << endl;
        cout << "                      ���ѳɹ��˳�ϵͳ����ӭ�����ٴ�ʹ��                       " << endl;
        cout << endl;
        cout << "��    ===================================================================    ��" << endl;

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

/*************************  ��������  ***********************/
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
        cout << "                           �����������ȷ���룡";
        Sleep(2000);
        system("cls");
        menu_show();
    }
}

void account::login()    //��¼ϵͳ����
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

    cout << "                            �������˺ţ�";
    cin >> setw(7) >> b.use;

    while (b.use <= 100000 && b.use >= 999999)
    {
        cout << "                         �˺Ŵ������������룡";
        Sleep(2000);
        welcome();

    }
    cout << "                            ���������룺";
    cin >> setw(7) >> b.pwd;
    while ((b.use <= 100000 && b.use >= 999999))
    {
        cout << "                            ����������������룡";
        Sleep(2000);
        welcome();
    }

    if (b.use == a.use && b.pwd == a.pwd)
    {
        login_show();
    }
    else
    {
        cout << "                       ���û������ڻ�������������������룡";
        Sleep(2000);
        welcome();
    }

}

void account::withdraw()    //ATMȡ���
{
    int g = 0;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // ����ļ��Ƿ�ɹ���  
        cout << "          ϵͳ���ϣ��޷�ʹ�ã�����ϵ�ͷ���" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    cin >> g;


    while (g != 1 && g != 2 && g % 100 != 0 && g > 5000 && g > a.rmb)
    {
        cout << "                          ������������¼������룡                         " << endl;
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
        cout << "                              ���ѳɹ�ȡ���" << setw(15) << g << "Ԫ            " << endl;
        a.rmb -= g;
        acc.open("ac.txt", ios::out);
        acc << a.use << "   " << a.pwd << "   " << a.rmb;
        acc.close();

        Sleep(2000);
        system("cls");
        menu_show();

    }


}

void account::deposit()   //ATM����
{
    int h;
    fstream acc;
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // ����ļ��Ƿ�ɹ���  
        cout << "          ϵͳ���ϣ��޷�ʹ�ã�����ϵ�ͷ���" << endl;
    else
        acc >> a.use >> a.pwd >> a.rmb;
    acc.close();

    cin >> h;
    while (h != 1 && h != 2 && h % 100 != 0)
    {
        cout << "                          �����д������¼������룡                         " << endl;
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


        cout << "                        ���Ժ����ѳɹ�����" << setw(15) << h << "Ԫ            " << endl;
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



/*************************    main����     ************************/

int main()
{
    fstream acc; //the account book
    acc.open("ac.txt", ios::in);
    if (!acc.is_open())                               // ����ļ��Ƿ�ɹ���  
    {//cout << "          ��ϵͳ�Ѿ����ִ����޷�ʹ�ã�����ϵ�ٷ��ͷ���" << endl;
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