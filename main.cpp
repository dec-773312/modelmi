#include <iostream>
#include <fstream>
#include<memory.h>

void ShowUsage()
{
    std::cout << "Usage for encryption" << std::endl;
    std::cout << "/Users/shuumichi/Desktop/CLIP-main/train00.py" << std::endl;
    std::cout << "/Users/shuumichi/Desktop/CLIP-main/out " << std::endl;
    //    std::cout << "length" << std::endl;
    //    std::cout << "example:\n ./encryption /data_2/small.pt /data_2/small_en" << std::endl;
    return;
}

std::string rand_str(const int len)
{
    srand( (unsigned)time( NULL ) );
    std::string str;
    char symbol[20] = {'!','@','#','$','%','^','&','*','(',')','?','.','<','>','~','-','+','{',']','['};
    int i;
    char ch;
    for(i=0;i<len;++i)
    {
        switch((rand()%4))
        {
            case 1:
                ch='A'+rand()%26;
                break;
            case 2:
                ch='a'+rand()%26;
                break;
            case 3:
                ch=symbol[rand()%20];
                break;
            default:
                ch='0'+rand()%10;
                break;
        }
        str += ch;
    }

    return str;
}



int main()
{

    std::string path_pt = "/Users/shuumichi/Desktop/MINIST-master/cnn2.pkl";
    std::string path_save_jiami = "/Users/shuumichi/Desktop/MINIST-master/jiami";
    std::string str_len = "10";

    int len = std::stoi(str_len);
    std::string key = "C02V35EZHV29"+rand_str(len);  //加密码为：硬盘指定的序列号+随机生成的密钥

    std::filebuf in;
    std::filebuf outbuf;
    outbuf.open(path_save_jiami,std::ios::out);
    if (!in.open(path_pt, std::ios::in)) {
        std::cout << "fail to open model pt" << std::endl;
        std::cout << "please check path: " << path_pt << std::endl;
        return 0;
    }

    FILE *in_file;
    in_file=fopen(path_pt.c_str(),"rb");//以读的方式打开二进制文件
    char ch=fgetc(in_file);

    int i = 0;
    while(!feof(in_file))
    {
        ch = ch^key[i>=key.size()?i=0:i++];
        outbuf.sputc(ch);
        ch=fgetc(in_file);
    }
    outbuf.sputc(ch);
    outbuf.close();

    std::cout<<"\nsuccess create encryption model!" << std::endl;
    std::cout<<"key=\n"<< key << std::endl;

    return 0;
}
