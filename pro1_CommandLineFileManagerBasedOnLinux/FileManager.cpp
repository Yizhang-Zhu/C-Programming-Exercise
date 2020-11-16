#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
using namespace std;


/****************************************View*********************************/

//view:对输入命令分割的函数
vector<string> split_str(string s){
	vector<string> tokens;	
	istringstream iss(s);
    do{
        string sub;
        iss >> sub;
        tokens.push_back(sub);
    } while (iss);
    tokens.erase(tokens.end()-1); // 删除最后的换行回车符
    
    return tokens;
}

//view:欢迎界面-提示开始以及命令格式
void welcome(){
	cout<<"=============================================="<<endl;
	cout<<"            欢迎使用命令行文件管理器"<<endl;
	cout<<"                ver: 5.1final  modified by zyz"<<endl;
	cout<<"=============================================="<<endl;
	cout<<"命令格式： ? xx1 xx2 …… xxN"<<endl;
	cout<<"   ?表示操作选项，xx1~xxN表示操作参数"<<endl;
	cout<<"\n操作选项如下："<<endl;
	cout<<"   md  创建文件夹       rd  删除文件夹"<<endl;
	cout<<"   cd  改变当前文件夹   ld  列出文件夹内容"<<endl;
	cout<<"   cp  复制文件/文件夹  rf  删除文件"<<endl;
	cout<<"   q   退出\n"<<endl;  
}


/*************************************Module****************************************/

//Module:创建文件夹
void makedoc(vector<string> commandArgs){
	if(commandArgs.size()<2){
		cout<<"error: 请输入文件夹名字"<<endl;
	}else{
		string dirName = commandArgs[1];
		mode_t mode = 0775;
		if(mkdir(dirName.c_str(), mode)==0){
    		cout<<"创建文件夹‘"<<dirName<<"’成功"<<endl;
    	}else{
    		cout<<"error: 创建文件夹‘"<<dirName<<"’失败。"<<endl;
    	}
	}		
}

//Module:删除文件夹
void removedoc(vector<string> commandArgs){
	if(commandArgs.size()<2){
		cout<<"error: 请输入文件夹名字"<<endl;
	}else{
		string dirName = commandArgs[1];
		if(rmdir(dirName.c_str()) == 0 ){
			cout<<"删除文件夹‘"<<dirName<<"’成功"<<endl;
		}else{
    		cout<<"error: 删除文件夹‘"<<dirName<<"’失败。"<<endl;
    	}	
    }    
}

//Module:删除文件
void removefile(vector<string> commandArgs){
	if(commandArgs.size()<2){
		cout<<"error: 请输入文件名字"<<endl;
	}else{
		string fileName = commandArgs[1];
		if(remove(fileName.c_str()) == 0 ){
			cout<<"删除文件‘"<<fileName<<"’成功"<<endl;
		}else{
    		cout<<"error: 删除文件‘"<<fileName<<"’失败。"<<endl;
    	}	
	}    
}

//Module:改变文件夹
void changedoc(vector<string> commandArgs){
	if(commandArgs.size()<2){
		cout<<"error: 请输入文件夹名字"<<endl;
	}else{
		string dirName = commandArgs[1];
		if(chdir(dirName.c_str())==0){
    		char curDir[300];
    		getcwd(curDir,300);
    		cout<<"当前工作目录更改为："<<curDir<<endl;
    	}else{
    		cout<<"error: 改变当前文件夹失败。"<<endl;
    	}
	}
}

//Module:列出文件夹
void listdoc(vector<string> commandArgs){
	DIR * curDir;
	struct dirent *ent;
	struct stat entStat;
	if((curDir=opendir("."))==NULL){
    	cout<<"error: 打开当前文件夹失败。"<<endl;
    }else{
		while((ent=readdir(curDir))!=NULL){   			
			if(stat(ent->d_name, &entStat) == 0){
				if(entStat.st_mode & S_IFDIR){
					cout<<setw(6)<<left<<"d";
					cout<<right<<setw(10)<<entStat.st_size<<left<<setw(8)<<" bytes";
					cout<<ent->d_name<<"/"<<endl;
				}else if(entStat.st_mode & S_IFREG){
					cout<<setw(6)<<left<<"-";
					cout<<right<<setw(10)<<entStat.st_size<<left<<setw(8)<<" bytes";
					cout<<ent->d_name<<endl;
				}						
	   		}	   			 	
		}
		closedir(curDir);
    }
}

//Module:复制文件夹
void copydoc(vector<string> commandArgs){
    if(commandArgs.size()<3){
		cout<<"error: 请输入源文件/文件夹名和目标文件/文件夹名。"<<endl;
	}else{
		string sourceFileName = commandArgs[1];
		string targetFileName = commandArgs[2];
		ifstream sourceFile(sourceFileName.c_str(), ios::binary);
		ofstream targetFile(targetFileName.c_str(), ios::binary);
		targetFile<<sourceFile.rdbuf();
		targetFile.close();
		sourceFile.close();
		cout<<"复制成功。"<<endl;			
	}
}

//Module:错误
void error(){
    cout<<"error: 命令错误。"<<endl;
}



/*************************************Control************************************/

//control:不同命令下的控制函数
void control(string commandLine, vector<string> commandArgs){
	if("md"==commandArgs[0]){	
        //创建文件夹		
        makedoc(commandArgs);	
	}else if("rd"==commandArgs[0]){
		//删除文件夹
        removedoc(commandArgs);
	}else if("rf"==commandArgs[0]){
		//删除文件
        removefile(commandArgs);
	}else if("cd"==commandArgs[0]){
		//改变当前文件夹
        changedoc(commandArgs);
	}else if("ld"==commandArgs[0]){
		//列出文件夹内容
        listdoc(commandArgs);
	}else if("cp"==commandArgs[0]){
		//复制文件/文件夹
        copydoc(commandArgs);
	}else{
		error();
	}
}

//control:main()主函数
int main(int argc, char **argv)
{
    //开始界面
	welcome();

    //输入处理
	cout<<"?";
	string commandLine;
	vector<string> commandArgs;
	
	getline(cin,commandLine);	
	commandArgs=split_str(commandLine);
	
    //命令实现
	while(commandArgs.size()>0 && "q"!=commandArgs[0]){

        //根据不同命令进行文件处理
        control(commandLine, commandArgs);

		cout<<"?";
		getline(cin,commandLine);	
		commandArgs=split_str(commandLine);

	}
	
	return 0;
}